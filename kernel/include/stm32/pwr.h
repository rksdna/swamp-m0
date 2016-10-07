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

#ifndef PWR_H
#define PWR_H

#include <types.h>

struct pwr
{
    volatile u32_t CR;
    volatile u32_t CSR;
};

#define PWR ((struct pwr *)0x40007000)

#define PWR_CR_LPDS ((u32_t)0x00000001)
#define PWR_CR_PDDS ((u32_t)0x00000002)
#define PWR_CR_CWUF ((u32_t)0x00000004)
#define PWR_CR_CSBF ((u32_t)0x00000008)
#define PWR_CR_PVDE ((u32_t)0x00000010)
#define PWR_CR_PLS ((u32_t)0x000000E0)
#define PWR_CR_PLS_0 ((u32_t)0x00000020)
#define PWR_CR_PLS_1 ((u32_t)0x00000040)
#define PWR_CR_PLS_2 ((u32_t)0x00000080)
#define PWR_CR_PLS_2V2 ((u32_t)0x00000000)
#define PWR_CR_PLS_2V3 ((u32_t)0x00000020)
#define PWR_CR_PLS_2V4 ((u32_t)0x00000040)
#define PWR_CR_PLS_2V5 ((u32_t)0x00000060)
#define PWR_CR_PLS_2V6 ((u32_t)0x00000080)
#define PWR_CR_PLS_2V7 ((u32_t)0x000000A0)
#define PWR_CR_PLS_2V8 ((u32_t)0x000000C0)
#define PWR_CR_PLS_2V9 ((u32_t)0x000000E0)
#define PWR_CR_DBP ((u32_t)0x00000100)

#define PWR_CSR_WUF ((u32_t)0x00000001)
#define PWR_CSR_SBF ((u32_t)0x00000002)
#define PWR_CSR_EWUP1 ((u32_t)0x00000100)
#define PWR_CSR_EWUP2 ((u32_t)0x00000200)
#define PWR_CSR_EWUP4 ((u32_t)0x00000800)
#define PWR_CSR_EWUP5 ((u32_t)0x00001000)
#define PWR_CSR_EWUP6 ((u32_t)0x00002000)
#define PWR_CSR_EWUP7 ((u32_t)0x00004000)
#define PWR_CSR_PVDO ((u32_t)0x00000004)
#define PWR_CSR_VREFINTRDYF ((u32_t)0x00000008)
#define PWR_CSR_EWUP3 ((u32_t)0x00000400)
#define PWR_CSR_EWUP8 ((u32_t)0x00008000)

#endif
