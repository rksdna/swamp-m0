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

#ifndef CRC_H
#define CRC_H

#include <types.h>

struct crc
{
    volatile u32_t DR;
    volatile u32_t IDR;
    volatile u32_t CR;
    u32_t RESERVED0;
    volatile u32_t INIT;
    volatile u32_t POL;
};

#define CRC ((struct crc *)0x40023000)

#define CRC_CR_RESET ((u32_t)0x00000001)
#define CRC_CR_REV_IN ((u32_t)0x00000060)
#define CRC_CR_REV_IN_0 ((u32_t)0x00000020)
#define CRC_CR_REV_IN_1 ((u32_t)0x00000040)
#define CRC_CR_REV_OUT ((u32_t)0x00000080)
#define CRC_CR_POLYSIZE ((u32_t)0x00000018)
#define CRC_CR_POLYSIZE_0 ((u32_t)0x00000008)
#define CRC_CR_POLYSIZE_1 ((u32_t)0x00000010)

#define CRC_DR_DR ((u32_t)0xFFFFFFFF)

#define CRC_IDR_IDR ((u32_t)0x000000FF)

#define CRC_INIT_INIT ((u32_t)0xFFFFFFFF)

#define CRC_POL_POL ((u32_t)0xFFFFFFFF)

#endif
