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

#ifndef DAC_H
#define DAC_H

#include <types.h>

struct dac
{
    volatile u32_t CR;
    volatile u32_t SWTRIGR;
    volatile u32_t DHR12R1;
    volatile u32_t DHR12L1;
    volatile u32_t DHR8R1;
    volatile u32_t DHR12R2;
    volatile u32_t DHR12L2;
    volatile u32_t DHR8R2;
    volatile u32_t DHR12RD;
    volatile u32_t DHR12LD;
    volatile u32_t DHR8RD;
    volatile u32_t DOR1;
    volatile u32_t DOR2;
    volatile u32_t SR;
};

#define DAC ((struct dac *)0x40007400)

#define DAC_CR_EN1 ((u32_t)0x00000001)
#define DAC_CR_BOFF1 ((u32_t)0x00000002)
#define DAC_CR_TEN1 ((u32_t)0x00000004)
#define DAC_CR_TSEL1 ((u32_t)0x00000038)
#define DAC_CR_TSEL1_0 ((u32_t)0x00000008)
#define DAC_CR_TSEL1_1 ((u32_t)0x00000010)
#define DAC_CR_TSEL1_2 ((u32_t)0x00000020)
#define DAC_CR_WAVE1 ((u32_t)0x000000C0)
#define DAC_CR_WAVE1_0 ((u32_t)0x00000040)
#define DAC_CR_WAVE1_1 ((u32_t)0x00000080)
#define DAC_CR_WAVE1_CUSTOM ((u32_t)0x00000000)
#define DAC_CR_WAVE1_NOISE ((u32_t)0x00000040)
#define DAC_CR_WAVE1_TRIANGLE ((u32_t)0x00000080)
#define DAC_CR_MAMP1 ((u32_t)0x00000F00)
#define DAC_CR_MAMP1_0 ((u32_t)0x00000100)
#define DAC_CR_MAMP1_1 ((u32_t)0x00000200)
#define DAC_CR_MAMP1_2 ((u32_t)0x00000400)
#define DAC_CR_MAMP1_3 ((u32_t)0x00000800)
#define DAC_CR_DMAEN1 ((u32_t)0x00001000)
#define DAC_CR_DMAUDRIE1 ((u32_t)0x00002000)
#define DAC_CR_EN2 ((u32_t)0x00010000)
#define DAC_CR_BOFF2 ((u32_t)0x00020000)
#define DAC_CR_TEN2 ((u32_t)0x00040000)
#define DAC_CR_TSEL2 ((u32_t)0x00380000)
#define DAC_CR_TSEL2_0 ((u32_t)0x00080000)
#define DAC_CR_TSEL2_1 ((u32_t)0x00100000)
#define DAC_CR_TSEL2_2 ((u32_t)0x00200000)
#define DAC_CR_WAVE2 ((u32_t)0x00C00000)
#define DAC_CR_WAVE2_0 ((u32_t)0x00400000)
#define DAC_CR_WAVE2_1 ((u32_t)0x00800000)
#define DAC_CR_WAVE2_CUSTOM ((u32_t)0x00000000)
#define DAC_CR_WAVE2_NOISE ((u32_t)0x00400000)
#define DAC_CR_WAVE2_TRIANGLE ((u32_t)0x00800000)
#define DAC_CR_MAMP2 ((u32_t)0x0F000000)
#define DAC_CR_MAMP2_0 ((u32_t)0x01000000)
#define DAC_CR_MAMP2_1 ((u32_t)0x02000000)
#define DAC_CR_MAMP2_2 ((u32_t)0x04000000)
#define DAC_CR_MAMP2_3 ((u32_t)0x08000000)
#define DAC_CR_DMAEN2 ((u32_t)0x10000000)
#define DAC_CR_DMAUDRIE2 ((u32_t)0x20000000)

#define DAC_SWTRIGR_SWTRIG1 ((u32_t)0x00000001)
#define DAC_SWTRIGR_SWTRIG2 ((u32_t)0x00000002)

#define DAC_DHR12R1_DACC1DHR ((u32_t)0x00000FFF)

#define DAC_DHR12L1_DACC1DHR ((u32_t)0x0000FFF0)

#define DAC_DHR8R1_DACC1DHR ((u32_t)0x000000FF)

#define DAC_DHR12R2_DACC2DHR ((u32_t)0x00000FFF)

#define DAC_DHR12L2_DACC2DHR ((u32_t)0x0000FFF0)

#define DAC_DHR8R2_DACC2DHR ((u32_t)0x000000FF)

#define DAC_DHR12RD_DACC1DHR ((u32_t)0x00000FFF)
#define DAC_DHR12RD_DACC2DHR ((u32_t)0x0FFF0000)

#define DAC_DHR12LD_DACC1DHR ((u32_t)0x0000FFF0)
#define DAC_DHR12LD_DACC2DHR ((u32_t)0xFFF00000)

#define DAC_DHR8RD_DACC1DHR ((u32_t)0x000000FF)
#define DAC_DHR8RD_DACC2DHR ((u32_t)0x0000FF00)

#define DAC_DOR1_DACC1DOR ((u32_t)0x00000FFF)

#define DAC_DOR2_DACC2DOR ((u32_t)0x00000FFF)

#define DAC_SR_DMAUDR1 ((u32_t)0x00002000)
#define DAC_SR_DMAUDR2 ((u32_t)0x20000000)

#endif
