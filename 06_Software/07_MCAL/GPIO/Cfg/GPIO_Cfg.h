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

#ifndef GPIO_CFG_H
#define GPIO_CFG_H

#define PORT_CFG  (DataType_u8)1
#define PIN_CFG   (DataType_u8)1

static const DataType_Pin_Configuration Pin_Configuration_Table[PIN_CFG] = 
{
/*    Port - Pin -  Mode        - Output Type      - Output Speed - Resistance Connection -  Output status setup - Configuration Lock status - Alternate function */
    { PortB, Pin_0, Output_Mode,  Output_Push_Pull,  Low_Speed,     Resistance_NotConnected, High,                 Configuration_UnLocked,     Alternate_Function_0 }
};

static const DataType_Port_Lock_Key Port_Lock_Status_Table[PORT_CFG] =
{
/*   Port - Configuration lock key status */
    {PortB, UnActive}
};

#endif /* GPIO_CFG_H */