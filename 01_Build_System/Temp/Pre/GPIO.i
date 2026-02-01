# 0 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/01_Build_System//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
# 31 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO.h" 1
# 31 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h" 1
# 32 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h" 1
# 43 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h" 1
# 35 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/PlatformTypes.h" 1
# 38 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/PlatformTypes.h"
typedef unsigned char Uc_Arch;
typedef unsigned short Us_Arch;
typedef unsigned int Ui_Arch;
typedef unsigned long Ul_Arch;
typedef unsigned long long Ull_Arch;




typedef signed char Sc_Arch;
typedef signed short Ss_Arch;
typedef signed int Si_Arch;
typedef signed long Sl_Arch;
typedef signed long long Sll_Arch;




typedef float Float_Arch;
typedef double Double_Arch;
typedef long double LongDouble_Arch;




typedef unsigned char Boolean_Arch;




typedef unsigned char * UcPtr_Arch;
typedef unsigned short * UsPtr_Arch;
typedef unsigned int * UiPtr_Arch;
typedef unsigned long * UlPtr_Arch;
typedef unsigned long long * UllPtr_Arch;




typedef signed char * ScPtr_Arch;
typedef signed short * SsPtr_Arch;
typedef signed int * SiPtr_Arch;
typedef signed long * SlPtr_Arch;
typedef signed long long * SllPtr_Arch;




typedef float * FloatPtr_Arch;
typedef double * DoublePtr_Arch;
typedef long double * LongDoublePtr_Arch;




typedef void * Ptr_Arch;
# 36 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h" 2
# 44 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h" 2
# 73 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Uc_Arch U8_Cfg;
typedef Us_Arch U16_Cfg;
typedef Ui_Arch U32_Cfg;
typedef Ull_Arch U64_Cfg;
# 88 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Sc_Arch S8_Cfg;
typedef Ss_Arch S16_Cfg;
typedef Si_Arch S32_Cfg;
typedef Sll_Arch S64_Cfg;
# 101 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Float_Arch F32_Cfg;
typedef Double_Arch F64_Cfg;
typedef LongDouble_Arch F128_Cfg;
# 112 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Boolean_Arch Bool8_Cfg;
# 124 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef UcPtr_Arch U8_Ptr_Cfg;
typedef UsPtr_Arch U16_Ptr_Cfg;
typedef UiPtr_Arch U32_Ptr_Cfg;
typedef UllPtr_Arch U64_Ptr_Cfg;
# 139 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef ScPtr_Arch S8_Ptr_Cfg;
typedef SsPtr_Arch S16_Ptr_Cfg;
typedef SiPtr_Arch S32_Ptr_Cfg;
typedef SllPtr_Arch S64_Ptr_Cfg;
# 152 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef FloatPtr_Arch F32_Ptr_Cfg;
typedef DoublePtr_Arch F64_Ptr_Cfg;
typedef LongDoublePtr_Arch F128_Ptr_Cfg;







typedef Ptr_Arch Void_Ptr_Cfg;
# 33 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h" 2
# 79 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
typedef U8_Cfg DataType_u8;
typedef U16_Cfg DataType_u16;
typedef U32_Cfg DataType_u32;
typedef U64_Cfg DataType_u64;




typedef S8_Cfg DataType_s8;
typedef S16_Cfg DataType_s16;
typedef S32_Cfg DataType_s32;
typedef S64_Cfg DataType_s64;




typedef F32_Cfg DataType_f32;
typedef F64_Cfg DataType_f64;
typedef F128_Cfg DataType_f128;




typedef Bool8_Cfg DataType_b8;




typedef U8_Ptr_Cfg DataType_u8Ptr;
typedef U16_Ptr_Cfg DataType_u16Ptr;
typedef U32_Ptr_Cfg DataType_u32Ptr;
typedef U64_Ptr_Cfg DataType_u64Ptr;




typedef S8_Ptr_Cfg DataType_s8Ptr;
typedef S16_Ptr_Cfg DataType_s16Ptr;
typedef S32_Ptr_Cfg DataType_s32Ptr;
typedef S64_Ptr_Cfg DataType_s64Ptr;




