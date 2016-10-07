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

#ifndef EXTI_H
#define EXTI_H

#include <types.h>

struct exti
{
    volatile u32_t IMR;
    volatile u32_t EMR;
    volatile u32_t RTSR;
    volatile u32_t FTSR;
    volatile u32_t SWIER;
    volatile u32_t PR;
};

#define EXTI ((struct exti *)0x40010400)

#define EXTI_IMR_MR0 ((u32_t)0x00000001)
#define EXTI_IMR_MR1 ((u32_t)0x00000002)
#define EXTI_IMR_MR2 ((u32_t)0x00000004)
#define EXTI_IMR_MR3 ((u32_t)0x00000008)
#define EXTI_IMR_MR4 ((u32_t)0x00000010)
#define EXTI_IMR_MR5 ((u32_t)0x00000020)
#define EXTI_IMR_MR6 ((u32_t)0x00000040)
#define EXTI_IMR_MR7 ((u32_t)0x00000080)
#define EXTI_IMR_MR8 ((u32_t)0x00000100)
#define EXTI_IMR_MR9 ((u32_t)0x00000200)
#define EXTI_IMR_MR10 ((u32_t)0x00000400)
#define EXTI_IMR_MR11 ((u32_t)0x00000800)
#define EXTI_IMR_MR12 ((u32_t)0x00001000)
#define EXTI_IMR_MR13 ((u32_t)0x00002000)
#define EXTI_IMR_MR14 ((u32_t)0x00004000)
#define EXTI_IMR_MR15 ((u32_t)0x00008000)
#define EXTI_IMR_MR16 ((u32_t)0x00010000)
#define EXTI_IMR_MR17 ((u32_t)0x00020000)
#define EXTI_IMR_MR18 ((u32_t)0x00040000)
#define EXTI_IMR_MR19 ((u32_t)0x00080000)
#define EXTI_IMR_MR23 ((u32_t)0x00800000)
#define EXTI_IMR_MR20 ((u32_t)0x00100000)
#define EXTI_IMR_MR16 ((u32_t)0x00010000)
#define EXTI_IMR_MR21 ((u32_t)0x00200000)
#define EXTI_IMR_MR22 ((u32_t)0x00400000)
#define EXTI_IMR_MR25 ((u32_t)0x02000000)
#define EXTI_IMR_MR27 ((u32_t)0x08000000)
#define EXTI_IMR_MR31 ((u32_t)0x80000000)
#define EXTI_IMR_MR26 ((u32_t)0x04000000)
#define EXTI_IMR_MR28 ((u32_t)0x10000000)
#define EXTI_IMR_MR29 ((u32_t)0x20000000)
#define EXTI_IMR_MR30 ((u32_t)0x40000000)
#define EXTI_IMR_MR31 ((u32_t)0x80000000)

