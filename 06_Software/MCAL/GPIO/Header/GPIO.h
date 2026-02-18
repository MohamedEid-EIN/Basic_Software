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
* - File Name   : GPIO.h
* - File Type   : Private Header File
* - Module      : GPIO
* - Layer       : MCAL
* - Description : Public GPIO module interface.
* - Design Note : Exposes GPIO services without hardware details.
* - Toolchain   : Independent
* - References  : None.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial public GPIO interface
**********************************************************************************************************************************************************************************/


#ifndef GPIO_H
#define GPIO_H

#include "GPIO_Types.h"

/********************************************************************************************
 * Section: Macros Definition Section
 * Description : Internal GPIO macros used for register access, configuration,
 *               and bit manipulation.
********************************************************************************************/

/*__________________________________________________________________________________________
 | Macro Name   : PORTx_BASE_ADDRESS                                                        |
 | Description  : Base address definitions for GPIO peripheral instances                    |
 | Type         : Macro                                                                     |
 | Storage      : N/A                                                                       |
 | Usage        : Casted to DataType_GpioRegisters for direct MMIO access                   |
 | HW Mapping   : STM32 GPIOx base addresses                                                |
 |_________________________________________________________________________________________*/
#define PORTA_BASE_ADDRESS ((DataType_GpioRegisters) 0x40020000U)
#define PORTB_BASE_ADDRESS ((DataType_GpioRegisters) 0x40020400U)
#define PORTC_BASE_ADDRESS ((DataType_GpioRegisters) 0x40020800U)
#define PORTD_BASE_ADDRESS ((DataType_GpioRegisters) 0x40020C00U)
#define PORTE_BASE_ADDRESS ((DataType_GpioRegisters) 0x40021000U)
#define PORTH_BASE_ADDRESS ((DataType_GpioRegisters) 0x40021C00U)

/*__________________________________________________________________________________________
 | Macro Name   : NUM_OF_PORTS                                                              |
 | Description  : Total number of supported GPIO ports                                      |
 | Type         : Macro                                                                     |
 | Storage      : N/A                                                                       |
 | Usage        : Used for array sizing and bounds checking                                 |
 |_________________________________________________________________________________________*/
#define HW_SUPPORTED_PORTS_NUM                 (DataType_u8)6U

/*__________________________________________________________________________________________
 | Macro Group  : GPIO Register Bit Definitions                                             |
 | Description  : Bit width and offset definitions for GPIO registers                       |
 | Usage        : Used in bit manipulation and register programming logic                   |
 |_________________________________________________________________________________________*/
#define REG_SIZE                     (DataType_u32)32U
#define REG_MODER_BITS               (DataType_u32)2U
#define REG_OSPEEDR_BITS             (DataType_u32)2U
#define REG_PUPDR_BITS               (DataType_u32)2U
#define REG_BSRR_RESET_BITS_OFFSET   (DataType_u32)16U
#define REG_AFRL_BITS                (DataType_u32)4U
#define REG_AFRH_BITS                (DataType_u32)4U
#define REG_AFRH_PINS_OFFSET         (DataType_u32)8U
#define REG_LCKR_LCKK_BIT            (DataType_u32)16U
#define REG_LCKR_LCKK_MASK           (DataType_u32)0x00010000U

/*__________________________________________________________________________________________
 | Macro Group  : Configuration Limits                                                      |
 | Description  : Maximum and minimum allowed configuration counts                          |
 | Usage        : Validation of configuration tables                                        |
 |_________________________________________________________________________________________*/
#define MAX_PIN_CONFIGURATION        (DataType_u8)96
#define MAX_PORT_CONFIGURATION       (DataType_u8)6
#define MIN_PIN_CONFIGURATION        (DataType_u8)1
#define MIN_PORT_CONFIGURATION       (DataType_u8)1

/*__________________________________________________________________________________________
 | Macro Group  : GPIO Lock Key Masks                                                       |
 | Description  : Bit masks used for GPIO port lock mechanism                               |
 | Usage        : Applied during GPIO lock sequence                                         |
 |_________________________________________________________________________________________*/
#define REG_LOCK_KEY_ACTIVE_MASK      (DataType_u32)0x00010000U
#define REG_LOCK_KEY_NOTACTIVE_MASK   (DataType_u32)0xFFFEFFFFU

/*__________________________________________________________________________________________
 | Macro Name   : IO_PIN_MASK                                                               |
 | Description  : Generic single-pin bit mask                                               |
 | Usage        : Used for pin-level operations                                             |
 |_________________________________________________________________________________________*/
#define IO_PIN_MASK                   (DataType_u32)1U

/*__________________________________________________________________________________________
 | Macro Group  : GPIO Critical Section Macros                                              |
 | Description  : Placeholders for OS / interrupt protection                                |
 | Usage        : Reserved for future concurrency protection                                |
 | Notes        : Currently empty by design                                                 |
 |_________________________________________________________________________________________*/
#define GPIO_ENTER_CRITICAL_SECTION()   void
#define GPIO_EXIT_CRITICAL_SECTION()    void
#define GPIO_PROTECT_SECTION()          void
#define GPIO_UNPROTECT_SECTION()        void

