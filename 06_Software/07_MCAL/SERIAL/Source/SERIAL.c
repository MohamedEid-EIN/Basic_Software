#include "DataTypes.h"
#include "USART_Cfg.h"
DataType_Request_Status Build_Common_Configuration(DataType_Registers Register_Shadow_Table[USART_CHANNEL_NUM_CFG])

const volatile DataType_Usart_Registers Registers_Table[USART_CHANNEL_NUM] = 
{
    USART1_BASE_ADDRESS,
    USART2_BASE_ADDRESS,
    USART6_BASE_ADDRESS
};

DataType_Request_Status Serial_Initialization(void)
{
    DataType_Request_Status Return_Status = Error;

    if(USART_CHANNEL_NUM_CFG >= USART_CHANNEL_NUM)
    {
        Return_Status = Invalid_Parameter;
    }
    else
    {
        static DataType_Registers Register_Shadow_Table[USART_CHANNEL_NUM_CFG] = {INITIALIZE_ZERO};
        Return_Status = Build_Common_Configuration(Register_Shadow_Table);
    }

    return Return_Status;
}



DataType_Request_Status Build_Common_Configuration(DataType_Registers Register_Shadow_Table[USART_CHANNEL_NUM_CFG])
{
    DataType_u8 Index;
    DataType_Request_Status Return_Status = Error;
    DataType_Registers Register_Shadow_Table[USART_CHANNEL_NUM] = {0};

    if(Register_Shadow_Table == NULL_PTR || Serial_Configuration_Table == NULL_PTR)
    {
        Return_Status = Null_Pointer;
    }
    else
    {
        for(Index = 0; Index < USART_CHANNEL_NUM; Index++)
        {
            /* Prepare DIV_Fraction bits in the Baud rate register */
            Register_Shadow_Table[Index].Usart_BRR.Bit.DIV_Fraction = 0;

            /* Prepare with DIV_Mantissa bits in the Baud rate register */
            Register_Shadow_Table[Index].Usart_BRR.Bit.DIV_Mantissa = 0;

            /* Prepare RE: Receiver enable bit in the Control1 Register */
            Register_Shadow_Table[Index].Usart_CR1.Bit.RE = Serial_Configuration_Table[Index].SerialCommon_Cfg.RxControl_State;
            
            /* Prepare TE: Transmitter enable bit in the Control1 Register */
            Register_Shadow_Table[Index].Usart_CR1.Bit.TE = Serial_Configuration_Table[Index].SerialCommon_Cfg.TxControl_State;;
            
            /* Prepare RXNEIE: Receiver not empty bit in the Control1 Register */
            Register_Shadow_Table[Index].Usart_CR1.Bit.RXNEIE = Serial_Configuration_Table[Index].SerialCommon_Cfg.RxNotEmptyInterrupt_State;
            
            /* Prepare TCEIE: Transmission complete interrupt enable bit in the Control1 Register */
            Register_Shadow_Table[Index].Usart_CR1.Bit.TCIE = Serial_Configuration_Table[Index].SerialCommon_Cfg.TxCompleteInterupt_State;
            
            /* Prepare TXEIE: Transmission interrupt enable bit in the Control1 Register */
            Register_Shadow_Table[Index].Usart_CR1.Bit.TXEIE = Serial_Configuration_Table[Index].SerialCommon_Cfg.TxInterrupt_State;;
            Register_Shadow_Table[Index].Usart_CR1.Bit.PEIE = 0;
            Register_Shadow_Table[Index].Usart_CR1.Bit.PS =   0;
            Register_Shadow_Table[Index].Usart_CR1.Bit.PCE =  0;
            Register_Shadow_Table[Index].Usart_CR1.Bit.WAKE = 0;
            Register_Shadow_Table[Index].Usart_CR1.Bit.M =    0;
            Register_Shadow_Table[Index].Usart_CR1.Bit.UE =0;
            Register_Shadow_Table[Index].Usart_CR1.Bit.OVER8 =0;
        }
    }

    return Return_Status;
}

void Build_Usart_Configuration()
{
    DataType_u8 Index;
    DataType_Registers Register_Shadow_Table[USART_CHANNEL_NUM] = {0};

    for(Index = 0; Index < USART_CHANNEL_NUM; Index++)
    {
        Register_Shadow_Table[Index].Usart_DR.Bit.Data = 0;
        Register_Shadow_Table[Index].Usart_BRR.Bit.DIV_Fraction = 0;
        Register_Shadow_Table[Index].Usart_BRR.Bit.DIV_Mantissa = 0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.SBK = Serial_Configuration_Table[Index].SerialMode_Cfg.USART_Cfg.SendBreakCharacter_Cfg;
        Register_Shadow_Table[Index].Usart_CR1.Bit.RWU =  0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.RE =   0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.TE =   0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.IDLEIE =0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.RXNEIE =0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.TCIE =0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.TXEIE =0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.PEIE = 0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.PS =   0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.PCE =  0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.WAKE = 0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.M =    0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.UE =0;
        Register_Shadow_Table[Index].Usart_CR1.Bit.OVER8 =0;
  
    }
}