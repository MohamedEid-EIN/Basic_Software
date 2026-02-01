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
* - File Name   : GPT.h
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
#ifndef GPT_H
#define GPT_H

#include "DataTypes.h"

/*==================================================================================================
 | Function Name : Gpt_Initialization
 | Description   : Initializes the GPT module and configures the required
 |                 hardware timer registers based on static configuration.
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
 |   - Configuration data valid
 | Context       : Callable From : Startup
 *==================================================================================================*/

DataType_Request_Status GPT_Initialization(void);

/*==================================================================================================
 | Function Name : GPT_DeInitialization
 | Description   : De-initializes the GPT module and resets all timer channels
 |                 to their default state.
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
 |   - GPT module initialized
 | Context       : Callable From : Startup
 *==================================================================================================*/
DataType_Request_Status GPT_DeInitialization(void);

/*==================================================================================================
 | Function Name : GPT_StartTimer
 | Description   : Starts the specified GPT timer channel with the configured
 |                 timeout value.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId, TimeoutValue
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 |   - Timer channel stopped
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status GPT_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType TimeoutValue);

/*==================================================================================================
 | Function Name : GPT_StopTimer
 | Description   : Stops the specified GPT timer channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status GPT_StopTimer(Gpt_ChannelType ChannelId);

/*==================================================================================================
 | Function Name : GPT_GetTimeElapsed
 | Description   : Returns the elapsed time value for the specified
 |                 GPT timer channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId
 |   InOut       : None
 |   Output      : ElapsedTime
 |
 | Return        : Gpt_ValueType
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
Gpt_ValueType GPT_GetTimeElapsed(Gpt_ChannelType ChannelId);

/*==================================================================================================
 | Function Name : GPT_GetTimeRemaining
 | Description   : Returns the remaining time value for the specified
 |                 GPT timer channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId
 |   InOut       : None
 |   Output      : RemainingTime
 |
 | Return        : Gpt_ValueType
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
Gpt_ValueType GPT_GetTimeRemaining(Gpt_ChannelType ChannelId);

/*==================================================================================================
 | Function Name : GPT_EnableNotification
 | Description   : Enables the interrupt notification for the specified
 |                 GPT timer channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status GPT_EnableNotification(Gpt_ChannelType ChannelId);

/*==================================================================================================
 | Function Name : GPT_DisableNotification
 | Description   : Disables the interrupt notification for the specified
 |                 GPT timer channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status GPT_DisableNotification(Gpt_ChannelType ChannelId);

/*==================================================================================================
 | Function Name : GPT_GetStatus
 | Description   : Returns the current status of the specified GPT
 |                 timer channel.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : ChannelId
 |   InOut       : None
 |   Output      : None
 |
 | Return        : Gpt_StatusType
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - GPT module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
Gpt_StatusType GPT_GetStatus(Gpt_ChannelType ChannelId);







#endif /* GPT_H */