typedef F32_Ptr_Cfg DataType_f32Ptr;
typedef F64_Ptr_Cfg DataType_f64Ptr;
typedef F128_Ptr_Cfg DataType_f128Ptr;




typedef Void_Ptr_Cfg DataType_vPtr;

typedef DataType_u8 DataType_Register_Size8;
typedef DataType_u16 DataType_Register_Size16;
typedef DataType_u32 DataType_Register_Size32;
typedef DataType_u64 DataType_Register_Size64;
# 148 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Off = 0,
    On = 1
}DataType_Input_Status;
# 161 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Unused = 0,
    Used = 1
}DataType_Usage;
# 174 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Flag_NotSet = 0,
    Flag_Set = 1
}DataType_Status_Flag;
# 187 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Low = 0,
    High = 1
}DataType_Output_Level;

typedef enum
{
    InValid = 0,
    Valid = 1
}DataType_Validity;

typedef enum
{
    Not_Detected = 0,
    Detected = 1
}DataType_Detection;

typedef enum
{
    Disable = 0,
    Enable = 1
}DataType_State;
# 218 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Unkown = 0,
    Success,
    Accepted,
    Busy,
    Invalid,
    Invalid_Parameter,
    Null_Pointer,
    Error
}DataType_Request_Status;
# 32 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO.h" 2
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h" 1
# 80 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef DataType_u32 DataType_Register;







typedef enum
{
    PortA = 0,
    PortB = 1,
    PortC = 2,
    PortD = 3,
    PortE = 4,
    PortH = 5
}DataType_Port_Group;
# 105 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
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
# 132 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Input_Mode = 0,
    Output_Mode = 1,
    Alternate_Function_Mode = 2,
    Analog_Mode = 3
}DataType_Mode;
# 147 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Output_Push_Pull = 0,
    Output_Open_Drain = 1
}DataType_Output_Type;
# 160 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Low_Speed = 0,
    Medium_Speed = 1,
    Fast_Speed = 2,
    High_Speed = 3
}DataType_Output_Speed;
# 175 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Resistance_NotConnected = 0,
    Pullup_Resistance_Connected = 1,
    PullDown_Resistance_Connedted = 2,
}DataType_Resistance_Connection;
# 189 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Reset_Pin = 0,
    Set_Pin = 1
}DataType_Output_Status_Setup;
# 202 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    UnActive = 0,
    Active = 1
}DataType_Lock_Key;
# 215 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Configuration_UnLocked = 0,
    Configuration_Locked = 1
}DataType_Configuration_Lock;
# 228 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
typedef enum
{
    Key_UnLocked = 0,
    Key_Locked = 1,
    Key_Error = 2
}DataType_Key_Status;
# 242 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h"
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




