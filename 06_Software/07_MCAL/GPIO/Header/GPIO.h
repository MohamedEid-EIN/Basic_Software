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
#ifndef GPIO_H
#define GPIO_H

#include "DataTypes.h"
#include "GPIO_Types.h"
#include "GPIO_Cfg.h"
#include "UTILS_Int.h"

volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[NUM_OF_PORTS] =
{
    {PortA, Key_UnLocked},
    {PortB, Key_UnLocked},
    {PortC, Key_UnLocked},
    {PortD, Key_UnLocked},
    {PortE, Key_UnLocked},
    {PortH, Key_UnLocked}

};

DataType_Gpio_Registers Registers_Table[NUM_OF_PORTS] =
{
    PORTA_BASE_ADDRESS,
    PORTB_BASE_ADDRESS,
    PORTC_BASE_ADDRESS,
    PORTD_BASE_ADDRESS,
    PORTE_BASE_ADDRESS,
    PORTH_BASE_ADDRESS
};

static DataType_Usage Port_Usage_Table[NUM_OF_PORTS] = {Unused};

static volatile DataType_u32 GPIO_Module_State = LIB_UTILS_STATE_UNDEFINED;

/********************************************************************************************
 * Struct to define the Port registers PORTs.
*********************************************************************************************/
DataType_Gpio_Registers Registers_Table[NUM_OF_PORTS];

static const DataType_Pin_Configuration Pin_Configuration_Table[PORT_CFG];

static const DataType_Port_Lock_Key Port_Lock_Configuration_Table[PORT_CFG];

volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[NUM_OF_PORTS];

/**********************************************************************************************************************************
 * Function ProtoType defination area
 **********************************************************************************************************************************/
/*=================================================================================================================
 | Function Name : Intitialization                                                                                 |
 | Module        : GPIO                                                                                            |
 | Layer         : MCAL                                                                                            |
 | Description   : Initialize module state and all required hardware registers with configuration value.           |
 |-----------------------------------------------------------------------------------------------------------------|
 | Sync/Async  : Synchronous                                                                                       |
 | Reentrancy  : Non-Reentrant                                                                                     |
 |-----------------------------------------------------------------------------------------------------------------|
 | Parameters                                                                                                      |
 |   Input       : None                                                                                            |
 |   InOut       : None                                                                                            |
 |   Output      : None                                                                                            |
 | Return        : DataType_Request_Status                                                                         |
 |-----------------------------------------------------------------------------------------------------------------|
 | Preconditions : None                                                                                            |
 | Context       : Callable From : From MCU                                                                        |
 *================================================================================================================*/
DataType_Request_Status GPIO_Intitialization(void);

/*=================================================================================================================
 | Function Name : Intitialization                                                                                 |
 | Module        : GPIO                                                                                            |
 | Layer         : MCAL                                                                                            |
 | Description   : Initialize module state and all required hardware registers with configuration value.           |
 |-----------------------------------------------------------------------------------------------------------------|
 | Sync/Async  : Synchronous                                                                                       |
 | Reentrancy  : Non-Reentrant                                                                                     |
 |-----------------------------------------------------------------------------------------------------------------|
 | Parameters                                                                                                      |
 |   Input       : None                                                                                            |
 |   InOut       : None                                                                                            |
 |   Output      : None                                                                                            |
 | Return        : DataType_Request_Status                                                                         |
 |-----------------------------------------------------------------------------------------------------------------|
 | Preconditions : None                                                                                            |
 | Context       : Callable From : From MCU                                                                        |
 *================================================================================================================*/
DataType_Request_Status GPIO_SetModuleState(DataType_u32 State);

/*=================================================================================================================
 | Function Name : Intitialization                                                                                 |
 | Module        : GPIO                                                                                            |
 | Layer         : MCAL                                                                                            |
 | Description   : Initialize module state and all required hardware registers with configuration value.           |
 |-----------------------------------------------------------------------------------------------------------------|
 | Sync/Async  : Synchronous                                                                                       |
 | Reentrancy  : Non-Reentrant                                                                                     |
 |-----------------------------------------------------------------------------------------------------------------|
 | Parameters                                                                                                      |
 |   Input       : None                                                                                            |
 |   InOut       : None                                                                                            |
 |   Output      : None                                                                                            |
 | Return        : DataType_Request_Status                                                                         |
 |-----------------------------------------------------------------------------------------------------------------|
 | Preconditions : None                                                                                            |
 | Context       : Callable From : From MCU                                                                        |
 *================================================================================================================*/
DataType_Request_Status Write_Registers_Configuration(
    DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION],
    DataType_Gpio_Registers Registers_Table[MAX_PORT_CONFIGURATION]);

/*=================================================================================================================
 | Function Name : Intitialization                                                                                 |
 | Module        : GPIO                                                                                            |
 | Layer         : MCAL                                                                                            |
 | Description   : Initialize module state and all required hardware registers with configuration value.           |
 |-----------------------------------------------------------------------------------------------------------------|
 | Sync/Async  : Synchronous                                                                                       |
 | Reentrancy  : Non-Reentrant                                                                                     |
 |-----------------------------------------------------------------------------------------------------------------|
 | Parameters                                                                                                      |
 |   Input       : None                                                                                            |
 |   InOut       : None                                                                                            |
 |   Output      : None                                                                                            |
 | Return        : DataType_Request_Status                                                                         |
 |-----------------------------------------------------------------------------------------------------------------|
 | Preconditions : None                                                                                            |
 | Context       : Callable From : From MCU                                                                        |
 *================================================================================================================*/
DataType_Request_Status Port_Lock_Init(
    DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION],
     DataType_Gpio_Registers Registers_Table[MAX_PORT_CONFIGURATION]);

/*=================================================================================================================
 | Function Name : Intitialization                                                                                 |
 | Module        : GPIO                                                                                            |
 | Layer         : MCAL                                                                                            |
 | Description   : Initialize module state and all required hardware registers with configuration value.           |
 |-----------------------------------------------------------------------------------------------------------------|
 | Sync/Async  : Synchronous                                                                                       |
 | Reentrancy  : Non-Reentrant                                                                                     |
 |-----------------------------------------------------------------------------------------------------------------|
 | Parameters                                                                                                      |
 |   Input       : None                                                                                            |
 |   InOut       : None                                                                                            |
 |   Output      : None                                                                                            |
 | Return        : DataType_Request_Status                                                                         |
 |-----------------------------------------------------------------------------------------------------------------|
 | Preconditions : None                                                                                            |
 | Context       : Callable From : From MCU                                                                        |
 *================================================================================================================*/
void Build_Configuration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION]);

#endif /* GPIO_H */
