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
* - File Name   : UTILS.h
* - File Type   : Interface File
* - Module      : UTILS
* - Layer       : Libraries
* - Description : Here you can find helper interfaces.
* - Design Note : None.
* - Toolchain   : None.
* - References  : None.
*--------------------------------------------------------------------------------------------
* - Version History :
*   - 1.00.00  | 2025-12-01 | Mohamed Eid | File Creation
*********************************************************************************************/
#ifndef UTILS_INT_H
#define UTILS_INT_H

#include "DataTypes.h"

/******************************************************************************************************************************
 * Macros area to define used values in the software
 *****************************************************************************************************************************/
/* Module state values used to define module states Hamming code values are used to detiacte bit flips errors */
#define LIB_UTILS_STATE_UNDEFINED       (DataType_u32)0x00000000U /* state: indicates module is in unkown state                         */
#define LIB_UTILS_STATE_UNINITIALIZED   (DataType_u32)0xA5A5A5A5U /* state: indicates module never initialized                          */
#define LIB_UTILS_STATE_INITIALIZED     (DataType_u32)0x55555555U /* state: indicates module is initialized                             */
#define LIB_UTILS_STATE_DEINITIALIZED   (DataType_u32)0xAAAAAAAAU /* state: indicates module was initialized and now it's not           */
#define LIB_UTILS_STATE_LOW_POWER       (DataType_u32)0xF0F0F0F0U /* state: indicates module is in low power state                      */
#define LIB_UTILS_STATE_SAFE            (DataType_u32)0x0F0F0F0FU /* state: indicates error happen and module went to safe state        */
#define LIB_UTILS_STATE_SLEEP           (DataType_u32)0x5A5A5A5AU /* state: indicates module is in sleep mode                           */
#define LIB_UTILS_STATE_READY           (DataType_u32)0x00FF00FFU /* state: indicates module is in initialized clock enabled and ready  */
#define LIB_UTILS_STATE_BUSY            (DataType_u32)0xFF00FF00U /* state: indicates module is proccessing and request in the moment   */
#define LIB_UTILS_STATE_ERROR           (DataType_u32)0xDEADDEADU /* state: indicates Error happened and module is not responding       */

/**********************************************************************************************************************************
 * Data ProtoType defination area
 **********************************************************************************************************************************/
/*=================================================================================================================
 | Function Name : IsValidState                                                                                    |
 | Module        : UTILS                                                                                           |
 | Layer         : Libraries                                                                                       |
 | Description   : Check the given module state is valid and in the range states or not.                           |
 |-----------------------------------------------------------------------------------------------------------------|
 | Sync/Async  : Synchronous                                                                                       |
 | Reentrancy  : Reentrant                                                                                         |
 |-----------------------------------------------------------------------------------------------------------------|
 | Parameters                                                                                                      |
 |   Input       : ModuleState                                                                                     |
 |   InOut       : None                                                                                            |
 |   Output      : None                                                                                            |
 | Return        : DataType_Validity                                                                               |
 |-----------------------------------------------------------------------------------------------------------------|
 | Preconditions : None                                                                                            |
 | Context       : Callable From : BasicSoftware                                                                   |
 *================================================================================================================*/
static inline DataType_Validity LIB_UTILS_IsValidState(DataType_u32 ModuleState);


/**********************************************************************************************************************************
 * Data declration area
 **********************************************************************************************************************************/
/*==================================================================================================================
 | Function Name : IsValidState                                                                                     |
 | Module        : UTILS                                                                                            |
 | Layer         : Libraries                                                                                        |
 | Description   : Check the given module state is valid and in the range states or not.                            |
 *==================================================================================================================*/
static inline DataType_Validity LIB_UTILS_IsValidState(DataType_u32 ModuleState)
{
    /* Declare return states value */
    DataType_Validity Return_Status = InValid;

    /* Check if the state is in range of definded states or not */
    switch(ModuleState)
    {
        case LIB_UTILS_STATE_UNDEFINED:
        case LIB_UTILS_STATE_UNINITIALIZED:
        case LIB_UTILS_STATE_INITIALIZED:
        case LIB_UTILS_STATE_DEINITIALIZED:
        case LIB_UTILS_STATE_LOW_POWER:
        case LIB_UTILS_STATE_SAFE:
        case LIB_UTILS_STATE_SLEEP:
        case LIB_UTILS_STATE_READY:
        case LIB_UTILS_STATE_BUSY:
        case LIB_UTILS_STATE_ERROR:
        {
            /* Return the States is valid */
            Return_Status = Valid;
            break;
        }
        default:
        { /* Do nothing return Invalid states */ }
    }

    return Return_Status;
}

#endif /* UTILS_INT_H */
