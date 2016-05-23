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

#ifndef RTC_H
#define RTC_H

#include <types.h>

struct rtc
{
    volatile u32_t TR;
    volatile u32_t DR;
    volatile u32_t CR;
    volatile u32_t ISR;
    volatile u32_t PRER;
    u32_t RESERVED1;
    u32_t RESERVED2;
    volatile u32_t ALRMAR;
    u32_t RESERVED3;
    volatile u32_t WPR;
    volatile u32_t SSR;
    volatile u32_t SHIFTR;
    volatile u32_t TSTR;
    volatile u32_t TSDR;
    volatile u32_t TSSSR;
    volatile u32_t CALR;
    volatile u32_t TAFCR;
    volatile u32_t ALRMASSR;
    u32_t RESERVED4;
    u32_t RESERVED5;
    volatile u32_t BKP0R;
    volatile u32_t BKP1R;
    volatile u32_t BKP2R;
    volatile u32_t BKP3R;
    volatile u32_t BKP4R;
};

#define RTC ((struct rtc *)0x40002800)

#define RTC_ALRMAR_MSK4 ((u32_t)0x80000000)
#define RTC_ALRMAR_WDSEL ((u32_t)0x40000000)
#define RTC_ALRMAR_DT ((u32_t)0x30000000)
#define RTC_ALRMAR_DT_0 ((u32_t)0x10000000)
#define RTC_ALRMAR_DT_1 ((u32_t)0x20000000)
#define RTC_ALRMAR_DU ((u32_t)0x0F000000)
#define RTC_ALRMAR_DU_0 ((u32_t)0x01000000)
#define RTC_ALRMAR_DU_1 ((u32_t)0x02000000)
#define RTC_ALRMAR_DU_2 ((u32_t)0x04000000)
#define RTC_ALRMAR_DU_3 ((u32_t)0x08000000)
#define RTC_ALRMAR_MSK3 ((u32_t)0x00800000)
#define RTC_ALRMAR_PM ((u32_t)0x00400000)
#define RTC_ALRMAR_HT ((u32_t)0x00300000)
#define RTC_ALRMAR_HT_0 ((u32_t)0x00100000)
#define RTC_ALRMAR_HT_1 ((u32_t)0x00200000)
#define RTC_ALRMAR_HU ((u32_t)0x000F0000)
#define RTC_ALRMAR_HU_0 ((u32_t)0x00010000)
#define RTC_ALRMAR_HU_1 ((u32_t)0x00020000)
#define RTC_ALRMAR_HU_2 ((u32_t)0x00040000)
#define RTC_ALRMAR_HU_3 ((u32_t)0x00080000)
#define RTC_ALRMAR_MSK2 ((u32_t)0x00008000)
#define RTC_ALRMAR_MNT ((u32_t)0x00007000)
#define RTC_ALRMAR_MNT_0 ((u32_t)0x00001000)
#define RTC_ALRMAR_MNT_1 ((u32_t)0x00002000)
#define RTC_ALRMAR_MNT_2 ((u32_t)0x00004000)
#define RTC_ALRMAR_MNU ((u32_t)0x00000F00)
#define RTC_ALRMAR_MNU_0 ((u32_t)0x00000100)
#define RTC_ALRMAR_MNU_1 ((u32_t)0x00000200)
#define RTC_ALRMAR_MNU_2 ((u32_t)0x00000400)
#define RTC_ALRMAR_MNU_3 ((u32_t)0x00000800)
#define RTC_ALRMAR_MSK1 ((u32_t)0x00000080)
#define RTC_ALRMAR_ST ((u32_t)0x00000070)
#define RTC_ALRMAR_ST_0 ((u32_t)0x00000010)
#define RTC_ALRMAR_ST_1 ((u32_t)0x00000020)
#define RTC_ALRMAR_ST_2 ((u32_t)0x00000040)
#define RTC_ALRMAR_SU ((u32_t)0x0000000F)
#define RTC_ALRMAR_SU_0 ((u32_t)0x00000001)
#define RTC_ALRMAR_SU_1 ((u32_t)0x00000002)
#define RTC_ALRMAR_SU_2 ((u32_t)0x00000004)
#define RTC_ALRMAR_SU_3 ((u32_t)0x00000008)

#define RTC_ALRMASSR_MASKSS ((u32_t)0x0F000000)
#define RTC_ALRMASSR_MASKSS_0 ((u32_t)0x01000000)
#define RTC_ALRMASSR_MASKSS_1 ((u32_t)0x02000000)
#define RTC_ALRMASSR_MASKSS_2 ((u32_t)0x04000000)
#define RTC_ALRMASSR_MASKSS_3 ((u32_t)0x08000000)
#define RTC_ALRMASSR_SS ((u32_t)0x00007FFF)

