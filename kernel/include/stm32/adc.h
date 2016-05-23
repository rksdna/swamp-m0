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

#ifndef ADC_H
#define ADC_H

#include <types.h>

struct adc
{
    volatile u32_t ISR;
    volatile u32_t IER;
    volatile u32_t CR;
    volatile u32_t CFGR1;
    volatile u32_t CFGR2;
    volatile u32_t SMPR;
    u32_t RESERVED1;
    u32_t RESERVED2;
    volatile u32_t TR;
    u32_t RESERVED3;
    volatile u32_t CHSELR;
    u32_t RESERVED4[5];
    volatile u32_t DR;
    u32_t RESERVED5[177];
    volatile u32_t CCR;
};

#define ADC1 ((struct adc *)0x40012400)

#define ADC_CCR_VREFEN ((u32_t)0x00400000)
#define ADC_CCR_TSEN ((u32_t)0x00800000)
#define ADC_CCR_VBATEN ((u32_t)0x01000000)

#define ADC_CFGR1_DMAEN ((u32_t)0x00000001)
#define ADC_CFGR1_DMACFG ((u32_t)0x00000002)
#define ADC_CFGR1_SCANDIR ((u32_t)0x00000004)
#define ADC_CFGR1_RES ((u32_t)0x00000018)
#define ADC_CFGR1_RES_0 ((u32_t)0x00000008)
#define ADC_CFGR1_RES_1 ((u32_t)0x00000010)
#define ADC_CFGR1_ALIGN ((u32_t)0x00000020)
#define ADC_CFGR1_EXTSEL ((u32_t)0x000001C0)
#define ADC_CFGR1_EXTSEL_0 ((u32_t)0x00000040)
#define ADC_CFGR1_EXTSEL_1 ((u32_t)0x00000080)
#define ADC_CFGR1_EXTSEL_2 ((u32_t)0x00000100)
#define ADC_CFGR1_EXTEN ((u32_t)0x00000C00)
#define ADC_CFGR1_EXTEN_0 ((u32_t)0x00000400)
#define ADC_CFGR1_EXTEN_1 ((u32_t)0x00000800)
#define ADC_CFGR1_OVRMOD ((u32_t)0x00001000)
#define ADC_CFGR1_CONT ((u32_t)0x00002000)
#define ADC_CFGR1_WAIT ((u32_t)0x00004000)
#define ADC_CFGR1_AUTOFF ((u32_t)0x00008000)
#define ADC_CFGR1_DISCEN ((u32_t)0x00010000)
#define ADC_CFGR1_AWD1SGL ((u32_t)0x00400000)
#define ADC_CFGR1_AWD1EN ((u32_t)0x00800000)
#define ADC_CFGR1_AWD1CH ((u32_t)0x7C000000)
#define ADC_CFGR1_AWD1CH_0 ((u32_t)0x04000000)
#define ADC_CFGR1_AWD1CH_1 ((u32_t)0x08000000)
#define ADC_CFGR1_AWD1CH_2 ((u32_t)0x10000000)
#define ADC_CFGR1_AWD1CH_3 ((u32_t)0x20000000)
#define ADC_CFGR1_AWD1CH_4 ((u32_t)0x40000000)

#define ADC_CFGR2_CKMODE ((u32_t)0xC0000000)
#define ADC_CFGR2_CKMODE_1 ((u32_t)0x80000000)
#define ADC_CFGR2_CKMODE_0 ((u32_t)0x40000000)

#define ADC_CHSELR_CHSEL ((u32_t)0x0007FFFF)
#define ADC_CHSELR_CHSEL18 ((u32_t)0x00040000)
#define ADC_CHSELR_CHSEL17 ((u32_t)0x00020000)
#define ADC_CHSELR_CHSEL16 ((u32_t)0x00010000)
#define ADC_CHSELR_CHSEL15 ((u32_t)0x00008000)
#define ADC_CHSELR_CHSEL14 ((u32_t)0x00004000)
#define ADC_CHSELR_CHSEL13 ((u32_t)0x00002000)
#define ADC_CHSELR_CHSEL12 ((u32_t)0x00001000)
#define ADC_CHSELR_CHSEL11 ((u32_t)0x00000800)
#define ADC_CHSELR_CHSEL10 ((u32_t)0x00000400)
#define ADC_CHSELR_CHSEL9 ((u32_t)0x00000200)
#define ADC_CHSELR_CHSEL8 ((u32_t)0x00000100)
#define ADC_CHSELR_CHSEL7 ((u32_t)0x00000080)
#define ADC_CHSELR_CHSEL6 ((u32_t)0x00000040)
#define ADC_CHSELR_CHSEL5 ((u32_t)0x00000020)
#define ADC_CHSELR_CHSEL4 ((u32_t)0x00000010)
#define ADC_CHSELR_CHSEL3 ((u32_t)0x00000008)
#define ADC_CHSELR_CHSEL2 ((u32_t)0x00000004)
#define ADC_CHSELR_CHSEL1 ((u32_t)0x00000002)
#define ADC_CHSELR_CHSEL0 ((u32_t)0x00000001)

