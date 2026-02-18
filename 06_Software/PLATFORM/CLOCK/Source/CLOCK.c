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
* - File Name   : CLOCK.c
* - File Type   : Source File
* - Module      : CLOCK
* - Layer       : Platform
* - Description : Here you can find helper interfaces.
* - Design Note : None.
* - Toolchain   : None.
* - References  : None.
*--------------------------------------------------------------------------------------------
* - Version History :
*   - 1.00.00  | 2025-12-01 | Mohamed Eid | File Creation
**********************************************************************************************************************************************************************************/

#include "CLOCK.h"

static volatile DataType_u32 CLOCK_Module_State = LIB_UTILS_STATE_UNDEFINED;

DataType_Request_Status CLOCK_Initiailization(void)
{
    DataType_Request_Status Return_Status = Unkown;
    DataType_u8 Index;

    for(Index = 0; Index < ClockIndex_Cfg; Index++)
    {
        if(GpioClock_Cfg[Index] == Enable)
        {
			*REG_RCCAHB1ENR_ADDRESS = 0;
            *REG_RCCAHB1ENR_ADDRESS = REG_BIT_GPIOAEN_MASK;
        }

    }
    CLOCK_Module_State = LIB_UTILS_STATE_READY;

    return Return_Status;
}

DataType_u32 CLOCK_GetModuleState(void)
{

    DataType_u32 State = CLOCK_Module_State;

    return State;
}
