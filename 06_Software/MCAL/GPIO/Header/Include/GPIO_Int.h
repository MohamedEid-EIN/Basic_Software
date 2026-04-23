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
* - File Name   : GPIO_Int.h
* - File Type   : Interface File
* - Module      : GPIO
* - Layer       : MCAL
* - Description : GPIO internal service interface for upper layers.
* - Design Note : Provides GPIO APIs to HAL and application layers.
* - Toolchain   : Independent
* - References  : None.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|------------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial GPIO interface definition
**********************************************************************************************************************************************************************************/


#ifndef GPIO_INT_H
#define GPIO_INT_H

#include "DataTypes.h"

/**********************************************************************************************************************************************************
 * GPIO Service Identifiers
 *********************************************************************************************************************************************************/
/*_________________________________________________________________________________________
| Interface Name: GPIO pins identifiers                                                    |
| Description : Logical GPIO pin identifiers used by higher software layers.               |
| Notes :                                                                                  |
|   - These identifiers are abstract and do NOT represent physical MCU pin numbers.        |
|   - Mapping between SignalId and actual Port/Pin is defined in GPIO_Cfg.c.               |
|   - Upper layers must never assume a direct Port/Pin relationship.                       |
|_________________________________________________________________________________________*/
#define GPIO_PIN_A0    U8_TYPECAST(0U)
#define GPIO_PIN_A1    U8_TYPECAST(GPIO_PIN_A0  + 1U)
#define GPIO_PIN_A2    U8_TYPECAST(GPIO_PIN_A1  + 1U)
#define GPIO_PIN_A3    U8_TYPECAST(GPIO_PIN_A2  + 1U)
#define GPIO_PIN_A4    U8_TYPECAST(GPIO_PIN_A3  + 1U)
#define GPIO_PIN_A5    U8_TYPECAST(GPIO_PIN_A4  + 1U)
#define GPIO_PIN_A6    U8_TYPECAST(GPIO_PIN_A5  + 1U)
#define GPIO_PIN_A7    U8_TYPECAST(GPIO_PIN_A6  + 1U)
#define GPIO_PIN_A8    U8_TYPECAST(GPIO_PIN_A7  + 1U)
#define GPIO_PIN_A9    U8_TYPECAST(GPIO_PIN_A8  + 1U)
#define GPIO_PIN_A10   U8_TYPECAST(GPIO_PIN_A9  + 1U)
#define GPIO_PIN_A11   U8_TYPECAST(GPIO_PIN_A10 + 1U)
#define GPIO_PIN_A12   U8_TYPECAST(GPIO_PIN_A11 + 1U)
#define GPIO_PIN_A13   U8_TYPECAST(GPIO_PIN_A12 + 1U)
#define GPIO_PIN_A14   U8_TYPECAST(GPIO_PIN_A13 + 1U)
#define GPIO_PIN_A15   U8_TYPECAST(GPIO_PIN_A14 + 1U)

/* Total number of configured logical GPIO pins */
#define GPIO_MAX_PIN_CFG  U8_TYPECAST(GPIO_PIN_A15 + 1U)

/*__________________________________________________________________________________________
| Interface Name : GPIO port identifiers                                                   |
| Description    : Logical GPIO port identifiers used for grouped GPIO operations.         |
| Notes          :                                                                         |
|   - These identifiers represent logical GPIO ports (e.g. PORTA, PORTB).                  |
|   - Each port maps directly to a physical GPIO port on the MCU.                          |
|   - Intended for port-level services such as bulk output or diagnostics.                 |
|   - Upper layers must not assume any pin-level configuration from port identifiers.      |
|_________________________________________________________________________________________*/
#define GPIO_PORTA   U32_TYPECAST(0U)

/* Total number of configured GPIO ports */
#define GPIO_MAX_PORT U32_TYPECAST(GPIO_PORTA + 1U)

/**********************************************************************************************************************************************************
 * GPIO Service APIS
 *********************************************************************************************************************************************************/
