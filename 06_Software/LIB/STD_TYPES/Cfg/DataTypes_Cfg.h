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
* - Description: This file is used to define all used data types ( All sizes based on
*                Architecture or compiler dependent).
* - Author      : Mohamed Eid
* - File Name   : DataTypes_Cfg.h
* - File Type   : Header file
* - References  : TBD
* - Toolchain   : TBD
* - Version : History
* - 1.00.00 : File Creation
*********************************************************************************************
* How to use the file:
*  In this file you configure the values of the parameters [ Cfg_ ] based on your Architecture
*  All values of data type sizes compiler and Architucre dependent could be 
*  different from one to another. 
* 
*  Example: the unsigned int on ARM Arch is 32 but on others is 16 based on 
*          these values you should adapt the configuration which will be 
*          used in the MCAL 
*******************************************************************************************/

/* Files Includes */
#include "PlatformDataTypes_Cfg.h"

#ifndef TYPESDEF_CFG_H
#define TYPESDEF_CFG_H

/**************************************************************************************************
 * MACROS configuration section                                                                   *
 *************************************************************************************************/

/**************************************************************************************************
 * 1. Configuration: Generic pointer type
 * Configure: Which size your platform supports
 * Configuration:
 * Ptr_Arch
 *************************************************************************************************/
#define MEMORY_SECTION_ATTRIBUTE(MemSection) __attribute__((section(MemSection)))

/**************************************************************************************************
 * Types defination configuration section                                                         *
 *************************************************************************************************/
/**************************************************************************************************
 * 1. DataType: Unsigned primitive types (architecture-defined widths)
 * Configure: Which size your platform supports
 * Configuration:
 * Uc_Arch
 * Us_Arch
 * Ui_Arch
 * Ul_Arch
 * Ull_Arch
 *************************************************************************************************/
typedef Uc_Arch                        U8_Cfg;  /* 1 Byte  exact 8-bit  unsigned value, Architecture dependent */
typedef Us_Arch                        U16_Cfg; /* 2 Bytes exact 16-bit unsigned value, Architecture dependent */
typedef Ui_Arch                        U32_Cfg; /* 4 Bytes exact 32-bit unsigned value, Architecture dependent */
typedef Ull_Arch                       U64_Cfg; /* 8 Bytes exact 64-bit unsigned value, Architecture dependent */

/**************************************************************************************************
 * 2. DataType: Signed primitive types (architecture-defined widths)
 * Configure: Which size your platform supports
 * Configuration: 
 * Sc_Arch
 * Ss_Arch
 * Si_Arch
 * Sl_Arch
 * Sll_Arch
 *************************************************************************************************/
typedef Sc_Arch                        S8_Cfg;  /* 1 Byte  exact 8-bit  signed value, Architecture dependent */
typedef Ss_Arch                        S16_Cfg; /* 2 Bytes exact 16-bit signed value, Architecture dependent */
typedef Si_Arch                        S32_Cfg; /* 4 Bytes exact 32-bit signed value, Architecture dependent */
typedef Sll_Arch                       S64_Cfg; /* 8 Bytes exact 64-bit signed value, Architecture dependent */

/**************************************************************************************************
 * 3. Datatype: Floating point types (architecture-defined widths)
 * Configure: Which size your platform supports
 * Configuration:
 * Float_Arch    
 * Double_Arch   
 * LongDouble_Arch
 *************************************************************************************************/
typedef Float_Arch                     F32_Cfg;  /* Single precision, 4 Bytes exact 32-bit value, Architecture dependent */    
typedef Double_Arch                    F64_Cfg;  /* Double precision, 8 Bytes exact 64-bit value, Architecture dependent */
typedef LongDouble_Arch                F128_Cfg; /* Extended precision, 16 Bytes exact 128-bit value, Compiler dependent */

/**************************************************************************************************
 * 4. Datatype: Boolean type (fixed-width boolean storage)
 * Configure: Which size your platform supports
 * Configuration:
 * Boolean_Arch
 * Bool_Arch
 *************************************************************************************************/
typedef Boolean_Arch                   Bool8_Cfg; /* Always storage 1 unit, 1 Byte  exact 8-bit  boolean value, Architecture dependent */

/*************************************************************************************************
 * 5. Datatype: Pointer to unsigned types (architecture-defined pointer width)
 * Configure: Which size your platform supports
 * Configuration:
 * UcPtr_Arch 
 * UsPtr_Arch 
 * UiPtr_Arch 
 * UlPtr_Arch 
 * UllPtr_Arch
 *************************************************************************************************/
typedef UcPtr_Arch                     U8_Ptr_Cfg;  /* Pointer to unsinged char:      1 Byte exact 8-bit,  pointer size 4 bytes Architecture depended */
typedef UsPtr_Arch                     U16_Ptr_Cfg; /* Pointer to unsinged short:     2 Byte exact 16-bit, pointer size 4 bytes Architecture depended */
typedef UiPtr_Arch                     U32_Ptr_Cfg; /* Pointer to unsinged int:       4 Byte exact 32-bit, pointer size 4 bytes Architecture depended */
typedef UllPtr_Arch                    U64_Ptr_Cfg; /* Pointer to unsinged long long: 8 Byte exact 64-bit, pointer size 4 bytes Architecture depended */            

/**************************************************************************************************
 * 6. Datatype: Pointer to signed types (architecture-defined pointer width)
 * Configure: Which size your platform supports
 * Configuration:
 * ScPtr_Arch
 * SsPtr_Arch
 * SiPtr_Arch
 * SlPtr_Arch
 * SllPtr_Arch
 *************************************************************************************************/
typedef ScPtr_Arch                     S8_Ptr_Cfg;  /* Pointer to singed char:      1 Byte exact 8-bit,  pointer size 4 bytes Architecture depended */
typedef SsPtr_Arch                     S16_Ptr_Cfg; /* Pointer to singed short:     2 Byte exact 16-bit, pointer size 4 bytes Architecture depended */
typedef SiPtr_Arch                     S32_Ptr_Cfg; /* Pointer to singed int:       4 Byte exact 32-bit, pointer size 4 bytes Architecture depended */
typedef SllPtr_Arch                    S64_Ptr_Cfg; /* Pointer to singed long long: 8 Byte exact 64-bit, pointer size 4 bytes Architecture depended */

/**************************************************************************************************
 * 7. Datatype: Pointer to Precision point types (architecture-defined pointer width)
 * Configure: Which size your platform supports
 * Configuration:
 * FloatPtr_Arch;    
 * DoublePtr_Arch;    
 * LongDoublePtr_Arch
 *************************************************************************************************/
typedef FloatPtr_Arch                  F32_Ptr_Cfg;  /* Single precision,   Pointer to 4 Bytes exact 32-bit value, Architecture dependent */
typedef DoublePtr_Arch                 F64_Ptr_Cfg;  /* Double precision,   Pointer to 8 Bytes exact 64-bit value, Architecture dependent */
typedef LongDoublePtr_Arch             F128_Ptr_Cfg; /* Extended precision, Pointer to 16 Bytes exact 128-bit value, Compiler dependent */ 

/**************************************************************************************************
 * 8. Configuration: Generic pointer type
 * Configure: Which size your platform supports
 * Configuration:
 * Ptr_Arch
 *************************************************************************************************/
typedef Ptr_Arch                       Void_Ptr_Cfg; /* Pointer to void size is Architecture dependent  */

#endif /* TYPESDEF_CFG_H */