/* ***************************************************************************************
* License     : MIT License
* Copyright (c) 2025 Mohamed Eid
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Author      : Mohamed Eid
* File Name   : StartupCode.s
* File Type   : STM32 Assembly
* Description : Startup code for STM32 microcontroller.
* Date        : 16*08*2025
* References  : STM32 Datasheet TBD
* Toolchain   : GNU TBD / TBD assembly
* Version : History
* 1.00.00 : Assembly start up file creation
* *********************************************************************************/

/**********************************************************************************
  *  Assmbler directive instruction: for main function
**********************************************************************************/
.syntax unified
.cpu cortex-m4
.thumb

.global main                 
.global RESET_HANDLER
.global DEFAULT_HANDLER

/**********************************************************************************
  *  Assmbler directive instruction: vector table (Jump table)
***********************************************************************************/

/* Creates a memory section called .VectorTable, marked allocatable (a) and executable (x). */
.section .VectorTable, "a", %progbits
.type VectorTable, %object

VectorTable:
/* Jump table */
    .word __STACK_POINTER_START_ADDRESS_VALUE
    .word RESET_HANDLER

/**********************************************************************************
  *  Assmbler directive instruction: create Code section
***********************************************************************************/

.section .text, "ax"           /* Create memory section called .text marked allocatable (a) and executable (x). */
.type RESET_HANDLER, %function

/**********************************************************************************
  *  Assmbly instruction: Reset Handler everything 
  *  needs to be initialized before main write it here
***********************************************************************************/
RESET_HANDLER:
    ldr r0, =__DATA_ADDRESS_BEGIN            /* Load .data start address memory section into register r0 */
    ldr r1, =__DATA_ADDRESS_END              /* Load .data end address memory section into register r1 */
    ldr r2, =__DATA_LOAD_ADDRESS_BEGIN       /* Load .data_load start address memory section into register r2 */

MEM_DATA_COPY_LOOP:
    cmp   r0, r1
    bcs   LOOP1_DONE
 
    ldr   r3, [r2], #4 
    str   r3, [r0], #4
    b     MEM_DATA_COPY_LOOP
 
LOOP1_DONE:
    ldr r0, =__RAMFUNC_ADDRESS_BEGIN            /* Load .ramfunc start address memory section into register r0 */
    ldr r1, =__RAMFUNC_ADDRESS_END              /* Load .ramfunc end address memory section into register r1 */
    ldr r2, =__RAMFUNC_LOAD_ADDRESS_BEGIN       /* Load .ramfunc_load start address memory section into register r2 */

MEM_RAMFUNC_COPY_LOOP:
    cmp   r0, r1
    bcs   LOOP2_DONE
  
    ldr   r3, [r2], #4
    str   r3, [r0], #4
    b     MEM_RAMFUNC_COPY_LOOP

LOOP2_DONE:
    ldr r0, =__BSS_ADDRESS_BEGIN            /* Load .ramfunc start address memory section into register r0 */
    ldr r1, =__BSS_ADDRESS_END              /* Load .ramfunc end address memory section into register r1 */
    movs r2, #0

MEM_BSS_CLEAR_LOOP:
    cmp r0,r1
    bcs LOOP3_DONE

    str r2, [r0], #4
    b MEM_BSS_CLEAR_LOOP

LOOP3_DONE:

bl main

DEFAULT_HANDLER:
    b DEFAULT_HANDLER



