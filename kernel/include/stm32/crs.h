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

#ifndef CRS_H
#define CRS_H

#include <types.h>

struct crs
{
    volatile u32_t CR;
    volatile u32_t CFGR;
    volatile u32_t ISR;
    volatile u32_t ICR;
};

#define CRS ((struct crs *)0x40006C00)

#define CRS_CFGR_RELOAD ((u32_t)0x0000FFFF)
#define CRS_CFGR_FELIM ((u32_t)0x00FF0000)
#define CRS_CFGR_SYNCDIV ((u32_t)0x07000000)
#define CRS_CFGR_SYNCDIV_0 ((u32_t)0x01000000)
#define CRS_CFGR_SYNCDIV_1 ((u32_t)0x02000000)
#define CRS_CFGR_SYNCDIV_2 ((u32_t)0x04000000)
#define CRS_CFGR_SYNCSRC ((u32_t)0x30000000)
#define CRS_CFGR_SYNCSRC_0 ((u32_t)0x10000000)
#define CRS_CFGR_SYNCSRC_1 ((u32_t)0x20000000)
#define CRS_CFGR_SYNCPOL ((u32_t)0x80000000)

#define CRS_CR_SYNCOKIE ((u32_t)0x00000001)
#define CRS_CR_SYNCWARNIE ((u32_t)0x00000002)
#define CRS_CR_ERRIE ((u32_t)0x00000004)
#define CRS_CR_ESYNCIE ((u32_t)0x00000008)
#define CRS_CR_CEN ((u32_t)0x00000020)
#define CRS_CR_AUTOTRIMEN ((u32_t)0x00000040)
#define CRS_CR_SWSYNC ((u32_t)0x00000080)
#define CRS_CR_TRIM ((u32_t)0x00003F00)

#define CRS_ICR_SYNCOKC ((u32_t)0x00000001)
#define CRS_ICR_SYNCWARNC ((u32_t)0x00000002)
#define CRS_ICR_ERRC ((u32_t)0x00000004)
#define CRS_ICR_ESYNCC ((u32_t)0x00000008)

#define CRS_ISR_SYNCOKF ((u32_t)0x00000001)
#define CRS_ISR_SYNCWARNF ((u32_t)0x00000002)
#define CRS_ISR_ERRF ((u32_t)0x00000004)
#define CRS_ISR_ESYNCF ((u32_t)0x00000008)
#define CRS_ISR_SYNCERR ((u32_t)0x00000100)
#define CRS_ISR_SYNCMISS ((u32_t)0x00000200)
#define CRS_ISR_TRIMOVF ((u32_t)0x00000400)
#define CRS_ISR_FEDIR ((u32_t)0x00008000)
#define CRS_ISR_FECAP ((u32_t)0xFFFF0000)

#endif
