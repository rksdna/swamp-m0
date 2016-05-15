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
    volatile u16_t EP0R;
    volatile u16_t RESERVED0;
    volatile u16_t EP1R;
    volatile u16_t RESERVED1;
    volatile u16_t EP2R;
    volatile u16_t RESERVED2;
    volatile u16_t EP3R;
    volatile u16_t RESERVED3;
    volatile u16_t EP4R;
    volatile u16_t RESERVED4;
    volatile u16_t EP5R;
    volatile u16_t RESERVED5;
    volatile u16_t EP6R;
    volatile u16_t RESERVED6;
    volatile u16_t EP7R;
    volatile u16_t RESERVED7[17];
    volatile u16_t CNTR;
    volatile u16_t RESERVED8;
    volatile u16_t ISTR;
    volatile u16_t RESERVED9;
    volatile u16_t FNR;
    volatile u16_t RESERVEDA;
    volatile u16_t DADDR;
    volatile u16_t RESERVEDB;
    volatile u16_t BTABLE;
    volatile u16_t RESERVEDC;
    volatile u16_t LPMCSR;
    volatile u16_t RESERVEDD;
    volatile u16_t BCDR;
    volatile u16_t RESERVEDE;
};

#define USB ((struct usb *)0x40005C00)

#define USB_ISTR_CTR ((u16_t)0x8000)
#define USB_ISTR_PMAOVR ((u16_t)0x4000)
#define USB_ISTR_ERR ((u16_t)0x2000)
#define USB_ISTR_WKUP ((u16_t)0x1000)
#define USB_ISTR_SUSP ((u16_t)0x0800)
#define USB_ISTR_RESET ((u16_t)0x0400)
#define USB_ISTR_SOF ((u16_t)0x0200)
#define USB_ISTR_ESOF ((u16_t)0x0100)
#define USB_ISTR_L1REQ ((u16_t)0x0080)
#define USB_ISTR_DIR ((u16_t)0x0010)
#define USB_ISTR_EP_ID ((u16_t)0x000F)

#define USB_CLR_CTR (~USB_ISTR_CTR)
#define USB_CLR_PMAOVR (~USB_ISTR_PMAOVR)
#define USB_CLR_ERR (~USB_ISTR_ERR)
#define USB_CLR_WKUP (~USB_ISTR_WKUP)
#define USB_CLR_SUSP (~USB_ISTR_SUSP)
#define USB_CLR_RESET (~USB_ISTR_RESET)
#define USB_CLR_SOF (~USB_ISTR_SOF)
#define USB_CLR_ESOF (~USB_ISTR_ESOF)
#define USB_CLR_L1REQ (~USB_ISTR_L1REQ)

#define USB_CNTR_CTRM ((u16_t)0x8000)
#define USB_CNTR_PMAOVRM ((u16_t)0x4000)
#define USB_CNTR_ERRM ((u16_t)0x2000)
#define USB_CNTR_WKUPM ((u16_t)0x1000)
#define USB_CNTR_SUSPM ((u16_t)0x0800)
#define USB_CNTR_RESETM ((u16_t)0x0400)
#define USB_CNTR_SOFM ((u16_t)0x0200)
#define USB_CNTR_ESOFM ((u16_t)0x0100)
#define USB_CNTR_L1REQM ((u16_t)0x0080)
#define USB_CNTR_L1RESUME ((u16_t)0x0020)
#define USB_CNTR_RESUME ((u16_t)0x0010)
#define USB_CNTR_FSUSP ((u16_t)0x0008)
#define USB_CNTR_LPMODE ((u16_t)0x0004)
#define USB_CNTR_PDWN ((u16_t)0x0002)
#define USB_CNTR_FRES ((u16_t)0x0001)

#define USB_BCDR_DPPU ((u16_t)0x8000)
#define USB_BCDR_PS2DET ((u16_t)0x0080)
#define USB_BCDR_SDET ((u16_t)0x0040)
#define USB_BCDR_PDET ((u16_t)0x0020)
#define USB_BCDR_DCDET ((u16_t)0x0010)
#define USB_BCDR_SDEN ((u16_t)0x0008)
#define USB_BCDR_PDEN ((u16_t)0x0004)
#define USB_BCDR_DCDEN ((u16_t)0x0002)
#define USB_BCDR_BCDEN ((u16_t)0x0001)

#define USB_LPMCSR_BESL ((u16_t)0x00F0)
#define USB_LPMCSR_REMWAKE ((u16_t)0x0008)
#define USB_LPMCSR_LPMACK ((u16_t)0x0002)
#define USB_LPMCSR_LMPEN ((u16_t)0x0001)

#define USB_FNR_RXDP ((u16_t)0x8000)
#define USB_FNR_RXDM ((u16_t)0x4000)
#define USB_FNR_LCK ((u16_t)0x2000)
#define USB_FNR_LSOF ((u16_t)0x1800)
#define USB_FNR_FN ((u16_t)0x07FF)

#define USB_DADDR_EF ((u8_t)0x80)
#define USB_DADDR_ADD ((u8_t)0x7F)

#define USB_EP_CTR_RX ((u16_t)0x8000)
#define USB_EP_DTOG_RX ((u16_t)0x4000)
#define USB_EP_DBUF_TX ((u16_t)0x4000)
#define USB_EP_STAT_RX ((u16_t)0x3000)
#define USB_EP_STAT_RX_1 ((u16_t)0x2000)
#define USB_EP_STAT_RX_0 ((u16_t)0x1000)
#define USB_EP_STAT_RX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_RX_STALL ((u16_t)0x1000)
#define USB_EP_STAT_RX_NAK ((u16_t)0x2000)
#define USB_EP_STAT_RX_VALID ((u16_t)0x3000)
#define USB_EP_SETUP ((u16_t)0x0800)
#define USB_EP_TYPE ((u16_t)0x0600)
#define USB_EP_TYPE_BULK ((u16_t)0x0000)
#define USB_EP_TYPE_CONTROL ((u16_t)0x0200)
#define USB_EP_TYPE_ISOCHRONOUS ((u16_t)0x0400)
#define USB_EP_TYPE_INTERRUPT ((u16_t)0x0600)
#define USB_EP_KIND ((u16_t)0x0100)
#define USB_EP_CTR_TX ((u16_t)0x0080)
#define USB_EP_DTOG_TX ((u16_t)0x0040)
#define USB_EP_DBUF_RX ((u16_t)0x0040)
#define USB_EP_STAT_TX ((u16_t)0x0030)
#define USB_EP_STAT_TX_1 ((u16_t)0x0020)
#define USB_EP_STAT_TX_0 ((u16_t)0x0010)
#define USB_EP_STAT_TX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_TX_STALL ((u16_t)0x0010)
#define USB_EP_STAT_TX_NAK ((u16_t)0x0020)
#define USB_EP_STAT_TX_VALID ((u16_t)0x0030)
#define USB_EP_EA ((u16_t)0x000F)

#define PMA ((u16_t *)0x40006000)

#define USB_PMA_BLSIZE ((u16_t)0x8000)
#define USB_PMA_NUM_BLOCK_4 ((u16_t)0x4000)
#define USB_PMA_NUM_BLOCK_3 ((u16_t)0x2000)
#define USB_PMA_NUM_BLOCK_2 ((u16_t)0x1000)
#define USB_PMA_NUM_BLOCK_1 ((u16_t)0x0800)
#define USB_PMA_NUM_BLOCK_0 ((u16_t)0x0400)
#define USB_PMA_COUNT ((u16_t)0x03FF)

#endif
