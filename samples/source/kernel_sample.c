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

#include <stm32/usart.h>
#include <stm32/gpio.h>
#include <stm32/rcc.h>
#include <stm32/des.h>
#include <threads.h>
#include <timers.h>
#include <debug.h>
#include <tools.h>

void debug_put(void *data, char value)
{
    while (~USART2->ISR & USART_ISR_TXE)
        continue;

    USART2->TDR = value;
}

struct stream debug_stream = {debug_put, 0};

struct data
{
    const char *name;
    u32_t count;
    u32_t interval;
    u32_t pins;
};

static struct thread thread_1;
static u8_t stack_1[256];
static struct data data_1 = {"thread 1", 20, 200, GPIO_ODR_1};

static struct thread thread_2;
static u8_t stack_2[256];
static struct data data_2 = {"thread 2", 10, 300, GPIO_ODR_2};

static void blink(struct data *data)
{
    u32_t count = data->count;
    struct timer timer;

    debug("%s: hello\n", data->name);
    start_timer(&timer, data->interval);
    while (count--)
    {
        wait_timer(&timer);
        debug("%s: count {%d}\n", data->name, count);

        GPIOA->ODR ^= data->pins;
    }

    stop_timer(&timer);
    debug("%s: bue\n", data->name);
}

void main(void)
{
    u32_t count = 20;

    RCC->AHBENR = RCC_AHBENR_SRAMEN | RCC_AHBENR_FLITFEN | RCC_AHBENR_GPIOAEN;
    RCC->APB1ENR = RCC_APB1ENR_USART2EN;

    GPIOA->MODER = GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | GPIO_MODER_MODER14_1;
    GPIOA->PUPDR = 0;

    GPIOA->AFRH = (1 << 6 * 4);

    USART2->CR1 = USART_CR1_UE | USART_CR1_TE;
    USART2->CR2 = 0;
    USART2->BRR = 8000000 / 115200 + 1;

    start_timers_clock(8000);

    debug("main: hello\n");

    debug("[%s] [%2s] [%6s] [%*s]\n", "abcd", "abcd", "abcd", 5, "abcd");
    debug("[%d] [%d] [%d] [%4d] [%12d] [%*d]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%d] [%d] [%d] [%4d] [%12d] [%*d]\n", 0, 1, -1, -654321, -654321, 9, -654321);
    debug("[%u] [%u] [%u] [%4u] [%12u] [%*u]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%x] [%x] [%x] [%4x] [%12x] [%*x]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%c] [%3c] [%*c]\n", '.', '.', 9, '.');

    debug("{%*m}\n", 12, &DES->UID);
    debug("{%d}\n", DES->FSIZE);

    start_thread(&thread_1, (function_t)blink, &data_1, stack_1, sizeof(stack_1));
    start_thread(&thread_2, (function_t)blink, &data_2, stack_2, sizeof(stack_2));

    while (count--)
    {
        sleep(250);
        GPIOA->BSRR = GPIO_BSRR_BS_0;
        debug("main: count {%d}\n", count);
        GPIOA->BSRR = GPIO_BSRR_BR_0;
    }

    debug("main: bue\n");
    sleep(10);
}
