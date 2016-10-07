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

#ifndef WWDG_H
#define WWDG_H

#include <types.h>

struct wwdg
{
    volatile u32_t CR;
    volatile u32_t CFR;
    volatile u32_t SR;
};

#define WWDG ((struct wwdg *)0x40002C00)

#define WWDG_CR_T ((u32_t)0x0000007F)
#define WWDG_CR_WDGA ((u32_t)0x00000080)

#define WWDG_CFR_W ((u32_t)0x0000007F)
#define WWDG_CFR_WDGTB ((u32_t)0x00000180)
#define WWDG_CFR_WDGTB_0 ((u32_t)0x00000080)
#define WWDG_CFR_WDGTB_1 ((u32_t)0x00000100)
#define WWDG_CFR_EWI ((u32_t)0x00000200)

#define WWDG_SR_EWIF ((u32_t)0x00000001)

#endif