#define ADC_CR_ADEN ((u32_t)0x00000001)
#define ADC_CR_ADDIS ((u32_t)0x00000002)
#define ADC_CR_ADSTART ((u32_t)0x00000004)
#define ADC_CR_ADSTP ((u32_t)0x00000010)
#define ADC_CR_ADCAL ((u32_t)0x80000000)

#define ADC_DR_DATA ((u32_t)0x0000FFFF)
#define ADC_DR_DATA_0 ((u32_t)0x00000001)
#define ADC_DR_DATA_1 ((u32_t)0x00000002)
#define ADC_DR_DATA_2 ((u32_t)0x00000004)
#define ADC_DR_DATA_3 ((u32_t)0x00000008)
#define ADC_DR_DATA_4 ((u32_t)0x00000010)
#define ADC_DR_DATA_5 ((u32_t)0x00000020)
#define ADC_DR_DATA_6 ((u32_t)0x00000040)
#define ADC_DR_DATA_7 ((u32_t)0x00000080)
#define ADC_DR_DATA_8 ((u32_t)0x00000100)
#define ADC_DR_DATA_9 ((u32_t)0x00000200)
#define ADC_DR_DATA_10 ((u32_t)0x00000400)
#define ADC_DR_DATA_11 ((u32_t)0x00000800)
#define ADC_DR_DATA_12 ((u32_t)0x00001000)
#define ADC_DR_DATA_13 ((u32_t)0x00002000)
#define ADC_DR_DATA_14 ((u32_t)0x00004000)
#define ADC_DR_DATA_15 ((u32_t)0x00008000)

#define ADC_IER_ADRDYIE ((u32_t)0x00000001)
#define ADC_IER_EOSMPIE ((u32_t)0x00000002)
#define ADC_IER_EOCIE ((u32_t)0x00000004)
#define ADC_IER_EOSIE ((u32_t)0x00000008)
#define ADC_IER_OVRIE ((u32_t)0x00000010)
#define ADC_IER_AWD1IE ((u32_t)0x00000080)

#define ADC_ISR_ADRDY ((u32_t)0x00000001)
#define ADC_ISR_EOSMP ((u32_t)0x00000002)
#define ADC_ISR_EOC ((u32_t)0x00000004)
#define ADC_ISR_EOS ((u32_t)0x00000008)
#define ADC_ISR_OVR ((u32_t)0x00000010)
#define ADC_ISR_AWD1 ((u32_t)0x00000080)

#define ADC_SMPR_SMP ((u32_t)0x00000007)
#define ADC_SMPR_SMP_0 ((u32_t)0x00000001)
#define ADC_SMPR_SMP_1 ((u32_t)0x00000002)
#define ADC_SMPR_SMP_2 ((u32_t)0x00000004)

#define ADC_TR1_LT1 ((u32_t)0x00000FFF)
#define ADC_TR1_LT1_0 ((u32_t)0x00000001)
#define ADC_TR1_LT1_1 ((u32_t)0x00000002)
#define ADC_TR1_LT1_2 ((u32_t)0x00000004)
#define ADC_TR1_LT1_3 ((u32_t)0x00000008)
#define ADC_TR1_LT1_4 ((u32_t)0x00000010)
#define ADC_TR1_LT1_5 ((u32_t)0x00000020)
#define ADC_TR1_LT1_6 ((u32_t)0x00000040)
#define ADC_TR1_LT1_7 ((u32_t)0x00000080)
#define ADC_TR1_LT1_8 ((u32_t)0x00000100)
#define ADC_TR1_LT1_9 ((u32_t)0x00000200)
#define ADC_TR1_LT1_10 ((u32_t)0x00000400)
#define ADC_TR1_LT1_11 ((u32_t)0x00000800)
#define ADC_TR1_HT1 ((u32_t)0x0FFF0000)
#define ADC_TR1_HT1_0 ((u32_t)0x00010000)
#define ADC_TR1_HT1_1 ((u32_t)0x00020000)
#define ADC_TR1_HT1_2 ((u32_t)0x00040000)
#define ADC_TR1_HT1_3 ((u32_t)0x00080000)
#define ADC_TR1_HT1_4 ((u32_t)0x00100000)
#define ADC_TR1_HT1_5 ((u32_t)0x00200000)
#define ADC_TR1_HT1_6 ((u32_t)0x00400000)
#define ADC_TR1_HT1_7 ((u32_t)0x00800000)
#define ADC_TR1_HT1_8 ((u32_t)0x01000000)
#define ADC_TR1_HT1_9 ((u32_t)0x02000000)
#define ADC_TR1_HT1_10 ((u32_t)0x04000000)
#define ADC_TR1_HT1_11 ((u32_t)0x08000000)

#endif
