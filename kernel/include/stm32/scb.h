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

#ifndef SCB_H
#define SCB_H

#include <types.h>

struct scb
{
    volatile const u32_t CPUID;
    volatile u32_t ICSR;
    u32_t RESERVED0;
    volatile u32_t AIRCR;
    volatile u32_t SCR;
    volatile u32_t CCR;
    u32_t RESERVED1;
    volatile u32_t SHP[2];
};

#define SCB ((struct scb *)0xE000ED00)

#define SCB_CPUID_REVISION ((u32_t)0x0000000F)
#define SCB_CPUID_PARTNO ((u32_t)0x0000FFF0)
#define SCB_CPUID_CONSTANT ((u32_t)0x000F0000)
#define SCB_CPUID_VARIANT ((u32_t)0x00F00000)
#define SCB_CPUID_IMPLEMENTER ((u32_t)0xFF000000)

#define SCB_ICSR_VECTACTIVE  ((u32_t)0x0000003F)
#define SCB_ICSR_VECTPENDING ((u32_t)0x0003F000)
#define SCB_ICSR_ISRPENDING ((u32_t)0x00400000)
#define SCB_ICSR_PENDSTCLR ((u32_t)0x02000000)
#define SCB_ICSR_PENDSTSET ((u32_t)0x04000000)
#define SCB_ICSR_PENDSVCLR ((u32_t)0x08000000)
#define SCB_ICSR_PENDSVSET ((u32_t)0x10000000)
#define SCB_ICSR_NMIPENDSET ((u32_t)0x80000000)

#define SCB_AIRCR_VECTCLRACTIVE ((u32_t)0x00000002)
#define SCB_AIRCR_SYSRESETREQ ((u32_t)0x00000004)
#define SCB_AIRCR_ENDIANESS ((u32_t)0x00008000)
#define SCB_AIRCR_VECTKEY ((u32_t)0xFFFF0000)
#define SCB_AIRCR_VECTKEY_KEY ((u32_t)0x05FA0000)

#define SCB_SCR_SLEEPONEXIT ((u32_t)0x00000002)
#define SCB_SCR_SLEEPDEEP ((u32_t)0x00000004)
#define SCB_SCR_SEVONPEND ((u32_t)0x00000010)

#define SCB_CCR_UNALIGN_TRP ((u32_t)0x00000008)
#define SCB_CCR_STKALIGN ((u32_t)0x00000200)

#define SCB_SHPx_PR_0 ((u32_t)0x000000FF)
#define SCB_SHPx_PR_1 ((u32_t)0x0000FF00)
#define SCB_SHPx_PR_2 ((u32_t)0x00FF0000)
#define SCB_SHPx_PR_3 ((u32_t)0xFF000000)

#endif
