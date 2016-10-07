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
    struct can_tx_box TX[3];
    struct can_rx_box RX[2];
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

#define CAN_MCR_INRQ ((u32_t)0x00000001)
#define CAN_MCR_SLEEP ((u32_t)0x00000002)
#define CAN_MCR_TXFP ((u32_t)0x00000004)
#define CAN_MCR_RFLM ((u32_t)0x00000008)
#define CAN_MCR_NART ((u32_t)0x00000010)
#define CAN_MCR_AWUM ((u32_t)0x00000020)
#define CAN_MCR_ABOM ((u32_t)0x00000040)
#define CAN_MCR_TTCM ((u32_t)0x00000080)
#define CAN_MCR_RESET ((u32_t)0x00008000)
#define CAN_MCR_DBF ((u32_t)0x00010000)

#define CAN_MSR_INAK ((u32_t)0x00000001)
#define CAN_MSR_SLAK ((u32_t)0x00000002)
#define CAN_MSR_ERRI ((u32_t)0x00000004)
#define CAN_MSR_WKUI ((u32_t)0x00000008)
#define CAN_MSR_SLAKI ((u32_t)0x00000010)
#define CAN_MSR_TXM ((u32_t)0x00000100)
#define CAN_MSR_RXM ((u32_t)0x00000200)
#define CAN_MSR_SAMP ((u32_t)0x00000400)
#define CAN_MSR_RX ((u32_t)0x00000800)

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

#define CAN_RF0R_FMP0 ((u32_t)0x00000003)
#define CAN_RF0R_FMP0_0 ((u32_t)0x00000001)
#define CAN_RF0R_FMP0_1 ((u32_t)0x00000002)
#define CAN_RF0R_FULL0 ((u32_t)0x00000008)
#define CAN_RF0R_FOVR0 ((u32_t)0x00000010)
#define CAN_RF0R_RFOM0 ((u32_t)0x00000020)

#define CAN_RF1R_FMP1 ((u32_t)0x00000003)
#define CAN_RF1R_FMP1_0 ((u32_t)0x00000001)
#define CAN_RF1R_FMP1_1 ((u32_t)0x00000002)
#define CAN_RF1R_FULL1 ((u32_t)0x00000008)
#define CAN_RF1R_FOVR1 ((u32_t)0x00000010)
#define CAN_RF1R_RFOM1 ((u32_t)0x00000020)

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

#define CAN_ESR_EWGF ((u32_t)0x00000001)
#define CAN_ESR_EPVF ((u32_t)0x00000002)
#define CAN_ESR_BOFF ((u32_t)0x00000004)
#define CAN_ESR_LEC ((u32_t)0x00000070)
#define CAN_ESR_LEC_0 ((u32_t)0x00000010)
#define CAN_ESR_LEC_1 ((u32_t)0x00000020)
#define CAN_ESR_LEC_2 ((u32_t)0x00000040)
#define CAN_ESR_TEC ((u32_t)0x00FF0000)
#define CAN_ESR_REC ((u32_t)0xFF000000)

#define CAN_BTR_BRP ((u32_t)0x000003FF)
#define CAN_BTR_TS1 ((u32_t)0x000F0000)
#define CAN_BTR_TS2 ((u32_t)0x00700000)
#define CAN_BTR_SJW ((u32_t)0x03000000)
#define CAN_BTR_LBKM ((u32_t)0x40000000)
#define CAN_BTR_SILM ((u32_t)0x80000000)

#define CAN_TI0R_TXRQ ((u32_t)0x00000001)
#define CAN_TI0R_RTR ((u32_t)0x00000002)
#define CAN_TI0R_IDE ((u32_t)0x00000004)
#define CAN_TI0R_EXID ((u32_t)0xFFFFFFF8)
#define CAN_TI0R_STID ((u32_t)0xFFE00000)

#define CAN_TDT0R_DLC ((u32_t)0x0000000F)
#define CAN_TDT0R_TGT ((u32_t)0x00000100)
#define CAN_TDT0R_TIME ((u32_t)0xFFFF0000)

#define CAN_TDL0R_DATA0 ((u32_t)0x000000FF)
#define CAN_TDL0R_DATA1 ((u32_t)0x0000FF00)
#define CAN_TDL0R_DATA2 ((u32_t)0x00FF0000)
#define CAN_TDL0R_DATA3 ((u32_t)0xFF000000)

#define CAN_TDH0R_DATA4 ((u32_t)0x000000FF)
#define CAN_TDH0R_DATA5 ((u32_t)0x0000FF00)
#define CAN_TDH0R_DATA6 ((u32_t)0x00FF0000)
#define CAN_TDH0R_DATA7 ((u32_t)0xFF000000)

#define CAN_TI1R_TXRQ ((u32_t)0x00000001)
#define CAN_TI1R_RTR ((u32_t)0x00000002)
#define CAN_TI1R_IDE ((u32_t)0x00000004)
#define CAN_TI1R_EXID ((u32_t)0xFFFFFFF8)
#define CAN_TI1R_STID ((u32_t)0xFFE00000)

#define CAN_TDT1R_DLC ((u32_t)0x0000000F)
#define CAN_TDT1R_TGT ((u32_t)0x00000100)
#define CAN_TDT1R_TIME ((u32_t)0xFFFF0000)

