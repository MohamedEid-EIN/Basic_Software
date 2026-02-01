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
* - Description: This file is used to define all used data types ( All sizes based on Architecture or compiler dependent).
* - Author      : Mohamed Eid
* - File Name   : DataTypes.h
* - File Type   : Header file
* - References  : Compiler Manual
* - Toolchain   : TBD
* - Version : History
* - 1.00.00 : File Creation
********************************************************************************************/

#include "DataTypes_Cfg.h"

#ifndef TYPESDEF_H
#define TYPESDEF_H

/***********************************************************************************
 * Generic data types macros used for specifc memory placing                    *
 **********************************************************************************/
#define VAR(DataType, MemClass) DataType MemClass
#define CONST(DataType, MemClass) const DataType MemClass
#define STATIC_VAR(DataType) static DataType
#define STATIC_CONST(DataType) static const DataType
#define P2VAR(DataType, MemClass,PtrClass) DataType * PtrClass
#define P2CONST(DataType, MemClass,PtrClass) const DataType * PtrClass
#define CONSTP2VAR(DataType, MemClass,PtrClass) DataType * const PtrClass
#define CONSTP2CONST(DataType, MemClass,PtrClass) const DataType * const PtrClass
#define P2FUNC(ReturnType, PtrClass, FuncName) ReturnType (* PtrClass FuncName)
#define CONSTP2FUNC(ReturnType, PtrClass, FuncName) ReturnType (* const PtrClass FuncName)
#define P2CONSTFUNC(ReturnType, PtrClass, FuncName) const ReturnType (* PtrClass FuncName)
#define P2VAR_ARRAY(DataType, MemClass, PtrClass) DataType (* PtrClass) []
#define P2CONST_ARRAY(DataType, MemClass, PtrClass) const DataType (* PtrClass) []
#define P2REG(DataType, MemClass, PtrClass) volatile DataType * PtrClass
#define CONSTP2REG(DataType, MemClass, PtrClass) volatile DataType * const PtrClass


#define INITIALIZE_ZERO 0U

#define STATE_UNDEFINDED      (DataType_u32)0x00000000U
#define STATE_UNINTIALIZED    (DataType_u32)0x11111111U
#define STATE_INITIALIZED     (DataType_u32)0x22222222U
#define STATE_DEINITIALIZED   (DataType_u32)0x33333333U
#define STATE_LOW_POWER       (DataType_u32)0x44444444U
#define STATE_SAFE            (DataType_u32)0x55555555U
#define STATE_SLEEP           (DataType_u32)0x66666666U
#define STATE_READY           (DataType_u32)0x77777777U
#define STATE_BUSY            (DataType_u32)0x88888888U
#define STATE_ERROR           (DataType_u32)0x99999999U

/**********************************************************************************
 * utilites MACROS
 **********************************************************************************/
#define NULL_PTR            ((void*)0)


/**********************************************************************************
 * 1. Unsigned Data types                                                         *
 **********************************************************************************/
typedef U8_Cfg          DataType_u8;  /* 1 Byte  exact 8-bit  unsigned value */
typedef U16_Cfg         DataType_u16; /* 2 Bytes exact 16-bit unsigned value */
typedef U32_Cfg         DataType_u32; /* 4 Bytes exact 32-bit unsigned value */
typedef U64_Cfg         DataType_u64; /* 8 Bytes exact 64-bit unsigned value */
      
/**********************************************************************************
 * 2. Signed Data types                                                           *
 **********************************************************************************/
typedef S8_Cfg          DataType_s8;  /* 1 Byte  exact 8-bit  signed value */
typedef S16_Cfg         DataType_s16; /* 2 Bytes exact 16-bit signed value */
typedef S32_Cfg         DataType_s32; /* 4 Bytes exact 32-bit signed value */
typedef S64_Cfg         DataType_s64; /* 8 Bytes exact 64-bit signed value */

/**********************************************************************************
 * 3. Precision points data types                                                 *
 *********************************************************************************/
typedef F32_Cfg         DataType_f32;  /* 4 Bytes  exact 32-bit  Precision value */
typedef F64_Cfg         DataType_f64;  /* 8 Bytes  exact 64-bit  Precision value */
typedef F128_Cfg        DataType_f128; /* 16 Bytes exact 128-bit Precision value */

/***********************************************************************************
 * 4. Boolean type (fixed-width boolean storage)                                   *
 **********************************************************************************/
typedef Bool8_Cfg       DataType_b8; /* 1 Byte exact 8-bit boolean value */

/**********************************************************************************
 * 5. Pointer to unsigned types (architecture-defined pointer width)              *
 *********************************************************************************/
typedef U8_Ptr_Cfg      DataType_u8Ptr;  /* Pointer to 1 Byte  exact 8-bit  unsigned value */
typedef U16_Ptr_Cfg     DataType_u16Ptr; /* Pointer to 2 Byte  exact 16-bit unsigned value */
typedef U32_Ptr_Cfg     DataType_u32Ptr; /* Pointer to 4 Byte  exact 32-bit unsigned value */
typedef U64_Ptr_Cfg     DataType_u64Ptr; /* Pointer to 8 Byte  exact 64-bit unsigned value */

/***********************************************************************************
 * 6. Pointer to signed types (architecture-defined pointer width)                 *
 **********************************************************************************/
typedef S8_Ptr_Cfg      DataType_s8Ptr;  /* Pointer to 1 Byte  exact 8-bit  signed value */
typedef S16_Ptr_Cfg     DataType_s16Ptr; /* Pointer to 2 Byte  exact 16-bit signed value */
typedef S32_Ptr_Cfg     DataType_s32Ptr; /* Pointer to 4 Byte  exact 32-bit signed value */
typedef S64_Ptr_Cfg     DataType_s64Ptr; /* Pointer to 8 Byte  exact 64-bit signed value */ 

/***********************************************************************************
 * 7. Pointer to Precision point types (architecture-defined pointer width)        *
 **********************************************************************************/
typedef F32_Ptr_Cfg     DataType_f32Ptr;  /* Pointer to 4 Bytes  exact 32-bit  Precision value */
typedef F64_Ptr_Cfg     DataType_f64Ptr;  /* Pointer to 8 Bytes  exact 64-bit  Precision value */
typedef F128_Ptr_Cfg    DataType_f128Ptr; /* Pointer to 16 Bytes exact 128-bit Precision value */

/***********************************************************************************
 * 8. Generic pointer type                                                         *
 **********************************************************************************/
typedef Void_Ptr_Cfg    DataType_vPtr; /* Pointer to void size is Architecture dependent */

typedef DataType_u8  DataType_Register_Size8;
typedef DataType_u16 DataType_Register_Size16;
typedef DataType_u32 DataType_Register_Size32;
typedef DataType_u64 DataType_Register_Size64;


/***********************************************************************************
 * 10. Internal types for Platform                                                 *
 **********************************************************************************/
/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Off = 0,
    On = 1
}DataType_Input_Status;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Unused = 0,
    Used = 1
}DataType_Usage;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Flag_NotSet = 0,
    Flag_Set = 1
}DataType_Status_Flag;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Low = 0,
    High = 1
}DataType_Output_Level;

typedef enum
{
    InValid = 0,
    Valid = 1
}DataType_Validity;

typedef enum
{
    Not_Detected = 0,
    Detected = 1
}DataType_Detection;

typedef enum
{
    Disable = 0,
    Enable = 1
}DataType_State;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
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
}DataType_Request_Status;
  
#endif /* TYPESDEF_H */