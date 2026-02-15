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
* - File Name   : GPIO.c
* - File Type   : Source File
* - Module      : GPIO
* - Layer       : MCAL
* - Description : GPIO driver implementation.
* - Design Note : Implements GPIO services using register-level access.
* - Toolchain   : Independent
* - References  : STM32 Reference Manual.
*--------------------------------------------------------------------------------------------
* Version History
*--------------------------------------------------------------------------------------------
* Version | Date       | Author       | Description
* --------|------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------------
* 1.00.00 | 2025-12-01 | Mohamed Eid  | Initial GPIO driver implementation
**********************************************************************************************************************************************************************************/

#include "GPIO.h"          /* GPIO public interfaces */
#include "GPIO_Cfg.h"      /* GPIO static configuration */
#include "UTILS_Int.h"     /* Utility macros and helpers */

/**********************************************************************************************************************************************************************************
 * Data Declaration Section
**********************************************************************************************************************************************************************************/
/*__________________________________________________________________________________________
| Data Name    : GPIO_Module_State                                                         |
| Description  : Holds the current state of the GPIO module                                |
| Type         : DataType_u32                                                              |
| Size         : 4 Bytes                                                                   |
| Storage      : RAM                                                                       |
| Usage        : Used to control GPIO service availability                                 |
|_________________________________________________________________________________________*/
volatile DataType_u32 GPIO_Module_State = LIB_UTILS_STATE_UNDEFINED;

/*__________________________________________________________________________________________
| Data Name    : PortLockStatus_Table                                                      |
| Description  : Runtime table tracking GPIO port lock status                              |
| Type         : Array of DataType_PortLockStatus                                          |
| Element Size : 4 Bytes (u32-based structure)                                             |
| Array Size   : HW_SUPPORTED_PORTS_NUM × 4 Bytes                                          |
| Storage      : RAM                                                                       |
| Usage        : Monitor whether a port is locked or unlocked                              |
|_________________________________________________________________________________________*/
DataType_PortLockStatus PortLockStatus_Table[HW_SUPPORTED_PORTS_NUM] =
{
    {PortA, Key_UnLocked},
    {PortB, Key_UnLocked},
    {PortC, Key_UnLocked},
    {PortD, Key_UnLocked},
    {PortE, Key_UnLocked},
    {PortH, Key_UnLocked}
};

/*__________________________________________________________________________________________
| Data Name    : Registers_Table                                                           |
| Description  : Maps logical port indices to GPIO register base addresses                 |
| Type         : Array of DataType_GpioRegisters                                           |
| Element Size : 4 Bytes (register base address)                                           |
| Array Size   : HW_SUPPORTED_PORTS_NUM × 4 Bytes                                          |
| Storage      : RAM                                                                       |
| Usage        : Used for direct hardware register access                                  |
|_________________________________________________________________________________________*/
 DataType_GpioRegisters Registers_Table[HW_SUPPORTED_PORTS_NUM] =
{
    PORTA_BASE_ADDRESS,
    PORTB_BASE_ADDRESS,
    PORTC_BASE_ADDRESS,
    PORTD_BASE_ADDRESS,
    PORTE_BASE_ADDRESS,
    PORTH_BASE_ADDRESS
};

/*__________________________________________________________________________________________
| Data Name    : PortUsage_Table                                                          |
| Description  : Tracks whether each GPIO port is used by configuration                   |
| Type         : Array of DataType_Usage                                                  |
| Element Size : 4 Bytes (u32 enum)                                                       |
| Array Size   : HW_SUPPORTED_PORTS_NUM × 4 Bytes                                         |
| Storage      : RAM                                                                      |
| Usage        : Skip unused ports during configuration                                   |
|_________________________________________________________________________________________*/
DataType_Usage PortUsage_Table[HW_SUPPORTED_PORTS_NUM] = {Unused};

/**********************************************************************************************************************************************************************************
 * Function Definitions Section
**********************************************************************************************************************************************************************************/