/*__________________________________________________________________________________________
| Function Name : GPIO_Intitialization                                                     |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Initializes the GPIO module using static configuration data              |
|                 defined in GPIO_Cfg.c.                                                   |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Non-Reentrant                                                            |
| Parameters    : None                                                                     |
| Return        : DataType_Request_Status                                                  |
| Preconditions : MCU clock and RCC must be initialized, ClockModuleState = Ready          |
| Postconditions: GPIO pins are configured and GpioModuleState = Initialized               |
| Usage         : Services to initialize GPIO registers and apply user pin configurations  |
| Context       : Startup / MCU context                                                    |
| Notes         : NA                                                                       |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_Intitialization(void);

/*__________________________________________________________________________________________
| Function Name : GPIO_GetModuleState                                                      |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Returns the current internal GPIO module state                           |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Reentrant                                                                |
| Parameters    : None                                                                     |
| Return        : DataType_u32 (current module state)                                      |
| Preconditions : None                                                                     |
| Usage         : Service to Get GPIO module states                                        |
| Context       : MCU context                                                              |
| Notes         : Intended for diagnostic and state checks                                 |
|_________________________________________________________________________________________*/
DataType_u32 GPIO_GetModuleState(void);

/*__________________________________________________________________________________________
| Function Name : GPIO_WritePort                                                           |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Writes a full 8-bit value to a GPIO port                                 |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Non-Reentrant                                                            |
| Parameters    : Input : PortId                                                           |
|               : Input : PortValue                                                        |
| Return        : DataType_Request_Status                                                  |
| Preconditions : GPIO module must be initialized and GPIO ModuleState = Ready             |
| Usage         : Services to Write an entire GPIO port in one operation                   |
| Context       : MCU context                                                              |
| Notes         : Affects all pins of the selected port                                    |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_WritePort(DataType_u8 Index, DataType_u16 PortValue);

/*__________________________________________________________________________________________
| Function Name : GPIO_WritePin                                                            |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Writes a logical level to a specific GPIO pin                            |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Reentrant (different PinId)                                              |
| Parameters    : Input : PinId                                                            |
|               : Input : SignalValue                                                      |
| Return        : DataType_Request_Status                                                  |
| Preconditions : GPIO module must be initialized and GPIO ModuleState = Ready             |
| Usage         : Services to set or clear a specific GPIO pin                             |
| Context       : MCU context                                                              |
| Notes         : Valid only for pins configured as output                                 |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_WritePin(DataType_u8 Index, DataType_Output_Level PinValue);

/*__________________________________________________________________________________________
| Function Name : GPIO_ReadPin                                                             |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Reads the logical level of a specific GPIO pin                           |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Reentrant (different PinId)                                              |
| Parameters    : Input  : PinId                                                           |
|               : Output : PinValue                                                        |
| Return        : DataType_Request_Status                                                  |
| Preconditions : GPIO module must be initialized and GPIO ModuleState = Ready             |
| Usage         : Services to read the current level of a specific GPIO pin                |
| Context       : MCU context                                                              |
| Notes         : Works for both input and output pins                                     |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_ReadPin(DataType_u8 Index, DataType_Output_Level* PinValue);

/*__________________________________________________________________________________________
| Function Name : GPIO_ToggelPin                                                           |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Toggles the output level of a specific GPIO pin                          |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Reentrant (different PinId)                                              |
| Parameters    : Input : PinId                                                            |
| Return        : DataType_Request_Status                                                  |
| Preconditions : GPIO module must be initialized and GPIO ModuleState = Ready             |
| Usage         : Services to toggle a specific GPIO pin                                   |
| Context       : MCU context                                                              |
| Notes         : Valid only for pins configured as output                                 |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_ToggelPin(DataType_u8 Index);

/*__________________________________________________________________________________________
| Function Name : GPIO_SetPin                                                              |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Sets a specific GPIO pin to logical HIGH                                 |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Reentrant (different PinId)                                              |
| Parameters    : Input : PinId                                                            |
| Return        : DataType_Request_Status                                                  |
| Preconditions : GPIO module must be initialized and GPIO ModuleState = Ready             |
| Usage         : Services to set a specific GPIO pin                                      |
| Context       : MCU context                                                              |
| Notes         : Valid only for pins configured as output                                 |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_SetPin(DataType_u8 Index);

/*__________________________________________________________________________________________
| Function Name : GPIO_ResetPin                                                            |
| Module        : GPIO                                                                     |
| Layer         : MCAL                                                                     |
| Description   : Resets a specific GPIO pin to logical LOW                                |
| Sync/Async    : Synchronous                                                              |
| Reentrancy    : Reentrant (different PinId)                                              |
| Parameters    : Input : PinId                                                            |
| Return        : DataType_Request_Status                                                  |
| Preconditions : GPIO module must be initialized and GPIO ModuleState = Ready             |
| Usage         : Services to reset a specific GPIO pin                                    |
| Context       : MCU context                                                              |
| Notes         : Valid only for pins configured as output                                 |
|_________________________________________________________________________________________*/
DataType_Request_Status GPIO_ResetPin(DataType_u8 Index);

#endif /* GPIO_INT_H */
