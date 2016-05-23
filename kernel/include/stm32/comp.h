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

#ifndef COMP_H
#define COMP_H

#include <types.h>

struct comp
{
    volatile u32_t CSR;
};

#define COMP ((struct comp *)0x4001001C)

#define COMP_CSR_COMP1EN ((u32_t)0x00000001)
#define COMP_CSR_COMP1SW1 ((u32_t)0x00000002)
#define COMP_CSR_COMP1MODE ((u32_t)0x0000000C)
#define COMP_CSR_COMP1MODE_0 ((u32_t)0x00000004)
#define COMP_CSR_COMP1MODE_1 ((u32_t)0x00000008)
#define COMP_CSR_COMP1INSEL ((u32_t)0x00000070)
#define COMP_CSR_COMP1INSEL_0 ((u32_t)0x00000010)
#define COMP_CSR_COMP1INSEL_1 ((u32_t)0x00000020)
#define COMP_CSR_COMP1INSEL_2 ((u32_t)0x00000040)
#define COMP_CSR_COMP1OUTSEL ((u32_t)0x00000700)
#define COMP_CSR_COMP1OUTSEL_0 ((u32_t)0x00000100)
#define COMP_CSR_COMP1OUTSEL_1 ((u32_t)0x00000200)
#define COMP_CSR_COMP1OUTSEL_2 ((u32_t)0x00000400)
#define COMP_CSR_COMP1POL ((u32_t)0x00000800)
#define COMP_CSR_COMP1HYST ((u32_t)0x00003000)
#define COMP_CSR_COMP1HYST_0 ((u32_t)0x00001000)
#define COMP_CSR_COMP1HYST_1 ((u32_t)0x00002000)
#define COMP_CSR_COMP1OUT ((u32_t)0x00004000)
#define COMP_CSR_COMP1LOCK ((u32_t)0x00008000)
#define COMP_CSR_COMP2EN ((u32_t)0x00010000)
#define COMP_CSR_COMP2MODE ((u32_t)0x000C0000)
#define COMP_CSR_COMP2MODE_0 ((u32_t)0x00040000)
#define COMP_CSR_COMP2MODE_1 ((u32_t)0x00080000)
#define COMP_CSR_COMP2INSEL ((u32_t)0x00700000)
#define COMP_CSR_COMP2INSEL_0 ((u32_t)0x00100000)
#define COMP_CSR_COMP2INSEL_1 ((u32_t)0x00200000)
#define COMP_CSR_COMP2INSEL_2 ((u32_t)0x00400000)
#define COMP_CSR_WNDWEN ((u32_t)0x00800000)
#define COMP_CSR_COMP2OUTSEL ((u32_t)0x07000000)
#define COMP_CSR_COMP2OUTSEL_0 ((u32_t)0x01000000)
#define COMP_CSR_COMP2OUTSEL_1 ((u32_t)0x02000000)
#define COMP_CSR_COMP2OUTSEL_2 ((u32_t)0x04000000)
#define COMP_CSR_COMP2POL ((u32_t)0x08000000)
#define COMP_CSR_COMP2HYST ((u32_t)0x30000000)
#define COMP_CSR_COMP2HYST_0 ((u32_t)0x10000000)
#define COMP_CSR_COMP2HYST_1 ((u32_t)0x20000000)
#define COMP_CSR_COMP2OUT ((u32_t)0x40000000)
#define COMP_CSR_COMP2LOCK ((u32_t)0x80000000)

#endif