/*_________________________________________________________________________________________________________________________________________
 | Function Name : GPIO_Intitialization                                                                                                    |
 | Module        : GPIO                                                                                                                    |
 | Layer         : MCAL                                                                                                                    |
 | Description   : Initializes the GPIO module by configuring all GPIO registers                                                           |
 |                 using static configuration data.                                                                                        |
 | Sync/Async    : Synchronous                                                                                                             |
 | Reentrancy    : Non-Reentrant                                                                                                           |
 | Parameters    : None                                                                                                                    |
 | Return        : DataType_Request_Status                                                                                                 |
 | Preconditions : MCU clock and RCC must be initialized                                                                                   |
 | Postconditions: GPIO module state is set to Initialized                                                                                 |
 | Usage         : Initialize all GPIO registers and apply user pin configurations                                                         |
 | Context       : Startup / MCU context                                                                                                   |
 | Notes         : NA                                                                                                                      |
 |________________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_Intitialization(void)
{
    /* Variable to store function execution status */
    DataType_Request_Status Return_Status = Unkown;

    /* Set GPIO module state to uninitialized before configuration */
    GPIO_Module_State = LIB_UTILS_STATE_UNINITIALIZED;

    /* Validate number of configured ports and pins */
    if (NUMBER_PORT_CFG < MIN_PORT_CONFIGURATION || NUMBER_PORT_CFG > MAX_PORT_CONFIGURATION ||
        NUMBER_PINS_CFG  < MIN_PIN_CONFIGURATION  || NUMBER_PINS_CFG  > MAX_PIN_CONFIGURATION)
    {
        /* Configuration parameters are invalid */
        Return_Status = Invalid_Parameter;
    }
    else
    {
        /* Shadow register table to build GPIO configuration safely */
        DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION] = {INITIALIZE_ZERO};

        /* Build shadow register configuration based on pin configuration table */
        GPIO_BuildConfiguration(Registers_Shadow);

        /* Write shadow register values to actual hardware registers */
        Return_Status = GPIO_ConfigureRegisters(Registers_Shadow, Registers_Table);

        /* Check hardware write operation result */
        if(Return_Status != Success)
        {
            /* Hardware configuration failed */
            Return_Status = Error;
        }
        else
        {
            /* Initialize GPIO port lock feature */
            Return_Status = GPIO_PortLockInit(Registers_Shadow, Registers_Table);

            /* Check lock initialization result */
            if(Return_Status != Success)
            {
                /* Port locking failed */
                Return_Status = Error;
            }
            else
            {
                /* Configuration and locking completed successfully set module state Initialized */
                GPIO_SetModuleState(LIB_UTILS_STATE_READY);
                Return_Status = Success;
            }
        }
    }

    /* Return final operation status */
    return Return_Status;
}

/*____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_BuildConfiguration                                                                                            |
 | Module        : GPIO                                                                                                               |
 | Layer         : MCAL                                                                                                               |
 | Description   : Builds GPIO register values in shadow registers based on static pin configuration.                                 |
 | Sync/Async    : Synchronous                                                                                                        |
 | Reentrancy    : Non-Reentrant                                                                                                      |
 | Parameters    : Input : Registers_Shadow                                                                                           |
 | Return        : None                                                                                                               |
 | Preconditions : GPIO module not yet initialized                                                                                    |
 | Usage         : Prepare GPIO configuration before hardware write                                                                   |
 | Context       : MCU context                                                                                                        |
 | Notes         : Does not access hardware registers                                                                                 |
 |___________________________________________________________________________________________________________________________________*/
