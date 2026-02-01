#ifndef USART_TYPES_H
#define USART_TYPES_H

#include "DataTypes.h"

#define USART_CHANNEL_NUM (DataType_u32)3U

#define USART1_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40011000)
#define USART2_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40004400)
#define USART6_BASE_ADDRESS ((volatile DataType_Registers * const) 0x40011400)











typedef enum
{
    Parity_NotDetcted = 0,
    Parity_Detcted
}DataType_ParityErrorFlag;

typedef enum
{
    FramingError_NotDetcted = 0,
    FramingErrorOrBreackCharacter_Detcted
}DataType_FramingErrorFlag;

typedef enum
{
    Noise_NotDetcted = 0,
    Noise_Detected
}DataType_NoiseFlag;

typedef enum
{
    OverRunError_NotDetcted = 0,
    OverRunError_Detected
}DataType_OverRunFlag;

typedef enum
{
    IdleLine_NotDetected = 0,
    IdleLine_Detected
}DataType_IdleLineFlag;

typedef enum
{
    Data_NotReceived = 0,
    Data_Received
}DataType_RecieveDataNotEmptyFlag;

typedef enum
{
    Transmission_NotCompleted = 0,
    Transmission_Completed
}DataType_TransmitnCompleteFlag;

typedef enum
{
    TransferDataToShiftRegister_NotDetcted = 0,
    TransferDataToShiftRegister_Detcted
}DataType_TransmitDataEmptyFlag;

typedef enum
{
    Lin_Break_NotDetected = 0,
    Lin_Break_Detected
}DataType_Lin_BreakDetectionFlag;

typedef enum
{
    CTS_NotChanged = 0,
    CTS_Changed
}DataType_ClearToSendFlag;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    BreakCharacter_NotTransmitted = 0,
    BreakCharacter_Transmitted
}DataType_SendBreak;

typedef enum
{
    Receiver_ActiveMode = 0,
    Receiver_MuteMode
}DataType_ReceiverWakeUp;

typedef enum
{
    Receiver_Disabled = 0,
    Receiver_Enabled
}DataType_ReceiverControl;

typedef enum
{
    Transmitter_Disabled = 0,
    Transmitter_Enabled
}DataType_TransmitterControl;

typedef enum
{
    Interrupt_Disabled = 0,
    Interrupt_Enabled
}DataType_IdleInterrupt;

typedef enum
{
    ReceiverInterrupt_Disabled = 0,
    ReceiverInterrupt_Enabled
}DataType_ReceiverNotEmptyInterrupt;

typedef enum
{
    TransmissionCompleteInterrupt_Disabled = 0,
    TransmissionCompleteInterrupt_Enabled
}DataType_TransmissionCompleteInterrupt;

typedef enum
{
    TransmissionInterrupt_Disabled = 0,
    TransmissionInterrupt_Enabled
}DataType_TransmissionInterrupt;

typedef enum
{
    ParityErrorInterrupt_Disabled = 0,
    ParityErrorInterrupt_Enabled
}DataType_ParityErrorInterrupt;

typedef enum
{
    EvenParity = 0,
    OddParity
}DataType_ParitySelection;

typedef enum
{
    ParityControl_Disabled = 0,
    ParityControl_Enabled
}DataType_ParityControl;

typedef enum
{
    IdleLine = 0,
    AddressMark
}DataType_WakeUpMethod;

typedef enum
{
    DataLength_8Bit = 0,
    DataLength_9Bit
}DataType_WordLength;

typedef enum
{
    Usart_Disabled = 0,
    Usart_Enabled
}DataType_UsartControl;

typedef enum
{
    OverSampling_By16 = 0,
    OverSampling_By8 = 0,

}DataType_OverSamplingMode;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    Lin_BreackDetection_10Bits = 0,
    Lin_BreackDetection_11Bits
}DataType_Lin_BreakDetection;

typedef enum
{
    Lin_BreackDetectionInterrupt_Disabled = 0,
    Lin_BreackDetectionInterrupt_Enabled
}DataType_Lin_BreakDetectionInterrupt;

typedef enum
{
    LastBitClockPulse_Disabled = 0,
    LastBitClockPulse_Enabled
}DataType_LastBitClockPulse;

typedef enum
{
    FirstClock = 0,
    SecondClock
}DataType_ClockPhase;

typedef enum
{
    Polarity_Low = 0,
    Polarity_High
}DataType_ClockPolarity;

