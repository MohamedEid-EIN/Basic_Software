/********************************************************************************************
* License     : MIT License
* Copyright (c) 2025 Mohamed Eid
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
* - File Name   : STM32.ld
* - File Type   : ARM STM32 Linker
* - Description : Linker code for STM32 microcontroller.
* - Date        : 16-08-2025
* - References  : STM32 Datasheet TBD, STM32 Instruction Set Manual
* - Toolchain   : GNU ARM-GCC / ARM-assembly
* - Version : History
* - 1.00.00 : Linker file Creation
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

MEMORY
{
    FLASH (rx) : ORIGIN = __MEMORY_FLASH_ADDRESS_ORIGIN, LENGTH = __MEMORY_FLASH_LENGTH
    SRAM (rw) : ORIGIN = __MEMORY_SRAM_ADDRESS_ORIGIN, LENGTH = __MEMORY_SRAM_LENGTH
}

/***********************************************
* Set Entry point
************************************************/
ENTRY(RESET_HANDLER)

/**************************************************************************************************
* Memory sections mapping you can add all your sections here
****************************************************************************************************/
SECTIONS
{
/**************************************************************************************************************************************************************/
    /* Section Name: Vector table memory section
       Short Name: .VectorTable
       Description: All controller Irq's.
       Calculation: Calculated size  512_B
                    (1 SP + 1 Reset + 14 Core exception + 86 NVIC Irq = 102 interrupt Entry with 4 bytes size each.
                    Address end 408_B + Align it to 512_B --> 0x00000198 => 0x00000200) */
    
    .VectorTable __MEM_SECTION_JUMPTABLE_START_ADDRESS :
    {
        PROVIDE(__JUMP_TABLE_ADDRESS_BEGIN = .);                /* Create linker symbol to store calculated start address */
        KEEP(*(.VectorTable))                                   /* Force linker to include the specifed input section into the final output even if it's unused */
        PROVIDE(__JUMP_TABLE_ADDRESS_END = .);                  /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__JUMP_TABLE_ADDRESS_END - __JUMP_TABLE_ADDRESS_BEGIN) <= (__MEM_SECTION_JUMPTABLE_END_ADDRESS - __MEM_SECTION_JUMPTABLE_START_ADDRESS),
           "VectorTable memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/
    /* Section Name: Constant memory section
       Short Name: .rodata
       Description: (Fixed size arrays, Lookup tables, String literals, Floating points, Fixed values)
       Calculation: Estimated fixed safe size 16_KB */

    .rodata __MEM_SECTION_CONSTANT_START_ADDRESS :
    {     
        __CONSTANT_ADDRESS_BEGIN = .;                           /* Create linker symbol to store calculated start address */
        KEEP(*(.rodata))                                        /* Force linker to include the specifed input section into the final output even if it's unused */
        __CONSTANT_ADDRESS_END = .;                             /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__CONSTANT_ADDRESS_END - __CONSTANT_ADDRESS_BEGIN) <= (__MEM_SECTION_CONSTANT_END_ADDRESS - __MEM_SECTION_CONSTANT_START_ADDRESS),
           "rodata data memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/
    /* Section Name: data load memory section
       Short Name: .data_load
       Description: Initialized global and static variables in the FLASH memory to be copied at initializtion into SRAM at startup.
       Calculation: Estimated fixed safe size 8_KB */

    .data_load __MEM_SECTION_DATA_LOAD_START_ADDRESS :
    {     
        __DATA_LOAD_ADDRESS_BEGIN = .;                          /* Create linker symbol to store calculated start address */
        KEEP(*(.data_load))                                     /* Force linker to include the specifed input section into the final output even if it's unused */
        __DATA_LOAD_ADDRESS_END = .;                            /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__DATA_LOAD_ADDRESS_END - __DATA_LOAD_ADDRESS_BEGIN) <= (__MEM_SECTION_DATA_LOAD_END_ADDRESS - __MEM_SECTION_DATA_LOAD_START_ADDRESS),
           "data_load memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/
    /* Section Name: Ram function load memory section:
       Short Name: .ramfunc_load
       Description: used to run some functions or operations from RAM after loading it from the FLASH memory to be copied at initializtion into SRAM.
       Calculation: Estimated size 2_KB */

    .ramfunc_load __MEM_SECTION_RAMFUNC_LOAD_START_ADDRESS :
    {     
        __RAMFUNC_LOAD_ADDRESS_BEGIN = .;                       /* Create linker symbol to store calculated start address */
        KEEP(*(.ramfunc_load))                                  /* Force linker to include the specifed input section into the final output even if it's unused */
        __RAMFUNC_LOAD_ADDRESS_END = .;                         /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__RAMFUNC_LOAD_ADDRESS_END - __RAMFUNC_LOAD_ADDRESS_BEGIN) <= (__MEM_SECTION_RAMFUNC_LOAD_END_ADDRESS - __MEM_SECTION_RAMFUNC_LOAD_START_ADDRESS),
           "ramfunc_load memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/
    /* Section Name: before initialization memory section:
       Short Name: .init
       Description: used for startup and initialized routines normally called before main function call to do startup operations.
       Calculation: Estimated size 2_KB */

    .init __MEM_SECTION_INIT_START_ADDRESS :
    {     
        __INIT_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.init))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __INIT_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__INIT_ADDRESS_END - __INIT_ADDRESS_BEGIN) <= (__MEM_SECTION_INIT_END_ADDRESS - __MEM_SECTION_INIT_START_ADDRESS),
           "init memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/

    /* Section Name: after initialization memory section
       Short Name: .finit
       Description: Finalization routines normally called after main function to run specific operatioin after main returns.
       Calculation: Estimated size 2_KB */

    .finit __MEM_SECTION_FINIT_START_ADDRESS :
    {     
        __FINIT_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.finit))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __FINIT_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__FINIT_ADDRESS_END - __FINIT_ADDRESS_BEGIN) <= (__MEM_SECTION_FINIT_END_ADDRESS - __MEM_SECTION_FINIT_START_ADDRESS),
           "finit memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/
    /* Section Name: code memory section
       Short Name: .text
       Description: The software contain of application and Basic software
       Calculation: Estimated size 512_KB */

    .text __MEM_SECTION_CODE_START_ADDRESS :
    {     
        __CODE_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.text))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __CODE_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__CODE_ADDRESS_END - __CODE_ADDRESS_BEGIN) <= (__MEM_SECTION_CODE_END_ADDRESS - __MEM_SECTION_CODE_START_ADDRESS),
           "text memory section overflow!");
    } > FLASH
