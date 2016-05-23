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

#ifndef CAN_H
#define CAN_H

#include <types.h>

struct can_tx_box
{
    volatile u32_t TIR;
    volatile u32_t TDTR;
    volatile u32_t TDLR;
    volatile u32_t TDHR;
};

struct can_rx_box
{
    volatile u32_t RIR;
    volatile u32_t RDTR;
    volatile u32_t RDLR;
    volatile u32_t RDHR;
};

struct can_filter
{
    volatile u32_t FR1;
    volatile u32_t FR2;
};

struct can
{
    volatile u32_t MCR;
    volatile u32_t MSR;
    volatile u32_t TSR;
    volatile u32_t RF0R;
    volatile u32_t RF1R;
    volatile u32_t IER;
    volatile u32_t ESR;
    volatile u32_t BTR;
    u32_t RESERVED0[88];
    struct can_tx_box TBOX[3];
    struct can_rx_box RBOX[2];
    u32_t RESERVED1[12];
    volatile u32_t FMR;
    volatile u32_t FM1R;
    u32_t RESERVED2;
    volatile u32_t FS1R;
    u32_t RESERVED3;
    volatile u32_t FFA1R;
    u32_t RESERVED4;
    volatile u32_t FA1R;
    u32_t RESERVED5[8];
    struct can_filter FILTER[28];
};

#define CAN ((struct can *)0x40006400)
#define PMA ((u16_t *)0x40006000)

#define CAN_BTR_BRP ((u32_t)0x000003FF)
#define CAN_BTR_TS1 ((u32_t)0x000F0000)
#define CAN_BTR_TS1_0 ((u32_t)0x00010000)
#define CAN_BTR_TS1_1 ((u32_t)0x00020000)
#define CAN_BTR_TS1_2 ((u32_t)0x00040000)
#define CAN_BTR_TS1_3 ((u32_t)0x00080000)
#define CAN_BTR_TS2 ((u32_t)0x00700000)
#define CAN_BTR_TS2_0 ((u32_t)0x00100000)
#define CAN_BTR_TS2_1 ((u32_t)0x00200000)
#define CAN_BTR_TS2_2 ((u32_t)0x00400000)
#define CAN_BTR_SJW ((u32_t)0x03000000)
#define CAN_BTR_SJW_0 ((u32_t)0x01000000)
#define CAN_BTR_SJW_1 ((u32_t)0x02000000)
#define CAN_BTR_LBKM ((u32_t)0x40000000)
#define CAN_BTR_SILM ((u32_t)0x80000000)

#define CAN_ESR_EWGF ((u32_t)0x00000001)
#define CAN_ESR_EPVF ((u32_t)0x00000002)
#define CAN_ESR_BOFF ((u32_t)0x00000004)
#define CAN_ESR_LEC ((u32_t)0x00000070)
#define CAN_ESR_LEC_0 ((u32_t)0x00000010)
#define CAN_ESR_LEC_1 ((u32_t)0x00000020)
#define CAN_ESR_LEC_2 ((u32_t)0x00000040)
#define CAN_ESR_TEC ((u32_t)0x00FF0000)
#define CAN_ESR_REC ((u32_t)0xFF000000)