typedef enum
{
    Clock_Enabled = 0,
    Clock_Disabled
}DataType_ClockControl;

typedef enum
{
    StopBit_One = 0,
    StopBit_Half,
    StopBit_Two
}DataType_StopBits;

typedef enum
{
    Lin_Mode_Disabled = 0,
    Lin_Mode_Enabled
}DataType_Lin_Mode;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef enum
{
    ErrorInterrupt_Disabled = 0,
    ErrorInterrupt_Enabled
}DataType_ErrorInterrupt;

typedef enum
{
    InfraredDataModeInterrupt_Disabled = 0,
    InfraredDataModeInterrupt_Enabled
}DataType_InfraredDataModeInterrupt;

typedef enum
{
    InfraredDataMode_Disabled = 0,
    InfraredDataMode_Enabled
}DataType_InfraredDataMode;

typedef enum
{
    Normal_Mode = 0,
    LowPower_Mode
}DataType_InfraredDataLowPower;

typedef enum
{
    FullDuplex_Mode = 0,
    HalfDuplex_Mode
}DataType_DuplexMode;

typedef enum
{
    SmartCardNack_Disabled = 0,
    SmartCardNack_Enabled
}DataType_SmartCardNack;

typedef enum
{
    SmartCardMode_Disabled = 0,
    SmartCardMode_Enabled
}DataType_SmartCardMode;

typedef enum
{
    ReceiverDma_Disabled = 0,
    ReceiverDma_Enabled
}DataType_Receiver_DMAmode;

typedef enum
{
    TransmitterDma_Disabled = 0,
    TransmitterDma_Enabled
}DataType_TransmitterDMAmode;

typedef enum
{
    RequestToSendMode_Disabled = 0,
    RequestToSendMode_Enabled
}DataType_RequestToSendMode;

typedef enum
{
    ClearToSendMode_Disabled = 0,
    ClearToSendMode_Enabled
}DataType_ClearToSendMode;

typedef enum
{
    ClearToSendModeInterrupt_Disabled = 0,
    ClearToSendModeInterrupt_Enabled
}DataType_ClearToSendInterrupt;

typedef enum
{
    ThreeBitSampling = 0,
    OneBitSampling
}DataType_SamplingMethod;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 PE   :1;
        DataType_u32 FE   :1;
        DataType_u32 NF   :1;
        DataType_u32 ORE  :1;
        DataType_u32 IDLE :1;
        DataType_u32 RXNE :1;
        DataType_u32 TC   :1;
        DataType_u32 TXE  :1;
        DataType_u32 LBD  :1;
        DataType_u32 CTS  :1;
        DataType_u32      :22;
    }Bit;
    
}DataTypes_Status;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 Data :9;
        DataType_u32    :23;
    }Bit;
    
}DataTypes_Data;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 DIV_Fraction   :4;
        DataType_u32 DIV_Mantissa   :12;
        DataType_u32                :16;
    }Bit;
    
}DataTypes_BaudRate;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 SBK    :1;
        DataType_u32 RWU    :1;
        DataType_u32 RE     :1;
        DataType_u32 TE     :1;
        DataType_u32 IDLEIE :1;
        DataType_u32 RXNEIE :1;
        DataType_u32 TCIE   :1;
        DataType_u32 TXEIE  :1;
        DataType_u32 PEIE   :1;
        DataType_u32 PS     :1;
        DataType_u32 PCE    :1;
        DataType_u32 WAKE   :1;
        DataType_u32 M      :1;
        DataType_u32 UE     :1;
        DataType_u32        :1;
        DataType_u32 OVER8  :1;
        DataType_u32        :16;
    }Bit;
    
}DataTypes_Control1;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 ADD   :4;
        DataType_u32       :1;
        DataType_u32 LBDL  :1;
        DataType_u32 LBDIE :1;
        DataType_u32       :1;
        DataType_u32 LBCL  :1;
        DataType_u32 CPHA  :1;
        DataType_u32 CPOL  :1;
        DataType_u32 CLKEN :1;
        DataType_u32 STOP  :2;
        DataType_u32 LINEN :1;
        DataType_u32       :17;
    }Bit;
    
}DataTypes_Control2;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 EIE    :1;
        DataType_u32 IREN   :1;
        DataType_u32 IRLP   :1;
        DataType_u32 HDSEL  :1;
        DataType_u32 NACK   :1;
        DataType_u32 SCEN   :1;
        DataType_u32 DMAR   :1;
        DataType_u32 DMAT   :1;
        DataType_u32 RTSE   :1;
        DataType_u32 CTSE   :1;
        DataType_u32 CTSIE  :1;
        DataType_u32 ONEBIT :1;
        DataType_u32        :20;

    }Bit;
    
}DataTypes_Control3;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef union
{
    volatile DataType_u32 Reg;
    volatile struct
    {
        DataType_u32 PSC :8;
        DataType_u32 GT  :8;
        DataType_u32     :16;
    }Bit;
    
}DataTypes_GT_PreScaler;

