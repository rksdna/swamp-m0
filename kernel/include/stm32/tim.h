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

#ifndef TIM_H
#define TIM_H

#include <types.h>

struct tim
{
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t SMCR;
    volatile u32_t DIER;
    volatile u32_t SR;
    volatile u32_t EGR;
    volatile u32_t CCMR1;
    volatile u32_t CCMR2;
    volatile u32_t CCER;
    volatile u32_t CNT;
    volatile u32_t PSC;
    volatile u32_t ARR;
    volatile u32_t RCR;
    volatile u32_t CCR1;
    volatile u32_t CCR2;
    volatile u32_t CCR3;
    volatile u32_t CCR4;
    volatile u32_t BDTR;
    volatile u32_t DCR;
    volatile u32_t DMAR;
    volatile u32_t OR;
};

#define TIM1 ((struct tim *)0x40012C00)
#define TIM2 ((struct tim *)0x40000000)
#define TIM3 ((struct tim *)0x40000400)
#define TIM6 ((struct tim *)0x40001000)
#define TIM7 ((struct tim *)0x40001400)
#define TIM14 ((struct tim *)0x40002000)
#define TIM15 ((struct tim *)0x40014000)
#define TIM16 ((struct tim *)0x40014400)
#define TIM17 ((struct tim *)0x40014800)

#define TIM_CR1_CEN ((u32_t)0x00000001)
#define TIM_CR1_UDIS ((u32_t)0x00000002)
#define TIM_CR1_URS ((u32_t)0x00000004)
#define TIM_CR1_OPM ((u32_t)0x00000008)
#define TIM_CR1_DIR ((u32_t)0x00000010)
#define TIM_CR1_CMS ((u32_t)0x00000060)
#define TIM_CR1_CMS_0 ((u32_t)0x00000020)
#define TIM_CR1_CMS_1 ((u32_t)0x00000040)
#define TIM_CR1_ARPE ((u32_t)0x00000080)
#define TIM_CR1_CKD ((u32_t)0x00000300)
#define TIM_CR1_CKD_0 ((u32_t)0x00000100)
#define TIM_CR1_CKD_1 ((u32_t)0x00000200)

#define TIM_CR2_CCPC ((u32_t)0x00000001)
#define TIM_CR2_CCUS ((u32_t)0x00000004)
#define TIM_CR2_CCDS ((u32_t)0x00000008)
#define TIM_CR2_MMS ((u32_t)0x00000070)
#define TIM_CR2_MMS_0 ((u32_t)0x00000010)
#define TIM_CR2_MMS_1 ((u32_t)0x00000020)
#define TIM_CR2_MMS_2 ((u32_t)0x00000040)
#define TIM_CR2_TI1S ((u32_t)0x00000080)
#define TIM_CR2_OIS1 ((u32_t)0x00000100)
#define TIM_CR2_OIS1N ((u32_t)0x00000200)
#define TIM_CR2_OIS2 ((u32_t)0x00000400)
#define TIM_CR2_OIS2N ((u32_t)0x00000800)
#define TIM_CR2_OIS3 ((u32_t)0x00001000)
#define TIM_CR2_OIS3N ((u32_t)0x00002000)
#define TIM_CR2_OIS4 ((u32_t)0x00004000)

#define TIM_SMCR_SMS ((u32_t)0x00000007)
#define TIM_SMCR_SMS_0 ((u32_t)0x00000001)
#define TIM_SMCR_SMS_1 ((u32_t)0x00000002)
#define TIM_SMCR_SMS_2 ((u32_t)0x00000004)
#define TIM_SMCR_OCCS ((u32_t)0x00000008)
#define TIM_SMCR_TS ((u32_t)0x00000070)
#define TIM_SMCR_TS_0 ((u32_t)0x00000010)
#define TIM_SMCR_TS_1 ((u32_t)0x00000020)
#define TIM_SMCR_TS_2 ((u32_t)0x00000040)
#define TIM_SMCR_MSM ((u32_t)0x00000080)
#define TIM_SMCR_ETF ((u32_t)0x00000F00)
#define TIM_SMCR_ETF_0 ((u32_t)0x00000100)
#define TIM_SMCR_ETF_1 ((u32_t)0x00000200)
#define TIM_SMCR_ETF_2 ((u32_t)0x00000400)
#define TIM_SMCR_ETF_3 ((u32_t)0x00000800)
#define TIM_SMCR_ETPS ((u32_t)0x00003000)
#define TIM_SMCR_ETPS_0 ((u32_t)0x00001000)
#define TIM_SMCR_ETPS_1 ((u32_t)0x00002000)
#define TIM_SMCR_ECE ((u32_t)0x00004000)
#define TIM_SMCR_ETP ((u32_t)0x00008000)

