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
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*
*--------------------------------------------------------------------------------------------
* - Author      : Mohamed Eid
* - File Name   : GPIO_Types.h
* - File Type   : Type Definition Header File
* - Module      : GPIO
* - Layer       : MCAL
* - Description : GPIO module data type definitions.
* - Design Note : Defines enums, structures, and type aliases used by GPIO.
* - Toolchain   : Independent
* - References  : None.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial GPIO type definitions
**********************************************************************************************************************************************************************************/


#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include "DataTypes.h"

/********************************************************************************************
 * Section: Macros Definition Section                                                      |
 * Description : GPIO-related macro definitions used by the GPIO types layer.               |
********************************************************************************************/

/********************************************************************************************
 * Section: GPIO Enum Types Section                                                         |
 * Description : Enumeration types defining logical GPIO configuration domains.             |
********************************************************************************************/

/*__________________________________________________________________________________________
 | Data Type Name : DataType_PortName                                                       |
 | Description    : Used to define GPIO port identifiers                                    |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 5                                                                   |
 | Usage          : GPIO configuration, register base address selection                     |
 | HW Mapping     : STM32 GPIOx base address selection                                      |
 |_________________________________________________________________________________________*/
typedef enum
{
    PortA = 0,
    PortB = 1,
    PortC = 2,
    PortD = 3,
    PortE = 4,
    PortH = 5
} DataType_PortName;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_PinNumber                                                      |
 | Description    : Used to define GPIO pin numbers within a port                           |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 15                                                                  |
 | Usage          : GPIO pin selection and bit position calculation                         |
 | HW Mapping     : STM32 GPIOx_MODER, IDR, ODR, BSRR bit fields                            |
 |_________________________________________________________________________________________*/
typedef enum
{
    Pin_0  = 0,
    Pin_1  = 1,
    Pin_2  = 2,
    Pin_3  = 3,
    Pin_4  = 4,
    Pin_5  = 5,
    Pin_6  = 6,
    Pin_7  = 7,
    Pin_8  = 8,
    Pin_9  = 9,
    Pin_10 = 10,
    Pin_11 = 11,
    Pin_12 = 12,
    Pin_13 = 13,
    Pin_14 = 14,
    Pin_15 = 15
} DataType_PinNumber;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Mode                                                           |
 | Description    : Used to define GPIO pin operating mode                                  |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 3                                                                   |
 | Usage          : GPIO pin mode configuration                                             |
 | HW Mapping     : STM32 GPIOx_MODER register                                              |
 |_________________________________________________________________________________________*/
typedef enum
{
    Input_Mode              = 0,
    Output_Mode             = 1,
    Alternate_Function_Mode = 2,
    Analog_Mode             = 3
} DataType_Mode;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_OutputType                                                     |
 | Description    : Used to define GPIO output driver type                                  |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 1                                                                   |
 | Usage          : GPIO output driver configuration                                        |
 | HW Mapping     : STM32 GPIOx_OTYPER register                                             |
 |_________________________________________________________________________________________*/
typedef enum
{
    Output_Push_Pull  = 0,
    Output_Open_Drain = 1
} DataType_OutputType;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_OutputSpeed                                                    |
 | Description    : Used to define GPIO output speed configuration                          |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 3                                                                   |
 | Usage          : GPIO output speed configuration                                         |
 | HW Mapping     : STM32 GPIOx_OSPEEDR register                                            |
 |_________________________________________________________________________________________*/
typedef enum
{
    Low_Speed    = 0,
    Medium_Speed = 1,
    Fast_Speed   = 2,
    High_Speed   = 3
} DataType_OutputSpeed;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_ResistanceConnection                                           |
 | Description    : Used to define GPIO pull-up / pull-down configuration                   |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 2                                                                   |
 | Usage          : GPIO input/output pull configuration                                    |
 | HW Mapping     : STM32 GPIOx_PUPDR register                                              |
 |_________________________________________________________________________________________*/
