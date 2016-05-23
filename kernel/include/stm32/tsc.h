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

#ifndef TSC_H
#define TSC_H

#include <types.h>

struct tsc
{
    volatile u32_t CR;
    volatile u32_t IER;
    volatile u32_t ICR;
    volatile u32_t ISR;
    volatile u32_t IOHCR;
    u32_t RESERVED1;
    volatile u32_t IOASCR;
    u32_t RESERVED2;
    volatile u32_t IOSCR;
    u32_t RESERVED3;
    volatile u32_t IOCCR;
    u32_t RESERVED4;
    volatile u32_t IOGCSR;
    volatile u32_t IOGXCR[8];
};

#define TSC ((struct tsc *)0x40024000)

#define TSC_CR_TSCE ((u32_t)0x00000001)
#define TSC_CR_START ((u32_t)0x00000002)
#define TSC_CR_AM ((u32_t)0x00000004)
#define TSC_CR_SYNCPOL ((u32_t)0x00000008)
#define TSC_CR_IODEF ((u32_t)0x00000010)
#define TSC_CR_MCV ((u32_t)0x000000E0)
#define TSC_CR_MCV_0 ((u32_t)0x00000020)
#define TSC_CR_MCV_1 ((u32_t)0x00000040)
#define TSC_CR_MCV_2 ((u32_t)0x00000080)
#define TSC_CR_PGPSC ((u32_t)0x00007000)
#define TSC_CR_PGPSC_0 ((u32_t)0x00001000)
#define TSC_CR_PGPSC_1 ((u32_t)0x00002000)
#define TSC_CR_PGPSC_2 ((u32_t)0x00004000)
#define TSC_CR_SSPSC ((u32_t)0x00008000)
#define TSC_CR_SSE ((u32_t)0x00010000)
#define TSC_CR_SSD ((u32_t)0x00FE0000)
#define TSC_CR_SSD_0 ((u32_t)0x00020000)
#define TSC_CR_SSD_1 ((u32_t)0x00040000)
#define TSC_CR_SSD_2 ((u32_t)0x00080000)
#define TSC_CR_SSD_3 ((u32_t)0x00100000)
#define TSC_CR_SSD_4 ((u32_t)0x00200000)
#define TSC_CR_SSD_5 ((u32_t)0x00400000)
#define TSC_CR_SSD_6 ((u32_t)0x00800000)
#define TSC_CR_CTPL ((u32_t)0x0F000000)
#define TSC_CR_CTPL_0 ((u32_t)0x01000000)
#define TSC_CR_CTPL_1 ((u32_t)0x02000000)
#define TSC_CR_CTPL_2 ((u32_t)0x04000000)
#define TSC_CR_CTPL_3 ((u32_t)0x08000000)
#define TSC_CR_CTPH ((u32_t)0xF0000000)
#define TSC_CR_CTPH_0 ((u32_t)0x10000000)
#define TSC_CR_CTPH_1 ((u32_t)0x20000000)
#define TSC_CR_CTPH_2 ((u32_t)0x40000000)
#define TSC_CR_CTPH_3 ((u32_t)0x80000000)

#define TSC_ICR_EOAIC ((u32_t)0x00000001)
#define TSC_ICR_MCEIC ((u32_t)0x00000002)

#define TSC_IER_EOAIE ((u32_t)0x00000001)
#define TSC_IER_MCEIE ((u32_t)0x00000002)

#define TSC_IOASCR_G1_IO1 ((u32_t)0x00000001)
#define TSC_IOASCR_G1_IO2 ((u32_t)0x00000002)
#define TSC_IOASCR_G1_IO3 ((u32_t)0x00000004)
#define TSC_IOASCR_G1_IO4 ((u32_t)0x00000008)
#define TSC_IOASCR_G2_IO1 ((u32_t)0x00000010)
#define TSC_IOASCR_G2_IO2 ((u32_t)0x00000020)
#define TSC_IOASCR_G2_IO3 ((u32_t)0x00000040)
#define TSC_IOASCR_G2_IO4 ((u32_t)0x00000080)
#define TSC_IOASCR_G3_IO1 ((u32_t)0x00000100)
#define TSC_IOASCR_G3_IO2 ((u32_t)0x00000200)
#define TSC_IOASCR_G3_IO3 ((u32_t)0x00000400)
#define TSC_IOASCR_G3_IO4 ((u32_t)0x00000800)
#define TSC_IOASCR_G4_IO1 ((u32_t)0x00001000)
#define TSC_IOASCR_G4_IO2 ((u32_t)0x00002000)
#define TSC_IOASCR_G4_IO3 ((u32_t)0x00004000)
#define TSC_IOASCR_G4_IO4 ((u32_t)0x00008000)
#define TSC_IOASCR_G5_IO1 ((u32_t)0x00010000)
#define TSC_IOASCR_G5_IO2 ((u32_t)0x00020000)
#define TSC_IOASCR_G5_IO3 ((u32_t)0x00040000)
#define TSC_IOASCR_G5_IO4 ((u32_t)0x00080000)
#define TSC_IOASCR_G6_IO1 ((u32_t)0x00100000)
#define TSC_IOASCR_G6_IO2 ((u32_t)0x00200000)
#define TSC_IOASCR_G6_IO3 ((u32_t)0x00400000)
#define TSC_IOASCR_G6_IO4 ((u32_t)0x00800000)
#define TSC_IOASCR_G7_IO1 ((u32_t)0x01000000)
#define TSC_IOASCR_G7_IO2 ((u32_t)0x02000000)
#define TSC_IOASCR_G7_IO3 ((u32_t)0x04000000)
#define TSC_IOASCR_G7_IO4 ((u32_t)0x08000000)
#define TSC_IOASCR_G8_IO1 ((u32_t)0x10000000)
#define TSC_IOASCR_G8_IO2 ((u32_t)0x20000000)
#define TSC_IOASCR_G8_IO3 ((u32_t)0x40000000)
#define TSC_IOASCR_G8_IO4 ((u32_t)0x80000000)

