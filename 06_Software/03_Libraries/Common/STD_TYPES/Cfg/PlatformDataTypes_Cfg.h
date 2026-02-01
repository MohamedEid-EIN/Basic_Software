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
* - Description : This file is used to define all used data types,
*                 All sizes based on Architecture or compiler dependent.
* - Author      : Mohamed Eid
* - File Name   : PlatformDataTypes_Cfg.h
* - File Type   : Header file
* - References  : TBD
* - Toolchain   : TBD
* - Version     : History
* - 1.00.00     : File Creation
********************************************************************************************/
#ifndef PLATFORMDATATYPES_CFG_H
#define PLATFORMDATATYPES_CFG_H

#include "PlatformTypes.h"

/**********************************************************************************
 * 1. Platform ENDIANNESS (architecture-defined widths)
 **********************************************************************************/
#define PLATFORM_LITTLE_ENDIAN    1u
#define PLATFORM_BIGENDIAN        0u


/**********************************************************************************
 * 2. CPU Register width
 **********************************************************************************/
#define PLATFORM_CPU_REGISTER_SIZE         4
#define PLATFORM_CPU_BIT_ORDER_MSB_FIRST   0
#define PLATFORM_CPU_BIT_ORDER_LSB_FIRST   1

#endif /* PLATFORMDATATYPES_CFG_H */