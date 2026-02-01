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
* - Description : 
* - Author      : Mohamed Eid
* - File Name   : GPIO.c
* - File Type   : Source file
* - References  : Compiler Manual
* - Toolchain   : TBD
* - Version     : History
* - 1.00.00     : File Creation
********************************************************************************************/
#include "GPIO.h"

volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[NUM_OF_PORTS] = 
{
    {PortA, Key_UnLocked},
    {PortB, Key_UnLocked},
    {PortC, Key_UnLocked},
    {PortD, Key_UnLocked},
    {PortE, Key_UnLocked},
    {PortH, Key_UnLocked}

};

DataType_Gpio_Registers Registers_Table[NUM_OF_PORTS] =
{
    PORTA_BASE_ADDRESS,
    PORTB_BASE_ADDRESS,
    PORTC_BASE_ADDRESS,
    PORTD_BASE_ADDRESS,
    PORTE_BASE_ADDRESS,
    PORTH_BASE_ADDRESS
};

static DataType_Usage Port_Usage_Table[NUM_OF_PORTS] = {Unused};

static volatile DataType_u32 GPIO_Module_State = STATE_UNDEFINDED; 

DataType_Request_Status GPIO_Set_Module_State(DataType_u32 State);
/*________________________________________________________________________________________________________________________________________________________
 | Function Name : Gpio_Intitialization                                                                                                                   |
 | Description : Used to Initialize IO register                                                                                                           |
 | Module : GPIO                                                                                                                                          |
 | Paramiters : TBD                                                                                                                                       |
 | Return : TBD                                                                                                                                           |
 | Synchrounsity                                                                                                                                          |
 | Reentrunt:                                                                                                                                             |
 | Size :                                                                                                                                                 |
 | Excution Time : TBD                                                                                                                                    |
 |_______________________________________________________________________________________________________________________________________________________*/
DataType_Request_Status Gpio_Intitialization(void)
{
    /* initialize return status  = Error */
    DataType_Request_Status Return_Status = Error;

    /* Initialize Module state = UnInitialized */
    GPIO_Module_State = STATE_UNINTIALIZED;
    
    /* Check the validity of Pins and Ports configuration */
    if (PORT_CFG < MIN_PORT_CONFIGURATION || PORT_CFG > MAX_PORT_CONFIGURATION ||
        PIN_CFG  < MIN_PIN_CONFIGURATION  || PIN_CFG  > MAX_PIN_CONFIGURATION)
    {
        /* Set return status with invalid configuration */
        Return_Status = Invalid_Parameter;
    }

    else
    {
        /* create registers Shadow Table to to store the configuration values */
        DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION] = {INITIALIZE_ZERO};

        /* Build configurations in the shadow registers map */
        Build_Configuration(Registers_Shadow);
        
        /* Set all the IO regosters values and store operation status */
        Return_Status = Write_Registers_Configuration(Registers_Shadow, Registers_Table);

        /* check the registers configuration status */
        if(Return_Status != Success)
        {
            /* Set return status with error */
            Return_Status = Error;
        }
        else
        {
            /* Configure port lock featuer and store operation status */
            Return_Status = Port_Lock_Init(Registers_Shadow, Registers_Table);
        }

        /* check the registers configuration status */
        if(Return_Status != Success)
        {
            /* Set return status with error */
            Return_Status = Error;
        }
        else
        {
            /* Set return status with operation succssed */
            Return_Status = Success;
        }
    }

    /* Set Module state variable IO is Ready */
    GPIO_Set_Module_State(STATE_READY);

    return Return_Status;
}

/*_________________________________________________________________________________________
 | Function Name : Gpio_Intitialization                                                    |
 | Description : Used to Initialize IO register                                            |
 | Module : GPIO                                                                           |
 | Paramiters : TBD                                                                        |
 | Return : TBD                                                                            |
 | Synchrounsity                                                                           |
 | Reentrunt:                                                                              |
 | Size :                                                                                  |
 | Excution Time : TBD                                                                     |
 |_________________________________________________________________________________________*/