#define CAN_FxR1_FB0 ((u32_t)0x00000001)
#define CAN_FxR1_FB1 ((u32_t)0x00000002)
#define CAN_FxR1_FB2 ((u32_t)0x00000004)
#define CAN_FxR1_FB3 ((u32_t)0x00000008)
#define CAN_FxR1_FB4 ((u32_t)0x00000010)
#define CAN_FxR1_FB5 ((u32_t)0x00000020)
#define CAN_FxR1_FB6 ((u32_t)0x00000040)
#define CAN_FxR1_FB7 ((u32_t)0x00000080)
#define CAN_FxR1_FB8 ((u32_t)0x00000100)
#define CAN_FxR1_FB9 ((u32_t)0x00000200)
#define CAN_FxR1_FB10 ((u32_t)0x00000400)
#define CAN_FxR1_FB11 ((u32_t)0x00000800)
#define CAN_FxR1_FB12 ((u32_t)0x00001000)
#define CAN_FxR1_FB13 ((u32_t)0x00002000)
#define CAN_FxR1_FB14 ((u32_t)0x00004000)
#define CAN_FxR1_FB15 ((u32_t)0x00008000)
#define CAN_FxR1_FB16 ((u32_t)0x00010000)
#define CAN_FxR1_FB17 ((u32_t)0x00020000)
#define CAN_FxR1_FB18 ((u32_t)0x00040000)
#define CAN_FxR1_FB19 ((u32_t)0x00080000)
#define CAN_FxR1_FB20 ((u32_t)0x00100000)
#define CAN_FxR1_FB21 ((u32_t)0x00200000)
#define CAN_FxR1_FB22 ((u32_t)0x00400000)
#define CAN_FxR1_FB23 ((u32_t)0x00800000)
#define CAN_FxR1_FB24 ((u32_t)0x01000000)
#define CAN_FxR1_FB25 ((u32_t)0x02000000)
#define CAN_FxR1_FB26 ((u32_t)0x04000000)
#define CAN_FxR1_FB27 ((u32_t)0x08000000)
#define CAN_FxR1_FB28 ((u32_t)0x10000000)
#define CAN_FxR1_FB29 ((u32_t)0x20000000)
#define CAN_FxR1_FB30 ((u32_t)0x40000000)
#define CAN_FxR1_FB31 ((u32_t)0x80000000)

#define CAN_FxR2_FB0 ((u32_t)0x00000001)
#define CAN_FxR2_FB1 ((u32_t)0x00000002)
#define CAN_FxR2_FB2 ((u32_t)0x00000004)
#define CAN_FxR2_FB3 ((u32_t)0x00000008)
#define CAN_FxR2_FB4 ((u32_t)0x00000010)
#define CAN_FxR2_FB5 ((u32_t)0x00000020)
#define CAN_FxR2_FB6 ((u32_t)0x00000040)
#define CAN_FxR2_FB7 ((u32_t)0x00000080)
#define CAN_FxR2_FB8 ((u32_t)0x00000100)
#define CAN_FxR2_FB9 ((u32_t)0x00000200)
#define CAN_FxR2_FB10 ((u32_t)0x00000400)
#define CAN_FxR2_FB11 ((u32_t)0x00000800)
#define CAN_FxR2_FB12 ((u32_t)0x00001000)
#define CAN_FxR2_FB13 ((u32_t)0x00002000)
#define CAN_FxR2_FB14 ((u32_t)0x00004000)
#define CAN_FxR2_FB15 ((u32_t)0x00008000)
#define CAN_FxR2_FB16 ((u32_t)0x00010000)
#define CAN_FxR2_FB17 ((u32_t)0x00020000)
#define CAN_FxR2_FB18 ((u32_t)0x00040000)
#define CAN_FxR2_FB19 ((u32_t)0x00080000)
#define CAN_FxR2_FB20 ((u32_t)0x00100000)
#define CAN_FxR2_FB21 ((u32_t)0x00200000)
#define CAN_FxR2_FB22 ((u32_t)0x00400000)
#define CAN_FxR2_FB23 ((u32_t)0x00800000)
#define CAN_FxR2_FB24 ((u32_t)0x01000000)
#define CAN_FxR2_FB25 ((u32_t)0x02000000)
#define CAN_FxR2_FB26 ((u32_t)0x04000000)
#define CAN_FxR2_FB27 ((u32_t)0x08000000)
#define CAN_FxR2_FB28 ((u32_t)0x10000000)
#define CAN_FxR2_FB29 ((u32_t)0x20000000)
#define CAN_FxR2_FB30 ((u32_t)0x40000000)
#define CAN_FxR2_FB31 ((u32_t)0x80000000)

