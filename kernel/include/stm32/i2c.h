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

#ifndef I2C_H
#define I2C_H

#include <types.h>

struct i2c
{
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t OAR1;
    volatile u32_t OAR2;
    volatile u32_t TIMINGR;
    volatile u32_t TIMEOUTR;
    volatile u32_t ISR;
    volatile u32_t ICR;
    volatile u32_t PECR;
    volatile u32_t RXDR;
    volatile u32_t TXDR;
};

#define I2C1 ((struct i2c *)0x40005400)
#define I2C2 ((struct i2c *)0x40005800)

#define I2C_CR1_PE ((u32_t)0x00000001)
#define I2C_CR1_TXIE ((u32_t)0x00000002)
#define I2C_CR1_RXIE ((u32_t)0x00000004)
#define I2C_CR1_ADDRIE ((u32_t)0x00000008)
#define I2C_CR1_NACKIE ((u32_t)0x00000010)
#define I2C_CR1_STOPIE ((u32_t)0x00000020)
#define I2C_CR1_TCIE ((u32_t)0x00000040)
#define I2C_CR1_ERRIE ((u32_t)0x00000080)
#define I2C_CR1_DNF ((u32_t)0x00000F00)
#define I2C_CR1_ANFOFF ((u32_t)0x00001000)
#define I2C_CR1_SWRST ((u32_t)0x00002000)
#define I2C_CR1_TXDMAEN ((u32_t)0x00004000)
#define I2C_CR1_RXDMAEN ((u32_t)0x00008000)
#define I2C_CR1_SBC ((u32_t)0x00010000)
#define I2C_CR1_NOSTRETCH ((u32_t)0x00020000)
#define I2C_CR1_GCEN ((u32_t)0x00080000)
#define I2C_CR1_SMBHEN ((u32_t)0x00100000)
#define I2C_CR1_SMBDEN ((u32_t)0x00200000)
#define I2C_CR1_ALERTEN ((u32_t)0x00400000)
#define I2C_CR1_PECEN ((u32_t)0x00800000)
#define I2C_CR1_WUPEN ((u32_t)0x00040000)

#define I2C_CR2_SADD ((u32_t)0x000003FF)
#define I2C_CR2_RD_WRN ((u32_t)0x00000400)
#define I2C_CR2_ADD10 ((u32_t)0x00000800)
#define I2C_CR2_HEAD10R ((u32_t)0x00001000)
#define I2C_CR2_START ((u32_t)0x00002000)
#define I2C_CR2_STOP ((u32_t)0x00004000)
#define I2C_CR2_NACK ((u32_t)0x00008000)
#define I2C_CR2_NBYTES ((u32_t)0x00FF0000)
#define I2C_CR2_RELOAD ((u32_t)0x01000000)
#define I2C_CR2_AUTOEND ((u32_t)0x02000000)
#define I2C_CR2_PECBYTE ((u32_t)0x04000000)

#define I2C_ICR_ADDRCF ((u32_t)0x00000008)
#define I2C_ICR_NACKCF ((u32_t)0x00000010)
#define I2C_ICR_STOPCF ((u32_t)0x00000020)
#define I2C_ICR_BERRCF ((u32_t)0x00000100)
#define I2C_ICR_ARLOCF ((u32_t)0x00000200)
#define I2C_ICR_OVRCF ((u32_t)0x00000400)
#define I2C_ICR_PECCF ((u32_t)0x00000800)
#define I2C_ICR_TIMOUTCF ((u32_t)0x00001000)
#define I2C_ICR_ALERTCF ((u32_t)0x00002000)

#define I2C_ISR_TXE ((u32_t)0x00000001)
#define I2C_ISR_TXIS ((u32_t)0x00000002)
#define I2C_ISR_RXNE ((u32_t)0x00000004)
#define I2C_ISR_ADDR ((u32_t)0x00000008)
#define I2C_ISR_NACKF ((u32_t)0x00000010)
#define I2C_ISR_STOPF ((u32_t)0x00000020)
#define I2C_ISR_TC ((u32_t)0x00000040)
#define I2C_ISR_TCR ((u32_t)0x00000080)
#define I2C_ISR_BERR ((u32_t)0x00000100)
#define I2C_ISR_ARLO ((u32_t)0x00000200)
#define I2C_ISR_OVR ((u32_t)0x00000400)
#define I2C_ISR_PECERR ((u32_t)0x00000800)
#define I2C_ISR_TIMEOUT ((u32_t)0x00001000)
#define I2C_ISR_ALERT ((u32_t)0x00002000)
#define I2C_ISR_BUSY ((u32_t)0x00008000)
#define I2C_ISR_DIR ((u32_t)0x00010000)
#define I2C_ISR_ADDCODE ((u32_t)0x00FE0000)

#define I2C_OAR1_OA1 ((u32_t)0x000003FF)
#define I2C_OAR1_OA1MODE ((u32_t)0x00000400)
#define I2C_OAR1_OA1EN ((u32_t)0x00008000)

#define I2C_OAR2_OA2 ((u32_t)0x000000FE)
#define I2C_OAR2_OA2MSK ((u32_t)0x00000700)
#define I2C_OAR2_OA2NOMASK ((u32_t)0x00000000)
#define I2C_OAR2_OA2MASK01 ((u32_t)0x00000100)
#define I2C_OAR2_OA2MASK02 ((u32_t)0x00000200)
#define I2C_OAR2_OA2MASK03 ((u32_t)0x00000300)
#define I2C_OAR2_OA2MASK04 ((u32_t)0x00000400)
#define I2C_OAR2_OA2MASK05 ((u32_t)0x00000500)
#define I2C_OAR2_OA2MASK06 ((u32_t)0x00000600)
#define I2C_OAR2_OA2MASK07 ((u32_t)0x00000700)
#define I2C_OAR2_OA2EN ((u32_t)0x00008000)

#define I2C_PECR_PEC ((u32_t)0x000000FF)

#define I2C_RXDR_RXDATA ((u32_t)0x000000FF)

#define I2C_TIMEOUTR_TIMEOUTA ((u32_t)0x00000FFF)
#define I2C_TIMEOUTR_TIDLE ((u32_t)0x00001000)
#define I2C_TIMEOUTR_TIMOUTEN ((u32_t)0x00008000)
#define I2C_TIMEOUTR_TIMEOUTB ((u32_t)0x0FFF0000)
#define I2C_TIMEOUTR_TEXTEN ((u32_t)0x80000000)

#define I2C_TIMINGR_SCLL ((u32_t)0x000000FF)
#define I2C_TIMINGR_SCLH ((u32_t)0x0000FF00)
#define I2C_TIMINGR_SDADEL ((u32_t)0x000F0000)
#define I2C_TIMINGR_SCLDEL ((u32_t)0x00F00000)
#define I2C_TIMINGR_PRESC ((u32_t)0xF0000000)

#define I2C_TXDR_TXDATA ((u32_t)0x000000FF)

#endif