typedef enum
{
    Resistance_NotConnected       = 0,
    Pullup_Resistance_Connected   = 1,
    PullDown_Resistance_Connected = 2
} DataType_ResistanceConnection;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_OutputStatusSetup                                              |
 | Description    : Used to define initial GPIO output level                                |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 1                                                                   |
 | Usage          : GPIO initial output state during initialization                         |
 | HW Mapping     : STM32 GPIOx_ODR, GPIOx_BSRR registers                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Reset_Pin = 0,
    Set_Pin   = 1
} DataType_OutputStatusSetup;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_LockKey                                                        |
 | Description    : Used to define GPIO lock key activation state                           |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 1                                                                   |
 | Usage          : GPIO port configuration lock control                                    |
 | HW Mapping     : STM32 GPIOx_LCKR register                                               |
 |_________________________________________________________________________________________*/
typedef enum
{
    UnActive = 0,
    Active   = 1
} DataType_LockKey;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_ConfigurationLock                                              |
 | Description    : Used to define GPIO configuration lock status                           |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 1                                                                   |
 | Usage          : GPIO configuration state reporting                                      |
 | HW Mapping     : STM32 GPIOx_LCKR register                                               |
 |_________________________________________________________________________________________*/
typedef enum
{
    Configuration_UnLocked = 0,
    Configuration_Locked   = 1
} DataType_ConfigurationLock;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_KeyStatus                                                      |
 | Description    : Used to define GPIO lock key operation result                           |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 2                                                                   |
 | Usage          : GPIO lock operation result reporting                                    |
 | HW Mapping     : STM32 GPIOx_LCKR register                                               |
 |_________________________________________________________________________________________*/
typedef enum
{
    Key_UnLocked = 0,
    Key_Locked   = 1,
    Key_Error    = 2
} DataType_KeyStatus;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_AlternateFunction                                              |
 | Description    : Used to define GPIO alternate function selection (AF0–AF15)             |
 | Type           : Enum                                                                    |
 | Storage        : None (only variables of this type are stored)                           |
 | Size           : Implementation-defined when used as an object (typically 4 bytes)       |
 | Valid Range    : 0 – 15                                                                  |
 | Usage          : GPIO alternate function configuration                                   |
 | HW Mapping     : STM32 GPIOx_AFRL, GPIOx_AFRH registers                                  |
 |_________________________________________________________________________________________*/
typedef enum
{
    Alternate_Function_0  = 0,
    Alternate_Function_1  = 1,
    Alternate_Function_2  = 2,
    Alternate_Function_3  = 3,
    Alternate_Function_4  = 4,
    Alternate_Function_5  = 5,
    Alternate_Function_6  = 6,
    Alternate_Function_7  = 7,
    Alternate_Function_8  = 8,
    Alternate_Function_9  = 9,
    Alternate_Function_10 = 10,
    Alternate_Function_11 = 11,
    Alternate_Function_12 = 12,
    Alternate_Function_13 = 13,
    Alternate_Function_14 = 14,
    Alternate_Function_15 = 15
} DataType_AlternateFunction;

/***************************************************************************************************************************************************
 * Section: GPIO Data Types and Register Definitions Section
 * Description : GPIO-related data types, configuration structures, and register mappings.
 * Notes       : This section contains both hardware-mapped and software-only data types.
 ***************************************************************************************************************************************************/

/*__________________________________________________________________________________________
 | Data Type Name : DataType_Registers                                                      |
 | Description    : Memory-mapped structure representing GPIO peripheral registers          |
 | Type           : Struct                                                                  |
 | Storage        : Memory-mapped I/O (MMIO), peripheral address space                      |
 | Size           : 40 bytes (10 registers × 4 bytes)                                       |
 | Usage          : Direct GPIO register access via base address casting                    |
 | HW Mapping     : STM32 GPIOx register map (Reference Manual)                             |
 | Access Type    : Volatile, hardware-controlled                                           |
 | Alignment      : 32-bit aligned                                                          |
 | Endianness     : Little-endian (ARM Cortex-M)                                            |
 | Safety Notes   : - Field order MUST match hardware layout                                |
 |                : - BSRR is write-only and atomic                                         |
 |_________________________________________________________________________________________*/