#define CAN_FA1R_FACT ((u32_t)0x0FFFFFFF)
#define CAN_FA1R_FACT0 ((u32_t)0x00000001)
#define CAN_FA1R_FACT1 ((u32_t)0x00000002)
#define CAN_FA1R_FACT2 ((u32_t)0x00000004)
#define CAN_FA1R_FACT3 ((u32_t)0x00000008)
#define CAN_FA1R_FACT4 ((u32_t)0x00000010)
#define CAN_FA1R_FACT5 ((u32_t)0x00000020)
#define CAN_FA1R_FACT6 ((u32_t)0x00000040)
#define CAN_FA1R_FACT7 ((u32_t)0x00000080)
#define CAN_FA1R_FACT8 ((u32_t)0x00000100)
#define CAN_FA1R_FACT9 ((u32_t)0x00000200)
#define CAN_FA1R_FACT10 ((u32_t)0x00000400)
#define CAN_FA1R_FACT11 ((u32_t)0x00000800)
#define CAN_FA1R_FACT12 ((u32_t)0x00001000)
#define CAN_FA1R_FACT13 ((u32_t)0x00002000)
#define CAN_FA1R_FACT14 ((u32_t)0x00004000)
#define CAN_FA1R_FACT15 ((u32_t)0x00008000)
#define CAN_FA1R_FACT16 ((u32_t)0x00010000)
#define CAN_FA1R_FACT17 ((u32_t)0x00020000)
#define CAN_FA1R_FACT18 ((u32_t)0x00040000)
#define CAN_FA1R_FACT19 ((u32_t)0x00080000)
#define CAN_FA1R_FACT20 ((u32_t)0x00100000)
#define CAN_FA1R_FACT21 ((u32_t)0x00200000)
#define CAN_FA1R_FACT22 ((u32_t)0x00400000)
#define CAN_FA1R_FACT23 ((u32_t)0x00800000)
#define CAN_FA1R_FACT24 ((u32_t)0x01000000)
#define CAN_FA1R_FACT25 ((u32_t)0x02000000)
#define CAN_FA1R_FACT26 ((u32_t)0x04000000)
#define CAN_FA1R_FACT27 ((u32_t)0x08000000)

#define CAN_FFA1R_FFA ((u32_t)0x0FFFFFFF)
#define CAN_FFA1R_FFA0 ((u32_t)0x00000001)
#define CAN_FFA1R_FFA1 ((u32_t)0x00000002)
#define CAN_FFA1R_FFA2 ((u32_t)0x00000004)
#define CAN_FFA1R_FFA3 ((u32_t)0x00000008)
#define CAN_FFA1R_FFA4 ((u32_t)0x00000010)
#define CAN_FFA1R_FFA5 ((u32_t)0x00000020)
#define CAN_FFA1R_FFA6 ((u32_t)0x00000040)
#define CAN_FFA1R_FFA7 ((u32_t)0x00000080)
#define CAN_FFA1R_FFA8 ((u32_t)0x00000100)
#define CAN_FFA1R_FFA9 ((u32_t)0x00000200)
#define CAN_FFA1R_FFA10 ((u32_t)0x00000400)
#define CAN_FFA1R_FFA11 ((u32_t)0x00000800)
#define CAN_FFA1R_FFA12 ((u32_t)0x00001000)
#define CAN_FFA1R_FFA13 ((u32_t)0x00002000)
#define CAN_FFA1R_FFA14 ((u32_t)0x00004000)
#define CAN_FFA1R_FFA15 ((u32_t)0x00008000)
#define CAN_FFA1R_FFA16 ((u32_t)0x00010000)
#define CAN_FFA1R_FFA17 ((u32_t)0x00020000)
#define CAN_FFA1R_FFA18 ((u32_t)0x00040000)
#define CAN_FFA1R_FFA19 ((u32_t)0x00080000)
#define CAN_FFA1R_FFA20 ((u32_t)0x00100000)
#define CAN_FFA1R_FFA21 ((u32_t)0x00200000)
#define CAN_FFA1R_FFA22 ((u32_t)0x00400000)
#define CAN_FFA1R_FFA23 ((u32_t)0x00800000)
#define CAN_FFA1R_FFA24 ((u32_t)0x01000000)
#define CAN_FFA1R_FFA25 ((u32_t)0x02000000)
#define CAN_FFA1R_FFA26 ((u32_t)0x04000000)
#define CAN_FFA1R_FFA27 ((u32_t)0x08000000)