void Build_Configuration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION])
{
    /* Initialize Index, PortId, PinId variables for upcoming operations */
    DataType_u8  Index;
    DataType_u8 PortId;
    DataType_u32 PinId;

    /* Loop on all configured pins */
    for(Index = INITIALIZE_ZERO; Index < PIN_CFG; Index++)
    {
        /* Store current PORT number and pin number */
        PortId = Pin_Configuration_Table[Index].Port_Id;
        PinId = Pin_Configuration_Table[Index].Pin_Id;

        /* Set current port is used in the port Usage_table*/
        Port_Usage_Table[PortId] = Used;

        /* Configure Shadow GPIO Mode register for current port and pin */
        Registers_Shadow[PortId].Gpio_Moder |= (Pin_Configuration_Table[Index].Pin_Mode << (PinId * REG_MODER_BITS));

        /* Configure Shadow GPIO Output Type register for current port and pin */
        Registers_Shadow[PortId].Gpio_Otyper |= (Pin_Configuration_Table[Index].Pin_Output_Type << PinId);

        /* Configure Shadow Output Speed register for current Port and Pin */
        Registers_Shadow[PortId].Gpio_Ospeedr |= (Pin_Configuration_Table[Index].Pin_Output_Speed << (PinId * REG_OSPEEDR_BITS));

        /* Configure Shadow GPIO Pullup/Pulldown register for current Port and Pin */
        Registers_Shadow[PortId].Gpio_Pupdr |= (Pin_Configuration_Table[Index].Pin_Resitances_Connection << (PinId * REG_PUPDR_BITS));

        /* Configure Shadow GPIO PortLock register for current Port and Pin */
        Registers_Shadow[PortId].Gpio_Lckr |= (Pin_Configuration_Table[Index].Pin_Configuration_Lock_Status << PinId);
        
        /* Check current pin between Pin0 to Pin7 */
        if(PinId <= Pin_7)
        {
            /* Configure Shadow GPIO Alternatefunction Low register */   
            Registers_Shadow[PortId].Gpio_Afrl |= (Pin_Configuration_Table[Index].Pin_Alternate_Function << (PinId * REG_AFRL_BITS));
        }
        else
        {
            /* Configure Shadow GPIO Alternatefunction High register */ 
            Registers_Shadow[PortId].Gpio_Afrh |= (Pin_Configuration_Table[Index].Pin_Alternate_Function << (PinId - 8  * REG_AFRH_BITS));
        }

        /* Configure Shadow GPIO Output Direction register for current Port and Pin */ 
        Registers_Shadow[PortId].Gpio_Odr |= (Pin_Configuration_Table[Index].Pin_Output_Status_Setup << PinId);
    }
}

/*_________________________________________________________________________________________
 | Function Name : Gpio_Intitialization                                                    |
 | Description : Used to Initialize IO register                                            |
 | Module : GPIO                                                                           |
 | Paramiters : TBD                                                                        |
 | Return : TBD                                                                            |
 | Synchrounsity                                                                           |
 | Reentrunt:                                                                              |
 | Size :                                                                                  |
 | Excution Time : TBD                                                                     |
 |_________________________________________________________________________________________*/