void GPIO_BuildConfiguration(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION])
{
    /* Index for iterating over configured pins */
    DataType_u8 Index;

    /* Variables to store port and pin identifiers */
    DataType_u8 PortId;
    DataType_u32 PinId;

    /* Iterate over all configured pins */
    for(Index = INITIALIZE_ZERO; Index < NUMBER_PINS_CFG; Index++)
    {
        /* Extract port and pin identifiers from configuration table */
        PortId = PinSetUp_TableCfg[Index].Port_Id;
        PinId  = PinSetUp_TableCfg[Index].Pin_Id;

        /* Mark the port as used */
        PortUsage_Table[PortId] = Used;

        /* Configure GPIO mode in shadow register */
        Registers_Shadow[PortId].Gpio_Moder |= (PinSetUp_TableCfg[Index].Pin_Mode << (PinId * REG_MODER_BITS));

        /* Configure output type in shadow register */
        Registers_Shadow[PortId].Gpio_Otyper |= (PinSetUp_TableCfg[Index].Pin_Output_Type << PinId);

        /* Configure output speed in shadow register */
        Registers_Shadow[PortId].Gpio_Ospeedr |= (PinSetUp_TableCfg[Index].Pin_Output_Speed << (PinId * REG_OSPEEDR_BITS));

        /* Configure pull-up / pull-down resistance */
        Registers_Shadow[PortId].Gpio_Pupdr |= (PinSetUp_TableCfg[Index].Pin_Resitances_Connection << (PinId * REG_PUPDR_BITS));

        /* Configure pin lock bit in shadow register */
        Registers_Shadow[PortId].Gpio_Lckr |= (PinSetUp_TableCfg[Index].Pin_Configuration_Lock_Status << PinId);

        /* Select alternate function low or high register based on pin index */
        if(PinId <= Pin_7)
        {
            /* Configure AFRL register */
            Registers_Shadow[PortId].Gpio_Afrl |= (PinSetUp_TableCfg[Index].Pin_Alternate_Function << (PinId * REG_AFRL_BITS));
        }
        else
        {
            /* Configure AFRH register */
            Registers_Shadow[PortId].Gpio_Afrh |= (PinSetUp_TableCfg[Index].Pin_Alternate_Function << ((PinId - REG_AFRH_PINS_OFFSET) * REG_AFRH_BITS));
        }

        /* Configure initial output level */
        Registers_Shadow[PortId].Gpio_Odr |= (PinSetUp_TableCfg[Index].Pin_Output_Status_Setup << PinId);
    }
}
/*___________________________________________________________________________________________________________________________________
| Function Name : GPIO_WriteRegistersConfiguration                                                                                  |
| Module        : GPIO                                                                                                              |
| Layer         : MCAL                                                                                                              |
| Description   : Writes GPIO shadow register values into hardware registers and verifies the written values.                       |
| Sync/Async    : Synchronous                                                                                                       |
| Reentrancy    : Non-Reentrant                                                                                                     |
| Parameters    : Input : Registers_Shadow                                                                                          |
|               : Input : Registers_Table                                                                                           |
| Return        : DataType_Request_Status                                                                                           |
| Preconditions : GPIO shadow configuration must be built                                                                           |
| Usage         : Apply GPIO configuration to hardware                                                                              |
| Context       : MCU context                                                                                                       |
| Notes         : Writes only ports marked as Used                                                                                  |
|__________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_ConfigureRegisters(DataType_Registers Registers_Shadow[HW_SUPPORTED_PORTS_NUM], DataType_GpioRegisters Registers_Table[HW_SUPPORTED_PORTS_NUM])
{
    /* Initialize return status assuming success */
    DataType_Request_Status Return_Status = Success;

    /* Variable to iterate over all supported ports */
    DataType_u8 PortId;

    /* Loop through all hardware-supported ports */
    for(PortId = INITIALIZE_ZERO; PortId < HW_SUPPORTED_PORTS_NUM; PortId++)
    {
        /* Check whether the current port is marked as used */
        if(PortUsage_Table[PortId] == Used)
        {
            /* Initialize GPIO mode register with Configuration */
            Registers_Table[PortId]->Gpio_Moder = Registers_Shadow[PortId].Gpio_Moder;

            /* Initialize GPIO output type register with Configuration */
            Registers_Table[PortId]->Gpio_Otyper = Registers_Shadow[PortId].Gpio_Otyper;

            /* Initialize GPIO output speed register with Configuration */
            Registers_Table[PortId]->Gpio_Ospeedr = Registers_Shadow[PortId].Gpio_Ospeedr;

            /* Initialize GPIO pull-up / pull-down register with Configuration */
            Registers_Table[PortId]->Gpio_Pupdr = Registers_Shadow[PortId].Gpio_Pupdr;

            /* Initialize GPIO output data register with Configuration */
            Registers_Table[PortId]->Gpio_Odr = Registers_Shadow[PortId].Gpio_Odr;

            /* Initialize GPIO alternate function low register with Configuration */
            Registers_Table[PortId]->Gpio_Afrl = Registers_Shadow[PortId].Gpio_Afrl;

            /* Initialize GPIO alternate function high register with Configuration */
            Registers_Table[PortId]->Gpio_Afrh = Registers_Shadow[PortId].Gpio_Afrh;
        }
        else
        {
            /* Initialize GPIO mode register with Zero */
            Registers_Table[PortId]->Gpio_Moder = INITIALIZE_ZERO;

            /* Initialize GPIO output type register with Zero */
            Registers_Table[PortId]->Gpio_Otyper = INITIALIZE_ZERO;

            /* Initialize GPIO output speed register with Zero */
            Registers_Table[PortId]->Gpio_Ospeedr = INITIALIZE_ZERO;

            /* Initialize GPIO pull-up / pull-down register with Zero */
            Registers_Table[PortId]->Gpio_Pupdr = INITIALIZE_ZERO;

            /* Initialize GPIO output data register with Zero */
            Registers_Table[PortId]->Gpio_Odr = INITIALIZE_ZERO;

            /* Initialize GPIO alternate function low register with Zero */
            Registers_Table[PortId]->Gpio_Afrl = INITIALIZE_ZERO;

            /* Initialize GPIO alternate function high register with Zero */
            Registers_Table[PortId]->Gpio_Afrh = INITIALIZE_ZERO;
        }
    }

    /* Verify written values by comparing hardware registers with shadow registers */
    for(PortId = INITIALIZE_ZERO; PortId < HW_SUPPORTED_PORTS_NUM; PortId++)
    {
        /* Only verify ports that were configured */
        if(PortUsage_Table[PortId] == Used)
        {
            /* Verify GPIO mode register */
            if(Registers_Table[PortId]->Gpio_Moder != Registers_Shadow[PortId].Gpio_Moder)
            {
                /* Setting configuration into register is not successful return Error */
                Return_Status = Error;
                break;
            }
            /* Verify GPIO output type register */
            else if(Registers_Table[PortId]->Gpio_Otyper != Registers_Shadow[PortId].Gpio_Otyper)
            {
                /* Setting configuration into register is not successful return Error */
                Return_Status = Error;
                break;
            }
            /* Verify GPIO output speed register */
            else if(Registers_Table[PortId]->Gpio_Ospeedr != Registers_Shadow[PortId].Gpio_Ospeedr)
            {
                /* Setting configuration into register is not successful return Error */
                Return_Status = Error;
                break;
            }
            /* Verify GPIO pull-up / pull-down register */
            else if(Registers_Table[PortId]->Gpio_Pupdr != Registers_Shadow[PortId].Gpio_Pupdr)
            {
                /* Setting configuration into register is not successful return Error */
                Return_Status = Error;
                break;
            }
            /* Verify GPIO alternate function low register */
            else if(Registers_Table[PortId]->Gpio_Afrl != Registers_Shadow[PortId].Gpio_Afrl)
            {
                /* Setting configuration into register is not successful return Error */
                Return_Status = Error;
                break;
            }
            /* Verify GPIO alternate function high register */
            else if(Registers_Table[PortId]->Gpio_Afrh != Registers_Shadow[PortId].Gpio_Afrh)
            {
                /* Setting configuration into register is not successful return Error */
                Return_Status = Error;
                break;
            }
            else
            {
                /* All used register values match the shadow configuration */
                Return_Status = Success;
            }
        }
        else
        {
            /* Port was not configured, skip verification */
        }
    }

    /* Return final verification result */
    return Return_Status;
}

