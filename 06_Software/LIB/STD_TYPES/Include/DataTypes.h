/**********************************************************************************************************************************************************************************
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
*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* - Author      : Mohamed Eid
* - File Name   : DataTypes.h
* - File Type   : Header File
* - Module      : STD_TYPES
* - Layer       : Libraries
* - Visibility  : Public (shared across all layers)
* - Description : Platform-independent basic data type definitions.
*                 Provides fixed-width integer types, pointer abstractions casting helpers, generic memory macros, and common status enums.
* - Design Note : This file defines semantic meaning and storage contracts only no hardware access or logic shall be placed here.
* - Toolchain   : GCC-ARM
* - References  : Compiler Manual, C99 Standard
*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* - Version History :
*  - 1.00.00|2025-12-01|Mohamed Eid: File Creation
**********************************************************************************************************************************************************************************/
#ifndef TYPESDEF_H
#define TYPESDEF_H

#include "DataTypes_Cfg.h"

/***********************************************************************************
 * Generic memory abstraction macros
 * Used to express intent for storage class, constness, and pointer qualification.
 * These macros do not allocate memory; they describe declaration semantics only.
 **********************************************************************************/
#define VAR(DataType, MemClass)                    DataType MemClass
#define CONST(DataType, MemClass)                  const DataType MemClass
#define STATIC_VAR(DataType)                       static DataType
#define STATIC_CONST(DataType)                     static const DataType
#define P2VAR(DataType, MemClass,PtrClass)         DataType * PtrClass
#define P2CONST(DataType, MemClass,PtrClass)       const DataType * PtrClass
#define CONSTP2VAR(DataType, MemClass,PtrClass)    DataType * const PtrClass
#define CONSTP2CONST(DataType, MemClass,PtrClass)  const DataType * const PtrClass
#define P2FUNC(ReturnType, PtrClass, FuncName)     ReturnType (* PtrClass FuncName)
#define CONSTP2FUNC(ReturnType, PtrClass, FuncName) ReturnType (* const PtrClass FuncName)
#define P2CONSTFUNC(ReturnType, PtrClass, FuncName) const ReturnType (* PtrClass FuncName)
#define P2VAR_ARRAY(DataType, MemClass, PtrClass)  DataType (* PtrClass)[]
#define P2CONST_ARRAY(DataType, MemClass, PtrClass) const DataType (* PtrClass)[]
#define P2REG(DataType, MemClass, PtrClass)        volatile DataType * PtrClass
#define CONSTP2REG(DataType, MemClass, PtrClass)   volatile DataType * const PtrClass

/***********************************************************************************
 * Explicit casting helper macros
 * Used to enforce intent and suppress implicit conversion warnings.
 * These macros affect type only and do not impact memory usage.
 **********************************************************************************/
#define U8_TYPECAST(Data)   (DataType_u8)(Data)
#define U16_TYPECAST(Data)  (DataType_u16)(Data)
#define U32_TYPECAST(Data)  (DataType_u32)(Data)

/***********************************************************************************
 * Common initialization and utility macros
 **********************************************************************************/
#define INITIALIZE_ZERO     0U

#define NULL_PTR            ((void*)0)

/**********************************************************************************
 * 1. Unsigned fixed-width integer data types
 * Storage size is guaranteed by platform configuration.
 **********************************************************************************/
typedef U8_Cfg   DataType_u8;   /* 1 byte  : exact 8-bit  unsigned integer */
typedef U16_Cfg  DataType_u16;  /* 2 bytes : exact 16-bit unsigned integer */
typedef U32_Cfg  DataType_u32;  /* 4 bytes : exact 32-bit unsigned integer */
typedef U64_Cfg  DataType_u64;  /* 8 bytes : exact 64-bit unsigned integer */

/**********************************************************************************
 * 2. Signed fixed-width integer data types
 **********************************************************************************/
typedef S8_Cfg   DataType_s8;   /* 1 byte  : exact 8-bit  signed integer */
typedef S16_Cfg  DataType_s16;  /* 2 bytes : exact 16-bit signed integer */
typedef S32_Cfg  DataType_s32;  /* 4 bytes : exact 32-bit signed integer */
typedef S64_Cfg  DataType_s64;  /* 8 bytes : exact 64-bit signed integer */

/**********************************************************************************
 * 3. Floating-point precision data types
 **********************************************************************************/
typedef F32_Cfg  DataType_f32;   /* 4 bytes  : 32-bit floating point */
typedef F64_Cfg  DataType_f64;   /* 8 bytes  : 64-bit floating point */
typedef F128_Cfg DataType_f128;  /* 16 bytes : 128-bit floating point */

/***********************************************************************************
 * 4. Boolean data type
 * Fixed-width boolean storage for deterministic memory layout.
 **********************************************************************************/
typedef Bool8_Cfg DataType_b8;  /* 1 byte : boolean value */

/**********************************************************************************
 * 5. Pointer types to unsigned data
 * Pointer width is architecture dependent.
 **********************************************************************************/
