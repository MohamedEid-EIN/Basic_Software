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
* - Description: This file is used to define all used data types ( All sizes based on Architecture or compiler dependent).
* - Author      : Mohamed Eid
* - File Name   : DataTypes.h
* - File Type   : Header file
* - References  : Compiler Manual
* - Toolchain   : TBD
* - Version : History
* - 1.00.00 : File Creation
********************************************************************************************/

#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#define PORTA_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40020000U)
#define PORTB_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40020400U)
#define PORTC_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40020800U)
#define PORTD_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40020C00U)
#define PORTE_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40021000U)
#define PORTH_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40021C00U)

#define NUM_OF_PORTS                 (DataType_u8)6U

#define REG_SIZE                     (DataType_u32)32U

#define REG_MODER_BITS               (DataType_u32)2U
#define REG_OSPEEDR_BITS             (DataType_u32)2U
#define REG_PUPDR_BITS               (DataType_u32)2U
#define REG_BSRR_RESET_BITS_OFFSET   (DataType_u32)16U
#define REG_AFRL_BITS                (DataType_u32)4U
#define REG_AFRH_BITS                (DataType_u32)4U
#define Reg_AFRH_PINS_OFFSET         (DataType_u32)8U
#define REG_LCKR_LCKK_BIT            (DataType_u32)16U
#define REG_LCKR_LCKK_MASK           (DataType_u32)0x00010000U

#define MAX_PIN_CONFIGURATION        (DataType_u8)16
#define MAX_PORT_CONFIGURATION       (DataType_u8)6
#define MIN_PIN_CONFIGURATION        (DataType_u8)1
#define MIN_PORT_CONFIGURATION       (DataType_u8)1

#define REG_LOCK_KEY_ACTIVE_MASK      (DataType_u32)0x00010000U
#define REG_LOCK_KEY_NOTACTIVE_MASK   (DataType_u32)0xFFFEFFFFU

#define IO_PIN_MASK                   (DataType_u32)1U



#define GPIO_ENTER_CRITICAL_SECTION()  void
#define GPIO_EXIT_CRITICAL_SECTION() void

#define GPIO_PROTECT_SECTION() void
#define GPIO_UNPROTECT_SECTION() void




/********************************************************************************************
 * static and constant enums to define the Port registers value.
*********************************************************************************************/
typedef DataType_u32 DataType_Register;
/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    PortA = 0,
    PortB = 1,
    PortC = 2,
    PortD = 3,
    PortE = 4,
    PortH = 5
}DataType_Port_Group;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Pin_0 = 0,
    Pin_1 = 1,
    Pin_2 = 2,
    Pin_3 = 3,
    Pin_4 = 4,
    Pin_5 = 5,
    Pin_6 = 6,
    Pin_7 = 7,
    Pin_8 = 8,
    Pin_9 = 9,
    Pin_10 = 10,
    Pin_11 = 11,
    Pin_12 = 12,
    Pin_13 = 13,
    Pin_14 = 14,
    Pin_15 = 15
}DataType_Pin_Number;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Input_Mode = 0,
    Output_Mode = 1,
    Alternate_Function_Mode = 2,
    Analog_Mode = 3
}DataType_Mode;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Output_Push_Pull = 0,
    Output_Open_Drain = 1
}DataType_Output_Type;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Low_Speed = 0,
    Medium_Speed = 1,
    Fast_Speed = 2,
    High_Speed = 3
}DataType_Output_Speed;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Resistance_NotConnected = 0,
    Pullup_Resistance_Connected = 1,
    PullDown_Resistance_Connedted = 2,
}DataType_Resistance_Connection;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Reset_Pin = 0,
    Set_Pin = 1
}DataType_Output_Status_Setup;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    UnActive = 0,
    Active = 1
}DataType_Lock_Key;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Configuration_UnLocked = 0,
    Configuration_Locked = 1
}DataType_Configuration_Lock;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Key_UnLocked = 0,
    Key_Locked = 1,
    Key_Error = 2
}DataType_Key_Status;

/*_________________________________________________________________________________________
 | Name : e_Port_Group                                                                     |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Alternate_Function_0 = 0,
    Alternate_Function_1 = 1,
    Alternate_Function_2 = 2,
    Alternate_Function_3 = 3,
    Alternate_Function_4 = 4,
    Alternate_Function_5 = 5,
    Alternate_Function_6 = 6,
    Alternate_Function_7 = 7,
    Alternate_Function_8 = 8,
    Alternate_Function_9 = 9,
    Alternate_Function_10 = 10,
    Alternate_Function_11 = 11,
    Alternate_Function_12 = 12,
    Alternate_Function_13 = 13,
    Alternate_Function_14 = 14,
    Alternate_Function_15 = 15

}DataType_Alternate_Function;

/********************************************************************************************
 * Struct to define the Port registers.
*********************************************************************************************/
typedef struct
{
    volatile DataType_u32 Gpio_Moder;    /* port mode register               */
    volatile DataType_u32 Gpio_Otyper;   /* port output type register        */
    volatile DataType_u32 Gpio_Ospeedr;  /* port output speed register       */
    volatile DataType_u32 Gpio_Pupdr;    /* port pull-up/pull-down register  */
    volatile DataType_u32 Gpio_Idr;      /* port input data register         */
    volatile DataType_u32 Gpio_Odr;      /* port output data register        */
    volatile DataType_u32 Gpio_Bsrr;     /* port bit set/reset register      */
    volatile DataType_u32 Gpio_Lckr;     /* port configuration lock register */
    volatile DataType_u32 Gpio_Afrl;     /* alternate function low register  */
    volatile DataType_u32 Gpio_Afrh;     /* alternate function high register */
}DataType_Registers;

typedef struct
{
    DataType_Port_Group Port_Id;
    DataType_Pin_Number Pin_Id;
    DataType_Mode Pin_Mode;
    DataType_Output_Type Pin_Output_Type;
    DataType_Output_Speed Pin_Output_Speed;
    DataType_Resistance_Connection Pin_Resitances_Connection;
    DataType_Output_Level Pin_Output_Status_Setup;
    DataType_Configuration_Lock Pin_Configuration_Lock_Status;
    DataType_Alternate_Function Pin_Alternate_Function;
}DataType_Pin_Configuration;

typedef struct 
{
    DataType_Port_Group Port_Id;
    DataType_Lock_Key Port_Configuration_Lock_Key;
}DataType_Port_Lock_Key;

typedef struct 
{
    DataType_Port_Group Port_Id;
    DataType_Key_Status Port_Key_Status;
}DataType_Port_Lock_Status;


typedef volatile DataType_Registers* const DataType_Gpio_Registers;
#endif /* GPIO_TYPES_H */