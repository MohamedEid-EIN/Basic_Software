#ifndef USART_CFG_H
#define USART_CFG_H

#include "USART_Types.h"

#define USART_CHANNEL_NUM_CFG (DataType_u32)1U

static const DataType_Configuration Serial_Configuration_Table[USART_CHANNEL_NUM] =

{
    {
        .Channel_Mode = USART_Mode,

        .SerialCommon_Cfg = 
        {
            .Channel_ID                = Channel_0,
            .RxControl_State           = Enable,
            .TxControl_State           = Enable,
            .DataLength_Cfg            = DataLength_8Bit,
            .StopBit_Cfg               = StopBit_Two,
            .ParitySelection_Cfg       = EvenParity,
            .ParityControl_State       = Disable,
            .OvwerSamplingMode_Cfg     = OverSampling_By8,
            .SamplingMethod_Cfg        = OneBitSampling,
            .DuplexMode_Cfg            = FullDuplex_Mode,
            .Rx_DMA_State              = Disable,
            .Tx_DMA_State              = Disable,
            .RxNotEmptyInterrupt_State = Disable,
            .TxCompleteInterupt_State  = Disable,
            .TxInterrupt_State         = Disable,
            .ErrorInterrupt_State      = Disable
        },

        .SerialMode_Cfg.USART_Cfg = 
        {
           .Usart_State                = Enable, 
           .SendBreakCharacter_Cfg     = BreakCharacter_NotTransmitted,
           .RecevierWakeup_Cfg         = Receiver_ActiveMode,
           .WakeUpMethod_Cfg           = IdleLine,
           .RequestToSendMode_State    = Disable,
           .ClearToSendMode_State      = Disable,
           .ClearToSendInterrupt_State = Disable,
           .ParityErrorInterrupt_State = Disable,
           .IdleInterrupt_State        = Disable
        }

   }
};

#endif /* USART_CFG_H */