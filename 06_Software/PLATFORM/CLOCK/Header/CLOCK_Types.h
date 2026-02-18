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
* - File Name   : CLOCK_Types.h
* - File Type   : Header File
* - Module      : CLOCK
* - Layer       : PLATFORM
* - Description : TBD.
* - Design Note : None.
* - Toolchain   : None.
* - References  : None.
*--------------------------------------------------------------------------------------------
* - Version History :
*   - 1.00.00  | 2025-12-01 | Mohamed Eid | File Creation
*********************************************************************************************/
#ifndef CLOCK_H
#define CLOCK_H

#include "DataTypes.h"

#define REG_RCCAHB1ENR_ADDRESS ((volatile DataType_u32Ptr const) 0x40023830)


#define REG_BIT_GPIOAEN_MASK (DataType_u32)0x00000001U /* Register: RCC_AHB1ENR->GPIOAEN: Clock enable bit for GPIO PORTA */
#define REG_BIT_GPIOBEN_MASK (DataType_u32)0x00000002U /* Register: RCC_AHB1ENR->GPIOBEN: Clock enable bit for GPIO PORTb */
#define REG_BIT_GPIOCEN_MASK (DataType_u32)0x00000004U /* Register: RCC_AHB1ENR->GPIOCEN: Clock enable bit for GPIO PORTC */
#define REG_BIT_GPIODEN_MASK (DataType_u32)0x00000008U /* Register: RCC_AHB1ENR->GPIODEN: Clock enable bit for GPIO PORTD */
#define REG_BIT_GPIOEEN_MASK (DataType_u32)0x00000010U /* Register: RCC_AHB1ENR->GPIOEEN: Clock enable bit for GPIO PORTE */
#define REG_BIT_GPIOHEN_MASK (DataType_u32)0x00000080U /* Register: RCC_AHB1ENR->GPIOHEN: Clock enable bit for GPIO PORTH */

#define REG_BIT_GPIOAEN_DISBALE (DataType_u32)0x00000000U /* Clock disable MASK for GPIOxEN */
#define REG_BIT_GPIOAEN_ENABLE  (DataType_u32)0x00000001U /* Clock enable MASK for GPIOxEN */

typedef enum
{
    GpioA_Clock = 0,
    GpioB_Clock,
    GpioC_Clock,
    GpioD_Clock,
    GpioE_Clock,
    GpioH_Clock,

    ClockIndex_Cfg
}DataType_GpioClockState;

typedef struct
{
    volatile DataType_u32 Clock_RCC_AHB1ENR;
}DataTypeRegister_Clock;






#endif /* CLOCK_H */