/*__________________________________________________________________________________________________________________________________
 | Function Name : GPIO_PortLockInit                                                                                                |
 | Module        : GPIO                                                                                                             |
 | Layer         : MCAL                                                                                                             |
 | Description   : Applies GPIO port configuration lock according to static configuration and verifies lock activation.             |
 | Sync/Async    : Synchronous                                                                                                      |
 | Reentrancy    : Non-Reentrant                                                                                                    |
 | Parameters    : Input : Registers_Shadow                                                                                         |
 |               : Input : Registers_Table                                                                                          |
 | Return        : DataType_Request_Status                                                                                          |
 | Preconditions : GPIO registers must be configured                                                                                |
 | Usage         : Lock GPIO configuration to prevent runtime changes                                                               |
 | Context       : MCU context                                                                                                      |
 | Notes         : Uses STM32 GPIO lock sequence                                                                                    |
 |_________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_PortLockInit(DataType_Registers Registers_Shadow[MAX_PORT_CONFIGURATION], DataType_GpioRegisters Registers_Table[MAX_PORT_CONFIGURATION])
{
    /* Loop index for configured ports */
    DataType_u8 Index;

    /* Initialize return status as busy */
    DataType_Request_Status Return_Status = Success;

    /* Iterate over port lock configuration table */
    for(Index = INITIALIZE_ZERO; Index < NUMBER_PORT_CFG; Index++)
    {
        /* Check if lock is enabled for the current port */
        if(PortLock_TableCfg[Index].Port_Configuration_Lock_Key == Active)
        {
            /* Variable to hold current port identifier */
            DataType_u8 PortId;

           /* variable used to read back lock register */
           DataType_u32 Configuration_Lock_Register = INITIALIZE_ZERO;

            /* Read configured port identifier */
            PortId = PortLock_TableCfg[Index].Port_Id;

            /* Write lock key sequence: set LCKK bit */
            Registers_Table[PortId]->Gpio_Lckr =
                Registers_Shadow[PortId].Gpio_Lckr | REG_LOCK_KEY_ACTIVE_MASK;

            /* Clear LCKK bit */
            Registers_Table[PortId]->Gpio_Lckr =
                Registers_Shadow[PortId].Gpio_Lckr & REG_LOCK_KEY_NOTACTIVE_MASK;

            /* Set LCKK bit again to complete lock sequence */
            Registers_Table[PortId]->Gpio_Lckr =
                Registers_Shadow[PortId].Gpio_Lckr | REG_LOCK_KEY_ACTIVE_MASK;

            /* Read back lock register to finalize sequence */
            Configuration_Lock_Register = Registers_Table[PortId]->Gpio_Lckr;

            /* Check whether lock bit is set */
            if(((Configuration_Lock_Register & REG_LCKR_LCKK_MASK) >> REG_LCKR_LCKK_BIT) == Active)
            {
                /* Mark port as locked */
                PortLockStatus_Table[Index].Port_Key_Status = Key_Locked;
            }
            else
            {
                /* Lock failed */
                PortLockStatus_Table[Index].Port_Key_Status = Key_Error;
                Return_Status = Error;
                break;
            }
        }
        else
        {
            /* Port lock not enabled, do nothing */
        }
    }

    /* Return lock initialization status */
    return Return_Status;
}