typedef U8_Ptr_Cfg   DataType_u8Ptr;
typedef U16_Ptr_Cfg  DataType_u16Ptr;
typedef U32_Ptr_Cfg  DataType_u32Ptr;
typedef U64_Ptr_Cfg  DataType_u64Ptr;

/***********************************************************************************
 * 6. Pointer types to signed data
 **********************************************************************************/
typedef S8_Ptr_Cfg   DataType_s8Ptr;
typedef S16_Ptr_Cfg  DataType_s16Ptr;
typedef S32_Ptr_Cfg  DataType_s32Ptr;
typedef S64_Ptr_Cfg  DataType_s64Ptr;

/***********************************************************************************
 * 7. Pointer types to floating-point data
 **********************************************************************************/
typedef F32_Ptr_Cfg  DataType_f32Ptr;
typedef F64_Ptr_Cfg  DataType_f64Ptr;
typedef F128_Ptr_Cfg DataType_f128Ptr;

/***********************************************************************************
 * 8. Generic pointer type
 **********************************************************************************/
typedef Void_Ptr_Cfg DataType_vPtr; /* Pointer to unspecified type */

/***********************************************************************************
 * 9. Register-sized aliases
 * Used to express register access width explicitly.
 **********************************************************************************/
typedef DataType_u8  DataType_Register_Size8;
typedef DataType_u16 DataType_Register_Size16;
typedef DataType_u32 DataType_Register_Size32;
typedef DataType_u64 DataType_Register_Size64;

/***********************************************************************************
 * 10. Common platform enums
 * These enums provide semantic meaning for states, flags, and results.
 **********************************************************************************/

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Input_Status                                                   |
 | Description    : Logical digital input signal state                                      |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Represent sampled or logical input states                               |
 | Lifetime       : Runtime (depends on variable usage)                                     |
 | Notes          : Binary semantic abstraction for readability and validation              |
 |_________________________________________________________________________________________*/
typedef enum
{
    Off = 0,
    On  = 1
} DataType_Input_Status;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Usage                                                          |
 | Description    : Resource usage state indicator                                          |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Track allocation or ownership of software or hardware resources         |
 | Lifetime       : Runtime                                                                 |
 | Notes          : Commonly used for validation and conflict detection                     |
 |_________________________________________________________________________________________*/
typedef enum
{
    Unused = 0,
    Used   = 1
} DataType_Usage;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Status_Flag                                                    |
 | Description    : Generic binary status flag                                              |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Represent logical flags, conditions, or internal states                 |
 | Lifetime       : Runtime                                                                 |
 | Notes          : Used to improve clarity over raw boolean values                         |
 |_________________________________________________________________________________________*/
typedef enum
{
    Flag_NotSet = 0,
    Flag_Set    = 1
} DataType_Status_Flag;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Output_Level                                                   |
 | Description    : Logical digital output signal level                                     |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Configure or represent GPIO output states                               |
 | Lifetime       : Runtime                                                                 |
 | Notes          : Abstracts electrical level into semantic form                           |
 |_________________________________________________________________________________________*/
typedef enum
{
    Low  = 0,
    High = 1
} DataType_Output_Level;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Validity                                                       |
 | Description    : Generic data validity indicator                                         |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Validate configuration data, parameters, or results                     |
 | Lifetime       : Runtime                                                                 |
 | Notes          : Commonly used in configuration and diagnostic checks                    |
 |_________________________________________________________________________________________*/
typedef enum
{
    InValid = 0,
    Valid   = 1
} DataType_Validity;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Detection                                                      |
 | Description    : Detection status indicator                                              |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Indicate whether a condition, event, or signal was detected             |
 | Lifetime       : Runtime                                                                 |
 | Notes          : Often used in diagnostics, monitoring, and safety logic                 |
 |_________________________________________________________________________________________*/
typedef enum
{
    Not_Detected = 0,
    Detected     = 1
} DataType_Detection;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_State                                                          |
 | Description    : Generic enable/disable state                                            |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Control or represent module, feature, or signal states                  |
 | Lifetime       : Runtime                                                                 |
 | Notes          : Preferred over raw boolean for clarity                                  |
 |_________________________________________________________________________________________*/
typedef enum
{
    Disable = 0,
    Enable  = 1
} DataType_State;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Request_Status                                                 |
 | Description    : Standardized API return status                                          |
 | Type           : Enum                                                                    |
 | Storage        : None (values only; stored only when used in variables)                  |
 | Size           : Compiler-dependent (typically 4 bytes, ARM-GCC)                         |
 | Usage          : Returned by service interfaces across modules                           |
 | Lifetime       : Temporary (per API call)                                                |
 | Notes          : Enables unified error handling and diagnostics across layers            |
 |_________________________________________________________________________________________*/
typedef enum
{
    Unkown = 0,
    Success,
    Accepted,
    Busy,
    Invalid,
    Invalid_Parameter,
    Null_Pointer,
    Error
} DataType_Request_Status;


#endif /* TYPESDEF_H */
