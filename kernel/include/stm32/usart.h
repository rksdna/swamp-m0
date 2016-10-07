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

#ifndef USART_H
#define USART_H

#include <types.h>

struct usart
{
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t CR3;
    volatile u32_t BRR;
    volatile u32_t GTPR;
    volatile u32_t RTOR;
    volatile u32_t RQR;
    volatile u32_t ISR;
    volatile u32_t ICR;
    volatile u32_t RDR;
    volatile u32_t TDR;
};

#define USART1 ((struct usart *)0x40013800)
#define USART2 ((struct usart *)0x40004400)
#define USART3 ((struct usart *)0x40004800)
#define USART4 ((struct usart *)0x40004C00)
#define USART5 ((struct usart *)0x40005000)
#define USART6 ((struct usart *)0x40011400)
#define USART7 ((struct usart *)0x40011800)
#define USART8 ((struct usart *)0x40011C00)

#define USART_BRR_DIV_FRACTION ((u32_t)0x0000000F)
#define USART_BRR_DIV_MANTISSA ((u32_t)0x0000FFF0)

#define USART_CR1_UE ((u32_t)0x00000001)
#define USART_CR1_RE ((u32_t)0x00000004)
#define USART_CR1_TE ((u32_t)0x00000008)
#define USART_CR1_IDLEIE ((u32_t)0x00000010)
#define USART_CR1_RXNEIE ((u32_t)0x00000020)
#define USART_CR1_TCIE ((u32_t)0x00000040)
#define USART_CR1_TXEIE ((u32_t)0x00000080)
#define USART_CR1_PEIE ((u32_t)0x00000100)
#define USART_CR1_PS ((u32_t)0x00000200)
#define USART_CR1_PCE ((u32_t)0x00000400)
#define USART_CR1_WAKE ((u32_t)0x00000800)
#define USART_CR1_MME ((u32_t)0x00002000)
#define USART_CR1_CMIE ((u32_t)0x00004000)
#define USART_CR1_OVER8 ((u32_t)0x00008000)
#define USART_CR1_DEDT ((u32_t)0x001F0000)
#define USART_CR1_DEDT_0 ((u32_t)0x00010000)
#define USART_CR1_DEDT_1 ((u32_t)0x00020000)
#define USART_CR1_DEDT_2 ((u32_t)0x00040000)
#define USART_CR1_DEDT_3 ((u32_t)0x00080000)
#define USART_CR1_DEDT_4 ((u32_t)0x00100000)
#define USART_CR1_DEAT ((u32_t)0x03E00000)
#define USART_CR1_DEAT_0 ((u32_t)0x00200000)
#define USART_CR1_DEAT_1 ((u32_t)0x00400000)
#define USART_CR1_DEAT_2 ((u32_t)0x00800000)
#define USART_CR1_DEAT_3 ((u32_t)0x01000000)
#define USART_CR1_DEAT_4 ((u32_t)0x02000000)
#define USART_CR1_RTOIE ((u32_t)0x04000000)
#define USART_CR1_EOBIE ((u32_t)0x08000000)
#define USART_CR1_M0 ((u32_t)0x00001000)
#define USART_CR1_M1 ((u32_t)0x10000000)
#define USART_CR1_M ((u32_t)0x10001000)
#define USART_CR1_UESM ((u32_t)0x00000002)

#define USART_CR2_ADDM7 ((u32_t)0x00000010)
#define USART_CR2_LBCL ((u32_t)0x00000100)
#define USART_CR2_CPHA ((u32_t)0x00000200)
#define USART_CR2_CPOL ((u32_t)0x00000400)
#define USART_CR2_CLKEN ((u32_t)0x00000800)
#define USART_CR2_STOP ((u32_t)0x00003000)
#define USART_CR2_STOP_0 ((u32_t)0x00001000)
#define USART_CR2_STOP_1 ((u32_t)0x00002000)
#define USART_CR2_SWAP ((u32_t)0x00008000)
#define USART_CR2_RXINV ((u32_t)0x00010000)
#define USART_CR2_TXINV ((u32_t)0x00020000)
#define USART_CR2_DATAINV ((u32_t)0x00040000)
#define USART_CR2_MSBFIRST ((u32_t)0x00080000)
#define USART_CR2_ABREN ((u32_t)0x00100000)
#define USART_CR2_ABRMODE ((u32_t)0x00600000)
#define USART_CR2_ABRMODE_0 ((u32_t)0x00200000)
#define USART_CR2_ABRMODE_1 ((u32_t)0x00400000)
#define USART_CR2_RTOEN ((u32_t)0x00800000)
#define USART_CR2_ADD ((u32_t)0xFF000000)
#define USART_CR2_LBDL ((u32_t)0x00000020)
#define USART_CR2_LBDIE ((u32_t)0x00000040)
#define USART_CR2_LINEN ((u32_t)0x00004000)