DataType_Request_Status Write_Registers_Configuration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION], DataType_Gpio_Registers Registers_Table[MAX_PORT_CONFIGURATION])
{
    /* Set return status Succssed if no error occuord */
    DataType_Request_Status Return_Status = Success;

    /* Declare variable to store current Port number */
    DataType_u8 PortId;

    /* Loop on all controller existed ports */
    for(PortId = INITIALIZE_ZERO; PortId < NUM_OF_PORTS; PortId++)
    {
        /* Check if the Port is used set the configured registers value */
        if(Port_Usage_Table[PortId] == Used)
        {
            /* Set GPIO Mode Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Moder   = Registers_Shadow[PortId].Gpio_Moder;

            /* Set GPIO Output Type Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Otyper  = Registers_Shadow[PortId].Gpio_Otyper;

            /* Set GPIO Output Speed Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Ospeedr = Registers_Shadow[PortId].Gpio_Ospeedr;

            /* Set GPIO Pullup/PullDown Resistance Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Pupdr   = Registers_Shadow[PortId].Gpio_Pupdr;

            /* Set GPIO Output Direction Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Odr     = Registers_Shadow[PortId].Gpio_Odr;

            /* Set GPIO AlternateFunction Low Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Afrl    = Registers_Shadow[PortId].Gpio_Afrl;

            /* Set GPIO AlternateFunction High Register with the Shadow value */
            Registers_Table[PortId]->Gpio_Afrh    = Registers_Shadow[PortId].Gpio_Afrh;
        }

        else
        {
            /* If Port Not used keep the reset values in the Registers */
        }
    }

    /* Loop on all used port to check the registers values are correctly set in the Hardware */
    for(PortId = INITIALIZE_ZERO; PortId < NUM_OF_PORTS; PortId++)
    {
        /* Check if the current Port is used */
        if(Port_Usage_Table[PortId] == Used)
        {
            /* If the written value is not equal to the configured value */
            if(Registers_Table[PortId]->Gpio_Moder != Registers_Shadow[PortId].Gpio_Moder)
            {
                /* Set return status with Error and Exit loop */
                Return_Status = Error;
                break;
            }
    
            else if(Registers_Table[PortId]->Gpio_Otyper  != Registers_Shadow[PortId].Gpio_Otyper)
            {
                /* Set return status with Error and Exit loop */
                Return_Status = Error;
                break;
            }
    
            else if(Registers_Table[PortId]->Gpio_Ospeedr  != Registers_Shadow[PortId].Gpio_Ospeedr)
            {
                /* Set return status with Error and Exit loop */
                Return_Status = Error;
                break;
            }
    
            else if(Registers_Table[PortId]->Gpio_Pupdr  != Registers_Shadow[PortId].Gpio_Pupdr)
            {
                /* Set return status with Error and Exit loop */
                Return_Status = Error;
                break;
            }
    
            else if(Registers_Table[PortId]->Gpio_Afrl  != Registers_Shadow[PortId].Gpio_Afrl)
            {
                /* Set return status with Error and Exit loop */
                Return_Status = Error;
                break;
            }
    
            else if(Registers_Table[PortId]->Gpio_Afrh  != Registers_Shadow[PortId].Gpio_Afrh)
            {
                /* Set return status with Error and Exit loop */
                Return_Status = Error;
                break;
            }
    
            else
            {
                /* Set return status Succssed */
                Return_Status = Success;
            }
        }

        else
        {
            /* The Port is not used Do nothing */
        }
    }

    return Return_Status;
}

/*_________________________________________________________________________________________
 | Function Name : Gpio_Intitialization                                                    |
 | Description : Used to Initialize IO register                                            |
 | Module : GPIO                                                                           |
 | Paramiters : TBD                                                                        |
 | Return : TBD                                                                            |
 | Synchrounsity                                                                           |
 | Reentrunt:                                                                              |
 | Size :                                                                                  |
 | Excution Time : TBD                                                                     |
 |_________________________________________________________________________________________*/
DataType_Request_Status Port_Lock_Init(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION], DataType_Gpio_Registers Registers_Table[MAX_PORT_CONFIGURATION])
{
    DataType_u8 Index;
    DataType_u8 PortId;
    DataType_u32 Dummy_Value = INITIALIZE_ZERO;
    DataType_Request_Status Return_Status = Busy;

    for(Index = INITIALIZE_ZERO; Index < PORT_CFG; Index++)
    {
        if(Port_Lock_Configuration_Table[Index].Port_Configuration_Lock_Key == Active)
        {
            DataType_u32 Configuration_Lock_Register = 0;
            PortId = Port_Lock_Configuration_Table[Index].Port_Id;

            Registers_Table[PortId]->Gpio_Lckr = Registers_Shadow[PortId].Gpio_Lckr | (REG_LOCK_KEY_ACTIVE_MASK);

            Registers_Table[PortId]->Gpio_Lckr = Registers_Shadow[PortId].Gpio_Lckr & (REG_LOCK_KEY_NOTACTIVE_MASK);

            Registers_Table[PortId]->Gpio_Lckr = Registers_Shadow[PortId].Gpio_Lckr | (REG_LOCK_KEY_ACTIVE_MASK);

            Configuration_Lock_Register = Registers_Table[PortId]->Gpio_Lckr;

            Configuration_Lock_Register = ((Registers_Table[PortId]->Gpio_Lckr & REG_LCKR_LCKK_MASK) >> REG_LCKR_LCKK_BIT);

            if( ((Configuration_Lock_Register & REG_LCKR_LCKK_MASK) >> REG_LCKR_LCKK_BIT) == Active)
            {
                Port_Lock_Key_Status_Table[Index].Port_Key_Status = Key_Locked;
                Return_Status = Success;
            }
            else
            {
                Port_Lock_Key_Status_Table[Index].Port_Key_Status = Key_Error;
                Return_Status = Error;
                break;
            }
        }
        else
        {
            /* Do Nothing */
        }

    }

    return Return_Status;
}

DataType_Request_Status GPIO_DeInitialization()
{

}

DataType_Request_Status GPIO_Enter_SafeState()
{

}

