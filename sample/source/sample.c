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

#if defined(swamp_cdc_module)

#include <threads.h>
#include <timers.h>
#include <tools.h>
#include <debug.h>
#include <cdc.h>
#include "board.h"

static struct thread service_thread;
static u8_t stack[256];

static void service(void *data)
{
    WASTE(data);
    while (1)
    {
        yield_thread((condition_t)has_cdc_line_coding, 0);
        const struct line_coding *coding = get_cdc_line_coding();
        debug("baudrate: %d, data %d, parity %d, stop %d\n", coding->baud_rate, coding->data_bits, coding->parity_type, coding->stop_bits);
    }
}

void main(void)
{
    startup_board();

    start_thread(&service_thread, service, 0, stack, sizeof(stack));

    start_cdc_service();
    set_cdc_timeout(10);
    while (1)
    {
        yield_thread((condition_t)has_cdc_connection, 0);
        debug("connected\n");
        while (has_cdc_connection())
        {
            static u8_t buffer[1024];

            const u32_t count = read_cdc_data(buffer, sizeof(buffer));
            if (count)
            {
                write_cdc_data(buffer, count);
                debug("%m\n", buffer, count);
            }
        }

        debug("disconnected\n");
    }
}

#elif defined(swamp_hid_module)

#include <threads.h>
#include <timers.h>
#include <tools.h>
#include <debug.h>
#include <hid.h>
#include "board.h"

static struct thread service_thread;
static u8_t stack[256];

static void service(void *data)
{
    WASTE(data);
    u32_t status = 0;
    while (1)
    {
        const u32_t new_status = get_hid_led_status();

        if (new_status != status)
        {
            status = new_status;
            debug("led status: %2x", status);
        }

        sleep(100);
    }
}

static struct hid_keyboard_report keyboard;
static struct hid_mouse_report mouse;

static void press(u8_t code)
{
    keyboard.keys[0] = code;
    write_hid_keyboard_report(&keyboard);
    keyboard.keys[0] = 0x00;
    write_hid_keyboard_report(&keyboard);
}

static void move(s8_t x, s8_t y)
{
    mouse.x = x;
    mouse.y = y;
    write_hid_mouse_report(&mouse);
}

void main(void)
{
    startup_board();

    start_thread(&service_thread, service, 0, stack, sizeof(stack));

    start_hid_service();
    while (1)
    {
        yield_thread((condition_t)has_hid_connection, 0);
        debug("connected\n");

        while (has_hid_connection())
        {
            press(0x04);
            press(0x05);
            press(0x06);
            sleep(250);
            move(0, -100);
            sleep(250);
            move(-100, 0);
            sleep(250);
            move(0, 100);
            sleep(250);
            move(100, 0);
            sleep(200);
        }

        debug("disconnected\n");
    }
}

#else

#include <threads.h>
#include <timers.h>
#include <tools.h>
#include <debug.h>
#include "board.h"

struct data
{
    const char *name;
    u32_t count;
    u32_t interval;
};

static struct thread thread_1;
static u8_t stack_1[256];
static struct data data_1 = {"thread 1", 20, 200};

static struct thread thread_2;
static u8_t stack_2[256];
static struct data data_2 = {"thread 2", 10, 300};

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
    }

    stop_timer(&timer);
    debug("%s: bue\n", data->name);
}

void main(void)
{
    u32_t count = 20;

    startup_board();

    debug("[%s] [%2s] [%6s] [%*s]\n", "abcd", "abcd", "abcd", 5, "abcd");
    debug("[%d] [%d] [%d] [%4d] [%12d] [%*d]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%d] [%d] [%d] [%4d] [%12d] [%*d]\n", 0, 1, -1, -654321, -654321, 9, -654321);
    debug("[%u] [%u] [%u] [%4u] [%12u] [%*u]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%x] [%x] [%x] [%4x] [%12x] [%*x]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%c] [%3c] [%*c]\n", '.', '.', 9, '.');

    start_thread(&thread_1, (function_t)blink, &data_1, stack_1, sizeof(stack_1));
    start_thread(&thread_2, (function_t)blink, &data_2, stack_2, sizeof(stack_2));

    debug("main: hello\n");
    board_info();

    while (count--)
    {
        sleep(250);
        debug("main: count {%d}\n", count);
    }

    debug("main: bue\n");
    sleep(10);
}

#endif
