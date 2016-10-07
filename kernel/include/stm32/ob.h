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

#ifndef OB_H
#define OB_H

#include <types.h>

struct ob
{
    volatile u16_t RDP;
    volatile u16_t USER;
    volatile u16_t DATA0;
    volatile u16_t DATA1;
    volatile u16_t WRP0;
    volatile u16_t WRP1;
    volatile u16_t WRP2;
    volatile u16_t WRP3;
};

#define OB ((struct ob *)0x1FFFF800)

#define OB_RDP_RDP ((u16_t)0x00FF)
#define OB_RDP_NRDP ((u16_t)0xFF00)

#define OB_USER_USER ((u16_t)0x00FF)
#define OB_USER_NUSER ((u16_t)0xFF00)

#define OB_DATA0_DATA0 ((u16_t)0x00FF)
#define OB_DATA0_NDATA0 ((u16_t)0xFF00)

#define OB_DATA1_DATA1 ((u16_t)0x00FF)
#define OB_DATA1_NDATA1 ((u16_t)0xFF00)

#define OB_WRP0_WRP0 ((u16_t)0x00FF)
#define OB_WRP0_NWRP0 ((u16_t)0xFF00)

#define OB_WRP1_WRP1 ((u16_t)0x00FF)
#define OB_WRP1_NWRP1 ((u16_t)0xFF00)

#define OB_WRP2_WRP2 ((u16_t)0x00FF)
#define OB_WRP2_NWRP2 ((u16_t)0xFF00)

#define OB_WRP3_WRP3 ((u16_t)0x00FF)
#define OB_WRP3_NWRP3 ((u16_t)0xFF00)

#endif