#define RTC_CALR_CALP ((u32_t)0x00008000)
#define RTC_CALR_CALW8 ((u32_t)0x00004000)
#define RTC_CALR_CALW16 ((u32_t)0x00002000)
#define RTC_CALR_CALM ((u32_t)0x000001FF)
#define RTC_CALR_CALM_0 ((u32_t)0x00000001)
#define RTC_CALR_CALM_1 ((u32_t)0x00000002)
#define RTC_CALR_CALM_2 ((u32_t)0x00000004)
#define RTC_CALR_CALM_3 ((u32_t)0x00000008)
#define RTC_CALR_CALM_4 ((u32_t)0x00000010)
#define RTC_CALR_CALM_5 ((u32_t)0x00000020)
#define RTC_CALR_CALM_6 ((u32_t)0x00000040)
#define RTC_CALR_CALM_7 ((u32_t)0x00000080)
#define RTC_CALR_CALM_8 ((u32_t)0x00000100)

#define RTC_CR_COE ((u32_t)0x00800000)
#define RTC_CR_OSEL ((u32_t)0x00600000)
#define RTC_CR_OSEL_0 ((u32_t)0x00200000)
#define RTC_CR_OSEL_1 ((u32_t)0x00400000)
#define RTC_CR_POL ((u32_t)0x00100000)
#define RTC_CR_COSEL ((u32_t)0x00080000)
#define RTC_CR_BCK ((u32_t)0x00040000)
#define RTC_CR_SUB1H ((u32_t)0x00020000)
#define RTC_CR_ADD1H ((u32_t)0x00010000)
#define RTC_CR_TSIE ((u32_t)0x00008000)
#define RTC_CR_ALRAIE ((u32_t)0x00001000)
#define RTC_CR_TSE ((u32_t)0x00000800)
#define RTC_CR_ALRAE ((u32_t)0x00000100)
#define RTC_CR_FMT ((u32_t)0x00000040)
#define RTC_CR_BYPSHAD ((u32_t)0x00000020)
#define RTC_CR_REFCKON ((u32_t)0x00000010)
#define RTC_CR_TSEDGE ((u32_t)0x00000008)
#define RTC_CR_WUTIE ((u32_t)0x00004000)
#define RTC_CR_WUTE ((u32_t)0x00000400)
#define RTC_CR_WUCKSEL ((u32_t)0x00000007)
#define RTC_CR_WUCKSEL_0 ((u32_t)0x00000001)
#define RTC_CR_WUCKSEL_1 ((u32_t)0x00000002)
#define RTC_CR_WUCKSEL_2 ((u32_t)0x00000004)

#define RTC_DR_YT ((u32_t)0x00F00000)
#define RTC_DR_YT_0 ((u32_t)0x00100000)
#define RTC_DR_YT_1 ((u32_t)0x00200000)
#define RTC_DR_YT_2 ((u32_t)0x00400000)
#define RTC_DR_YT_3 ((u32_t)0x00800000)
#define RTC_DR_YU ((u32_t)0x000F0000)
#define RTC_DR_YU_0 ((u32_t)0x00010000)
#define RTC_DR_YU_1 ((u32_t)0x00020000)
#define RTC_DR_YU_2 ((u32_t)0x00040000)
#define RTC_DR_YU_3 ((u32_t)0x00080000)
#define RTC_DR_WDU ((u32_t)0x0000E000)
#define RTC_DR_WDU_0 ((u32_t)0x00002000)
#define RTC_DR_WDU_1 ((u32_t)0x00004000)
#define RTC_DR_WDU_2 ((u32_t)0x00008000)
#define RTC_DR_MT ((u32_t)0x00001000)
#define RTC_DR_MU ((u32_t)0x00000F00)
#define RTC_DR_MU_0 ((u32_t)0x00000100)
#define RTC_DR_MU_1 ((u32_t)0x00000200)
#define RTC_DR_MU_2 ((u32_t)0x00000400)
#define RTC_DR_MU_3 ((u32_t)0x00000800)
#define RTC_DR_DT ((u32_t)0x00000030)
#define RTC_DR_DT_0 ((u32_t)0x00000010)
#define RTC_DR_DT_1 ((u32_t)0x00000020)
#define RTC_DR_DU ((u32_t)0x0000000F)
#define RTC_DR_DU_0 ((u32_t)0x00000001)
#define RTC_DR_DU_1 ((u32_t)0x00000002)
#define RTC_DR_DU_2 ((u32_t)0x00000004)
#define RTC_DR_DU_3 ((u32_t)0x00000008)

