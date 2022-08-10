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

#include <types.h>

extern u32_t stack_section_end;

extern void startup_handler(void);
extern void nmi_handler(void);
extern void fault_handler(void);
extern void svc_handler(void);
extern void pending_svc_handler(void);
extern void sys_tick_handler(void);
extern void null_handler(void);

__attribute__((naked))
static void irq_handler(void) { null_handler(); }

__attribute__ ((weak, alias("irq_handler")))
extern void irq0_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq1_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq2_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq3_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq4_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq5_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq6_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq7_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq8_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq9_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq10_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq11_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq12_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq13_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq14_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq15_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq16_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq17_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq18_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq19_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq20_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq21_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq22_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq23_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq24_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq25_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq26_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq27_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq28_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq29_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq30_handler(void);

__attribute__ ((weak, alias("irq_handler")))
extern void irq31_handler(void);

__attribute__ ((section(".startup")))
void * const startup_table[] =
{
    &stack_section_end,
    startup_handler,
    nmi_handler,
    fault_handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    svc_handler,
    0,
    0,
    pending_svc_handler,
    sys_tick_handler,
    irq0_handler,
    irq1_handler,
    irq2_handler,
    irq3_handler,
    irq4_handler,
    irq5_handler,
    irq6_handler,
    irq7_handler,
    irq8_handler,
    irq9_handler,
    irq10_handler,
    irq11_handler,
    irq12_handler,
    irq13_handler,
    irq14_handler,
    irq15_handler,
    irq16_handler,
    irq17_handler,
    irq18_handler,
    irq19_handler,
    irq20_handler,
    irq21_handler,
    irq22_handler,
    irq23_handler,
    irq24_handler,
    irq25_handler,
    irq26_handler,
    irq27_handler,
    irq28_handler,
    irq29_handler,
    irq30_handler,
    irq31_handler
};