DataType_Validity Is_State_Valid(DataType_u32 State);


DataType_Request_Status GPIO_Set_Module_State(DataType_u32 State)
{
    DataType_Request_Status Return_Status = Unkown;

    if (Is_State_Valid(State) != Valid)
    {
        Return_Status = Invalid_Parameter;
    }
    else
    {
        GPIO_PROTECT_SECTION();
        GPIO_Module_State = State;
        GPIO_UNPROTECT_SECTION();

        Return_Status = Success;
    }

    return Return_Status;
}

DataType_Request_Status GPIO_Get_Module_State(DataType_u32Ptr State)
{
    DataType_Request_Status Return_Status = Unkown;

    if (State == NULL_PTR)
    {
        Return_Status = Null_Pointer;
    }
    else
    {
        GPIO_PROTECT_SECTION();
        *State = GPIO_Module_State;
        GPIO_UNPROTECT_SECTION();

        Return_Status = Success;
    }

    return Return_Status;
}

DataType_Request_Status GPIO_Write_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != STATE_READY)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= PIN_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;

            if(SignalValue == High)
            {
                GPIO_ENTER_CRITICAL_SECTION();
    
                Registers_Table[PortId]->Gpio_Odr |= (IO_PIN_MASK << PinId);
                Return_Status = Success;
            
                GPIO_EXIT_CRITICAL_SECTION();
            }

            else if(SignalValue == Low)
            {
                GPIO_ENTER_CRITICAL_SECTION();
    
                Registers_Table[PortId]->Gpio_Odr &= ~(IO_PIN_MASK << PinId);
                Return_Status = Success;
            
                GPIO_EXIT_CRITICAL_SECTION();
            }
            else
            {
                Return_Status = Invalid_Parameter;
            }
        }
        
    }
    return Return_Status;
}

DataType_Request_Status GPIO_Read_Pin(DataType_u16 SignalId , DataType_Output_Level* SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != STATE_READY)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalValue == NULL_PTR)
        {
            Return_Status = Null_Pointer;
        }
        else if(SignalId >= PIN_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;
            DataType_Register_Size32 Register_Reading = 0;

            Register_Reading = Registers_Table[PortId]->Gpio_Idr;
            *SignalValue = (Register_Reading & (IO_PIN_MASK << PinId)) ? High : Low;
            Return_Status = Success;
        }
        
    }
    return Return_Status;
}

DataType_Request_Status GPIO_Toggel_Pin(DataType_u16 SignalId)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != STATE_READY)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= PIN_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;

            GPIO_ENTER_CRITICAL_SECTION();

            Registers_Table[PortId]->Gpio_Odr ^= (IO_PIN_MASK << PinId);
            Return_Status = Success;
        
            GPIO_EXIT_CRITICAL_SECTION();
        }
        
    }
    return Return_Status;
}

DataType_Request_Status GPIO_Set_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;
    
    if(GPIO_Module_State != STATE_READY )
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= PIN_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;
    
            if(SignalValue == High)
            {
                Registers_Table[PortId]->Gpio_Bsrr |= (IO_PIN_MASK << PinId);
                Return_Status = Success;
            }
            else
            {
                Return_Status = Invalid_Parameter;
            }
        }
    }

    return Return_Status;
}

DataType_Request_Status GPIO_Reset_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;
    
    if(GPIO_Module_State != STATE_READY )
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= PIN_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId  = Pin_Configuration_Table[SignalId].Pin_Id;
    
            if(SignalValue == Low)
            {
                Registers_Table[PortId]->Gpio_Bsrr |= (IO_PIN_MASK << (PinId + REG_BSRR_RESET_BITS_OFFSET));
                Return_Status = Success;
            }
            else
            {
                Return_Status = Invalid_Parameter;
            }
        }
    }
    return Return_Status;
}



DataType_Validity Is_State_Valid(DataType_u32 State)
{
    DataType_Validity Return_Status = InValid;
    switch(State)
    {
        case STATE_UNDEFINDED:
        case STATE_UNINTIALIZED:
        case STATE_INITIALIZED:
        case STATE_DEINITIALIZED:
        case STATE_LOW_POWER:
        case STATE_SAFE:
        case STATE_SLEEP:
        case STATE_READY:
        case STATE_BUSY:
        case STATE_ERROR:
        {
            Return_Status = Valid;
            break;
        }
        default:
        { /* Do nothing */}
    }
    
    return Return_Status;
}