/********************************************************************************************
 * Section: Internal State and Tables Section
 * Description : Internal GPIO runtime state variables and lookup tables.
********************************************************************************************/

/*__________________________________________________________________________________________
 | Data Name    : PortLockKeyStatus_Table                                                   |
 | Description  : Runtime GPIO port lock status table                                       |
 | Type         : Array of DataType_PortLockStatus                                          |
 | Storage      : RAM                                                                       |
 | Size         : NUM_OF_PORTS entries                                                      |
 | Usage        : Tracks lock status of each GPIO port                                      |
 |_________________________________________________________________________________________*/
extern DataType_PortLockStatus PortLockStatus_Table[HW_SUPPORTED_PORTS_NUM];

/*__________________________________________________________________________________________
 | Data Name    : Registers_Table                                                           |
 | Description  : Lookup table mapping ports to GPIO register base addresses                |
 | Type         : Array of DataType_GpioRegisters                                           |
 | Storage      : RAM                                                                       |
 | Usage        : Internal hardware register access                                         |
 |_________________________________________________________________________________________*/
extern DataType_GpioRegisters Registers_Table[HW_SUPPORTED_PORTS_NUM];

/*__________________________________________________________________________________________
 | Data Name    : Port_Usage_Table                                                          |
 | Description  : Tracks whether each GPIO port is used                                     |
 | Type         : Array of DataType_Usage                                                   |
 | Storage      : RAM                                                                       |
 | Usage        : Prevents duplicate or invalid port usage                                  |
 |_________________________________________________________________________________________*/
extern DataType_Usage PortUsage_Table[HW_SUPPORTED_PORTS_NUM];

/*__________________________________________________________________________________________
 | Data Name    : GPIO_Module_State                                                         |
 | Description  : Global GPIO module state machine variable                                 |
 | Type         : DataType_u32                                                              |
 | Storage      : RAM                                                                       |
 | Usage        : Controls GPIO module lifecycle                                            |
 |_________________________________________________________________________________________*/
extern volatile DataType_u32 GPIO_Module_State;

/**********************************************************************************************************************************
 * Section: Function Prototype Definition
 **********************************************************************************************************************************/

/*_________________________________________________________________________________________
 | Function Name : GPIO_ConfigureRegisters                                                 |
 | Module        : GPIO                                                                    |
 | Layer         : MCAL                                                                    |
 | Description   : Writes shadow GPIO register values into hardware registers              |
 | Sync/Async    : Synchronous                                                             |
 | Reentrancy    : Non-Reentrant                                                           |
 | Parameters    : Input : Registers_Shadow                                                |
 | Return        : DataType_Request_Status                                                 |
 | Preconditions : GPIO must be initialized                                                |
 | Usage         : Internal initialization helper                                          |
 | Context       : Callable from MCU context                                               |
 |________________________________________________________________________________________*/
DataType_Request_Status GPIO_ConfigureRegisters(
    DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION]);

/*_________________________________________________________________________________________
 | Function Name : GPIO_PortLockInit                                                       |
 | Module        : GPIO                                                                    |
 | Layer         : MCAL                                                                    |
 | Description   : Executes GPIO port lock sequence                                        |
 | Sync/Async    : Synchronous                                                             |
 | Reentrancy    : Non-Reentrant                                                           |
 | Parameters    : Input : Registers_Shadow                                                |
 | Return        : DataType_Request_Status                                                 |
 | Preconditions : GPIO registers must be configured                                       |
 | Usage         : Internal initialization helper                                          |
 | Context       : Callable from MCU context                                               |
 |________________________________________________________________________________________*/
DataType_Request_Status GPIO_PortLockInit(
    DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION]);

/*__________________________________________________________________________________________
 | Function Name : GPIO_BuildConfiguration                                                  |
 | Module        : GPIO                                                                     |
 | Layer         : MCAL                                                                     |
 | Description   : Builds GPIO register shadow configuration from config tables             |
 | Sync/Async    : Synchronous                                                              |
 | Reentrancy    : Non-Reentrant                                                            |
 | Parameters    : Input : Registers_Shadow                                                 |
 | Return        : None                                                                     |
 | Preconditions : GPIO module must be initialized                                          |
 | Usage         : Internal configuration builder                                           |
 | Context       : Callable from MCU context                                                |
 |_________________________________________________________________________________________*/
void GPIO_BuildConfiguration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION]);

/*__________________________________________________________________________________________
 | Function Name : GPIO_SetModuleState                                                      |
 | Module        : GPIO                                                                     |
 | Layer         : MCAL                                                                     |
 | Description   : Updates the internal GPIO module state machine                           |
 | Sync/Async    : Synchronous                                                              |
 | Reentrancy    : Non-Reentrant                                                            |
 | Parameters    : Input : State                                                            |
 | Return        : DataType_Request_Status                                                  |
 | Preconditions : GPIO module must be initialized                                          |
 | Usage         : Internal state control                                                   |
 | Context       : MCU context                                                              |
 | Notes         : This API is intended for internal framework usage                        |
 |_________________________________________________________________________________________*/
DataType_Request_Status GPIO_SetModuleState(DataType_u32 State);

#endif /* GPIO_H */