#define TSC_IOCCR_G1_IO1 ((u32_t)0x00000001)
#define TSC_IOCCR_G1_IO2 ((u32_t)0x00000002)
#define TSC_IOCCR_G1_IO3 ((u32_t)0x00000004)
#define TSC_IOCCR_G1_IO4 ((u32_t)0x00000008)
#define TSC_IOCCR_G2_IO1 ((u32_t)0x00000010)
#define TSC_IOCCR_G2_IO2 ((u32_t)0x00000020)
#define TSC_IOCCR_G2_IO3 ((u32_t)0x00000040)
#define TSC_IOCCR_G2_IO4 ((u32_t)0x00000080)
#define TSC_IOCCR_G3_IO1 ((u32_t)0x00000100)
#define TSC_IOCCR_G3_IO2 ((u32_t)0x00000200)
#define TSC_IOCCR_G3_IO3 ((u32_t)0x00000400)
#define TSC_IOCCR_G3_IO4 ((u32_t)0x00000800)
#define TSC_IOCCR_G4_IO1 ((u32_t)0x00001000)
#define TSC_IOCCR_G4_IO2 ((u32_t)0x00002000)
#define TSC_IOCCR_G4_IO3 ((u32_t)0x00004000)
#define TSC_IOCCR_G4_IO4 ((u32_t)0x00008000)
#define TSC_IOCCR_G5_IO1 ((u32_t)0x00010000)
#define TSC_IOCCR_G5_IO2 ((u32_t)0x00020000)
#define TSC_IOCCR_G5_IO3 ((u32_t)0x00040000)
#define TSC_IOCCR_G5_IO4 ((u32_t)0x00080000)
#define TSC_IOCCR_G6_IO1 ((u32_t)0x00100000)
#define TSC_IOCCR_G6_IO2 ((u32_t)0x00200000)
#define TSC_IOCCR_G6_IO3 ((u32_t)0x00400000)
#define TSC_IOCCR_G6_IO4 ((u32_t)0x00800000)
#define TSC_IOCCR_G7_IO1 ((u32_t)0x01000000)
#define TSC_IOCCR_G7_IO2 ((u32_t)0x02000000)
#define TSC_IOCCR_G7_IO3 ((u32_t)0x04000000)
#define TSC_IOCCR_G7_IO4 ((u32_t)0x08000000)
#define TSC_IOCCR_G8_IO1 ((u32_t)0x10000000)
#define TSC_IOCCR_G8_IO2 ((u32_t)0x20000000)
#define TSC_IOCCR_G8_IO3 ((u32_t)0x40000000)
#define TSC_IOCCR_G8_IO4 ((u32_t)0x80000000)

#define TSC_IOGCSR_G1E ((u32_t)0x00000001)
#define TSC_IOGCSR_G2E ((u32_t)0x00000002)
#define TSC_IOGCSR_G3E ((u32_t)0x00000004)
#define TSC_IOGCSR_G4E ((u32_t)0x00000008)
#define TSC_IOGCSR_G5E ((u32_t)0x00000010)
#define TSC_IOGCSR_G6E ((u32_t)0x00000020)
#define TSC_IOGCSR_G7E ((u32_t)0x00000040)
#define TSC_IOGCSR_G8E ((u32_t)0x00000080)
#define TSC_IOGCSR_G1S ((u32_t)0x00010000)
#define TSC_IOGCSR_G2S ((u32_t)0x00020000)
#define TSC_IOGCSR_G3S ((u32_t)0x00040000)
#define TSC_IOGCSR_G4S ((u32_t)0x00080000)
#define TSC_IOGCSR_G5S ((u32_t)0x00100000)
#define TSC_IOGCSR_G6S ((u32_t)0x00200000)
#define TSC_IOGCSR_G7S ((u32_t)0x00400000)
#define TSC_IOGCSR_G8S ((u32_t)0x00800000)

#define TSC_IOGXCR_CNT ((u32_t)0x00003FFF)