/*___________________________________________________________________________________________________________________________________
 | Function Name : GPIO_SetModuleState                                                                                               |
 | Module        : GPIO                                                                                                              |
 | Layer         : MCAL                                                                                                              |
 | Description   : Updates the internal GPIO module state                                                                            |
 | Sync/Async    : Synchronous                                                                                                       |
 | Reentrancy    : Non-Reentrant                                                                                                     |
 | Parameters    : Input : State                                                                                                     |
 | Return        : DataType_Request_Status                                                                                           |
 | Preconditions : State must be valid                                                                                               |
 | Usage         : Control GPIO module lifecycle                                                                                     |
 | Context       : MCU context                                                                                                       |
 | Notes         : Internal service                                                                                                  |
 |__________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_SetModuleState(DataType_u32 State)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Validate requested state */
    if (LIB_UTILS_IsValidState(State) != Valid)
    {
        /* Invalid state provided */
        Return_Status = Invalid_Parameter;
    }
    else
    {
        /* Update module state */
        GPIO_Module_State = State;

        /* State update successful */
        Return_Status = Success;
    }

    /* Return state update result */
    return Return_Status;
}

/*_____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_GetModuleState                                                                                                 |
 | Module        : GPIO                                                                                                                |
 | Layer         : MCAL                                                                                                                |
 | Description   : Returns the current GPIO module state                                                                               |
 | Sync/Async    : Synchronous                                                                                                         |
 | Reentrancy    : Reentrant                                                                                                           |
 | Parameters    : None                                                                                                                |
 | Return        : DataType_u32                                                                                                        |
 | Preconditions : None                                                                                                                |
 | Usage         : Query GPIO module state                                                                                             |
 | Context       : MCU context                                                                                                         |
 | Notes         : NA                                                                                                                  |
 |____________________________________________________________________________________________________________________________________*/