#define CAN_FM1R_FBM ((u32_t)0x0FFFFFFF)
#define CAN_FM1R_FBM0 ((u32_t)0x00000001)
#define CAN_FM1R_FBM1 ((u32_t)0x00000002)
#define CAN_FM1R_FBM2 ((u32_t)0x00000004)
#define CAN_FM1R_FBM3 ((u32_t)0x00000008)
#define CAN_FM1R_FBM4 ((u32_t)0x00000010)
#define CAN_FM1R_FBM5 ((u32_t)0x00000020)
#define CAN_FM1R_FBM6 ((u32_t)0x00000040)
#define CAN_FM1R_FBM7 ((u32_t)0x00000080)
#define CAN_FM1R_FBM8 ((u32_t)0x00000100)
#define CAN_FM1R_FBM9 ((u32_t)0x00000200)
#define CAN_FM1R_FBM10 ((u32_t)0x00000400)
#define CAN_FM1R_FBM11 ((u32_t)0x00000800)
#define CAN_FM1R_FBM12 ((u32_t)0x00001000)
#define CAN_FM1R_FBM13 ((u32_t)0x00002000)
#define CAN_FM1R_FBM14 ((u32_t)0x00004000)
#define CAN_FM1R_FBM15 ((u32_t)0x00008000)
#define CAN_FM1R_FBM16 ((u32_t)0x00010000)
#define CAN_FM1R_FBM17 ((u32_t)0x00020000)
#define CAN_FM1R_FBM18 ((u32_t)0x00040000)
#define CAN_FM1R_FBM19 ((u32_t)0x00080000)
#define CAN_FM1R_FBM20 ((u32_t)0x00100000)
#define CAN_FM1R_FBM21 ((u32_t)0x00200000)
#define CAN_FM1R_FBM22 ((u32_t)0x00400000)
#define CAN_FM1R_FBM23 ((u32_t)0x00800000)
#define CAN_FM1R_FBM24 ((u32_t)0x01000000)
#define CAN_FM1R_FBM25 ((u32_t)0x02000000)
#define CAN_FM1R_FBM26 ((u32_t)0x04000000)
#define CAN_FM1R_FBM27 ((u32_t)0x08000000)

#define CAN_FMR_FINIT ((u32_t)0x00000001)
#define CAN_FMR_CAN2SB ((u32_t)0x00003F00)

#define CAN_FS1R_FSC ((u32_t)0x0FFFFFFF)
#define CAN_FS1R_FSC0 ((u32_t)0x00000001)
#define CAN_FS1R_FSC1 ((u32_t)0x00000002)
#define CAN_FS1R_FSC2 ((u32_t)0x00000004)
#define CAN_FS1R_FSC3 ((u32_t)0x00000008)
#define CAN_FS1R_FSC4 ((u32_t)0x00000010)
#define CAN_FS1R_FSC5 ((u32_t)0x00000020)
#define CAN_FS1R_FSC6 ((u32_t)0x00000040)
#define CAN_FS1R_FSC7 ((u32_t)0x00000080)
#define CAN_FS1R_FSC8 ((u32_t)0x00000100)
#define CAN_FS1R_FSC9 ((u32_t)0x00000200)
#define CAN_FS1R_FSC10 ((u32_t)0x00000400)
#define CAN_FS1R_FSC11 ((u32_t)0x00000800)
#define CAN_FS1R_FSC12 ((u32_t)0x00001000)
#define CAN_FS1R_FSC13 ((u32_t)0x00002000)
#define CAN_FS1R_FSC14 ((u32_t)0x00004000)
#define CAN_FS1R_FSC15 ((u32_t)0x00008000)
#define CAN_FS1R_FSC16 ((u32_t)0x00010000)
#define CAN_FS1R_FSC17 ((u32_t)0x00020000)
#define CAN_FS1R_FSC18 ((u32_t)0x00040000)
#define CAN_FS1R_FSC19 ((u32_t)0x00080000)
#define CAN_FS1R_FSC20 ((u32_t)0x00100000)
#define CAN_FS1R_FSC21 ((u32_t)0x00200000)
#define CAN_FS1R_FSC22 ((u32_t)0x00400000)
#define CAN_FS1R_FSC23 ((u32_t)0x00800000)
#define CAN_FS1R_FSC24 ((u32_t)0x01000000)
#define CAN_FS1R_FSC25 ((u32_t)0x02000000)
#define CAN_FS1R_FSC26 ((u32_t)0x04000000)
#define CAN_FS1R_FSC27 ((u32_t)0x08000000)

