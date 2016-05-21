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
    volatile u16_t CSR;
};

struct comp_common
{
    volatile u32_t CSR;
};

#define COMP_CSR_COMP1EN ((uint32_t)0x00000001)
#define COMP_CSR_COMP1SW1 ((uint32_t)0x00000002)
#define COMP_CSR_COMP1MODE ((uint32_t)0x0000000C)
#define COMP_CSR_COMP1MODE_0 ((uint32_t)0x00000004)
#define COMP_CSR_COMP1MODE_1 ((uint32_t)0x00000008)
#define COMP_CSR_COMP1INSEL ((uint32_t)0x00000070)
#define COMP_CSR_COMP1INSEL_0 ((uint32_t)0x00000010)
#define COMP_CSR_COMP1INSEL_1 ((uint32_t)0x00000020)
#define COMP_CSR_COMP1INSEL_2 ((uint32_t)0x00000040)
#define COMP_CSR_COMP1OUTSEL ((uint32_t)0x00000700)
#define COMP_CSR_COMP1OUTSEL_0 ((uint32_t)0x00000100)
#define COMP_CSR_COMP1OUTSEL_1 ((uint32_t)0x00000200)
#define COMP_CSR_COMP1OUTSEL_2 ((uint32_t)0x00000400)
#define COMP_CSR_COMP1POL ((uint32_t)0x00000800)
#define COMP_CSR_COMP1HYST ((uint32_t)0x00003000)
#define COMP_CSR_COMP1HYST_0 ((uint32_t)0x00001000)
#define COMP_CSR_COMP1HYST_1 ((uint32_t)0x00002000)
#define COMP_CSR_COMP1OUT ((uint32_t)0x00004000)
#define COMP_CSR_COMP1LOCK ((uint32_t)0x00008000)

#define COMP_CSR_COMP2EN ((uint32_t)0x00010000)
#define COMP_CSR_COMP2MODE ((uint32_t)0x000C0000)
#define COMP_CSR_COMP2MODE_0 ((uint32_t)0x00040000)
#define COMP_CSR_COMP2MODE_1 ((uint32_t)0x00080000)
#define COMP_CSR_COMP2INSEL ((uint32_t)0x00700000)
#define COMP_CSR_COMP2INSEL_0 ((uint32_t)0x00100000)
#define COMP_CSR_COMP2INSEL_1 ((uint32_t)0x00200000)
#define COMP_CSR_COMP2INSEL_2 ((uint32_t)0x00400000)
#define COMP_CSR_WNDWEN ((uint32_t)0x00800000)
#define COMP_CSR_COMP2OUTSEL ((uint32_t)0x07000000)
#define COMP_CSR_COMP2OUTSEL_0 ((uint32_t)0x01000000)
#define COMP_CSR_COMP2OUTSEL_1 ((uint32_t)0x02000000)
#define COMP_CSR_COMP2OUTSEL_2 ((uint32_t)0x04000000)
#define COMP_CSR_COMP2POL ((uint32_t)0x08000000)
#define COMP_CSR_COMP2HYST ((uint32_t)0x30000000)
#define COMP_CSR_COMP2HYST_0 ((uint32_t)0x10000000)
#define COMP_CSR_COMP2HYST_1 ((uint32_t)0x20000000)
#define COMP_CSR_COMP2OUT ((uint32_t)0x40000000)
#define COMP_CSR_COMP2LOCK ((uint32_t)0x80000000)

#define COMP_CSR_COMPxEN ((uint32_t)0x00000001)
#define COMP_CSR_COMPxMODE ((uint32_t)0x0000000C)
#define COMP_CSR_COMPxMODE_0 ((uint32_t)0x00000004)
#define COMP_CSR_COMPxMODE_1 ((uint32_t)0x00000008)
#define COMP_CSR_COMPxINSEL ((uint32_t)0x00000070)
#define COMP_CSR_COMPxINSEL_0 ((uint32_t)0x00000010)
#define COMP_CSR_COMPxINSEL_1 ((uint32_t)0x00000020)
#define COMP_CSR_COMPxINSEL_2 ((uint32_t)0x00000040)
#define COMP_CSR_COMPxOUTSEL ((uint32_t)0x00000700)
#define COMP_CSR_COMPxOUTSEL_0 ((uint32_t)0x00000100)
#define COMP_CSR_COMPxOUTSEL_1 ((uint32_t)0x00000200)
#define COMP_CSR_COMPxOUTSEL_2 ((uint32_t)0x00000400)
#define COMP_CSR_COMPxPOL ((uint32_t)0x00000800)
#define COMP_CSR_COMPxHYST ((uint32_t)0x00003000)
#define COMP_CSR_COMPxHYST_0 ((uint32_t)0x00001000)
#define COMP_CSR_COMPxHYST_1 ((uint32_t)0x00002000)
#define COMP_CSR_COMPxOUT ((uint32_t)0x00004000)
#define COMP_CSR_COMPxLOCK ((uint32_t)0x00008000)

#endif