/***************************************************************************************************************************************************************/
    /* Section Name: initialized data memory section
       Short Name: .data
       Description: Initialized global and static variables in the SRAM memory copied from FLASH.
       Calculation: Estimated size 8_KB */

    .data __MEM_SECTION_DATA_START_ADDRESS :
    {     
        __DATA_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.data))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __DATA_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__DATA_ADDRESS_END - __DATA_ADDRESS_BEGIN) <= (__MEM_SECTION_DATA_END_ADDRESS - __MEM_SECTION_DATA_START_ADDRESS),
           "data memory section overflow!");
    } > SRAM AT > FLASH

__DATA_LOAD_ADDRESS_BEGIN = LOADADDR(.data);
/***************************************************************************************************************************************************************/
    /* Section Name: uninitialized data memory section
       Short Name: .bss
       Description: unInitialized global and static variables or initialized with zero in the startup code.
       Calculation: Estimated size 16_KB */

    .bss __MEM_SECTION_BSS_START_ADDRESS :
    {     
        __BSS_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.bss))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __BSS_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__BSS_ADDRESS_END - __BSS_ADDRESS_BEGIN) <= (__MEM_SECTION_BSS_END_ADDRESS - __MEM_SECTION_BSS_START_ADDRESS),
           "bss memory section overflow!");
    } > SRAM
/***************************************************************************************************************************************************************/
    /* Section Name: Ram function memory section:
       Short Name: .ramfunc
       Description: used to run some functions or operations from RAM for fast access on variables and function calls.
       Calculation: Estimated size 2_KB */

    .ramfunc __MEM_SECTION_RAMFUNC_START_ADDRESS :
    {     
        __RAMFUNC_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.ramfunc))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __RAMFUNC_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__RAMFUNC_ADDRESS_END - __RAMFUNC_ADDRESS_BEGIN) <= (__MEM_SECTION_RAMFUNC_END_ADDRESS - __MEM_SECTION_RAMFUNC_START_ADDRESS),
           "ramfunc memory section overflow!");
    } > SRAM
/***************************************************************************************************************************************************************/
    /* Section Name: No initiailzed data memory section
       Short Name: .noinit
       Description: unInitialized data even on reset the data is not cleared.
       Calculation: Estimated size 2_KB */

    .noinit __MEM_SECTION_NOINIT_START_ADDRESS :
    {     
        __NOINIT_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.noinit))                                             /* Force linker to include the specifed input section into the final output even if it's unused */
        __NOINIT_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__NOINIT_ADDRESS_END - __NOINIT_ADDRESS_BEGIN) <= (__MEM_SECTION_NOINIT_END_ADDRESS - __MEM_SECTION_NOINIT_START_ADDRESS),
           "noinit memory section overflow!");
    } > SRAM
/***************************************************************************************************************************************************************/
    /* Section Name: Dynamic data memory section
       Short Name: .heap
       Description: Dynamic memory location used for Run time data.
       Calculation: Estimated size 8_KB */

    .heap __MEM_SECTION_HEAP_START_ADDRESS :
    {     
        __HEAP_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.heap))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __HEAP_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__HEAP_ADDRESS_END - __HEAP_ADDRESS_BEGIN) <= (__MEM_SECTION_HEAP_END_ADDRESS - __MEM_SECTION_HEAP_START_ADDRESS),
           "heap memory section overflow!");
    } > SRAM
/***************************************************************************************************************************************************************/
    /* Section Name: stack memory section
       Short Name: .stack
       Description: stack is used for CPU calculation on run time
       Calculation: Estimated size 100KB */

    .stack __MEM_SECTION_STACK_START_ADDRESS :
    {     
        __STACK_ADDRESS_BEGIN = .;                               /* Create linker symbol to store calculated start address */
        KEEP(*(.stack))                                          /* Force linker to include the specifed input section into the final output even if it's unused */
        __STACK_ADDRESS_END = .;                                 /* Create linker symbol to store calculated end address */

        /* Memory check operation */
        ASSERT((__STACK_ADDRESS_END - __STACK_ADDRESS_BEGIN) <= (__MEM_SECTION_STACK_END_ADDRESS - __MEM_SECTION_STACK_START_ADDRESS),
           "stack memory section overflow!");
    } > SRAM
/***************************************************************************************************************************************************************/
}
