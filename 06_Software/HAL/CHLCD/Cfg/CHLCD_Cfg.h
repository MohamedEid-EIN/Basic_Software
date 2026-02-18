/********************************************************************************************
* License     : MIT License
* Copyright   : (c) 2025 Mohamed Eid
*
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
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
*
*--------------------------------------------------------------------------------------------\
* - Author      : Mohamed Eid
* - File Name   : File.h
* - File Type   : Configuration File
* - Module      : Name
* - Layer       : Hardware Abstraction / Low-Level Driver
* - Description : TBD.
* - Design Note : TBD.
* - Toolchain   : TBD.
* - References  : TBD.
* - Execution Context :
*   - Initialization     : Startup phase only
*   - Runtime API        : Task context
*   - ISR Usage          : Limited (see function documentation)
*--------------------------------------------------------------------------------------------
* - Version History :
*   - 1.00.00  | 2025-xx-xx | Mohamed Eid | File Creation
********************************************************************************************/
#ifndef FILE_CFG_H
#define FILE_CFG_H

/******************************************************************************************
 * Display Commands
 *****************************************************************************************/
#include "CHLCD_Types.h"
#include "CHLCD.h"
#include "MCAL_Int.h"
#include "CHLCD_Int.h"
#define DATA_GROUP_CFG MCAL_GPIO_GROUPSIGNAL_B
#define LCD_NUM_CFG 1U

#define LCD_PIN_RS_CFG MCAL_GPIO_SIGNAL_1
#define LCD_PIN_EN_CFG MCAL_GPIO_SIGNAL_2


DataType_Display_Configurations ChLcd_Configuration_Table[LCD_NUM_CFG] =
{
    {
      .Display_FunctionSet = DISPLAY_FUNC_8BIT_2LINE_5x8FONT,
      .Display_EntryMode = DISPLAY_ENTRY_CURSOR_RIGHT,
      .Display_Control = DISPLAY_ON,
      .Display_Alignment = LCD_ALIGN_LEFT,

    }
};

static const DataType_u8 LCD_HeartChar[8] =
{
    0x00,  //
    0x0A,  //  █ █
    0x1F,  // █████
    0x1F,  // █████
    0x1F,  // █████
    0x0E,  //  ███
    0x04,  //   █
    0x00
};

#endif /* FILE_CFG_H */
