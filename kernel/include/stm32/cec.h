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

#ifndef CEC_H
#define CEC_H

#include <types.h>

struct cec
{
    volatile u32_t CR;
    volatile u32_t CFGR;
    volatile u32_t TXDR;
    volatile u32_t RXDR;
    volatile u32_t ISR;
    volatile u32_t IER;
};

#define CEC ((struct cec *)0x40007800)

#define CEC_CFGR_SFT ((u32_t)0x00000007)
#define CEC_CFGR_RXTOL ((u32_t)0x00000008)
#define CEC_CFGR_BRESTP ((u32_t)0x00000010)
#define CEC_CFGR_BREGEN ((u32_t)0x00000020)
#define CEC_CFGR_LBPEGEN ((u32_t)0x00000040)
#define CEC_CFGR_BRDNOGEN ((u32_t)0x00000080)
#define CEC_CFGR_SFTOPT ((u32_t)0x00000100)
#define CEC_CFGR_OAR ((u32_t)0x7FFF0000)
#define CEC_CFGR_LSTN ((u32_t)0x80000000)

#define CEC_CR_CECEN ((u32_t)0x00000001)
#define CEC_CR_TXSOM ((u32_t)0x00000002)
#define CEC_CR_TXEOM ((u32_t)0x00000004)

#define CEC_IER_RXBRIE ((u32_t)0x00000001)
#define CEC_IER_RXENDIE ((u32_t)0x00000002)
#define CEC_IER_RXOVRIE ((u32_t)0x00000004)
#define CEC_IER_BREIE ((u32_t)0x00000008)
#define CEC_IER_SBPEIE ((u32_t)0x00000010)
#define CEC_IER_LBPEIE ((u32_t)0x00000020)
#define CEC_IER_RXACKEIE ((u32_t)0x00000040)
#define CEC_IER_ARBLSTIE ((u32_t)0x00000080)
#define CEC_IER_TXBRIE ((u32_t)0x00000100)
#define CEC_IER_TXENDIE ((u32_t)0x00000200)
#define CEC_IER_TXUDRIE ((u32_t)0x00000400)
#define CEC_IER_TXERRIE ((u32_t)0x00000800)
#define CEC_IER_TXACKEIE ((u32_t)0x00001000)

#define CEC_ISR_RXBR ((u32_t)0x00000001)
#define CEC_ISR_RXEND ((u32_t)0x00000002)
#define CEC_ISR_RXOVR ((u32_t)0x00000004)
#define CEC_ISR_BRE ((u32_t)0x00000008)
#define CEC_ISR_SBPE ((u32_t)0x00000010)
#define CEC_ISR_LBPE ((u32_t)0x00000020)
#define CEC_ISR_RXACKE ((u32_t)0x00000040)
#define CEC_ISR_ARBLST ((u32_t)0x00000080)
#define CEC_ISR_TXBR ((u32_t)0x00000100)
#define CEC_ISR_TXEND ((u32_t)0x00000200)
#define CEC_ISR_TXUDR ((u32_t)0x00000400)
#define CEC_ISR_TXERR ((u32_t)0x00000800)
#define CEC_ISR_TXACKE ((u32_t)0x00001000)

#define CEC_TXDR_TXD ((u32_t)0x000000FF)

#define CEC_RXDR_RXD ((u32_t)0x000000FF)

#endif
