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

#ifndef CORE_H
#define CORE_H

#include <types.h>

#define PSR_ISR ((u32_t)(0x0000003F))
#define PSR_T ((u32_t)(0x01000000))
#define PSR_V ((u32_t)(0x10000000))
#define PSR_C ((u32_t)(0x20000000))
#define PSR_Z ((u32_t)(0x40000000))
#define PSR_N ((u32_t)(0x80000000))

#define PRIMASK_PRIMASK ((u32_t)(0x00000001))

#define CONTROL_ASPSEL ((u32_t)(0x00000002))

#define LR_HANDLER ((u32_t)0xFFFFFFF1)
#define LR_THREAD_MSP ((u32_t)0xFFFFFFF9)
#define LR_THREAD_PSP ((u32_t)0xFFFFFFFD)

#endif
