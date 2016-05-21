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

#ifndef DMA_H
#define DMA_H

#include <types.h>

struct dma_channel
{
    volatile u32_t CCR;
    volatile u32_t CNDTR;
    volatile u32_t CPAR;
    volatile u32_t CMAR;
};

struct dma
{
    volatile u32_t ISR;
    volatile u32_t IFCR;
};

#define DMA_ISR_GIF1 ((u32_t)0x00000001)
#define DMA_ISR_TCIF1 ((u32_t)0x00000002)
#define DMA_ISR_HTIF1 ((u32_t)0x00000004)
#define DMA_ISR_TEIF1 ((u32_t)0x00000008)
#define DMA_ISR_GIF2 ((u32_t)0x00000010)
#define DMA_ISR_TCIF2 ((u32_t)0x00000020)
#define DMA_ISR_HTIF2 ((u32_t)0x00000040)
#define DMA_ISR_TEIF2 ((u32_t)0x00000080)
#define DMA_ISR_GIF3 ((u32_t)0x00000100)
#define DMA_ISR_TCIF3 ((u32_t)0x00000200)
#define DMA_ISR_HTIF3 ((u32_t)0x00000400)
#define DMA_ISR_TEIF3 ((u32_t)0x00000800)
#define DMA_ISR_GIF4 ((u32_t)0x00001000)
#define DMA_ISR_TCIF4 ((u32_t)0x00002000)
#define DMA_ISR_HTIF4 ((u32_t)0x00004000)
#define DMA_ISR_TEIF4 ((u32_t)0x00008000)
#define DMA_ISR_GIF5 ((u32_t)0x00010000)
#define DMA_ISR_TCIF5 ((u32_t)0x00020000)
#define DMA_ISR_HTIF5 ((u32_t)0x00040000)
#define DMA_ISR_TEIF5 ((u32_t)0x00080000)
#define DMA_ISR_GIF6 ((u32_t)0x00100000)
#define DMA_ISR_TCIF6 ((u32_t)0x00200000)
#define DMA_ISR_HTIF6 ((u32_t)0x00400000)
#define DMA_ISR_TEIF6 ((u32_t)0x00800000)
#define DMA_ISR_GIF7 ((u32_t)0x01000000)
#define DMA_ISR_TCIF7 ((u32_t)0x02000000)
#define DMA_ISR_HTIF7 ((u32_t)0x04000000)
#define DMA_ISR_TEIF7 ((u32_t)0x08000000)

#define DMA_IFCR_CGIF1 ((u32_t)0x00000001)
#define DMA_IFCR_CTCIF1 ((u32_t)0x00000002)
#define DMA_IFCR_CHTIF1 ((u32_t)0x00000004)
#define DMA_IFCR_CTEIF1 ((u32_t)0x00000008)
#define DMA_IFCR_CGIF2 ((u32_t)0x00000010)
#define DMA_IFCR_CTCIF2 ((u32_t)0x00000020)
#define DMA_IFCR_CHTIF2 ((u32_t)0x00000040)
#define DMA_IFCR_CTEIF2 ((u32_t)0x00000080)
#define DMA_IFCR_CGIF3 ((u32_t)0x00000100)
#define DMA_IFCR_CTCIF3 ((u32_t)0x00000200)
#define DMA_IFCR_CHTIF3 ((u32_t)0x00000400)
#define DMA_IFCR_CTEIF3 ((u32_t)0x00000800)
#define DMA_IFCR_CGIF4 ((u32_t)0x00001000)
#define DMA_IFCR_CTCIF4 ((u32_t)0x00002000)
#define DMA_IFCR_CHTIF4 ((u32_t)0x00004000)
#define DMA_IFCR_CTEIF4 ((u32_t)0x00008000)
#define DMA_IFCR_CGIF5 ((u32_t)0x00010000)
#define DMA_IFCR_CTCIF5 ((u32_t)0x00020000)
#define DMA_IFCR_CHTIF5 ((u32_t)0x00040000)
#define DMA_IFCR_CTEIF5 ((u32_t)0x00080000)
#define DMA_IFCR_CGIF6 ((u32_t)0x00100000)
#define DMA_IFCR_CTCIF6 ((u32_t)0x00200000)
#define DMA_IFCR_CHTIF6 ((u32_t)0x00400000)
#define DMA_IFCR_CTEIF6 ((u32_t)0x00800000)
#define DMA_IFCR_CGIF7 ((u32_t)0x01000000)
#define DMA_IFCR_CTCIF7 ((u32_t)0x02000000)
#define DMA_IFCR_CHTIF7 ((u32_t)0x04000000)
#define DMA_IFCR_CTEIF7 ((u32_t)0x08000000)

#define DMA_CCR_EN ((u32_t)0x00000001)
#define DMA_CCR_TCIE ((u32_t)0x00000002)
#define DMA_CCR_HTIE ((u32_t)0x00000004)
#define DMA_CCR_TEIE ((u32_t)0x00000008)
#define DMA_CCR_DIR ((u32_t)0x00000010)
#define DMA_CCR_CIRC ((u32_t)0x00000020)
#define DMA_CCR_PINC ((u32_t)0x00000040)
#define DMA_CCR_MINC ((u32_t)0x00000080)
#define DMA_CCR_PSIZE ((u32_t)0x00000300)
#define DMA_CCR_PSIZE_0 ((u32_t)0x00000100)
#define DMA_CCR_PSIZE_1 ((u32_t)0x00000200)
#define DMA_CCR_MSIZE ((u32_t)0x00000C00)
#define DMA_CCR_MSIZE_0 ((u32_t)0x00000400)
#define DMA_CCR_MSIZE_1 ((u32_t)0x00000800)
#define DMA_CCR_PL ((u32_t)0x00003000)
#define DMA_CCR_PL_0 ((u32_t)0x00001000)
#define DMA_CCR_PL_1 ((u32_t)0x00002000)
#define DMA_CCR_MEM2MEM ((u32_t)0x00004000)

#define DMA_CNDTR_NDT ((u32_t)0x0000FFFF)

#define DMA_CPAR_PA ((u32_t)0xFFFFFFFF)

#define DMA_CMAR_MA ((u32_t)0xFFFFFFFF)

#endif