typedef struct
{
    volatile DataType_u32 Gpio_Moder;
    volatile DataType_u32 Gpio_Otyper;
    volatile DataType_u32 Gpio_Ospeedr;
    volatile DataType_u32 Gpio_Pupdr;
    volatile const DataType_u32 Gpio_Idr;
    volatile DataType_u32 Gpio_Odr;
    volatile DataType_u32 Gpio_Bsrr;
    volatile DataType_u32 Gpio_Lckr;
    volatile DataType_u32 Gpio_Afrl;
    volatile DataType_u32 Gpio_Afrh;
} DataType_Registers;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_PinConfiguration                                               |
 | Description    : Logical GPIO pin configuration container                                |
 | Type           : Struct                                                                  |
 | Storage        : RAM or Flash (depends on object declaration)                            |
 | Size           : 36 bytes (9 enum fields × 4 bytes, ARM-GCC typical)                     |
 | Usage          : GPIO initialization and configuration logic                             |
 | HW Mapping     : Indirect (used to program GPIOx registers)                              |
 | Lifetime       : Typically static; read-only after initialization                        |
 | Notes          : Enum-based fields provide compile-time domain validation                |
 |_________________________________________________________________________________________*/
typedef struct
{
    DataType_PortName              Port_Id;
    DataType_PinNumber             Pin_Id;
    DataType_Mode                  Pin_Mode;
    DataType_OutputType            Pin_Output_Type;
    DataType_OutputSpeed           Pin_Output_Speed;
    DataType_ResistanceConnection  Pin_Resitances_Connection;
    DataType_Output_Level          Pin_Output_Status_Setup;
    DataType_ConfigurationLock     Pin_Configuration_Lock_Status;
    DataType_AlternateFunction     Pin_Alternate_Function;
} DataType_PinConfiguration;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_PortLockKey                                                    |
 | Description    : GPIO port lock key command configuration container                      |
 | Type           : Struct                                                                  |
 | Storage        : RAM or Flash                                                            |
 | Size           : 8 bytes (2 enum fields × 4 bytes, ARM-GCC typical)                      |
 | Usage          : GPIO port configuration lock operation                                  |
 | HW Mapping     : STM32 GPIOx_LCKR register                                               |
 | Lifetime       : Temporary (used during lock sequence)                                   |
 | Notes          : Input structure for lock API                                            |
 |_________________________________________________________________________________________*/
typedef struct
{
    DataType_PortName Port_Id;
    DataType_LockKey  Port_Configuration_Lock_Key;
} DataType_PortLockKey;

/*__________________________________________________________________________________________
 | Data Type Name : DataType_PortLockStatus                                                 |
 | Description    : GPIO port lock status reporting container                               |
 | Type           : Struct                                                                  |
 | Storage        : RAM                                                                     |
 | Size           : 8 bytes (2 enum fields × 4 bytes, ARM-GCC typical)                      |
 | Usage          : GPIO port lock result reporting                                         |
 | HW Mapping     : STM32 GPIOx_LCKR register                                               |
 | Lifetime       : Temporary / runtime                                                     |
 | Notes          : Output/result structure from lock API                                   |
 |_________________________________________________________________________________________*/
typedef struct
{
    DataType_PortName  Port_Id;
    DataType_KeyStatus Port_Key_Status;
} DataType_PortLockStatus;

/***************************************************************************************************************************************************
 * Section: GPIO Register Access Type Definitions Section
 * Description : Type definitions related to GPIO register access and abstraction.
 * Notes       : This section defines register pointer abstraction types.
 ***************************************************************************************************************************************************/

/*__________________________________________________________________________________________
 | Data Type Name : DataType_GpioRegisters                                                  |
 | Description    : Constant pointer to volatile GPIO register structure                    |
 | Type           : Typedef (pointer type)                                                  |
 | Storage        : RAM (pointer variable when instantiated)                                |
 | Size           : Architecture-dependent (32-bit on Cortex-M)                             |
 | Usage          : Access GPIO hardware registers via base address mapping                 |
 | HW Mapping     : STM32 GPIOx register space                                              |
 | Lifetime       : Static or runtime (depends on declaration)                              |
 | Notes          : - Volatile enforces hardware access semantics                           |
 |                : - const prevents pointer reassignment                                   |
 |_________________________________________________________________________________________*/
typedef volatile DataType_Registers * DataType_GpioRegisters;

#endif /* GPIO_TYPES_H */
