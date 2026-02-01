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
*--------------------------------------------------------------------------------------------
* - Author      : Mohamed Eid
* - File Name   : File.c
* - File Type   : Source File
* - Module      : Name
* - Layer       : Hardware Abstraction / Low-Level Driver
* - Description : TBD.
* - Design Note : TBD
* - Toolchain   : TBD
* - References  : TBD
* - Execution Context :
*   - Initialization     : Startup phase only
*   - Runtime API        : Task context
*   - ISR Usage          : Limited (see function documentation)
*--------------------------------------------------------------------------------------------
* - Version History :
*   - 1.00.00  | 2025-xx-xx | Mohamed Eid | File Creation
********************************************************************************************/

#include "PWM.h"
#include "PWM_Cfg.h"

static volatile DataType_u32 PWM_Module_State = STATE_UNDEFINDED; 
/*==================================================================================================
 | Function Name : PWM_Initialization
 | Description   : Initializes the PWM module and configures TIM3
 |                 for PWM signal generation.
 *==================================================================================================*/
DataType_Request_Status PWM_Initialization(void)
{
    /* Variables declartion */
    PWM_Module_State = STATE_UNINTIALIZED;
    DataType_Request_Status Return_Status = Error;
    if(PWM_CHANNEL_CFG > 0 && PWM_CHANNEL_CFG <= 4)
    {
        Return_Status = Invalid_Parameter;
    }
    else
    {
        DataType_u8 Index;
        for(Index = 0; Index < PWM_CHANNEL_CFG; Index++)
        {
            REG_TIM3_CR1 = COUNTER_ENABLE | PWM_Configuration_Table[Index].AutoReload_Cfg;
            REG_TIM3_EGR 
            REG_TIM3_CCMR1
            REG_TIM3_CCMR2
            REG_TIM3_CCER 
            REG_TIM3_PSC  
            REG_TIM3_ARR  
            REG_TIM3_CCR1 
            REG_TIM3_CCR2 
            REG_TIM3_CCR3 
            REG_TIM3_CCR4 
        }
    }

    return Return_Status;
}