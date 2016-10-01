/*
 * Swamp - cooperative multitasking operating system
 * Copyright (c) 2016 rksdna
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stm32/syscfg.h>
#include <stm32/usart.h>
#include <stm32/gpio.h>
#include <stm32/rcc.h>
#include <threads.h>
#include <debug.h>
#include <tools.h>
#include <cdc.h>

void debug_put(void *data, char value)
{
    while (~USART2->ISR & USART_ISR_TXE)
        continue;

    USART2->TDR = value;
}

struct stream debug_stream = {debug_put, 0};

static u8_t buffer[1024];
static struct thread service_thread;
static u8_t stack[256];

static void service(void *data)
{
    WASTE(data);
    while (1)
    {
        wait_signal(has_cdc_line_coding);
        const struct line_coding *coding = get_cdc_line_coding();
        debug("baudrate: %d, data %d, parity %d, stop %d\n", coding->baud_rate, coding->data_bits, coding->parity_type, coding->stop_bits);
    }
}

void main(void)
{
    RCC->CR = RCC_CR_HSEON | RCC_CR_HSION;
    wait_status(&RCC->CR, RCC_CR_HSERDY);

    RCC->CFGR = RCC_CFGR_PLLMUL12 | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC_HSE_PREDIV;
    RCC->CR = RCC_CR_HSEON | RCC_CR_HSION | RCC_CR_PLLON;
    wait_status(&RCC->CR, RCC_CR_PLLRDY);

    RCC->CFGR = RCC_CFGR_PLLMUL12 | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR_SW_PLL;
    RCC->CFGR3 = 0;

    RCC->AHBENR = RCC_AHBENR_SRAMEN | RCC_AHBENR_FLITFEN | RCC_AHBENR_GPIOAEN;
    RCC->APB1ENR = RCC_APB1ENR_USART2EN | RCC_APB1ENR_USBEN;
    RCC->APB2ENR =  RCC_APB2ENR_SYSCFGCOMPEN;

    SYSCFG->CFGR1 = SYSCFG_CFGR1_PA11_PA12_RMP;

    GPIOA->MODER = GPIO_MODER_MODER0_0 | GPIO_MODER_MODER14_1;
    GPIOA->PUPDR = 0;

    GPIOA->AFRH = (1 << 6 * 4);

    USART2->CR1 = USART_CR1_UE | USART_CR1_TE;
    USART2->CR2 = 0;
    USART2->BRR = 48000000 / 115200 + 1;

    debug("hello\n");

    start_thread(&service_thread, service, 0, stack, sizeof(stack));

    start_cdc_service();
    set_cdc_timeout(10);
    while (1)
    {
        wait_signal(has_cdc_connection);
        debug("connected\n");
        while (has_cdc_connection())
        {
            const u32_t count = read_cdc_data(buffer, 2);
            if (count)
            {
                GPIOA->BSRR = GPIO_BSRR_BS_0;
                write_cdc_data(buffer, count);
                GPIOA->BSRR = GPIO_BSRR_BR_0;
            }
        }

        debug("disconnected\n");
    }
}
