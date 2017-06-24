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

#include <stm32/core.h>
#include <stm32/scb.h>
#include <threads.h>
#include <tools.h>
#include <debug.h>

#ifndef ISR_STACK_SIZE
#define ISR_STACK_SIZE 512
#endif

struct context
{
    u32_t R8;
    u32_t R9;
    u32_t R10;
    u32_t R11;
    u32_t R4;
    u32_t R5;
    u32_t R6;
    u32_t R7;
    u32_t R0;
    u32_t R1;
    u32_t R2;
    u32_t R3;
    u32_t R12;
    u32_t LR;
    u32_t PC;
    u32_t PSR;
};

struct bind
{
    volatile u32_t *location;
    u32_t mask;
    u32_t value;
};

extern u32_t stack_section_end;
extern u32_t text_section_end;
extern u32_t data_section_begin;
extern u32_t data_section_end;
extern u32_t bss_section_begin;
extern u32_t bss_section_end;

extern void main(void);

struct thread parent_thread =
{
    (void *)&stack_section_end - ISR_STACK_SIZE,
    0,
    0,
    &parent_thread
};

struct thread *active_thread = &parent_thread;
struct thread *shadow_thread;

__attribute__((naked))
void exit_handler(void)
{
    if (active_thread->next == active_thread)
        reboot();

    struct thread *thread = active_thread;
    while (thread->next != active_thread)
        thread = thread->next;

    thread->next = active_thread->next;
    asm volatile ("svc #0\n" : : : "memory");
}

__attribute__((naked))
void startup_handler(void)
{
    copy(&data_section_begin, &text_section_end, (&data_section_end - &data_section_begin) * sizeof(u32_t));
    fill(&bss_section_begin, 0, (&bss_section_end - &bss_section_begin) * sizeof(u32_t));

    SCB->SHP[0] = SCB_SHPx_PR_3;
    SCB->SHP[1] = SCB_SHPx_PR_2;

    asm volatile ("msr psp, %0\n"
                  "msr control, %1\n"
                  "isb\n"
                  "mov lr, %2\n"
                  "bx %3\n" : : "r" (parent_thread.stack), "r" (CONTROL_ASPSEL), "r" (exit_handler),  "r" (main) : );
}

__attribute__((naked))
void nmi_handler(void)
{
    reboot();
}

__attribute__((naked))
void fault_handler(void)
{
#ifdef NO_FAULTS
    reboot();
#else
    u32_t link;
    u32_t *msp;
    u32_t *psp;
    asm volatile ("mov %0, lr\n"
                  "mrs %1, msp\n"
                  "mrs %2, psp\n" : "=r" (link), "=r" (msp), "=r" (psp) : : );

    u32_t thread = link == LR_THREAD_PSP;
    u32_t *stack = thread ? psp : msp;
    debug("%s failed (%8x)\n", thread ? "Thread" : "Handler", stack);
    debug("r0: %8x r12: %8x\n", *stack, *(stack + 4));
    debug("r1: %8x  lr: %8x\n", *(stack + 1), *(stack + 5));
    debug("r2: %8x  pc: %8x\n", *(stack + 2), *(stack + 6));
    debug("r3: %8x psr: %8x\n", *(stack + 3), *(stack + 7));

    stop();
#endif
}

void svc_handler(void)
{
    struct thread *thread = active_thread->next;
    while (thread->condition && !thread->condition(thread->data))
        thread = thread->next;
    shadow_thread = thread;
    SCB->ICSR |= SCB_ICSR_PENDSVSET;
}

__attribute__((naked))
void pending_svc_handler(void)
{
    asm volatile ("mrs r1, psp\n"
                  "sub r1, r1, #16\n"
                  "stmia r1!, {r4, r5, r6, r7}\n"
                  "mov r4, r8\n"
                  "mov r5, r9\n"
                  "mov r6, sl\n"
                  "mov r7, fp\n"
                  "sub r1,r1, #32\n"
                  "stmia r1!, {r4, r5, r6, r7}\n"
                  "sub r1, r1, #16\n"
                  "ldr r3, =active_thread\n"
                  "ldr r2, [r3, #0] \n"
                  "str r1, [r2, #0]\n"
                  "ldr r4, =shadow_thread\n"
                  "ldr r2, [r4, #0]\n"
                  "str r2, [r3, #0]\n"
                  "ldr r3, [r2, #0]\n"
                  "ldmia r3!, {r4, r5, r6, r7}\n"
                  "mov r8, r4\n"
                  "mov r9, r5\n"
                  "mov sl, r6\n"
                  "mov fp, r7\n"
                  "ldmia r3!, {r4, r5, r6, r7}\n"
                  "msr psp, r3\n"
                  "bx lr\n" : : : );
}

__attribute__((naked))
void null_handler(void)
{
#ifdef NO_FAULTS
    reboot();
#else
    u32_t psr;
    asm volatile ("mrs %0, ipsr\n" : "=r" (psr) : : );
    debug("Dummy handler (%8x)", psr);

    stop();
#endif
}

void start_thread(struct thread *thread, function_t function, void *data, void *stack, u32_t size)
{
    struct context *context = (struct context *)(stack + size - sizeof(struct context));
    context->R0 = (u32_t)data;
    context->R1 = 0;
    context->R2 = 0;
    context->R3 = 0;
    context->R12 = 0;
    context->PC = (u32_t)function;
    context->LR = (u32_t)exit_handler;
    context->PSR = PSR_T;

    thread->stack = stack + size - sizeof(struct context);
    thread->condition = 0;
    thread->data = 0;
    thread->next = active_thread->next;
    active_thread->next = thread;
}

void yield_thread(condition_t condition, void *data)
{
    active_thread->condition = condition;
    active_thread->data = data;
    asm volatile ("svc #0\n" : : : "memory");
}

static u32_t bind_condition(struct bind *bind)
{
    return (*bind->location & bind->mask) == bind->value;
}

void wait_for(volatile u32_t *location, u32_t mask, u32_t value)
{
    struct bind bind = {location, mask, value};
    yield_thread((condition_t)bind_condition, &bind);
}

static u32_t mutex_condition(struct mutex *mutex)
{
    return mutex->data == 0;
}

void lock_mutex(struct mutex *mutex)
{
    ASSERT(mutex->data != active_thread);
    if (mutex->data)
        yield_thread((condition_t)mutex_condition, mutex);

    mutex->data = active_thread;
}

void unlock_mutex(struct mutex *mutex)
{
    ASSERT(mutex->data == active_thread);
    mutex->data = 0;
}

__attribute__((naked))
void reboot(void)
{
    SCB->AIRCR = SCB_AIRCR_VECTKEY_KEY | SCB_AIRCR_SYSRESETREQ;
}

__attribute__((naked))
void stop(void)
{
    asm volatile("cpsid i\n"
                 "label_again:\n"
                 "b label_again\n" : : : );
}