DataType_u32 GPIO_GetModuleState(void)
{
    /* Read current module state */
    DataType_u32 State = GPIO_Module_State;

    /* Return module state */
    return State;
}

/*_____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_WritePort                                                                                                      |
 | Module        : GPIO                                                                                                                |
 | Layer         : MCAL                                                                                                                |
 | Description   : Writes a value to the output data register of a GPIO port                                                           |
 | Sync/Async    : Synchronous                                                                                                         |
 | Reentrancy    : Non-Reentrant                                                                                                       |
 | Parameters    : Input : PortId                                                                                                      |
 |               : Input : PortValue                                                                                                   |
 | Return        : DataType_Request_Status                                                                                             |
 | Preconditions : GPIO module state must be Ready                                                                                     |
 | Usage         : Set all output pins of a specific port                                                                              |
 | Context       : MCU context                                                                                                         |
 | Notes         : Affects all pins of the selected port                                                                               |
 |____________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_WritePort(DataType_u8 Index, DataType_u16 PortValue)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Check if GPIO module is ready */
    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        /* Module not ready */
        Return_Status = Invalid;
    }
    else
    {
        /* Validate port identifier */
        if(Index >= NUMBER_PORT_CFG)
        {
            /* Invalid port ID */
            Return_Status = Invalid_Parameter;
        }
        else
        {
            /* Write value to output data register */
            Registers_Table[Index]->Gpio_Odr = PortValue;

            /* Write operation successful */
            Return_Status = Success;
        }
    }

    /* Return operation result */
    return Return_Status;
}

/*____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_WritePin                                                                                                      |
 | Module        : GPIO                                                                                                               |
 | Layer         : MCAL                                                                                                               |
 | Description   : Writes a logical level to a specific GPIO pin                                                                      |
 | Sync/Async    : Synchronous                                                                                                        |
 | Reentrancy    : Reentrant (different PinId)                                                                                        |
 | Parameters    : Input : PinId                                                                                                      |
 |               : Input : PinValue                                                                                                   |
 | Return        : DataType_Request_Status                                                                                            |
 | Preconditions : GPIO module state must be Ready                                                                                    |
 | Usage         : Set or clear a specific GPIO pin                                                                                   |
 | Context       : MCU context                                                                                                        |
 | Notes         : Valid only for output pins                                                                                         |
 |___________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_WritePin(DataType_u8 Index, DataType_Output_Level PinValue)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Check if GPIO module is in ready state */
    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        /* GPIO module not ready */
        Return_Status = Invalid;
    }
    else
    {
        /* Validate pin identifier */
        if(Index >= NUMBER_PINS_CFG)
        {
            /* Pin ID is out of configured range */
            Return_Status = Invalid_Parameter;
        }
        else
        {
            /* Extract port ID from pin configuration table */
            DataType_PortName PortId = PinSetUp_TableCfg[Index].Port_Id;

            /* Extract hardware pin number from pin configuration table */
            DataType_PinNumber PinId = PinSetUp_TableCfg[Index].Pin_Id;

            /* Check requested output level */
            if(PinValue == High)
            {
                /* Set pin output level to HIGH */
                Registers_Table[PortId]->Gpio_Odr |= (IO_PIN_MASK << PinId);

                /* Operation successful */
                Return_Status = Success;
            }
            else if(PinValue == Low)
            {
                /* Set pin output level to LOW */
                Registers_Table[PortId]->Gpio_Odr &= ~(IO_PIN_MASK << PinId);

                /* Operation successful */
                Return_Status = Success;
            }
            else
            {
                /* Invalid pin level value */
                Return_Status = Invalid_Parameter;
            }
        }
    }

    /* Return operation result */
    return Return_Status;
}