typedef struct
{
    volatile DataType_u32 Gpio_Moder;
    volatile DataType_u32 Gpio_Otyper;
    volatile DataType_u32 Gpio_Ospeedr;
    volatile DataType_u32 Gpio_Pupdr;
    volatile DataType_u32 Gpio_Idr;
    volatile DataType_u32 Gpio_Odr;
    volatile DataType_u32 Gpio_Bsrr;
    volatile DataType_u32 Gpio_Lckr;
    volatile DataType_u32 Gpio_Afrl;
    volatile DataType_u32 Gpio_Afrh;
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
# 33 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO.h" 2
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Cfg/GPIO_Cfg.h" 1
# 31 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Cfg/GPIO_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h" 1
# 32 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Cfg/DataTypes_Cfg.h" 1
# 33 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/03_Libraries/Common/STD_TYPES/Include/DataTypes.h" 2
# 32 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Cfg/GPIO_Cfg.h" 2
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO_Types.h" 1
# 33 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Cfg/GPIO_Cfg.h" 2







static const DataType_Pin_Configuration Pin_Configuration_Table[(DataType_u8)1] =
{

    { PortB, Pin_0, Output_Mode, Output_Push_Pull, Low_Speed, Resistance_NotConnected, High, Configuration_UnLocked, Alternate_Function_0 }
};

static const DataType_Port_Lock_Key Port_Lock_Status_Table[(DataType_u8)1] =
{

    {PortB, UnActive}
};
# 34 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Header/GPIO.h" 2




DataType_Request_Status Write_Registers_Configuration(DataType_Registers Registers_Shadow[(DataType_u8)6], DataType_Gpio_Registers Registers_Table[(DataType_u8)6]);
DataType_Request_Status Port_Lock_Init(DataType_Registers Registers_Shadow[(DataType_u8)6], DataType_Gpio_Registers Registers_Table[(DataType_u8)6]);
void Build_Configuration(DataType_Registers Registers_Shadow[(DataType_u8)6]);



DataType_Gpio_Registers Registers_Table[(DataType_u8)6U];

static const DataType_Pin_Configuration Pin_Configuration_Table[(DataType_u8)1];

static const DataType_Port_Lock_Key Port_Lock_Configuration_Table[(DataType_u8)1];

volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[(DataType_u8)6U];
# 32 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c" 2

volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[(DataType_u8)6U] =
{
    {PortA, Key_UnLocked},
    {PortB, Key_UnLocked},
    {PortC, Key_UnLocked},
    {PortD, Key_UnLocked},
    {PortE, Key_UnLocked},
    {PortH, Key_UnLocked}

};

DataType_Gpio_Registers Registers_Table[(DataType_u8)6U] =
{
    ((volatile DataType_Registers * const) 0x40020000U),
    ((volatile DataType_Registers * const) 0x40020400U),
    ((volatile DataType_Registers * const) 0x40020800U),
    ((volatile DataType_Registers * const) 0x40020C00U),
    ((volatile DataType_Registers * const) 0x40021000U),
    ((volatile DataType_Registers * const) 0x40021C00U)
};

static DataType_Usage Port_Usage_Table[(DataType_u8)6U] = {Unused};

static volatile DataType_u32 GPIO_Module_State = (DataType_u32)0x00000000U;

DataType_Request_Status GPIO_Set_Module_State(DataType_u32 State);
# 70 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
DataType_Request_Status Gpio_Intitialization(void)
{

    DataType_Request_Status Return_Status = Error;


    GPIO_Module_State = (DataType_u32)0x11111111U;


    if ((DataType_u8)1 < (DataType_u8)1 || (DataType_u8)1 > (DataType_u8)6 ||
        (DataType_u8)1 < (DataType_u8)1 || (DataType_u8)1 > (DataType_u8)16)
    {

        Return_Status = Invalid_Parameter;
    }

    else
    {

        DataType_Registers Registers_Shadow[(DataType_u8)6] = {0U};


        Build_Configuration(Registers_Shadow);


        Return_Status = Write_Registers_Configuration(Registers_Shadow, Registers_Table);


        if(Return_Status != Success)
        {

            Return_Status = Error;
        }
        else
        {

            Return_Status = Port_Lock_Init(Registers_Shadow, Registers_Table);
        }


        if(Return_Status != Success)
        {

            Return_Status = Error;
        }
        else
        {

            Return_Status = Success;
        }
    }


    GPIO_Set_Module_State((DataType_u32)0x77777777U);

    return Return_Status;
}
# 139 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
void Build_Configuration(DataType_Registers Registers_Shadow[(DataType_u8)6])
{

    DataType_u8 Index;
    DataType_u8 PortId;
    DataType_u32 PinId;


    for(Index = 0U; Index < (DataType_u8)1; Index++)
    {

        PortId = Pin_Configuration_Table[Index].Port_Id;
        PinId = Pin_Configuration_Table[Index].Pin_Id;


        Port_Usage_Table[PortId] = Used;


        Registers_Shadow[PortId].Gpio_Moder |= (Pin_Configuration_Table[Index].Pin_Mode << (PinId * (DataType_u32)2U));


        Registers_Shadow[PortId].Gpio_Otyper |= (Pin_Configuration_Table[Index].Pin_Output_Type << PinId);


        Registers_Shadow[PortId].Gpio_Ospeedr |= (Pin_Configuration_Table[Index].Pin_Output_Speed << (PinId * (DataType_u32)2U));


        Registers_Shadow[PortId].Gpio_Pupdr |= (Pin_Configuration_Table[Index].Pin_Resitances_Connection << (PinId * (DataType_u32)2U));


        Registers_Shadow[PortId].Gpio_Lckr |= (Pin_Configuration_Table[Index].Pin_Configuration_Lock_Status << PinId);


        if(PinId <= Pin_7)
        {

            Registers_Shadow[PortId].Gpio_Afrl |= (Pin_Configuration_Table[Index].Pin_Alternate_Function << (PinId * (DataType_u32)4U));
        }
        else
        {

            Registers_Shadow[PortId].Gpio_Afrh |= (Pin_Configuration_Table[Index].Pin_Alternate_Function << (PinId - 8 * (DataType_u32)4U));
        }


        Registers_Shadow[PortId].Gpio_Odr |= (Pin_Configuration_Table[Index].Pin_Output_Status_Setup << PinId);
    }
}
# 199 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
DataType_Request_Status Write_Registers_Configuration(DataType_Registers Registers_Shadow[(DataType_u8)6], DataType_Gpio_Registers Registers_Table[(DataType_u8)6])
{

    DataType_Request_Status Return_Status = Success;


    DataType_u8 PortId;


    for(PortId = 0U; PortId < (DataType_u8)6U; PortId++)
    {

        if(Port_Usage_Table[PortId] == Used)
        {

            Registers_Table[PortId]->Gpio_Moder = Registers_Shadow[PortId].Gpio_Moder;


            Registers_Table[PortId]->Gpio_Otyper = Registers_Shadow[PortId].Gpio_Otyper;


            Registers_Table[PortId]->Gpio_Ospeedr = Registers_Shadow[PortId].Gpio_Ospeedr;


            Registers_Table[PortId]->Gpio_Pupdr = Registers_Shadow[PortId].Gpio_Pupdr;


            Registers_Table[PortId]->Gpio_Odr = Registers_Shadow[PortId].Gpio_Odr;


            Registers_Table[PortId]->Gpio_Afrl = Registers_Shadow[PortId].Gpio_Afrl;


            Registers_Table[PortId]->Gpio_Afrh = Registers_Shadow[PortId].Gpio_Afrh;
        }

        else
        {

        }
    }


    for(PortId = 0U; PortId < (DataType_u8)6U; PortId++)
    {

        if(Port_Usage_Table[PortId] == Used)
        {

            if(Registers_Table[PortId]->Gpio_Moder != Registers_Shadow[PortId].Gpio_Moder)
            {

                Return_Status = Error;
                break;
            }

            else if(Registers_Table[PortId]->Gpio_Otyper != Registers_Shadow[PortId].Gpio_Otyper)
            {

                Return_Status = Error;
                break;
            }

            else if(Registers_Table[PortId]->Gpio_Ospeedr != Registers_Shadow[PortId].Gpio_Ospeedr)
            {

                Return_Status = Error;
                break;
            }

            else if(Registers_Table[PortId]->Gpio_Pupdr != Registers_Shadow[PortId].Gpio_Pupdr)
            {

                Return_Status = Error;
                break;
            }

            else if(Registers_Table[PortId]->Gpio_Afrl != Registers_Shadow[PortId].Gpio_Afrl)
            {

                Return_Status = Error;
                break;
            }

            else if(Registers_Table[PortId]->Gpio_Afrh != Registers_Shadow[PortId].Gpio_Afrh)
            {

                Return_Status = Error;
                break;
            }

            else
            {

                Return_Status = Success;
            }
        }

        else
        {

        }
    }

    return Return_Status;
}
# 317 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/07_MCAL/GPIO/Source/GPIO.c"
DataType_Request_Status Port_Lock_Init(DataType_Registers Registers_Shadow[(DataType_u8)6], DataType_Gpio_Registers Registers_Table[(DataType_u8)6])
{
    DataType_u8 Index;
    DataType_u8 PortId;
    DataType_u32 Dummy_Value = 0U;
    DataType_Request_Status Return_Status = Busy;

    for(Index = 0U; Index < (DataType_u8)1; Index++)
    {
        if(Port_Lock_Configuration_Table[Index].Port_Configuration_Lock_Key == Active)
        {
            DataType_u32 Configuration_Lock_Register = 0;
            PortId = Port_Lock_Configuration_Table[Index].Port_Id;

            Registers_Table[PortId]->Gpio_Lckr = Registers_Shadow[PortId].Gpio_Lckr | ((DataType_u32)0x00010000U);

            Registers_Table[PortId]->Gpio_Lckr = Registers_Shadow[PortId].Gpio_Lckr & ((DataType_u32)0xFFFEFFFFU);

            Registers_Table[PortId]->Gpio_Lckr = Registers_Shadow[PortId].Gpio_Lckr | ((DataType_u32)0x00010000U);

            Configuration_Lock_Register = Registers_Table[PortId]->Gpio_Lckr;

            Configuration_Lock_Register = ((Registers_Table[PortId]->Gpio_Lckr & (DataType_u32)0x00010000U) >> (DataType_u32)16U);

            if( ((Configuration_Lock_Register & (DataType_u32)0x00010000U) >> (DataType_u32)16U) == Active)
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
        void;
        GPIO_Module_State = State;
        void;

        Return_Status = Success;
    }

    return Return_Status;
}

DataType_Request_Status GPIO_Get_Module_State(DataType_u32Ptr State)
{
    DataType_Request_Status Return_Status = Unkown;

    if (State == ((void*)0))
    {
        Return_Status = Null_Pointer;
    }
    else
    {
        void;
        *State = GPIO_Module_State;
        void;

        Return_Status = Success;
    }

    return Return_Status;
}

DataType_Request_Status GPIO_Write_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != (DataType_u32)0x77777777U)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= (DataType_u8)1)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;

            if(SignalValue == High)
            {
                void;

                Registers_Table[PortId]->Gpio_Odr |= ((DataType_u32)1U << PinId);
                Return_Status = Success;

                void;
            }

            else if(SignalValue == Low)
            {
                void;

                Registers_Table[PortId]->Gpio_Odr &= ~((DataType_u32)1U << PinId);
                Return_Status = Success;

                void;
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

    if(GPIO_Module_State != (DataType_u32)0x77777777U)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalValue == ((void*)0))
        {
            Return_Status = Null_Pointer;
        }
        else if(SignalId >= (DataType_u8)1)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;
            DataType_Register_Size32 Register_Reading = 0;

            Register_Reading = Registers_Table[PortId]->Gpio_Idr;
            *SignalValue = (Register_Reading & ((DataType_u32)1U << PinId)) ? High : Low;
            Return_Status = Success;
        }

    }
    return Return_Status;
}

