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

#ifndef IWDG_H
#define IWDG_H

#include <types.h>

struct iwdg
{
    volatile u32_t KR;
    volatile u32_t PR;
    volatile u32_t RLR;
    volatile u32_t SR;
    volatile u32_t WINR;
};

#define IWDG ((struct iwdg *)0x40003000)

#define IWDG_KR_KEY ((u32_t)0x0000FFFF)
#define IWDG_KR_KEY_KEY_RESET ((u32_t)0x0000AAAA)
#define IWDG_KR_KEY_KEY_ACCESS ((u32_t)0x00005555)

#define IWDG_PR_PR ((u32_t)0x00000007)
#define IWDG_PR_PR_0 ((u32_t)0x00000001)
#define IWDG_PR_PR_1 ((u32_t)0x00000002)
#define IWDG_PR_PR_2 ((u32_t)0x00000004)

#define IWDG_RLR_RL ((u32_t)0x00000FFF)

#define IWDG_SR_PVU ((u32_t)0x00000001)
#define IWDG_SR_RVU ((u32_t)0x00000002)
#define IWDG_SR_WVU ((u32_t)0x00000004)

#define IWDG_WINR_WIN ((u32_t)0x00000FFF)

#endif