/*____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_ReadPin                                                                                                       |
 | Module        : GPIO                                                                                                               |
 | Layer         : MCAL                                                                                                               |
 | Description   : Reads the logical level of a specific GPIO pin                                                                     |
 | Sync/Async    : Synchronous                                                                                                        |
 | Reentrancy    : Reentrant (different PinId)                                                                                        |
 | Parameters    : Input  : PinId                                                                                                     |
 |               : Output : PinValue                                                                                                  |
 | Return        : DataType_Request_Status                                                                                            |
 | Preconditions : GPIO module state must be Ready                                                                                    |
 | Usage         : Read the current level of a specific GPIO pin                                                                      |
 | Context       : MCU context                                                                                                        |
 | Notes         : Works for both input and output pins                                                                               |
 |___________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_ReadPin(DataType_u8 Index , DataType_Output_Level* PinValue)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Check if GPIO module is ready */
    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        /* GPIO module not ready */
        Return_Status = Invalid;
    }
    else
    {
        /* Check for NULL pointer */
        if(PinValue == NULL_PTR)
        {
            /* Output pointer is NULL */
            Return_Status = Null_Pointer;
        }
        /* Validate pin identifier */
        else if(Index >= NUMBER_PINS_CFG)
        {
            /* Pin ID is invalid */
            Return_Status = Invalid_Parameter;
        }
        else
        {
            /* Extract port ID from pin configuration table */
            DataType_PortName PortId = PinSetUp_TableCfg[Index].Port_Id;

            /* Extract hardware pin number from pin configuration table */
            DataType_PinNumber PinId = PinSetUp_TableCfg[Index].Pin_Id;

            /* Variable to store input register reading */
            DataType_Register_Size32 Register_Reading = INITIALIZE_ZERO;

            /* Read GPIO input data register */
            Register_Reading = Registers_Table[PortId]->Gpio_Idr;

            /* Extract pin state and assign logical level */
            *PinValue = (Register_Reading & (IO_PIN_MASK << PinId)) ? High : Low;

            /* Read operation successful */
            Return_Status = Success;
        }
    }

    /* Return operation result */
    return Return_Status;
}

/*____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_ToggelPin                                                                                                     |
 | Module        : GPIO                                                                                                               |
 | Layer         : MCAL                                                                                                               |
 | Description   : Toggles the output level of a specific GPIO pin                                                                    |
 | Sync/Async    : Synchronous                                                                                                        |
 | Reentrancy    : Reentrant (different PinId)                                                                                        |
 | Parameters    : Input : PinId                                                                                                      |
 | Return        : DataType_Request_Status                                                                                            |
 | Preconditions : GPIO module state must be Ready                                                                                    |
 | Usage         : Toggle a specific GPIO pin                                                                                         |
 | Context       : MCU context                                                                                                        |
 | Notes         : Valid only for output pins                                                                                         |
 |___________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_ToggelPin(DataType_u8 Index)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Check if GPIO module is ready */
    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        /* GPIO module not ready */
        Return_Status = Invalid;
    }
    else
    {
        /* Validate pin identifier */
        if(Index >= NUMBER_PINS_CFG)
        {
            /* Pin ID is invalid */
            Return_Status = Invalid_Parameter;
        }
        else
        {
            /* Extract port ID from pin configuration table */
            DataType_PortName PortId = PinSetUp_TableCfg[Index].Port_Id;

            /* Extract hardware pin number from pin configuration table */
            DataType_PinNumber PinId = PinSetUp_TableCfg[Index].Pin_Id;

            /* Toggle pin output level */
            Registers_Table[PortId]->Gpio_Odr ^= (IO_PIN_MASK << PinId);

            /* Toggle operation successful */
            Return_Status = Success;
        }
    }

    /* Return operation result */
    return Return_Status;
}

