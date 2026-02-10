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
*--------------------------------------------------------------------------------------------
* - Author      : Mohamed Eid
* - File Name   : MCAL_Int.h
* - File Type   : Header File
* - Module      : MCAL
* - Layer       : MCAL
* - Description : MCAL public interface header exposing unified access to MCAL modules.
* - Design Note : Provides facade-style macros mapping MCAL APIs to underlying drivers.
*                 HAL and Application layers must include this file instead of driver headers.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial MCAL interface definition
**********************************************************************************************************************************************************************************/

#ifndef MCAL_INT_H
#define MCAL_INT_H

#include "DataTypes.h"
#include "GPIO_Int.h"

/********************************************************************************************************************************************************************
 * Section: GPIO Interfaces and APIs
 *******************************************************************************************************************************************************************/
/*__________________________________________________________________________________________
| MCAL GPIO Signal Definitions                                                             |
| Description  : Logical GPIO signals exposed to HAL and Application layers.               |
| Notes        : Upper layers must not use GPIO_PIN_x directly.                            |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_SIGNAL_0      GPIO_PIN_A0
#define MCAL_GPIO_SIGNAL_1      GPIO_PIN_A1
#define MCAL_GPIO_SIGNAL_2      GPIO_PIN_A2
#define MCAL_GPIO_SIGNAL_3      GPIO_PIN_A3
#define MCAL_GPIO_SIGNAL_4      GPIO_PIN_A4
#define MCAL_GPIO_SIGNAL_5      GPIO_PIN_A5
#define MCAL_GPIO_SIGNAL_6      GPIO_PIN_A6
#define MCAL_GPIO_SIGNAL_7      GPIO_PIN_A7
#define MCAL_GPIO_SIGNAL_8      GPIO_PIN_A8
#define MCAL_GPIO_SIGNAL_9      GPIO_PIN_A9
#define MCAL_GPIO_SIGNAL_10     GPIO_PIN_A10
#define MCAL_GPIO_SIGNAL_11     GPIO_PIN_A11
#define MCAL_GPIO_SIGNAL_12     GPIO_PIN_A12
//#define MCAL_GPIO_SIGNAL_13     GPIO_PIN_A13
//#define MCAL_GPIO_SIGNAL_14     GPIO_PIN_A14
#define MCAL_GPIO_SIGNAL_15     GPIO_PIN_A15
#define MCAL_GPIO_SIGNAL_16     GPIO_PIN_B0
#define MCAL_GPIO_SIGNAL_17     GPIO_PIN_B1
#define MCAL_GPIO_SIGNAL_18     GPIO_PIN_B2
#define MCAL_GPIO_SIGNAL_19     GPIO_PIN_B3
#define MCAL_GPIO_SIGNAL_20     GPIO_PIN_B4
#define MCAL_GPIO_SIGNAL_21     GPIO_PIN_B5
#define MCAL_GPIO_SIGNAL_22     GPIO_PIN_B6
#define MCAL_GPIO_SIGNAL_23     GPIO_PIN_B7
#define MCAL_GPIO_SIGNAL_24     GPIO_PIN_B8
#define MCAL_GPIO_SIGNAL_25     GPIO_PIN_B9
#define MCAL_GPIO_SIGNAL_26     GPIO_PIN_B10
//#define MCAL_GPIO_SIGNAL_27     GPIO_PIN_B11
#define MCAL_GPIO_SIGNAL_28     GPIO_PIN_B12
#define MCAL_GPIO_SIGNAL_29     GPIO_PIN_B13
#define MCAL_GPIO_SIGNAL_30     GPIO_PIN_B14
#define MCAL_GPIO_SIGNAL_31     GPIO_PIN_B15

#define MCAL_GPIO_MAX_SIGNAL   (DataType_u32)(MCAL_GPIO_SIGNAL_31 + 1U)

/*__________________________________________________________________________________________
| MCAL GPIO Port Definitions                                                               |
| Description  : Logical GPIO port identifiers for grouped port operations.                |
| Notes        : Intended for diagnostics and bulk operations only.                        |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_GROUPSIGNAL_A     GPIO_PORTA
#define MCAL_GPIO_GROUPSIGNAL_B     GPIO_PORTB
//#define MCAL_GPIO_GROUPSIGNAL_C     GPIO_PORTC
//#define MCAL_GPIO_GROUPSIGNAL_D     GPIO_PORTD
//#define MCAL_GPIO_GROUPSIGNAL_E     GPIO_PORTE
//#define MCAL_GPIO_GROUPSIGNAL_H     GPIO_PORTH

#define MCAL_GPIO_MAX_GROUPSIGNAL   (DataType_u32)(MCAL_GPIO_GROUPSIGNAL_B + 1U)


/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_Init                                                            |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Initializes GPIO hardware using static configuration data.                |
|                Configures mode, speed, pull-up/down, output type and AF registers.       |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Non-Reentrant                                                             |
| Parameters   : None                                                                      |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Initialization completed successfully               |
|                - Invalid_Parameter : Configuration parameters invalid                    |
|                - Error             : Hardware configuration or lock failed               |
| Preconditions: MCU clock system must be initialized                                      |
| Usage        : Startup service, shall be called once before any GPIO service             |
| Postconditions: GPIO module state is set to READY                                        |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_Init(void) GPIO_Intitialization(void)

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_GetModuleState                                                  |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Returns the current internal GPIO module state.                           |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Reentrant                                                                 |
| Parameters   : None                                                                      |
| Return       : DataType_u32                                                              |
| Preconditions: None                                                                      |
| Usage        : Diagnostic and state validation service                                   |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_GetModuleState(void) GPIO_GetModuleState(void)

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_WritePort                                                       |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Writes a value to the output data register of a GPIO port.                |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Non-Reentrant                                                             |
| Parameters   : SignalId    [IN]                                                          |
|                SignalValue [IN]                                                          |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Port written successfully                           |
|                - Invalid           : GPIO module not ready                               |
|                - Invalid_Parameter : PortId invalid                                      |
| Preconditions: GPIO module state must be READY                                           |
| Usage        : Runtime service for grouped output control                                |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_WritePort(SignalGroupId, SignalGroupValue) GPIO_WritePort((SignalGroupId), (SignalGroupValue))

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_WritePin                                                        |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Writes a logical level to the specified GPIO signal.                      |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Reentrant (for different SignalId values)                                 |
| Parameters   : SignalId [IN]                                                             |
|                SignalValue [IN]                                                          |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Signal written successfully                         |
|                - Invalid           : GPIO module not ready                               |
|                - Invalid_Parameter : SignalId or PinValue invalid                        |
| Preconditions: GPIO module state must be READY                                           |
| Usage        : Runtime service for digital output control                                |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_WritePin(SignalId, SignalValue) GPIO_WritePin((SignalId), (SignalValue))

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_ReadPin                                                         |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Reads the logical level of the specified GPIO signal.                     |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Reentrant (for different SignalId values)                                 |
| Parameters   : SignalId    [IN]                                                          |
|                SignalValuePtr [OUT]                                                      |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Signal read successfully                            |
|                - Invalid           : GPIO module not ready                               |
|                - Invalid_Parameter : SignalId invalid                                    |
|                - Null_Pointer      : PinValuePtr is NULL                                 |
| Preconditions: GPIO module state must be READY                                           |
| Usage        : Runtime service for digital input sampling                                |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_ReadPin(SignalId, SignalValuePtr) GPIO_ReadPin((SignalId), (SignalValuePtr))

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_TogglePin                                                       |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Toggles the output level of the specified GPIO signal.                    |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Reentrant (for different SignalId values)                                 |
| Parameters   : SignalId [IN]                                                             |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Signal toggled successfully                         |
|                - Invalid           : GPIO module not ready                               |
|                - Invalid_Parameter : SignalId invalid                                    |
| Preconditions: GPIO module state must be READY                                           |
| Usage        : Runtime service for signal toggling                                       |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_TogglePin(SignalId) GPIO_ToggelPin((SignalId))

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_SetPin                                                          |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Sets the specified GPIO signal to logical HIGH.                           |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Reentrant (for different SignalId values)                                 |
| Parameters   : SignalId [IN]                                                             |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Signal set HIGH successfully                        |
|                - Invalid           : GPIO module not ready                               |
|                - Invalid_Parameter : SignalId invalid                                    |
| Preconditions: GPIO module state must be READY                                           |
| Usage        : Runtime service for digital output control                                |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_SetPin(SignalId) GPIO_SetPin((SignalId))

/*_________________________________________________________________________________________
| Service Name : MCAL_GPIO_ResetPin                                                        |
| Module       : GPIO                                                                      |
| Layer        : MCAL                                                                      |
| Description  : Clears the output data register bit of the specified GPIO signal,         |
|                driving the associated physical pin to logical LOW.                       |
| Sync/Async   : Synchronous                                                               |
| Reentrancy   : Reentrant (for different SignalId values)                                 |
| Parameters   : SignalId [IN]                                                             |
| Return       : DataType_Request_Status                                                   |
|                - Success           : Signal set LOW successfully                         |
|                - Invalid           : GPIO module not ready                               |
|                - Invalid_Parameter : SignalId invalid                                    |
| Preconditions: GPIO module state must be READY                                           |
| Usage        : Runtime service for digital output control                                |
|_________________________________________________________________________________________*/
#define MCAL_GPIO_ResetPin(SignalId) GPIO_ResetPin((SignalId))

/********************************************************************************************************************************************************************
 *                                                                      End of Section GPIO                                                                         *
 *******************************************************************************************************************************************************************/

#endif /* MCAL_INT_H */
