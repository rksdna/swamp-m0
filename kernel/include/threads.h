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

#ifndef THREADS_H
#define THREADS_H

#include <types.h>

typedef void (*function_t)(void *data);
typedef u32_t (*condition_t)(void *data);
typedef u32_t (*signal_t)(void);

struct thread
{
    void *stack;
    condition_t condition;
    void *data;
    struct thread *next;
};

struct mutex
{
    void *data;
};

void start_thread(struct thread *thread, function_t function, void *data, void *stack, u32_t size);
void yield_thread(condition_t condition, void *data);

void wait_status(volatile u32_t *status, u32_t mask, u32_t complement);
void wait_signal(signal_t signal);

void lock_mutex(struct mutex *mutex);
void unlock_mutex(struct mutex *mutex);

void stop(void);
void reboot(void);

#endif
