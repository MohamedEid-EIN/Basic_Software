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
* - File Name   : GPIO_Cfg.c
* - File Type   : Configuration Source File
* - Module      : GPIO
* - Layer       : MCAL
* - Description : Static GPIO configuration tables.
* - Design Note : Contains configuration data only (no logic).
* - Toolchain   : Independent
* - References  : STM32 Reference Manual.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial GPIO configuration tables
**********************************************************************************************************************************************************************************/


#include "GPIO_Cfg.h"

/*__________________________________________________________________________________________
 | Data Type Name : PinSetUp_TableCfg                                                      |
 | Description    : GPIO pin configuration table                                           |
 | Type           : Array of DataType_PinConfiguration                                     |
 | Storage        : Flash (const)                                                          |
 | Size           : PIN_CFG × sizeof(DataType_PinConfiguration)                            |
 | Usage          : Used during GPIO initialization to configure pin modes and behavior    |
 | HW Mapping     : Indirect (applied to GPIOx registers during initialization)            |
 | Lifetime       : Static (valid for entire system lifetime)                              |
 | Notes          : Each entry represents one GPIO pin configuration                       |
 |_________________________________________________________________________________________*/
const DataType_PinConfiguration PinSetUp_TableCfg[NUMBER_PINS_CFG] =
{
/*    Port  | Pin    | Mode                     | Output Type        | Speed      | Pull/Resistor           | Initial Level       | Lock Status            |    Alternate Function */
    { PortA, Pin_0,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_1,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_2,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_3,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_4,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_5,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_6,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_7,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_8,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_9,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_10,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_11,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_12,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_13,  Alternate_Function_Mode,    Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_14,  Alternate_Function_Mode,    Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    { PortA, Pin_15,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 }

    // { PortB, Pin_0,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_1,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_2,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_3,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_4,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_5,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_6,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_7,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_8,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_9,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_10,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_12,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_13,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_14,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortB, Pin_15,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },

	// { PortC, Pin_0,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_1,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_2,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_3,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_4,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_5,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_6,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_7,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_8,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_9,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_10,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_12,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_13,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_14,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortC, Pin_15,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },

	// { PortD, Pin_0,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_1,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_2,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_3,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_4,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_5,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_6,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_7,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_8,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_9,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_10,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_12,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_13,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_14,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortD, Pin_15,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },

	// { PortE, Pin_0,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_1,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_2,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_3,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_4,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_5,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_6,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_7,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_8,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_9,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_10,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_12,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_13,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_14,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortE, Pin_15,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },

	// { PortH, Pin_0,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_1,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_2,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_3,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_4,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_5,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_6,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_7,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_8,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_9,   Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_10,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_12,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_13,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_14,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 },
    // { PortH, Pin_15,  Output_Mode,                Output_Push_Pull,    Low_Speed,   Resistance_NotConnected,       Low,             Configuration_UnLocked,   Alternate_Function_0 }
};

/*__________________________________________________________________________________________
 | Data Type Name : PortLockStatus_TableCfg                                                |
 | Description    : GPIO port lock configuration table                                     |
 | Type           : Array of DataType_PortLockKey                                          |
 | Storage        : Flash (const)                                                          |
 | Size           : PORT_CFG × sizeof(DataType_PortLockKey)                                |
 | Usage          : Used to configure GPIO port lock behavior during initialization        |
 | HW Mapping     : STM32 GPIOx_LCKR register                                              |
 | Lifetime       : Static (valid for entire system lifetime)                              |
 | Notes          : Determines whether port configuration can be modified at runtime       |
 |_________________________________________________________________________________________*/
const DataType_PortLockKey PortLock_TableCfg[NUMBER_PORT_CFG] =
{
/*   Port   | Lock */
    { PortA,  UnActive }
    // { PortB,  UnActive },
    // { PortC,  UnActive },
    // { PortD,  UnActive },
    // { PortE,  UnActive },
    // { PortH,  UnActive }


};