#define CAN_IER_TMEIE ((u32_t)0x00000001)
#define CAN_IER_FMPIE0 ((u32_t)0x00000002)
#define CAN_IER_FFIE0 ((u32_t)0x00000004)
#define CAN_IER_FOVIE0 ((u32_t)0x00000008)
#define CAN_IER_FMPIE1 ((u32_t)0x00000010)
#define CAN_IER_FFIE1 ((u32_t)0x00000020)
#define CAN_IER_FOVIE1 ((u32_t)0x00000040)
#define CAN_IER_EWGIE ((u32_t)0x00000100)
#define CAN_IER_EPVIE ((u32_t)0x00000200)
#define CAN_IER_BOFIE ((u32_t)0x00000400)
#define CAN_IER_LECIE ((u32_t)0x00000800)
#define CAN_IER_ERRIE ((u32_t)0x00008000)
#define CAN_IER_WKUIE ((u32_t)0x00010000)
#define CAN_IER_SLKIE ((u32_t)0x00020000)

#define CAN_MCR_INRQ ((u32_t)0x00000001)
#define CAN_MCR_SLEEP ((u32_t)0x00000002)
#define CAN_MCR_TXFP ((u32_t)0x00000004)
#define CAN_MCR_RFLM ((u32_t)0x00000008)
#define CAN_MCR_NART ((u32_t)0x00000010)
#define CAN_MCR_AWUM ((u32_t)0x00000020)
#define CAN_MCR_ABOM ((u32_t)0x00000040)
#define CAN_MCR_TTCM ((u32_t)0x00000080)
#define CAN_MCR_RESET ((u32_t)0x00008000)

#define CAN_MSR_INAK ((u32_t)0x00000001)
#define CAN_MSR_SLAK ((u32_t)0x00000002)
#define CAN_MSR_ERRI ((u32_t)0x00000004)
#define CAN_MSR_WKUI ((u32_t)0x00000008)
#define CAN_MSR_SLAKI ((u32_t)0x00000010)
#define CAN_MSR_TXM ((u32_t)0x00000100)
#define CAN_MSR_RXM ((u32_t)0x00000200)
#define CAN_MSR_SAMP ((u32_t)0x00000400)
#define CAN_MSR_RX ((u32_t)0x00000800)

#define CAN_RDHxR_DATA4 ((u32_t)0x000000FF)
#define CAN_RDHxR_DATA5 ((u32_t)0x0000FF00)
#define CAN_RDHxR_DATA6 ((u32_t)0x00FF0000)
#define CAN_RDHxR_DATA7 ((u32_t)0xFF000000)

#define CAN_RDLxR_DATA0 ((u32_t)0x000000FF)
#define CAN_RDLxR_DATA1 ((u32_t)0x0000FF00)
#define CAN_RDLxR_DATA2 ((u32_t)0x00FF0000)
#define CAN_RDLxR_DATA3 ((u32_t)0xFF000000)

#define CAN_RDTxR_DLC ((u32_t)0x0000000F)
#define CAN_RDTxR_FMI ((u32_t)0x0000FF00)
#define CAN_RDTxR_TIME ((u32_t)0xFFFF0000)

