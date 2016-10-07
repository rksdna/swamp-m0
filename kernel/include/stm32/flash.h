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

#ifndef FLASH_H
#define FLASH_H

#include <types.h>

struct flash
{
    volatile u32_t ACR;
    volatile u32_t KEYR;
    volatile u32_t OPTKEYR;
    volatile u32_t SR;
    volatile u32_t CR;
    volatile u32_t AR;
    volatile u32_t RESERVED;
    volatile u32_t OBR;
    volatile u32_t WRPR;
};

#define FLASH ((struct flash *)0x40022000)

#define FLASH_ACR_LATENCY ((u32_t)0x00000001)
#define FLASH_ACR_LATENCY_0 ((u32_t)0x00000001)
#define FLASH_ACR_LATENCY_24MHz ((u32_t)0x00000000)
#define FLASH_ACR_LATENCY_48MHz ((u32_t)0x00000001)
#define FLASH_ACR_PRFTBE ((u32_t)0x00000010)
#define FLASH_ACR_PRFTBS ((u32_t)0x00000020)

#define FLASH_KEYR_FKEYR ((u32_t)0xFFFFFFFF)
#define FLASH_KEYR_FKEYR_KEY1 ((u32_t)0x45670123)
#define FLASH_KEYR_FKEYR_KEY2 ((u32_t)0xCDEF89AB)

#define FLASH_OPTKEYR_OPTKEYR ((u32_t)0xFFFFFFFF)
#define FLASH_OPTKEYR_FKEYR_KEY1 ((u32_t)0x45670123)
#define FLASH_OPTKEYR_FKEYR_KEY2 ((u32_t)0xCDEF89AB)

#define FLASH_SR_BSY ((u32_t)0x00000001)
#define FLASH_SR_PGERR ((u32_t)0x00000004)
#define FLASH_SR_WRPRTERR ((u32_t)0x00000010)
#define FLASH_SR_EOP ((u32_t)0x00000020)

#define FLASH_CR_PG ((u32_t)0x00000001)
#define FLASH_CR_PER ((u32_t)0x00000002)
#define FLASH_CR_MER ((u32_t)0x00000004)
#define FLASH_CR_OPTPG ((u32_t)0x00000010)
#define FLASH_CR_OPTER ((u32_t)0x00000020)
#define FLASH_CR_STRT ((u32_t)0x00000040)
#define FLASH_CR_LOCK ((u32_t)0x00000080)
#define FLASH_CR_OPTWRE ((u32_t)0x00000200)
#define FLASH_CR_ERRIE ((u32_t)0x00000400)
#define FLASH_CR_EOPIE ((u32_t)0x00001000)
#define FLASH_CR_OBL_LAUNCH ((u32_t)0x00002000)

#define FLASH_AR_FAR ((u32_t)0xFFFFFFFF)

#define FLASH_OBR_OPTERR ((u32_t)0x00000001)
#define FLASH_OBR_RDPRT1 ((u32_t)0x00000002)
#define FLASH_OBR_RDPRT2 ((u32_t)0x00000004)
#define FLASH_OBR_USER ((u32_t)0x0000FF00)
#define FLASH_OBR_IWDG_SW ((u32_t)0x00000100)
#define FLASH_OBR_NRST_STOP ((u32_t)0x00000200)
#define FLASH_OBR_NRST_STDBY ((u32_t)0x00000400)
#define FLASH_OBR_NBOOT1 ((u32_t)0x00001000)
#define FLASH_OBR_VDDA_MONITOR ((u32_t)0x00002000)
#define FLASH_OBR_RAM_PARITY_CHECK ((u32_t)0x00004000)
#define FLASH_OBR_DATA0 ((u32_t)0x00FF0000)
#define FLASH_OBR_DATA1 ((u32_t)0xFF000000)
#define FLASH_OBR_NBOOT0 ((u32_t)0x00000800)
#define FLASH_OBR_BOOT_SEL ((u32_t)0x00008000)

#define FLASH_WRPR_WRP ((u32_t)0xFFFFFFFF)

#endif
