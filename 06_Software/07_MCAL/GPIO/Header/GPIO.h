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
#include "DataTypes.h"
#include "GPIO_Types.h"
#include "GPIO_Cfg.h"

#ifndef GPIO_H
#define GPIO_H

DataType_Request_Status Write_Registers_Configuration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION], DataType_Gpio_Registers Registers_Table[MAX_PORT_CONFIGURATION]);
DataType_Request_Status Port_Lock_Init(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION], DataType_Gpio_Registers Registers_Table[MAX_PORT_CONFIGURATION]);
void Build_Configuration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION]);
/********************************************************************************************
 * Struct to define the Port registers PORTs.
*********************************************************************************************/
DataType_Gpio_Registers Registers_Table[NUM_OF_PORTS];

static const DataType_Pin_Configuration Pin_Configuration_Table[PORT_CFG];

static const DataType_Port_Lock_Key Port_Lock_Configuration_Table[PORT_CFG];

volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[NUM_OF_PORTS];

#endif /* GPIO_H */