#define TSC_IOHCR_G1_IO1 ((u32_t)0x00000001)
#define TSC_IOHCR_G1_IO2 ((u32_t)0x00000002)
#define TSC_IOHCR_G1_IO3 ((u32_t)0x00000004)
#define TSC_IOHCR_G1_IO4 ((u32_t)0x00000008)
#define TSC_IOHCR_G2_IO1 ((u32_t)0x00000010)
#define TSC_IOHCR_G2_IO2 ((u32_t)0x00000020)
#define TSC_IOHCR_G2_IO3 ((u32_t)0x00000040)
#define TSC_IOHCR_G2_IO4 ((u32_t)0x00000080)
#define TSC_IOHCR_G3_IO1 ((u32_t)0x00000100)
#define TSC_IOHCR_G3_IO2 ((u32_t)0x00000200)
#define TSC_IOHCR_G3_IO3 ((u32_t)0x00000400)
#define TSC_IOHCR_G3_IO4 ((u32_t)0x00000800)
#define TSC_IOHCR_G4_IO1 ((u32_t)0x00001000)
#define TSC_IOHCR_G4_IO2 ((u32_t)0x00002000)
#define TSC_IOHCR_G4_IO3 ((u32_t)0x00004000)
#define TSC_IOHCR_G4_IO4 ((u32_t)0x00008000)
#define TSC_IOHCR_G5_IO1 ((u32_t)0x00010000)
#define TSC_IOHCR_G5_IO2 ((u32_t)0x00020000)
#define TSC_IOHCR_G5_IO3 ((u32_t)0x00040000)
#define TSC_IOHCR_G5_IO4 ((u32_t)0x00080000)
#define TSC_IOHCR_G6_IO1 ((u32_t)0x00100000)
#define TSC_IOHCR_G6_IO2 ((u32_t)0x00200000)
#define TSC_IOHCR_G6_IO3 ((u32_t)0x00400000)
#define TSC_IOHCR_G6_IO4 ((u32_t)0x00800000)
#define TSC_IOHCR_G7_IO1 ((u32_t)0x01000000)
#define TSC_IOHCR_G7_IO2 ((u32_t)0x02000000)
#define TSC_IOHCR_G7_IO3 ((u32_t)0x04000000)
#define TSC_IOHCR_G7_IO4 ((u32_t)0x08000000)
#define TSC_IOHCR_G8_IO1 ((u32_t)0x10000000)
#define TSC_IOHCR_G8_IO2 ((u32_t)0x20000000)
#define TSC_IOHCR_G8_IO3 ((u32_t)0x40000000)
#define TSC_IOHCR_G8_IO4 ((u32_t)0x80000000)

#define TSC_IOSCR_G1_IO1 ((u32_t)0x00000001)
#define TSC_IOSCR_G1_IO2 ((u32_t)0x00000002)
#define TSC_IOSCR_G1_IO3 ((u32_t)0x00000004)
#define TSC_IOSCR_G1_IO4 ((u32_t)0x00000008)
#define TSC_IOSCR_G2_IO1 ((u32_t)0x00000010)
#define TSC_IOSCR_G2_IO2 ((u32_t)0x00000020)
#define TSC_IOSCR_G2_IO3 ((u32_t)0x00000040)
#define TSC_IOSCR_G2_IO4 ((u32_t)0x00000080)
#define TSC_IOSCR_G3_IO1 ((u32_t)0x00000100)
#define TSC_IOSCR_G3_IO2 ((u32_t)0x00000200)
#define TSC_IOSCR_G3_IO3 ((u32_t)0x00000400)
#define TSC_IOSCR_G3_IO4 ((u32_t)0x00000800)
#define TSC_IOSCR_G4_IO1 ((u32_t)0x00001000)
#define TSC_IOSCR_G4_IO2 ((u32_t)0x00002000)
#define TSC_IOSCR_G4_IO3 ((u32_t)0x00004000)
#define TSC_IOSCR_G4_IO4 ((u32_t)0x00008000)
#define TSC_IOSCR_G5_IO1 ((u32_t)0x00010000)
#define TSC_IOSCR_G5_IO2 ((u32_t)0x00020000)
#define TSC_IOSCR_G5_IO3 ((u32_t)0x00040000)
#define TSC_IOSCR_G5_IO4 ((u32_t)0x00080000)
#define TSC_IOSCR_G6_IO1 ((u32_t)0x00100000)
#define TSC_IOSCR_G6_IO2 ((u32_t)0x00200000)
#define TSC_IOSCR_G6_IO3 ((u32_t)0x00400000)
#define TSC_IOSCR_G6_IO4 ((u32_t)0x00800000)
#define TSC_IOSCR_G7_IO1 ((u32_t)0x01000000)
#define TSC_IOSCR_G7_IO2 ((u32_t)0x02000000)
#define TSC_IOSCR_G7_IO3 ((u32_t)0x04000000)
#define TSC_IOSCR_G7_IO4 ((u32_t)0x08000000)
#define TSC_IOSCR_G8_IO1 ((u32_t)0x10000000)
#define TSC_IOSCR_G8_IO2 ((u32_t)0x20000000)
#define TSC_IOSCR_G8_IO3 ((u32_t)0x40000000)
#define TSC_IOSCR_G8_IO4 ((u32_t)0x80000000)

#define TSC_ISR_EOAF ((u32_t)0x00000001)
#define TSC_ISR_MCEF ((u32_t)0x00000002)

#endif