#define CAN_TDL1R_DATA0 ((u32_t)0x000000FF)
#define CAN_TDL1R_DATA1 ((u32_t)0x0000FF00)
#define CAN_TDL1R_DATA2 ((u32_t)0x00FF0000)
#define CAN_TDL1R_DATA3 ((u32_t)0xFF000000)

#define CAN_TDH1R_DATA4 ((u32_t)0x000000FF)
#define CAN_TDH1R_DATA5 ((u32_t)0x0000FF00)
#define CAN_TDH1R_DATA6 ((u32_t)0x00FF0000)
#define CAN_TDH1R_DATA7 ((u32_t)0xFF000000)

#define CAN_TI2R_TXRQ ((u32_t)0x00000001)
#define CAN_TI2R_RTR ((u32_t)0x00000002)
#define CAN_TI2R_IDE ((u32_t)0x00000004)
#define CAN_TI2R_EXID ((u32_t)0xFFFFFFF8)
#define CAN_TI2R_STID ((u32_t)0xFFE00000)

#define CAN_TDT2R_DLC ((u32_t)0x0000000F)
#define CAN_TDT2R_TGT ((u32_t)0x00000100)
#define CAN_TDT2R_TIME ((u32_t)0xFFFF0000)

#define CAN_TDL2R_DATA0 ((u32_t)0x000000FF)
#define CAN_TDL2R_DATA1 ((u32_t)0x0000FF00)
#define CAN_TDL2R_DATA2 ((u32_t)0x00FF0000)
#define CAN_TDL2R_DATA3 ((u32_t)0xFF000000)

#define CAN_TDH2R_DATA4 ((u32_t)0x000000FF)
#define CAN_TDH2R_DATA5 ((u32_t)0x0000FF00)
#define CAN_TDH2R_DATA6 ((u32_t)0x00FF0000)
#define CAN_TDH2R_DATA7 ((u32_t)0xFF000000)

#define CAN_RI0R_RTR ((u32_t)0x00000002)
#define CAN_RI0R_IDE ((u32_t)0x00000004)
#define CAN_RI0R_EXID ((u32_t)0xFFFFFFF8)
#define CAN_RI0R_STID ((u32_t)0xFFE00000)

#define CAN_RDT0R_DLC ((u32_t)0x0000000F)
#define CAN_RDT0R_FMI ((u32_t)0x0000FF00)
#define CAN_RDT0R_TIME ((u32_t)0xFFFF0000)

#define CAN_RDL0R_DATA0 ((u32_t)0x000000FF)
#define CAN_RDL0R_DATA1 ((u32_t)0x0000FF00)
#define CAN_RDL0R_DATA2 ((u32_t)0x00FF0000)
#define CAN_RDL0R_DATA3 ((u32_t)0xFF000000)

#define CAN_RDH0R_DATA4 ((u32_t)0x000000FF)
#define CAN_RDH0R_DATA5 ((u32_t)0x0000FF00)
#define CAN_RDH0R_DATA6 ((u32_t)0x00FF0000)
#define CAN_RDH0R_DATA7 ((u32_t)0xFF000000)

#define CAN_RI1R_RTR ((u32_t)0x00000002)
#define CAN_RI1R_IDE ((u32_t)0x00000004)
#define CAN_RI1R_EXID ((u32_t)0xFFFFFFF8)
#define CAN_RI1R_STID ((u32_t)0xFFE00000)

#define CAN_RDT1R_DLC ((u32_t)0x0000000F)
#define CAN_RDT1R_FMI ((u32_t)0x0000FF00)
#define CAN_RDT1R_TIME ((u32_t)0xFFFF0000)

#define CAN_RDL1R_DATA0 ((u32_t)0x000000FF)
#define CAN_RDL1R_DATA1 ((u32_t)0x0000FF00)
#define CAN_RDL1R_DATA2 ((u32_t)0x00FF0000)
#define CAN_RDL1R_DATA3 ((u32_t)0xFF000000)

#define CAN_RDH1R_DATA4 ((u32_t)0x000000FF)
#define CAN_RDH1R_DATA5 ((u32_t)0x0000FF00)
#define CAN_RDH1R_DATA6 ((u32_t)0x00FF0000)
#define CAN_RDH1R_DATA7 ((u32_t)0xFF000000)

#define CAN_FMR_FINIT ((u32_t)0x00000001)
#define CAN_FMR_CAN2SB (u32_t)0x00003F00)

#define CAN_FM1R_FBM ((u32_t)0x00003FFF)
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

#define CAN_FS1R_FSC ((u32_t)0x00003FFF)
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

#define CAN_FFA1R_FFA ((u32_t)0x00003FFF)
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

#define CAN_FA1R_FACT ((u32_t)0x00003FFF)
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

#define CAN_F0R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F0R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F1R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F1R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F2R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F2R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F3R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F3R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F4R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F4R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F5R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F5R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F6R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F6R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F7R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F7R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F8R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F8R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F9R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F9R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F10R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F10R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F11R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F11R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F12R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F12R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F13R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F13R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F14R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F14R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F15R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F15R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F16R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F16R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F17R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F17R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F18R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F18R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F19R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F19R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F20R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F20R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F21R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F21R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F22R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F22R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F23R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F23R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F24R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F24R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F25R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F25R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F26R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F26R2_FB ((u32_t)0xFFFFFFFF)

#define CAN_F27R1_FB ((u32_t)0xFFFFFFFF)

#define CAN_F27R2_FB ((u32_t)0xFFFFFFFF)

#endif
