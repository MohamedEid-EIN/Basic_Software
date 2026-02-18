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
* - File Name   : GPIO_Cfg.h
* - File Type   : Configuration Header File
* - Module      : GPIO
* - Layer       : MCAL
* - Description : GPIO configuration declarations and compile-time parameters.
* - Design Note : Contains configuration macros and extern declarations only.
* - Toolchain   : Independent
* - References  : STM32 Reference Manual.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|-----------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial GPIO configuration interface
**********************************************************************************************************************************************************************************/

#ifndef GPIO_CFG_H
#define GPIO_CFG_H

#include "GPIO_Types.h"

/*_______________________________________________________________________________________
 | Macro Name   : PORT_CFG                                                               |
 | Description  : Number of GPIO ports Used configuration                                |
 | Type         : Macro                                                                  |
 | Storage      : N/A                                                                    |
 | Usage        : Used to size port configuration tables                                 |
 | Notes        : Must match number of entries in PortLockStatus_TableCfg                |
 |______________________________________________________________________________________*/
#define NUMBER_PORT_CFG  (DataType_u8)6

/*________________________________________________________________________________________
 | Macro Name   : PIN_CFG                                                                 |
 | Description  : Number of GPIO pin Used configuration                                   |
 | Type         : Macro                                                                   |
 | Storage      : N/A                                                                     |
 | Usage        : Used to size pin configuration tables                                   |
 | Notes        : Must match number of entries in PinSetUp_TableCfg                       |
 |_______________________________________________________________________________________*/
#define NUMBER_PINS_CFG   (DataType_u8)96

/*__________________________________________________________________________________________
 | Data Name     : PinSetUp_TableCfg                                                        |
 | Description   : Static GPIO pin configuration table                                      |
 | Type          : Array of DataType_PinConfiguration                                       |
 | Storage       : Flash (const-qualified configuration data)                               |
 | Size          : PIN_CFG_NUM entries × sizeof(DataType_PinConfiguration)                  |
 | Usage         : Used by GPIO initialization logic to configure all pins                  |
 | HW Mapping    : Indirect (used to program GPIOx_MODER, OTYPER, OSPEEDR, etc.)            |
 | Lifetime      : Static; read-only after startup                                          |
 | Notes         : Enum-based fields provide compile-time domain validation                 |
 |_________________________________________________________________________________________*/
extern const DataType_PinConfiguration PinSetUp_TableCfg[NUMBER_PINS_CFG];

/*__________________________________________________________________________________________
 | Data Name     : PortLockStatus_TableCfg                                                  |
 | Description   : Static GPIO port lock configuration table                                |
 | Type          : Array of DataType_PortLockKey                                            |
 | Storage       : Flash (const-qualified configuration data)                               |
 | Size          : PORT_CFG_NUM entries × sizeof(DataType_PortLockKey)                      |
 | Usage         : Defines which GPIO ports shall be locked during initialization           |
 | HW Mapping    : Indirect (used to program GPIOx_LCKR register)                           |
 | Lifetime      : Static; valid for entire program execution                               |
 | Notes         : Read-only configuration provided by integrator                           |
 |_________________________________________________________________________________________*/
extern const DataType_PortLockKey PortLock_TableCfg[NUMBER_PORT_CFG];

#endif /* GPIO_CFG_H */
