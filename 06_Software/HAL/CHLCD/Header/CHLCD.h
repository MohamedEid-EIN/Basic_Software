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
* - File Type   : Private File
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
#ifndef FILE_H
#define FILE_H

#include "DataTypes.h"

/******************************************************************************************
 * Display Commands
 *****************************************************************************************/
/* ---------------- HD44780 COMMANDS ---------------- */

/* Function Set */
#define DISPLAY_FUNC_4BIT_1LINE_5x8FONT    (DataType_u8)0x20U
#define DISPLAY_FUNC_4BIT_2LINE_5x8FONT    (DataType_u8)0x28U
#define DISPLAY_FUNC_8BIT_1LINE_5x8FONT    (DataType_u8)0x30U
#define DISPLAY_FUNC_8BIT_2LINE_5x8FONT    (DataType_u8)0x38U

/* Display Control */
#define DISPLAY_OFF             (DataType_u8)0x08U
#define DISPLAY_ON              (DataType_u8)0x0CU
#define DISPLAY_ON_CURSOR       (DataType_u8)0x0EU
#define DISPLAY_ON_CURSOR_BLINK (DataType_u8)0x0FU

/* Clear / Home */
#define DISPLAY_CLEAR                   (DataType_u8)0x01U
#define DISPLAY_CURSOR_HOME             (DataType_u8)0x02U

/* Entry Mode Set */
#define DISPLAY_ENTRY_CURSOR_RIGHT      (DataType_u8)0x06U
#define DISPLAY_ENTRY_CURSOR_LEFT       (DataType_u8)0x04U
#define DISPLAY_ENTRY_SHIFT_RIGHT       (DataType_u8)0x07U
#define DISPLAY_ENTRY_SHIFT_LEFT        (DataType_u8)0x05U

/* ---------------- SOFTWARE POLICY ---------------- */

typedef enum
{
    LCD_ALIGN_LEFT = 0,
    LCD_ALIGN_RIGHT,
    LCD_ALIGN_CENTER

} DataType_LcdAlignment;

/* ---------------- CONFIG STRUCT ---------------- */

typedef struct
{
    DataType_u8            Display_FunctionSet;
    DataType_u8            Display_EntryMode;
    DataType_u8            Display_Control;
    DataType_LcdAlignment  Display_Alignment;

} DataType_Display_Configurations;

extern DataType_Display_Configurations ChLcd_Configuration_Table[];

#endif /* LCD_CFG_H */