#define RTC_ISR_RECALPF ((u32_t)0x00010000)
#define RTC_ISR_TAMP2F ((u32_t)0x00004000)
#define RTC_ISR_TAMP1F ((u32_t)0x00002000)
#define RTC_ISR_TSOVF ((u32_t)0x00001000)
#define RTC_ISR_TSF ((u32_t)0x00000800)
#define RTC_ISR_ALRAF ((u32_t)0x00000100)
#define RTC_ISR_INIT ((u32_t)0x00000080)
#define RTC_ISR_INITF ((u32_t)0x00000040)
#define RTC_ISR_RSF ((u32_t)0x00000020)
#define RTC_ISR_INITS ((u32_t)0x00000010)
#define RTC_ISR_SHPF ((u32_t)0x00000008)
#define RTC_ISR_ALRAWF ((u32_t)0x00000001)
#define RTC_ISR_WUTF ((u32_t)0x00000400)
#define RTC_ISR_WUTWF ((u32_t)0x00000004)
#define RTC_ISR_TAMP3F ((u32_t)0x00008000)

#define RTC_PRER_PREDIV_A ((u32_t)0x007F0000)
#define RTC_PRER_PREDIV_S ((u32_t)0x00007FFF)

#define RTC_SHIFTR_SUBFS ((u32_t)0x00007FFF)
#define RTC_SHIFTR_ADD1S ((u32_t)0x80000000)

#define RTC_SSR_SS ((u32_t)0x0000FFFF)

#define RTC_TAFCR_PC15MODE ((u32_t)0x00800000)
#define RTC_TAFCR_PC15VALUE ((u32_t)0x00400000)
#define RTC_TAFCR_PC14MODE ((u32_t)0x00200000)
#define RTC_TAFCR_PC14VALUE ((u32_t)0x00100000)
#define RTC_TAFCR_PC13MODE ((u32_t)0x00080000)
#define RTC_TAFCR_PC13VALUE ((u32_t)0x00040000)
#define RTC_TAFCR_TAMPPUDIS ((u32_t)0x00008000)
#define RTC_TAFCR_TAMPPRCH ((u32_t)0x00006000)
#define RTC_TAFCR_TAMPPRCH_0 ((u32_t)0x00002000)
#define RTC_TAFCR_TAMPPRCH_1 ((u32_t)0x00004000)
#define RTC_TAFCR_TAMPFLT ((u32_t)0x00001800)
#define RTC_TAFCR_TAMPFLT_0 ((u32_t)0x00000800)
#define RTC_TAFCR_TAMPFLT_1 ((u32_t)0x00001000)
#define RTC_TAFCR_TAMPFREQ ((u32_t)0x00000700)
#define RTC_TAFCR_TAMPFREQ_0 ((u32_t)0x00000100)
#define RTC_TAFCR_TAMPFREQ_1 ((u32_t)0x00000200)
#define RTC_TAFCR_TAMPFREQ_2 ((u32_t)0x00000400)
#define RTC_TAFCR_TAMPTS ((u32_t)0x00000080)
#define RTC_TAFCR_TAMP2TRG ((u32_t)0x00000010)
#define RTC_TAFCR_TAMP2E ((u32_t)0x00000008)
#define RTC_TAFCR_TAMPIE ((u32_t)0x00000004)
#define RTC_TAFCR_TAMP1TRG ((u32_t)0x00000002)
#define RTC_TAFCR_TAMP1E ((u32_t)0x00000001)
#define RTC_TAFCR_TAMP3TRG ((u32_t)0x00000040)
#define RTC_TAFCR_TAMP3E ((u32_t)0x00000020)

