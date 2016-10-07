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

#ifndef DBGMCU_H
#define DBGMCU_H

#include <types.h>

struct dbgmcu
{
    volatile u32_t IDCODE;
    volatile u32_t CR;
    volatile u32_t APB1FZ;
    volatile u32_t APB2FZ;
};

#define DBGMCU ((struct dbgmcu *)0x40015800)

#define DBGMCU_CR_DBG_STOP ((u32_t)0x00000002)
#define DBGMCU_CR_DBG_STANDBY ((u32_t)0x00000004)

#define DBGMCU_IDCODE_DEV_ID ((u32_t)0x00000FFF)
#define DBGMCU_IDCODE_REV_ID ((u32_t)0xFFFF0000)

#define DBGMCU_APB1_FZ_DBG_TIM3_STOP ((u32_t)0x00000002)
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP ((u32_t)0x00000100)
#define DBGMCU_APB1_FZ_DBG_RTC_STOP ((u32_t)0x00000400)
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP ((u32_t)0x00000800)
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP ((u32_t)0x00001000)
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT ((u32_t)0x00200000)
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP ((u32_t)0x00000010)
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP ((u32_t)0x00000020)
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP ((u32_t)0x00000001)
#define DBGMCU_APB1_FZ_DBG_CAN_STOP ((u32_t)0x02000000)

#define DBGMCU_APB2_FZ_DBG_TIM1_STOP ((u32_t)0x00000800)
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP ((u32_t)0x00020000)
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP ((u32_t)0x00040000)
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP ((u32_t)0x00010000)

#endif
