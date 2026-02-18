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

/*==================================================================================================
 | Function Name : PWM_Initialization
 | Description   : Initializes the PWM module and configures TIM3
 |                 for PWM signal generation.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : void
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 | Context       : Callable From : Startup
 *==================================================================================================*/
DataType_Request_Status PWM_Initialization(void);

/*==================================================================================================
 | Function Name : PWM_Enable
 | Description   : Enables the PWM output on the configured channel
 |                 without stopping the timer counter.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : void
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - PWM module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status PWM_Enable(void);

/*==================================================================================================
 | Function Name : PWM_Disable
 | Description   : Disables the PWM output on the configured channel
 |                 while keeping the timer running.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : void
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - PWM module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status PWM_Disable(void);

/*==================================================================================================
 | Function Name : PWM_SetDuty
 | Description   : Updates the PWM duty cycle value for the
 |                 configured channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : DutyPercent (0–100)
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - PWM module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status PWM_SetDuty(DataType_u8 DutyCycle);

#endif /* FILE_H */