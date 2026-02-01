/********************************************************************************************
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
* - Description: This file is used to set all memory section needed by the controller
* - Author      : Mohamed Eid
* - File Name   : LinkerCfg.h
* - File Type   : ARM STM32 Linker configuration file
* - Description : Linker configuration code for STM32 microcontroller.
* - Date        : 16-08-2025
* - References  : STM32 Datasheet TBD, STM32 Instruction Set Manual
* - Toolchain   : GNU ARM-GCC / ARM-assembly
* - Version : History
* - 1.00.00 : Linker configuration file creation
********************************************************************************************/
__MEMORY_FLASH_ADDRESS_ORIGIN              = 0x08000000 ;       
__MEMORY_FLASH_LENGTH                      = 0x40000 ;     /* 256_KB */

__MEMORY_SRAM_ADDRESS_ORIGIN               = 0x20000000 ;
__MEMORY_SRAM_LENGTH                       = 0x10000 ;     /* 64_KB */

__MEM_SECTION_JUMPTABLE_START_ADDRESS      = 0x08000000;   /* 512_B */
__MEM_SECTION_JUMPTABLE_END_ADDRESS        = 0x08000200;

__MEM_SECTION_CONSTANT_START_ADDRESS       = 0x08000200;  /* 16_KB */
__MEM_SECTION_CONSTANT_END_ADDRESS         = 0x08004200;

__MEM_SECTION_DATA_LOAD_START_ADDRESS      = 0x08004200;  /* 8_KB */
__MEM_SECTION_DATA_LOAD_END_ADDRESS        = 0x08006200;

__MEM_SECTION_RAMFUNC_LOAD_START_ADDRESS   = 0x08006200;  /* 2_KB */
__MEM_SECTION_RAMFUNC_LOAD_END_ADDRESS     = 0x08006A00;

__MEM_SECTION_INIT_START_ADDRESS           = 0x08006A00;  /* 2_KB */
__MEM_SECTION_INIT_END_ADDRESS             = 0x08007200;

__MEM_SECTION_FINIT_START_ADDRESS          = 0x08007200;  /* 2_KB */
__MEM_SECTION_FINIT_END_ADDRESS            = 0x08007A00;

__MEM_SECTION_CODE_START_ADDRESS           = 0x08007A00;  /* 226.5_KB */
__MEM_SECTION_CODE_END_ADDRESS             = 0x08040000;

__MEM_SECTION_DATA_START_ADDRESS           = 0x20000000;  /* 8_KB */
__MEM_SECTION_DATA_END_ADDRESS             = 0x20002000;

__MEM_SECTION_BSS_START_ADDRESS            = 0x20002000;  /* 16_KB */
__MEM_SECTION_BSS_END_ADDRESS              = 0x20006000;

__MEM_SECTION_RAMFUNC_START_ADDRESS        = 0x20006000;  /* 2_KB */
__MEM_SECTION_RAMFUNC_END_ADDRESS          = 0x20006800;

__MEM_SECTION_NOINIT_START_ADDRESS         = 0x20006800;  /* 2_KB */
__MEM_SECTION_NOINIT_END_ADDRESS           = 0x20007000;

__MEM_SECTION_HEAP_START_ADDRESS           = 0x20007000;  /* 8_KB */
__MEM_SECTION_HEAP_END_ADDRESS             = 0x20009000;

__MEM_SECTION_STACK_START_ADDRESS          = 0x20009000;  /* 28_KB */ /* Stack lower address */
__MEM_SECTION_STACK_END_ADDRESS            = 0x20010000;              /* Stack Higher address Top of the stack */
__STACK_POINTER_START_ADDRESS_VALUE        = 0x20010000;