#define TIM_DIER_UIE ((u32_t)0x00000001)
#define TIM_DIER_CC1IE ((u32_t)0x00000002)
#define TIM_DIER_CC2IE ((u32_t)0x00000004)
#define TIM_DIER_CC3IE ((u32_t)0x00000008)
#define TIM_DIER_CC4IE ((u32_t)0x00000010)
#define TIM_DIER_COMIE ((u32_t)0x00000020)
#define TIM_DIER_TIE ((u32_t)0x00000040)
#define TIM_DIER_BIE ((u32_t)0x00000080)
#define TIM_DIER_UDE ((u32_t)0x00000100)
#define TIM_DIER_CC1DE ((u32_t)0x00000200)
#define TIM_DIER_CC2DE ((u32_t)0x00000400)
#define TIM_DIER_CC3DE ((u32_t)0x00000800)
#define TIM_DIER_CC4DE ((u32_t)0x00001000)
#define TIM_DIER_COMDE ((u32_t)0x00002000)
#define TIM_DIER_TDE ((u32_t)0x00004000)

#define TIM_SR_UIF ((u32_t)0x00000001)
#define TIM_SR_CC1IF ((u32_t)0x00000002)
#define TIM_SR_CC2IF ((u32_t)0x00000004)
#define TIM_SR_CC3IF ((u32_t)0x00000008)
#define TIM_SR_CC4IF ((u32_t)0x00000010)
#define TIM_SR_COMIF ((u32_t)0x00000020)
#define TIM_SR_TIF ((u32_t)0x00000040)
#define TIM_SR_BIF ((u32_t)0x00000080)
#define TIM_SR_CC1OF ((u32_t)0x00000200)
#define TIM_SR_CC2OF ((u32_t)0x00000400)
#define TIM_SR_CC3OF ((u32_t)0x00000800)
#define TIM_SR_CC4OF ((u32_t)0x00001000)

#define TIM_EGR_UG ((u32_t)0x00000001)
#define TIM_EGR_CC1G ((u32_t)0x00000002)
#define TIM_EGR_CC2G ((u32_t)0x00000004)
#define TIM_EGR_CC3G ((u32_t)0x00000008)
#define TIM_EGR_CC4G ((u32_t)0x00000010)
#define TIM_EGR_COMG ((u32_t)0x00000020)
#define TIM_EGR_TG ((u32_t)0x00000040)
#define TIM_EGR_BG ((u32_t)0x00000080)

#define TIM_CCMR1_CC1S ((u32_t)0x00000003)
#define TIM_CCMR1_CC1S_0 ((u32_t)0x00000001)
#define TIM_CCMR1_CC1S_1 ((u32_t)0x00000002)
#define TIM_CCMR1_OC1FE ((u32_t)0x00000004)
#define TIM_CCMR1_OC1PE ((u32_t)0x00000008)
#define TIM_CCMR1_IC1PSC ((u32_t)0x0000000C)
#define TIM_CCMR1_IC1PSC_0 ((u32_t)0x00000004)
#define TIM_CCMR1_IC1PSC_1 ((u32_t)0x00000008)
#define TIM_CCMR1_OC1M ((u32_t)0x00000070)
#define TIM_CCMR1_OC1M_0 ((u32_t)0x00000010)
#define TIM_CCMR1_OC1M_1 ((u32_t)0x00000020)
#define TIM_CCMR1_OC1M_2 ((u32_t)0x00000040)
#define TIM_CCMR1_OC1CE ((u32_t)0x00000080)
#define TIM_CCMR1_IC1F ((u32_t)0x000000F0)
#define TIM_CCMR1_IC1F_0 ((u32_t)0x00000010)
#define TIM_CCMR1_IC1F_1 ((u32_t)0x00000020)
#define TIM_CCMR1_IC1F_2 ((u32_t)0x00000040)
#define TIM_CCMR1_IC1F_3 ((u32_t)0x00000080)
#define TIM_CCMR1_CC2S ((u32_t)0x00000300)
#define TIM_CCMR1_CC2S_0 ((u32_t)0x00000100)
#define TIM_CCMR1_CC2S_1 ((u32_t)0x00000200)
#define TIM_CCMR1_OC2FE ((u32_t)0x00000400)
#define TIM_CCMR1_OC2PE ((u32_t)0x00000800)
#define TIM_CCMR1_IC2PSC ((u32_t)0x00000C00)
#define TIM_CCMR1_IC2PSC_0 ((u32_t)0x00000400)
#define TIM_CCMR1_IC2PSC_1 ((u32_t)0x00000800)
#define TIM_CCMR1_OC2M ((u32_t)0x00007000)
#define TIM_CCMR1_OC2M_0 ((u32_t)0x00001000)
#define TIM_CCMR1_OC2M_1 ((u32_t)0x00002000)
#define TIM_CCMR1_OC2M_2 ((u32_t)0x00004000)
#define TIM_CCMR1_OC2CE ((u32_t)0x00008000)
#define TIM_CCMR1_IC2F ((u32_t)0x0000F000)
#define TIM_CCMR1_IC2F_0 ((u32_t)0x00001000)
#define TIM_CCMR1_IC2F_1 ((u32_t)0x00002000)
#define TIM_CCMR1_IC2F_2 ((u32_t)0x00004000)
#define TIM_CCMR1_IC2F_3 ((u32_t)0x00008000)