#define RTC_TR_PM ((u32_t)0x00400000)
#define RTC_TR_HT ((u32_t)0x00300000)
#define RTC_TR_HT_0 ((u32_t)0x00100000)
#define RTC_TR_HT_1 ((u32_t)0x00200000)
#define RTC_TR_HU ((u32_t)0x000F0000)
#define RTC_TR_HU_0 ((u32_t)0x00010000)
#define RTC_TR_HU_1 ((u32_t)0x00020000)
#define RTC_TR_HU_2 ((u32_t)0x00040000)
#define RTC_TR_HU_3 ((u32_t)0x00080000)
#define RTC_TR_MNT ((u32_t)0x00007000)
#define RTC_TR_MNT_0 ((u32_t)0x00001000)
#define RTC_TR_MNT_1 ((u32_t)0x00002000)
#define RTC_TR_MNT_2 ((u32_t)0x00004000)
#define RTC_TR_MNU ((u32_t)0x00000F00)
#define RTC_TR_MNU_0 ((u32_t)0x00000100)
#define RTC_TR_MNU_1 ((u32_t)0x00000200)
#define RTC_TR_MNU_2 ((u32_t)0x00000400)
#define RTC_TR_MNU_3 ((u32_t)0x00000800)
#define RTC_TR_ST ((u32_t)0x00000070)
#define RTC_TR_ST_0 ((u32_t)0x00000010)
#define RTC_TR_ST_1 ((u32_t)0x00000020)
#define RTC_TR_ST_2 ((u32_t)0x00000040)
#define RTC_TR_SU ((u32_t)0x0000000F)
#define RTC_TR_SU_0 ((u32_t)0x00000001)
#define RTC_TR_SU_1 ((u32_t)0x00000002)
#define RTC_TR_SU_2 ((u32_t)0x00000004)
#define RTC_TR_SU_3 ((u32_t)0x00000008)

#define RTC_TSDR_WDU ((u32_t)0x0000E000)
#define RTC_TSDR_WDU_0 ((u32_t)0x00002000)
#define RTC_TSDR_WDU_1 ((u32_t)0x00004000)
#define RTC_TSDR_WDU_2 ((u32_t)0x00008000)
#define RTC_TSDR_MT ((u32_t)0x00001000)
#define RTC_TSDR_MU ((u32_t)0x00000F00)
#define RTC_TSDR_MU_0 ((u32_t)0x00000100)
#define RTC_TSDR_MU_1 ((u32_t)0x00000200)
#define RTC_TSDR_MU_2 ((u32_t)0x00000400)
#define RTC_TSDR_MU_3 ((u32_t)0x00000800)
#define RTC_TSDR_DT ((u32_t)0x00000030)
#define RTC_TSDR_DT_0 ((u32_t)0x00000010)
#define RTC_TSDR_DT_1 ((u32_t)0x00000020)
#define RTC_TSDR_DU ((u32_t)0x0000000F)
#define RTC_TSDR_DU_0 ((u32_t)0x00000001)
#define RTC_TSDR_DU_1 ((u32_t)0x00000002)
#define RTC_TSDR_DU_2 ((u32_t)0x00000004)
#define RTC_TSDR_DU_3 ((u32_t)0x00000008)

#define RTC_TSSSR_SS ((u32_t)0x0000FFFF)

#define RTC_TSTR_PM ((u32_t)0x00400000)
#define RTC_TSTR_HT ((u32_t)0x00300000)
#define RTC_TSTR_HT_0 ((u32_t)0x00100000)
#define RTC_TSTR_HT_1 ((u32_t)0x00200000)
#define RTC_TSTR_HU ((u32_t)0x000F0000)
#define RTC_TSTR_HU_0 ((u32_t)0x00010000)
#define RTC_TSTR_HU_1 ((u32_t)0x00020000)
#define RTC_TSTR_HU_2 ((u32_t)0x00040000)
#define RTC_TSTR_HU_3 ((u32_t)0x00080000)
#define RTC_TSTR_MNT ((u32_t)0x00007000)
#define RTC_TSTR_MNT_0 ((u32_t)0x00001000)
#define RTC_TSTR_MNT_1 ((u32_t)0x00002000)
#define RTC_TSTR_MNT_2 ((u32_t)0x00004000)
#define RTC_TSTR_MNU ((u32_t)0x00000F00)
#define RTC_TSTR_MNU_0 ((u32_t)0x00000100)
#define RTC_TSTR_MNU_1 ((u32_t)0x00000200)
#define RTC_TSTR_MNU_2 ((u32_t)0x00000400)
#define RTC_TSTR_MNU_3 ((u32_t)0x00000800)
#define RTC_TSTR_ST ((u32_t)0x00000070)
#define RTC_TSTR_ST_0 ((u32_t)0x00000010)
#define RTC_TSTR_ST_1 ((u32_t)0x00000020)
#define RTC_TSTR_ST_2 ((u32_t)0x00000040)
#define RTC_TSTR_SU ((u32_t)0x0000000F)
#define RTC_TSTR_SU_0 ((u32_t)0x00000001)
#define RTC_TSTR_SU_1 ((u32_t)0x00000002)
#define RTC_TSTR_SU_2 ((u32_t)0x00000004)
#define RTC_TSTR_SU_3 ((u32_t)0x00000008)

#define RTC_WPR_KEY ((u32_t)0x000000FF)

#define RTC_WUTR_WUT ((u32_t)0x0000FFFF)

#endif
