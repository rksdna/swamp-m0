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

#ifndef STK_H
#define STK_H

#include <types.h>

struct stk
{
    volatile u32_t CTRL;
    volatile u32_t LOAD;
    volatile u32_t VAL;
    volatile const u32_t CALIB;
};

#define STK ((struct stk *)0xE000E010)

#define STK_CTRL_ENABLE ((u32_t)0x00000001)
#define STK_CTRL_TICKINT ((u32_t)0x00000002)
#define STK_CTRL_CLKSOURCE ((u32_t)0x00000004)
#define STK_CTRL_COUNTFLAG ((u32_t)0x00010000)

#define STK_LOAD_RELOAD ((u32_t)0x00FFFFFF)

#define STK_VAL_CURRENT ((u32_t)0x00FFFFFF)

#define STK_CALIB_TENMS ((u32_t)0x00FFFFFF)
#define STK_CALIB_SKEW ((u32_t)0x40000000)
#define STK_CALIB_NOREF ((u32_t)0x80000000)

#endif