#define TIM_CCMR2_CC3S ((u32_t)0x00000003)
#define TIM_CCMR2_CC3S_0 ((u32_t)0x00000001)
#define TIM_CCMR2_CC3S_1 ((u32_t)0x00000002)
#define TIM_CCMR2_OC3FE ((u32_t)0x00000004)
#define TIM_CCMR2_OC3PE ((u32_t)0x00000008)
#define TIM_CCMR2_IC3PSC ((u32_t)0x0000000C)
#define TIM_CCMR2_IC3PSC_0 ((u32_t)0x00000004)
#define TIM_CCMR2_IC3PSC_1 ((u32_t)0x00000008)
#define TIM_CCMR2_OC3M ((u32_t)0x00000070)
#define TIM_CCMR2_OC3M_0 ((u32_t)0x00000010)
#define TIM_CCMR2_OC3M_1 ((u32_t)0x00000020)
#define TIM_CCMR2_OC3M_2 ((u32_t)0x00000040)
#define TIM_CCMR2_OC3CE ((u32_t)0x00000080)
#define TIM_CCMR2_IC3F ((u32_t)0x000000F0)
#define TIM_CCMR2_IC3F_0 ((u32_t)0x00000010)
#define TIM_CCMR2_IC3F_1 ((u32_t)0x00000020)
#define TIM_CCMR2_IC3F_2 ((u32_t)0x00000040)
#define TIM_CCMR2_IC3F_3 ((u32_t)0x00000080)
#define TIM_CCMR2_CC4S ((u32_t)0x00000300)
#define TIM_CCMR2_CC4S_0 ((u32_t)0x00000100)
#define TIM_CCMR2_CC4S_1 ((u32_t)0x00000200)
#define TIM_CCMR2_OC4FE ((u32_t)0x00000400)
#define TIM_CCMR2_OC4PE ((u32_t)0x00000800)
#define TIM_CCMR2_OC4M ((u32_t)0x00007000)
#define TIM_CCMR2_IC4PSC ((u32_t)0x00000C00)
#define TIM_CCMR2_IC4PSC_0 ((u32_t)0x00000400)
#define TIM_CCMR2_IC4PSC_1 ((u32_t)0x00000800)
#define TIM_CCMR2_OC4M_0 ((u32_t)0x00001000)
#define TIM_CCMR2_OC4M_1 ((u32_t)0x00002000)
#define TIM_CCMR2_OC4M_2 ((u32_t)0x00004000)
#define TIM_CCMR2_OC4CE ((u32_t)0x00008000)
#define TIM_CCMR2_IC4F ((u32_t)0x0000F000)
#define TIM_CCMR2_IC4F_0 ((u32_t)0x00001000)
#define TIM_CCMR2_IC4F_1 ((u32_t)0x00002000)
#define TIM_CCMR2_IC4F_2 ((u32_t)0x00004000)
#define TIM_CCMR2_IC4F_3 ((u32_t)0x00008000)