/*_________________________________________________________________________________________
 | Name : DataType_SendBreak                                                               |
 | Description : Used to define GPIO ports groups name                                     |
 | Type: Enum                                                                              |
 | Storage : Flash                                                                         |
 | Size : Compiler based norammly 4 byte                                                   |
 |_________________________________________________________________________________________*/
typedef struct
{
    DataTypes_Status       Usart_SR;
    DataTypes_Data         Usart_DR;
    DataTypes_BaudRate     Usart_BRR;
    DataTypes_Control1     Usart_CR1;
    DataTypes_Control2     Usart_CR2;
    DataTypes_Control3     Usart_CR3;
    DataTypes_GT_PreScaler Usart_GTPR;
}DataType_Registers;

typedef enum
{
    USART_Mode = 0,
    LIN_Mode = 1,
    IrDA_Mode = 2,
    SmartCard_Mode = 3
}DataType_ChannelMode;

typedef enum
{
    Channel_0 = 0,
    Channel_1,
    Channel_2,
    Channle_3,
    Channel_4
}DataType_Channel;

typedef struct 
{
    DataType_Channel              Channel_ID;
    DataType_State                RxControl_State;
    DataType_State                TxControl_State;
    DataType_WordLength           DataLength_Cfg;  
    DataType_StopBits             StopBit_Cfg;
    DataType_ParitySelection      ParitySelection_Cfg;   
    DataType_State                ParityControl_State;
    DataType_OverSamplingMode     OvwerSamplingMode_Cfg;   
    DataType_SamplingMethod       SamplingMethod_Cfg;
    DataType_DuplexMode           DuplexMode_Cfg;
    DataType_State                Rx_DMA_State;
    DataType_State                Tx_DMA_State;
    DataType_State                RxNotEmptyInterrupt_State;
    DataType_State                TxCompleteInterupt_State;
    DataType_State                TxInterrupt_State;   
    DataType_State                ErrorInterrupt_State;

}DataType_Common_Configuration;

typedef struct 
{
    DataType_State                USART_State;   
    DataType_SendBreak            SendBreakCharacter_Cfg;   
    DataType_ReceiverWakeUp       RecevierWakeup_Cfg;
    DataType_WakeUpMethod         WakeUpMethod_Cfg;
    DataType_State                RequestToSendMode_State;
    DataType_State                ClearToSendMode_State;
    DataType_State                ClearToSendInterrupt_State;
    DataType_State                ParityErrorInterrupt_State;
    DataType_State                IdleInterrupt_State;

}DataType_USART_Configuration;

typedef struct 
{
    DataType_State                LIN_State;
    DataType_Lin_BreakDetection   Lin_BreakCharacter_Cfg;   
    DataType_State                Lin_BreakCharacterInterrupt_State; 

}DataType_LIN_Configuration;

typedef struct 
{
    DataType_InfraredDataMode     IrDA_Sate;
    DataType_InfraredDataLowPower IrDA_PowerMode;
    DataType_State                IrDaInterrupt_State;
}DataType_IrDA_Configuration;

typedef struct
{
    DataType_State                SmartCard_State;
    DataType_State                SmartCardNack;
}DataType_SmartCard_Configuration;

typedef union
{
    DataType_USART_Configuration USART_Cfg;
    DataType_LIN_Configuration LIN_Cfg;
    DataType_IrDA_Configuration IrDA_Cfg;
    DataType_SmartCard_Configuration SmartCard_Cfg;
}DataType_SerialModeConfiguration;

typedef struct
{
    DataType_ChannelMode             Channel_Mode;
    DataType_Common_Configuration    SerialCommon_Cfg;
    DataType_SerialModeConfiguration SerialMode_Cfg;
}DataType_Configuration;

typedef struct DataType_Registers* const DataType_Usart_Registers;

#endif