DataType_Request_Status GPIO_Toggel_Pin(DataType_u16 SignalId)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != (DataType_u32)0x77777777U)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= (DataType_u8)1)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;

            void;

            Registers_Table[PortId]->Gpio_Odr ^= ((DataType_u32)1U << PinId);
            Return_Status = Success;

            void;
        }

    }
    return Return_Status;
}

DataType_Request_Status GPIO_Set_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != (DataType_u32)0x77777777U )
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= (DataType_u8)1)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;

            if(SignalValue == High)
            {
                Registers_Table[PortId]->Gpio_Bsrr |= ((DataType_u32)1U << PinId);
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

    if(GPIO_Module_State != (DataType_u32)0x77777777U )
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalId >= (DataType_u8)1)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            DataType_Port_Group PortId = Pin_Configuration_Table[SignalId].Port_Id;
            DataType_Pin_Number PinId = Pin_Configuration_Table[SignalId].Pin_Id;

            if(SignalValue == Low)
            {
                Registers_Table[PortId]->Gpio_Bsrr |= ((DataType_u32)1U << (PinId + (DataType_u32)16U));
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
        case (DataType_u32)0x00000000U:
        case (DataType_u32)0x11111111U:
        case (DataType_u32)0x22222222U:
        case (DataType_u32)0x33333333U:
        case (DataType_u32)0x44444444U:
        case (DataType_u32)0x55555555U:
        case (DataType_u32)0x66666666U:
        case (DataType_u32)0x77777777U:
        case (DataType_u32)0x88888888U:
        case (DataType_u32)0x99999999U:
        {
            Return_Status = Valid;
            break;
        }
        default:
        { }
    }

    return Return_Status;
}