#define TIM_CCER_CC1E ((u32_t)0x00000001)
#define TIM_CCER_CC1P ((u32_t)0x00000002)
#define TIM_CCER_CC1NE ((u32_t)0x00000004)
#define TIM_CCER_CC1NP ((u32_t)0x00000008)
#define TIM_CCER_CC2E ((u32_t)0x00000010)
#define TIM_CCER_CC2P ((u32_t)0x00000020)
#define TIM_CCER_CC2NE ((u32_t)0x00000040)
#define TIM_CCER_CC2NP ((u32_t)0x00000080)
#define TIM_CCER_CC3E ((u32_t)0x00000100)
#define TIM_CCER_CC3P ((u32_t)0x00000200)
#define TIM_CCER_CC3NE ((u32_t)0x00000400)
#define TIM_CCER_CC3NP ((u32_t)0x00000800)
#define TIM_CCER_CC4E ((u32_t)0x00001000)
#define TIM_CCER_CC4P ((u32_t)0x00002000)
#define TIM_CCER_CC4NP ((u32_t)0x00008000)

#define TIM_CNT_CNT ((u32_t)0xFFFFFFFF)

#define TIM_PSC_PSC ((u32_t)0x0000FFFF)

#define TIM_ARR_ARR ((u32_t)0xFFFFFFFF)

#define TIM_RCR_REP ((u32_t)0x000000FF)

#define TIM_CCR1_CCR1 ((u32_t)0x0000FFFF)

#define TIM_CCR2_CCR2 ((u32_t)0x0000FFFF)

#define TIM_CCR3_CCR3 ((u32_t)0x0000FFFF)

#define TIM_CCR4_CCR4 ((u32_t)0x0000FFFF)

#define TIM_BDTR_DTG ((u32_t)0x000000FF)
#define TIM_BDTR_DTG_0 ((u32_t)0x00000001)
#define TIM_BDTR_DTG_1 ((u32_t)0x00000002)
#define TIM_BDTR_DTG_2 ((u32_t)0x00000004)
#define TIM_BDTR_DTG_3 ((u32_t)0x00000008)
#define TIM_BDTR_DTG_4 ((u32_t)0x00000010)
#define TIM_BDTR_DTG_5 ((u32_t)0x00000020)
#define TIM_BDTR_DTG_6 ((u32_t)0x00000040)
#define TIM_BDTR_DTG_7 ((u32_t)0x00000080)
#define TIM_BDTR_LOCK ((u32_t)0x00000300)
#define TIM_BDTR_LOCK_0 ((u32_t)0x00000100)
#define TIM_BDTR_LOCK_1 ((u32_t)0x00000200)
#define TIM_BDTR_OSSI ((u32_t)0x00000400)
#define TIM_BDTR_OSSR ((u32_t)0x00000800)
#define TIM_BDTR_BKE ((u32_t)0x00001000)
#define TIM_BDTR_BKP ((u32_t)0x00002000)
#define TIM_BDTR_AOE ((u32_t)0x00004000)
#define TIM_BDTR_MOE ((u32_t)0x00008000)

#define TIM_DCR_DBA ((u32_t)0x0000001F)
#define TIM_DCR_DBA_0 ((u32_t)0x00000001)
#define TIM_DCR_DBA_1 ((u32_t)0x00000002)
#define TIM_DCR_DBA_2 ((u32_t)0x00000004)
#define TIM_DCR_DBA_3 ((u32_t)0x00000008)
#define TIM_DCR_DBA_4 ((u32_t)0x00000010)
#define TIM_DCR_DBL ((u32_t)0x00001F00)
#define TIM_DCR_DBL_0 ((u32_t)0x00000100)
#define TIM_DCR_DBL_1 ((u32_t)0x00000200)
#define TIM_DCR_DBL_2 ((u32_t)0x00000400)
#define TIM_DCR_DBL_3 ((u32_t)0x00000800)
#define TIM_DCR_DBL_4 ((u32_t)0x00001000)

#define TIM_DMAR_DMAB ((u32_t)0x0000FFFF)

#define TIM14_OR_TI1_RMP ((u32_t)0x00000003)
#define TIM14_OR_TI1_RMP_0 ((u32_t)0x00000001)
#define TIM14_OR_TI1_RMP_1 ((u32_t)0x00000002)

#endif