#define CAN_RFxR_FMP ((u32_t)0x00000003)
#define CAN_RFxR_FULL ((u32_t)0x00000008)
#define CAN_RFxR_FOVR ((u32_t)0x00000010)
#define CAN_RFxR_RFOM ((u32_t)0x00000020)

#define CAN_RIxR_RTR ((u32_t)0x00000002)
#define CAN_RIxR_IDE ((u32_t)0x00000004)
#define CAN_RIxR_EXID ((u32_t)0x001FFFF8)
#define CAN_RIxR_STID ((u32_t)0xFFE00000)

#define CAN_TDHxR_DATA4 ((u32_t)0x000000FF)
#define CAN_TDHxR_DATA5 ((u32_t)0x0000FF00)
#define CAN_TDHxR_DATA6 ((u32_t)0x00FF0000)
#define CAN_TDHxR_DATA7 ((u32_t)0xFF000000)

#define CAN_TDHxR_DATA4 ((u32_t)0x000000FF)
#define CAN_TDHxR_DATA5 ((u32_t)0x0000FF00)
#define CAN_TDHxR_DATA6 ((u32_t)0x00FF0000)
#define CAN_TDHxR_DATA7 ((u32_t)0xFF000000)

#define CAN_TDLxR_DATA0 ((u32_t)0x000000FF)
#define CAN_TDLxR_DATA1 ((u32_t)0x0000FF00)
#define CAN_TDLxR_DATA2 ((u32_t)0x00FF0000)
#define CAN_TDLxR_DATA3 ((u32_t)0xFF000000)

#define CAN_TDTxR_DLC ((u32_t)0x0000000F)
#define CAN_TDTxR_TGT ((u32_t)0x00000100)
#define CAN_TDTxR_TIME ((u32_t)0xFFFF0000)

#define CAN_TIxR_TXRQ ((u32_t)0x00000001)
#define CAN_TIxR_RTR ((u32_t)0x00000002)
#define CAN_TIxR_IDE ((u32_t)0x00000004)
#define CAN_TIxR_EXID ((u32_t)0x001FFFF8)
#define CAN_TIxR_STID ((u32_t)0xFFE00000)

#define CAN_TSR_RQCP0 ((u32_t)0x00000001)
#define CAN_TSR_TXOK0 ((u32_t)0x00000002)
#define CAN_TSR_ALST0 ((u32_t)0x00000004)
#define CAN_TSR_TERR0 ((u32_t)0x00000008)
#define CAN_TSR_ABRQ0 ((u32_t)0x00000080)
#define CAN_TSR_RQCP1 ((u32_t)0x00000100)
#define CAN_TSR_TXOK1 ((u32_t)0x00000200)
#define CAN_TSR_ALST1 ((u32_t)0x00000400)
#define CAN_TSR_TERR1 ((u32_t)0x00000800)
#define CAN_TSR_ABRQ1 ((u32_t)0x00008000)
#define CAN_TSR_RQCP2 ((u32_t)0x00010000)
#define CAN_TSR_TXOK2 ((u32_t)0x00020000)
#define CAN_TSR_ALST2 ((u32_t)0x00040000)
#define CAN_TSR_TERR2 ((u32_t)0x00080000)
#define CAN_TSR_ABRQ2 ((u32_t)0x00800000)
#define CAN_TSR_CODE ((u32_t)0x03000000)
#define CAN_TSR_TME ((u32_t)0x1C000000)
#define CAN_TSR_TME0 ((u32_t)0x04000000)
#define CAN_TSR_TME1 ((u32_t)0x08000000)
#define CAN_TSR_TME2 ((u32_t)0x10000000)
#define CAN_TSR_LOW ((u32_t)0xE0000000)
#define CAN_TSR_LOW0 ((u32_t)0x20000000)
#define CAN_TSR_LOW1 ((u32_t)0x40000000)
#define CAN_TSR_LOW2 ((u32_t)0x80000000)

#endif
