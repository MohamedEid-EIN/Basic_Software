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
 | Function Name : Module_Name
 | Description   : TBD.
 |--------------------------------------------------------------------------------------------------
 |   Sync/Async  : Synchronous
 |   Reentrancy  : Non-Reentrant
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : None
 |   InOut       : None
 |   Output      : None
 |
 | Return        : DataType_Request_Status
 |                 - SERIAL_OK      : Operation successful
 |                 - SERIAL_NOT_OK  : Operation failed
 |--------------------------------------------------------------------------------------------------
 | Preconditions : Module initialized
 | Context       : Callable From : Task
 *==================================================================================================*/
DataType_Request_Status Module_Name(void);


#endif /* FILE_H */