#define EXTI_EMR_MR0 ((u32_t)0x00000001)
#define EXTI_EMR_MR1 ((u32_t)0x00000002)
#define EXTI_EMR_MR2 ((u32_t)0x00000004)
#define EXTI_EMR_MR3 ((u32_t)0x00000008)
#define EXTI_EMR_MR4 ((u32_t)0x00000010)
#define EXTI_EMR_MR5 ((u32_t)0x00000020)
#define EXTI_EMR_MR6 ((u32_t)0x00000040)
#define EXTI_EMR_MR7 ((u32_t)0x00000080)
#define EXTI_EMR_MR8 ((u32_t)0x00000100)
#define EXTI_EMR_MR9 ((u32_t)0x00000200)
#define EXTI_EMR_MR10 ((u32_t)0x00000400)
#define EXTI_EMR_MR11 ((u32_t)0x00000800)
#define EXTI_EMR_MR12 ((u32_t)0x00001000)
#define EXTI_EMR_MR13 ((u32_t)0x00002000)
#define EXTI_EMR_MR14 ((u32_t)0x00004000)
#define EXTI_EMR_MR15 ((u32_t)0x00008000)
#define EXTI_EMR_MR16 ((u32_t)0x00010000)
#define EXTI_EMR_MR17 ((u32_t)0x00020000)
#define EXTI_EMR_MR18 ((u32_t)0x00040000)
#define EXTI_EMR_MR19 ((u32_t)0x00080000)
#define EXTI_EMR_MR23 ((u32_t)0x00800000)
#define EXTI_EMR_MR20 ((u32_t)0x00100000)
#define EXTI_EMR_MR16 ((u32_t)0x00010000)
#define EXTI_EMR_MR21 ((u32_t)0x00200000)
#define EXTI_EMR_MR22 ((u32_t)0x00400000)
#define EXTI_EMR_MR25 ((u32_t)0x02000000)
#define EXTI_EMR_MR27 ((u32_t)0x08000000)
#define EXTI_EMR_MR31 ((u32_t)0x80000000)
#define EXTI_EMR_MR26 ((u32_t)0x04000000)
#define EXTI_EMR_MR28 ((u32_t)0x10000000)
#define EXTI_EMR_MR29 ((u32_t)0x20000000)
#define EXTI_EMR_MR30 ((u32_t)0x40000000)
#define EXTI_EMR_MR31 ((u32_t)0x80000000)

#define EXTI_RTSR_TR0 ((u32_t)0x00000001)
#define EXTI_RTSR_TR1 ((u32_t)0x00000002)
#define EXTI_RTSR_TR2 ((u32_t)0x00000004)
#define EXTI_RTSR_TR3 ((u32_t)0x00000008)
#define EXTI_RTSR_TR4 ((u32_t)0x00000010)
#define EXTI_RTSR_TR5 ((u32_t)0x00000020)
#define EXTI_RTSR_TR6 ((u32_t)0x00000040)
#define EXTI_RTSR_TR7 ((u32_t)0x00000080)
#define EXTI_RTSR_TR8 ((u32_t)0x00000100)
#define EXTI_RTSR_TR9 ((u32_t)0x00000200)
#define EXTI_RTSR_TR10 ((u32_t)0x00000400)
#define EXTI_RTSR_TR11 ((u32_t)0x00000800)
#define EXTI_RTSR_TR12 ((u32_t)0x00001000)
#define EXTI_RTSR_TR13 ((u32_t)0x00002000)
#define EXTI_RTSR_TR14 ((u32_t)0x00004000)
#define EXTI_RTSR_TR15 ((u32_t)0x00008000)
#define EXTI_RTSR_TR16 ((u32_t)0x00010000)
#define EXTI_RTSR_TR17 ((u32_t)0x00020000)
#define EXTI_RTSR_TR19 ((u32_t)0x00080000)
#define EXTI_RTSR_TR20 ((u32_t)0x00100000)
#define EXTI_RTSR_TR21 ((u32_t)0x00200000)
#define EXTI_RTSR_TR22 ((u32_t)0x00400000)

#define EXTI_FTSR_TR0 ((u32_t)0x00000001)
#define EXTI_FTSR_TR1 ((u32_t)0x00000002)
#define EXTI_FTSR_TR2 ((u32_t)0x00000004)
#define EXTI_FTSR_TR3 ((u32_t)0x00000008)
#define EXTI_FTSR_TR4 ((u32_t)0x00000010)
#define EXTI_FTSR_TR5 ((u32_t)0x00000020)
#define EXTI_FTSR_TR6 ((u32_t)0x00000040)
#define EXTI_FTSR_TR7 ((u32_t)0x00000080)
#define EXTI_FTSR_TR8 ((u32_t)0x00000100)
#define EXTI_FTSR_TR9 ((u32_t)0x00000200)
#define EXTI_FTSR_TR10 ((u32_t)0x00000400)
#define EXTI_FTSR_TR11 ((u32_t)0x00000800)
#define EXTI_FTSR_TR12 ((u32_t)0x00001000)
#define EXTI_FTSR_TR13 ((u32_t)0x00002000)
#define EXTI_FTSR_TR14 ((u32_t)0x00004000)
#define EXTI_FTSR_TR15 ((u32_t)0x00008000)
#define EXTI_FTSR_TR16 ((u32_t)0x00010000)
#define EXTI_FTSR_TR17 ((u32_t)0x00020000)
#define EXTI_FTSR_TR19 ((u32_t)0x00080000)
#define EXTI_FTSR_TR20 ((u32_t)0x00100000)
#define EXTI_FTSR_TR21 ((u32_t)0x00200000)
#define EXTI_FTSR_TR22 ((u32_t)0x00400000)