#define USART_CR3_EIE ((u32_t)0x00000001)
#define USART_CR3_HDSEL ((u32_t)0x00000008)
#define USART_CR3_DMAR ((u32_t)0x00000040)
#define USART_CR3_DMAT ((u32_t)0x00000080)
#define USART_CR3_RTSE ((u32_t)0x00000100)
#define USART_CR3_CTSE ((u32_t)0x00000200)
#define USART_CR3_CTSIE ((u32_t)0x00000400)
#define USART_CR3_ONEBIT ((u32_t)0x00000800)
#define USART_CR3_OVRDIS ((u32_t)0x00001000)
#define USART_CR3_DDRE ((u32_t)0x00002000)
#define USART_CR3_DEM ((u32_t)0x00004000)
#define USART_CR3_DEP ((u32_t)0x00008000)
#define USART_CR3_IREN ((u32_t)0x00000002)
#define USART_CR3_IRLP ((u32_t)0x00000004)
#define USART_CR3_NACK ((u32_t)0x00000010)
#define USART_CR3_SCEN ((u32_t)0x00000020)
#define USART_CR3_SCARCNT ((u32_t)0x000E0000)
#define USART_CR3_SCARCNT_0 ((u32_t)0x00020000)
#define USART_CR3_SCARCNT_1 ((u32_t)0x00040000)
#define USART_CR3_SCARCNT_2 ((u32_t)0x00080000)
#define USART_CR3_WUS ((u32_t)0x00300000)
#define USART_CR3_WUS_0 ((u32_t)0x00100000)
#define USART_CR3_WUS_1 ((u32_t)0x00200000)
#define USART_CR3_WUFIE ((u32_t)0x00400000)

#define USART_GTPR_PSC ((u32_t)0x000000FF)
#define USART_GTPR_GT ((u32_t)0x0000FF00)

#define USART_ICR_PECF ((u32_t)0x00000001)
#define USART_ICR_FECF ((u32_t)0x00000002)
#define USART_ICR_NCF ((u32_t)0x00000004)
#define USART_ICR_ORECF ((u32_t)0x00000008)
#define USART_ICR_IDLECF ((u32_t)0x00000010)
#define USART_ICR_TCCF ((u32_t)0x00000040)
#define USART_ICR_CTSCF ((u32_t)0x00000200)
#define USART_ICR_RTOCF ((u32_t)0x00000800)
#define USART_ICR_CMCF ((u32_t)0x00020000)
#define USART_ICR_LBDCF ((u32_t)0x00000100)
#define USART_ICR_EOBCF ((u32_t)0x00001000)
#define USART_ICR_WUCF ((u32_t)0x00100000)

#define USART_ISR_PE ((u32_t)0x00000001)
#define USART_ISR_FE ((u32_t)0x00000002)
#define USART_ISR_NE ((u32_t)0x00000004)
#define USART_ISR_ORE ((u32_t)0x00000008)
#define USART_ISR_IDLE ((u32_t)0x00000010)
#define USART_ISR_RXNE ((u32_t)0x00000020)
#define USART_ISR_TC ((u32_t)0x00000040)
#define USART_ISR_TXE ((u32_t)0x00000080)
#define USART_ISR_CTSIF ((u32_t)0x00000200)
#define USART_ISR_CTS ((u32_t)0x00000400)
#define USART_ISR_RTOF ((u32_t)0x00000800)
#define USART_ISR_ABRE ((u32_t)0x00004000)
#define USART_ISR_ABRF ((u32_t)0x00008000)
#define USART_ISR_BUSY ((u32_t)0x00010000)
#define USART_ISR_CMF ((u32_t)0x00020000)
#define USART_ISR_SBKF ((u32_t)0x00040000)
#define USART_ISR_TEACK ((u32_t)0x00200000)
#define USART_ISR_REACK ((u32_t)0x00400000)
#define USART_ISR_LBDF ((u32_t)0x00000100)
#define USART_ISR_EOBF ((u32_t)0x00001000)
#define USART_ISR_RWU ((u32_t)0x00080000)
#define USART_ISR_WUF ((u32_t)0x00100000)

#define USART_RDR_RDR ((u32_t)0x000001FF)

#define USART_RQR_ABRRQ ((u32_t)0x00000001)
#define USART_RQR_SBKRQ ((u32_t)0x00000002)
#define USART_RQR_MMRQ ((u32_t)0x00000004)
#define USART_RQR_RXFRQ ((u32_t)0x00000008)
#define USART_RQR_TXFRQ ((u32_t)0x00000010)

#define USART_RTOR_RTO ((u32_t)0x00FFFFFF)
#define USART_RTOR_BLEN ((u32_t)0xFF000000)

#define USART_TDR_TDR ((u32_t)0x000001FF)

#endif
