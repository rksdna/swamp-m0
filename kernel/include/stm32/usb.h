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

#ifndef USB_H
#define USB_H

#include <types.h>

struct usb
{
    volatile u32_t EP0R;
    volatile u32_t EP1R;
    volatile u32_t EP2R;
    volatile u32_t EP3R;
    volatile u32_t EP4R;
    volatile u32_t EP5R;
    volatile u32_t EP6R;
    volatile u32_t EP7R;
    u32_t RESERVED0[8];
    volatile u32_t CNTR;
    volatile u32_t ISTR;
    volatile u32_t FNR;
    volatile u32_t DADDR;
    volatile u32_t BTABLE;
    volatile u32_t LPMCSR;
    volatile u32_t BCDR;
};

#define USB ((struct usb *)0x40005C00)
#define PMA ((u16_t *)0x40006000)

#define USB_EP_EA ((u32_t)0x0000000F)
#define USB_EP_STAT_TX ((u32_t)0x00000030)
#define USB_EP_STAT_TX_0 ((u32_t)0x00000010)
#define USB_EP_STAT_TX_1 ((u32_t)0x00000020)
#define USB_EP_STAT_TX_DISABLED ((u32_t)0x00000000)
#define USB_EP_STAT_TX_STALL ((u32_t)0x00000010)
#define USB_EP_STAT_TX_NAK ((u32_t)0x00000020)
#define USB_EP_STAT_TX_VALID ((u32_t)0x00000030)
#define USB_EP_DTOG_TX ((u32_t)0x00000040)
#define USB_EP_DBUF_RX ((u32_t)0x00000040)
#define USB_EP_CTR_TX ((u32_t)0x00000080)
#define USB_EP_KIND ((u32_t)0x00000100)
#define USB_EP_TYPE_BULK ((u32_t)0x00000000)
#define USB_EP_TYPE_CONTROL ((u32_t)0x00000200)
#define USB_EP_TYPE_ISOCHRONOUS ((u32_t)0x00000400)
#define USB_EP_TYPE_INTERRUPT ((u32_t)0x00000600)
#define USB_EP_TYPE ((u32_t)0x00000600)
#define USB_EP_SETUP ((u32_t)0x00000800)
#define USB_EP_STAT_RX ((u32_t)0x00003000)
#define USB_EP_STAT_RX_0 ((u32_t)0x00001000)
#define USB_EP_STAT_RX_1 ((u32_t)0x00002000)
#define USB_EP_STAT_RX_DISABLED ((u32_t)0x00000000)
#define USB_EP_STAT_RX_STALL ((u32_t)0x00001000)
#define USB_EP_STAT_RX_NAK ((u32_t)0x00002000)
#define USB_EP_STAT_RX_VALID ((u32_t)0x00003000)
#define USB_EP_DTOG_RX ((u32_t)0x00004000)
#define USB_EP_DBUF_TX ((u32_t)0x00004000)
#define USB_EP_CTR_RX ((u32_t)0x00008000)

#define USB_CNTR_FRES ((u32_t)0x00000001)
#define USB_CNTR_PDWN ((u32_t)0x00000002)
#define USB_CNTR_LPMODE ((u32_t)0x00000004)
#define USB_CNTR_FSUSP ((u32_t)0x00000008)
#define USB_CNTR_RESUME ((u32_t)0x00000010)
#define USB_CNTR_L1RESUME ((u32_t)0x00000020)
#define USB_CNTR_L1REQM ((u32_t)0x00000080)
#define USB_CNTR_ESOFM ((u32_t)0x00000100)
#define USB_CNTR_SOFM ((u32_t)0x00000200)
#define USB_CNTR_RESETM ((u32_t)0x00000400)
#define USB_CNTR_SUSPM ((u32_t)0x00000800)
#define USB_CNTR_WKUPM ((u32_t)0x00001000)
#define USB_CNTR_ERRM ((u32_t)0x00002000)
#define USB_CNTR_PMAOVRM ((u32_t)0x00004000)
#define USB_CNTR_CTRM ((u32_t)0x00008000)

#define USB_ISTR_EP_ID ((u32_t)0x0000000F)
#define USB_ISTR_DIR ((u32_t)0x00000010)
#define USB_ISTR_L1REQ ((u32_t)0x00000080)
#define USB_ISTR_ESOF ((u32_t)0x00000100)
#define USB_ISTR_SOF ((u32_t)0x00000200)
#define USB_ISTR_RESET ((u32_t)0x00000400)
#define USB_ISTR_SUSP ((u32_t)0x00000800)
#define USB_ISTR_WKUP ((u32_t)0x00001000)
#define USB_ISTR_ERR ((u32_t)0x00002000)
#define USB_ISTR_PMAOVR ((u32_t)0x00004000)
#define USB_ISTR_CTR ((u32_t)0x00008000)

#define USB_FNR_FN ((u32_t)0x000007FF)
#define USB_FNR_LSOF ((u32_t)0x00001800)
#define USB_FNR_LCK ((u32_t)0x00002000)
#define USB_FNR_RXDM ((u32_t)0x00004000)
#define USB_FNR_RXDP ((u32_t)0x00008000)

#define USB_DADDR_ADD ((u32_t)0x0000007F)
#define USB_DADDR_EF ((u32_t)0x00000080)

#define USB_BTABLE_BTABLE ((u32_t)0x0000FFF8)

#define USB_BCDR_DPPU ((u32_t)0x00008000)
#define USB_BCDR_PS2DET ((u32_t)0x00000080)
#define USB_BCDR_SDET ((u32_t)0x00000040)
#define USB_BCDR_PDET ((u32_t)0x00000020)
#define USB_BCDR_DCDET ((u32_t)0x00000010)
#define USB_BCDR_SDEN ((u32_t)0x00000008)
#define USB_BCDR_PDEN ((u32_t)0x00000004)
#define USB_BCDR_DCDEN ((u32_t)0x00000002)
#define USB_BCDR_BCDEN ((u32_t)0x00000001)

#define USB_LPMCSR_BESL ((u32_t)0x000000F0)
#define USB_LPMCSR_REMWAKE ((u32_t)0x00000008)
#define USB_LPMCSR_LPMACK ((u32_t)0x00000002)
#define USB_LPMCSR_LMPEN ((u32_t)0x00000001)

#define USB_PMA_BLSIZE ((u16_t)0x8000)
#define USB_PMA_NUM_BLOCK ((u16_t)0x00007C00)
#define USB_PMA_NUM_BLOCK_4 ((u16_t)0x4000)
#define USB_PMA_NUM_BLOCK_3 ((u16_t)0x2000)
#define USB_PMA_NUM_BLOCK_2 ((u16_t)0x1000)
#define USB_PMA_NUM_BLOCK_1 ((u16_t)0x0800)
#define USB_PMA_NUM_BLOCK_0 ((u16_t)0x0400)
#define USB_PMA_COUNT ((u16_t)0x03FF)

#endif
