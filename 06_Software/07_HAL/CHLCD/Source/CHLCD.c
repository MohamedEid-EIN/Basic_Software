/********************************************************************************************
* License     : MIT License
* Copyright   : (c) 2025 Mohamed Eid
********************************************************************************************/

#include "DataTypes.h"
#include "CHLCD_Cfg.h"
#include "CHLCD.h"
#include "MCAL_Int.h"

/* ==========================================================================================
 * LCD INITIALIZATION
 * ========================================================================================== */
 void LCD_Delay_us(DataType_u32 us);
void LCD_Initialization(void)
{
    /* RS must be low during init */
    MCAL_GPIO_ResetPin(LCD_PIN_RS_CFG);

    /* Power-up delay */
    LCD_Delay_ms(20U);

    /* Interface synchronization (MANDATORY) */
    LCD_SendCommand(ChLcd_Configuration_Table[0].Display_FunctionSet);
    LCD_Delay_ms(5U);

    LCD_SendCommand(ChLcd_Configuration_Table[0].Display_FunctionSet);
    LCD_Delay_us(150U);

    LCD_SendCommand(ChLcd_Configuration_Table[0].Display_FunctionSet);
    LCD_Delay_us(150U);

    /* Function Set */
    LCD_SendCommand(
        ChLcd_Configuration_Table[0].Display_FunctionSet
    );

    /* Display OFF */
    LCD_SendCommand(DISPLAY_OFF);

    /* Clear Display */
    LCD_SendCommand(DISPLAY_CLEAR);
    LCD_Delay_ms(2U);

    /* Entry Mode Set */
   //LCD_SendCommand(ChLcd_Configuration_Table[0].Display_EntryMode);

    /* Display ON */
    LCD_SendCommand(ChLcd_Configuration_Table[0].Display_Control);

//LCD_SendCommand(0x80);  // DDRAM address 0
}

/* ==========================================================================================
 * SEND COMMAND
 * ========================================================================================== */

void LCD_SendCommand(DataType_u8 Command)
{
    /* RS = 0 → Command */
    MCAL_GPIO_ResetPin(LCD_PIN_RS_CFG);
    /* Put command on data bus */
    MCAL_GPIO_WritePort(DATA_GROUP_CFG, Command);
    MCAL_GPIO_SetPin(LCD_PIN_EN_CFG);
    LCD_Delay_us(1U);
    MCAL_GPIO_ResetPin(LCD_PIN_EN_CFG);

    /* Command execution time */
    LCD_Delay_us(40U);
}

/* ==========================================================================================
 * SEND DATA (CHARACTER)
 * ========================================================================================== */

void LCD_Print(DataType_u8 Data)
{
    /* RS = 1 → Data */
    MCAL_GPIO_SetPin(LCD_PIN_RS_CFG);
    /* Put data on data bus */
    MCAL_GPIO_WritePort(DATA_GROUP_CFG, Data);
    /* Enable pulse */
    MCAL_GPIO_SetPin(LCD_PIN_EN_CFG);
    LCD_Delay_us(1U);
    MCAL_GPIO_ResetPin(LCD_PIN_EN_CFG);

    /* Data execution time */
    LCD_Delay_us(40U);
}

/* ==========================================================================================
 * DELAY FUNCTIONS
 * ========================================================================================== */

 void LCD_Delay_us(DataType_u32 us)
{
    volatile DataType_u32 count;

    while (us--)
    {
        for (count = 0U; count < 10U; count++)
        {
            __asm volatile ("nop");
        }
    }
}

 void LCD_Delay_ms(DataType_u32 ms)
{
    while (ms--)
    {
        LCD_Delay_us(1000U);
    }
}