/*____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_SetPin                                                                                                        |
 | Module        : GPIO                                                                                                               |
 | Layer         : MCAL                                                                                                               |
 | Description   : Sets a specific GPIO pin to logical HIGH                                                                           |
 | Sync/Async    : Synchronous                                                                                                        |
 | Reentrancy    : Reentrant (different PinId)                                                                                        |
 | Parameters    : Input : PinId                                                                                                      |
 | Return        : DataType_Request_Status                                                                                            |
 | Preconditions : GPIO module state must be Ready                                                                                    |
 | Usage         : Set a specific GPIO pin                                                                                            |
 | Context       : MCU context                                                                                                        |
 | Notes         : Uses BSRR register for atomic operation                                                                            |
 |___________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_SetPin(DataType_u8 Index)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Check if GPIO module is ready */
    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        /* GPIO module not ready */
        Return_Status = Invalid;
    }
    else
    {
        /* Validate pin identifier */
        if(Index >= NUMBER_PINS_CFG)
        {
            /* Pin ID is invalid */
            Return_Status = Invalid_Parameter;
        }
        else
        {
            /* Extract port ID from pin configuration table */
            DataType_PortName PortId = PinSetUp_TableCfg[Index].Port_Id;

            /* Extract hardware pin number from pin configuration table */
            DataType_PinNumber PinId = PinSetUp_TableCfg[Index].Pin_Id;

            /* Set pin output level using bit set/reset register */
            Registers_Table[PortId]->Gpio_Bsrr = (IO_PIN_MASK << PinId);

            /* Set operation successful */
            Return_Status = Success;
        }
    }

    /* Return operation result */
    return Return_Status;
}

/*____________________________________________________________________________________________________________________________________
 | Function Name : GPIO_ResetPin                                                                                                      |
 | Module        : GPIO                                                                                                               |
 | Layer         : MCAL                                                                                                               |
 | Description   : Resets a specific GPIO pin to logical LOW                                                                          |
 | Sync/Async    : Synchronous                                                                                                        |
 | Reentrancy    : Reentrant (different PinId)                                                                                        |
 | Parameters    : Input : PinId                                                                                                      |
 | Return        : DataType_Request_Status                                                                                            |
 | Preconditions : GPIO module state must be Ready                                                                                    |
 | Usage         : Reset a specific GPIO pin                                                                                          |
 | Context       : MCU context                                                                                                        |
 | Notes         : Uses BSRR register for atomic operation                                                                            |
 |___________________________________________________________________________________________________________________________________*/
DataType_Request_Status GPIO_ResetPin(DataType_u8 Index)
{
    /* Initialize return status */
    DataType_Request_Status Return_Status = Unkown;

    /* Check if GPIO module is ready */
    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        /* GPIO module not ready */
        Return_Status = Invalid;
    }
    else
    {
        /* Validate pin identifier */
        if(Index >= NUMBER_PINS_CFG)
        {
            /* Pin ID is invalid */
            Return_Status = Invalid_Parameter;
        }
        else
        {
            /* Extract port ID from pin configuration table */
            DataType_PortName PortId = PinSetUp_TableCfg[Index].Port_Id;

            /* Extract hardware pin number from pin configuration table */
            DataType_PinNumber PinId = PinSetUp_TableCfg[Index].Pin_Id;

            /* Reset pin output level using BSRR reset bit offset */
            Registers_Table[PortId]->Gpio_Bsrr = (IO_PIN_MASK << (PinId + REG_BSRR_RESET_BITS_OFFSET));

            /* Reset operation successful */
            Return_Status = Success;
        }
    }

    /* Return operation result */
    return Return_Status;
}