#define EXTI_SWIER_SWIER0 ((u32_t)0x00000001)
#define EXTI_SWIER_SWIER1 ((u32_t)0x00000002)
#define EXTI_SWIER_SWIER2 ((u32_t)0x00000004)
#define EXTI_SWIER_SWIER3 ((u32_t)0x00000008)
#define EXTI_SWIER_SWIER4 ((u32_t)0x00000010)
#define EXTI_SWIER_SWIER5 ((u32_t)0x00000020)
#define EXTI_SWIER_SWIER6 ((u32_t)0x00000040)
#define EXTI_SWIER_SWIER7 ((u32_t)0x00000080)
#define EXTI_SWIER_SWIER8 ((u32_t)0x00000100)
#define EXTI_SWIER_SWIER9 ((u32_t)0x00000200)
#define EXTI_SWIER_SWIER10 ((u32_t)0x00000400)
#define EXTI_SWIER_SWIER11 ((u32_t)0x00000800)
#define EXTI_SWIER_SWIER12 ((u32_t)0x00001000)
#define EXTI_SWIER_SWIER13 ((u32_t)0x00002000)
#define EXTI_SWIER_SWIER14 ((u32_t)0x00004000)
#define EXTI_SWIER_SWIER15 ((u32_t)0x00008000)
#define EXTI_SWIER_SWIER16 ((u32_t)0x00010000)
#define EXTI_SWIER_SWIER17 ((u32_t)0x00020000)
#define EXTI_SWIER_SWIER19 ((u32_t)0x00080000)
#define EXTI_SWIER_SWIER20 ((u32_t)0x00100000)
#define EXTI_SWIER_SWIER21 ((u32_t)0x00200000)
#define EXTI_SWIER_SWIER22 ((u32_t)0x00400000)

#define EXTI_PR_PR0 ((u32_t)0x00000001)
#define EXTI_PR_PR1 ((u32_t)0x00000002)
#define EXTI_PR_PR2 ((u32_t)0x00000004)
#define EXTI_PR_PR3 ((u32_t)0x00000008)
#define EXTI_PR_PR4 ((u32_t)0x00000010)
#define EXTI_PR_PR5 ((u32_t)0x00000020)
#define EXTI_PR_PR6 ((u32_t)0x00000040)
#define EXTI_PR_PR7 ((u32_t)0x00000080)
#define EXTI_PR_PR8 ((u32_t)0x00000100)
#define EXTI_PR_PR9 ((u32_t)0x00000200)
#define EXTI_PR_PR10 ((u32_t)0x00000400)
#define EXTI_PR_PR11 ((u32_t)0x00000800)
#define EXTI_PR_PR12 ((u32_t)0x00001000)
#define EXTI_PR_PR13 ((u32_t)0x00002000)
#define EXTI_PR_PR14 ((u32_t)0x00004000)
#define EXTI_PR_PR15 ((u32_t)0x00008000)
#define EXTI_PR_PR16 ((u32_t)0x00010000)
#define EXTI_PR_PR17 ((u32_t)0x00020000)
#define EXTI_PR_PR19 ((u32_t)0x00080000)
#define EXTI_PR_PR20 ((u32_t)0x00100000)
#define EXTI_PR_PR21 ((u32_t)0x00200000)
#define EXTI_PR_PR22 ((u32_t)0x00400000)

#endif
