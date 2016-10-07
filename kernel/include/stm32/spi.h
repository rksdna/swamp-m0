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

#ifndef SPI_H
#define SPI_H

#include <types.h>

struct spi
{
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t SR;
    volatile u32_t DR;
    volatile u32_t CRCPR;
    volatile u32_t RXCRCR;
    volatile u32_t TXCRCR;
    volatile u32_t I2SCFGR;
    volatile u32_t I2SPR;
};

#define SPI1 ((struct spi *)0x40013000)
#define SPI2 ((struct spi *)0x40003800)

#define SPI_CR1_CPHA ((u32_t)0x00000001)
#define SPI_CR1_CPOL ((u32_t)0x00000002)
#define SPI_CR1_MSTR ((u32_t)0x00000004)
#define SPI_CR1_BR ((u32_t)0x00000038)
#define SPI_CR1_BR_0 ((u32_t)0x00000008)
#define SPI_CR1_BR_1 ((u32_t)0x00000010)
#define SPI_CR1_BR_2 ((u32_t)0x00000020)
#define SPI_CR1_SPE ((u32_t)0x00000040)
#define SPI_CR1_LSBFIRST ((u32_t)0x00000080)
#define SPI_CR1_SSI ((u32_t)0x00000100)
#define SPI_CR1_SSM ((u32_t)0x00000200)
#define SPI_CR1_RXONLY ((u32_t)0x00000400)
#define SPI_CR1_CRCL ((u32_t)0x00000800)
#define SPI_CR1_CRCNEXT ((u32_t)0x00001000)
#define SPI_CR1_CRCEN ((u32_t)0x00002000)
#define SPI_CR1_BIDIOE ((u32_t)0x00004000)
#define SPI_CR1_BIDIMODE ((u32_t)0x00008000)

#define SPI_CR2_RXDMAEN ((u32_t)0x00000001)
#define SPI_CR2_TXDMAEN ((u32_t)0x00000002)
#define SPI_CR2_SSOE ((u32_t)0x00000004)
#define SPI_CR2_NSSP ((u32_t)0x00000008)
#define SPI_CR2_FRF ((u32_t)0x00000010)
#define SPI_CR2_ERRIE ((u32_t)0x00000020)
#define SPI_CR2_RXNEIE ((u32_t)0x00000040)
#define SPI_CR2_TXEIE ((u32_t)0x00000080)
#define SPI_CR2_DS ((u32_t)0x00000F00)
#define SPI_CR2_DS_0 ((u32_t)0x00000100)
#define SPI_CR2_DS_1 ((u32_t)0x00000200)
#define SPI_CR2_DS_2 ((u32_t)0x00000400)
#define SPI_CR2_DS_3 ((u32_t)0x00000800)
#define SPI_CR2_FRXTH ((u32_t)0x00001000)
#define SPI_CR2_LDMARX ((u32_t)0x00002000)
#define SPI_CR2_LDMATX ((u32_t)0x00004000)

#define SPI_SR_RXNE ((u32_t)0x00000001)
#define SPI_SR_TXE ((u32_t)0x00000002)
#define SPI_SR_CRCERR ((u32_t)0x00000010)
#define SPI_SR_MODF ((u32_t)0x00000020)
#define SPI_SR_OVR ((u32_t)0x00000040)
#define SPI_SR_BSY ((u32_t)0x00000080)
#define SPI_SR_FRE ((u32_t)0x00000100)
#define SPI_SR_FRLVL ((u32_t)0x00000600)
#define SPI_SR_FRLVL_0 ((u32_t)0x00000200)
#define SPI_SR_FRLVL_1 ((u32_t)0x00000400)
#define SPI_SR_FTLVL ((u32_t)0x00001800)
#define SPI_SR_FTLVL_0 ((u32_t)0x00000800)
#define SPI_SR_FTLVL_1 ((u32_t)0x00001000)
#define SPI_SR_CHSIDE ((u32_t)0x00000004)
#define SPI_SR_UDR ((u32_t)0x00000008)

#define SPI_DR_DR ((u32_t)0x0000FFFF)

#define SPI_CRCPR_CRCPOLY ((u32_t)0x0000FFFF)

#define SPI_RXCRCR_RXCRC ((u32_t)0x0000FFFF)

#define SPI_TXCRCR_TXCRC ((u32_t)0x0000FFFF)

#define SPI_I2SCFGR_CHLEN ((u32_t)0x00000001)
#define SPI_I2SCFGR_DATLEN ((u32_t)0x00000006)
#define SPI_I2SCFGR_DATLEN_0 ((u32_t)0x00000002)
#define SPI_I2SCFGR_DATLEN_1 ((u32_t)0x00000004)
#define SPI_I2SCFGR_CKPOL ((u32_t)0x00000008)
#define SPI_I2SCFGR_I2SSTD ((u32_t)0x00000030)
#define SPI_I2SCFGR_I2SSTD_0 ((u32_t)0x00000010)
#define SPI_I2SCFGR_I2SSTD_1 ((u32_t)0x00000020)
#define SPI_I2SCFGR_PCMSYNC ((u32_t)0x00000080)
#define SPI_I2SCFGR_I2SCFG ((u32_t)0x00000300)
#define SPI_I2SCFGR_I2SCFG_0 ((u32_t)0x00000100)
#define SPI_I2SCFGR_I2SCFG_1 ((u32_t)0x00000200)
#define SPI_I2SCFGR_I2SE ((u32_t)0x00000400)
#define SPI_I2SCFGR_I2SMOD ((u32_t)0x00000800)

#define SPI_I2SPR_I2SDIV ((u32_t)0x000000FF)
#define SPI_I2SPR_ODD ((u32_t)0x00000100)
#define SPI_I2SPR_MCKOE ((u32_t)0x00000200)

#endif
