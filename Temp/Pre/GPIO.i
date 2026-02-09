# 0 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
# 36 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h" 1
# 46 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO_Types.h" 1
# 47 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h" 2
# 135 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
volatile DataType_PortLockStatus PortLockKeyStatus_Table[(DataType_u8)6U];
# 144 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
DataType_GpioRegisters Registers_Table[(DataType_u8)6U];







static DataType_Usage Port_Usage_Table[(DataType_u8)6U];
# 161 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
static volatile DataType_u32 GPIO_Module_State;
# 170 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
static const DataType_Port_Lock_Key Port_Lock_Configuration_Table[PORT_CFG];






volatile DataType_Port_Lock_Status Port_Lock_Key_Status_Table[(DataType_u8)6U];
# 196 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
DataType_Request_Status GPIO_Intitialization(void);
# 212 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
DataType_Request_Status GPIO_SetModuleState(DataType_u32 State);
# 229 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
DataType_Request_Status Write_Registers_Configuration(
    DataType_Registers Registers_Shadow[(DataType_u8)6],
    DataType_GpioRegisters Registers_Table[(DataType_u8)6]);
# 248 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
DataType_Request_Status Port_Lock_Init(
    DataType_Registers Registers_Shadow[(DataType_u8)6],
    DataType_GpioRegisters Registers_Table[(DataType_u8)6]);
# 265 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/GPIO.h"
void Build_Configuration(DataType_Registers Registers_Shadow[(DataType_u8)6]);
# 37 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c" 2
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/09_Platform/CLOCK/Header/Include/CLOCK_Int.h" 1
# 37 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/09_Platform/CLOCK/Header/Include/CLOCK_Int.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h" 1
# 41 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h" 1
# 43 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h" 1
# 35 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/PlatformTypes.h" 1
# 38 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/PlatformTypes.h"
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
# 36 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h" 2
# 44 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h" 2
# 73 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Uc_Arch U8_Cfg;
typedef Us_Arch U16_Cfg;
typedef Ui_Arch U32_Cfg;
typedef Ull_Arch U64_Cfg;
# 88 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Sc_Arch S8_Cfg;
typedef Ss_Arch S16_Cfg;
typedef Si_Arch S32_Cfg;
typedef Sll_Arch S64_Cfg;
# 101 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Float_Arch F32_Cfg;
typedef Double_Arch F64_Cfg;
typedef LongDouble_Arch F128_Cfg;
# 112 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef Boolean_Arch Bool8_Cfg;
# 124 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef UcPtr_Arch U8_Ptr_Cfg;
typedef UsPtr_Arch U16_Ptr_Cfg;
typedef UiPtr_Arch U32_Ptr_Cfg;
typedef UllPtr_Arch U64_Ptr_Cfg;
# 139 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef ScPtr_Arch S8_Ptr_Cfg;
typedef SsPtr_Arch S16_Ptr_Cfg;
typedef SiPtr_Arch S32_Ptr_Cfg;
typedef SllPtr_Arch S64_Ptr_Cfg;
# 152 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
typedef FloatPtr_Arch F32_Ptr_Cfg;
typedef DoublePtr_Arch F64_Ptr_Cfg;
typedef LongDoublePtr_Arch F128_Ptr_Cfg;







typedef Ptr_Arch Void_Ptr_Cfg;
# 42 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h" 2
# 84 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
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
# 163 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Off = 0,
    On = 1
} DataType_Input_Status;
# 179 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Unused = 0,
    Used = 1
} DataType_Usage;
# 195 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Flag_NotSet = 0,
    Flag_Set = 1
} DataType_Status_Flag;
# 211 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Low = 0,
    High = 1
} DataType_Output_Level;
# 227 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    InValid = 0,
    Valid = 1
} DataType_Validity;
# 243 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Not_Detected = 0,
    Detected = 1
} DataType_Detection;
# 259 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
typedef enum
{
    Disable = 0,
    Enable = 1
} DataType_State;
# 275 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
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
} DataType_Request_Status;
# 38 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/09_Platform/CLOCK/Header/Include/CLOCK_Int.h" 2
DataType_Request_Status CLOCK_Initiailization(void);

DataType_Request_Status CLOCK_GetModuleState(void);
# 38 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c" 2
# 49 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
static volatile DataType_u32 GPIO_Module_State = LIB_UTILS_STATE_UNDEFINED;
# 59 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
volatile DataType_PortLockStatus PortLockKeyStatus_Table[(DataType_u8)6U] =
{
    {PortA, Key_UnLocked},
    {PortB, Key_UnLocked},
    {PortC, Key_UnLocked},
    {PortD, Key_UnLocked},
    {PortE, Key_UnLocked},
    {PortH, Key_UnLocked}
};
# 76 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
DataType_GpioRegisters Registers_Table[(DataType_u8)6U] =
{
    ((volatile DataType_Registers * const) 0x40020000U),
    ((volatile DataType_Registers * const) 0x40020400U),
    ((volatile DataType_Registers * const) 0x40020800U),
    ((volatile DataType_Registers * const) 0x40020C00U),
    ((volatile DataType_Registers * const) 0x40021000U),
    ((volatile DataType_Registers * const) 0x40021C00U)
};







static DataType_Usage Port_Usage_Table[(DataType_u8)6U] = {Unused};
# 103 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
DataType_Request_Status Gpio_Intitialization(void)
{

    DataType_Request_Status Return_Status = Unkown;


    GPIO_Module_State = LIB_UTILS_STATE_UNINITIALIZED;


    if (PORT_CFG < (DataType_u8)1 || PORT_CFG > (DataType_u8)6 ||
        PIN_CFG < (DataType_u8)1 || PIN_CFG > (DataType_u8)16)
    {

        Return_Status = Invalid_Parameter;
    }

    else
    {

        if(1)
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

        else
        {
            Return_Status = Error;
        }
    }

    GPIO_SetModuleState(LIB_UTILS_STATE_READY);

    return Return_Status;
}
# 180 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
void Build_Configuration(DataType_Registers Registers_Shadow[(DataType_u8)6])
{

    DataType_u8 Index;
    DataType_u8 PortId;
    DataType_u32 PinId;


    for(Index = 0U; Index < PIN_CFG; Index++)
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

            Registers_Shadow[PortId].Gpio_Afrh |= (Pin_Configuration_Table[Index].Pin_Alternate_Function << ((PinId - 8) * (DataType_u32)4U));
        }


        Registers_Shadow[PortId].Gpio_Odr |= (Pin_Configuration_Table[Index].Pin_Output_Status_Setup << PinId);
    }
}
# 240 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
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
# 358 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Source/GPIO.c"
DataType_Request_Status Port_Lock_Init(DataType_Registers Registers_Shadow[(DataType_u8)6], DataType_Gpio_Registers Registers_Table[(DataType_u8)6])
{
    DataType_u8 Index;
    DataType_u8 PortId;
    DataType_u32 Dummy_Value = 0U;
    DataType_Request_Status Return_Status = Busy;

    for(Index = 0U; Index < PORT_CFG; Index++)
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

DataType_Request_Status GPIO_SetModuleState(DataType_u32 State)
{
    DataType_Request_Status Return_Status = Unkown;

    if (LIB_UTILS_IsValidState(State) != Valid)
    {
        Return_Status = Invalid_Parameter;
    }
    else
    {
        GPIO_Module_State = State;

        Return_Status = Success;
    }

    return Return_Status;
}

DataType_u32 GPIO_GetModuleState(void)
{
    DataType_u32 State = GPIO_Module_State;

    return State;
}

DataType_Request_Status GPIO_Write_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
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
                Registers_Table[PortId]->Gpio_Odr |= ((DataType_u32)1U << PinId);
                Return_Status = Success;
            }

            else if(SignalValue == Low)
            {

                Registers_Table[PortId]->Gpio_Odr &= ~((DataType_u32)1U << PinId);
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

DataType_Request_Status GPIO_WritePinsGroup(DataType_u16 SignalGroupId, DataType_u8 SignalGroupValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalGroupId >= PORT_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            Registers_Table[SignalGroupId]->Gpio_Odr = SignalGroupValue;
            Return_Status = Success;
        }

    }
    return Return_Status;
}

DataType_Request_Status GPIO_WritePinsGroup(DataType_u16 SignalGroupId, DataType_u8 SignalGroupValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalGroupId >= PORT_CFG)
        {
            Return_Status = Invalid_Parameter;
        }
        else
        {
            Registers_Table[SignalGroupId]->Gpio_Odr = SignalGroupValue;
            Return_Status = Success;
        }

    }
    return Return_Status;
}

DataType_Request_Status GPIO_Read_Pin(DataType_u16 SignalId , DataType_Output_Level* SignalValue)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
    {
        Return_Status = Invalid;
    }
    else
    {
        if(SignalValue == ((void*)0))
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
            *SignalValue = (Register_Reading & ((DataType_u32)1U << PinId)) ? High : Low;
            Return_Status = Success;
        }

    }
    return Return_Status;
}

DataType_Request_Status GPIO_Toggel_Pin(DataType_u16 SignalId)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY)
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

            Registers_Table[PortId]->Gpio_Odr ^= ((DataType_u32)1U << PinId);
            Return_Status = Success;
        }

    }
    return Return_Status;
}

DataType_Request_Status GPIO_Set_Pin(DataType_u16 SignalId)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY )
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

            Registers_Table[PortId]->Gpio_Bsrr = ((DataType_u32)1U << PinId);
            Return_Status = Success;
        }
    }

    return Return_Status;
}

DataType_Request_Status GPIO_Reset_Pin(DataType_u16 SignalId)
{
    DataType_Request_Status Return_Status = Unkown;

    if(GPIO_Module_State != LIB_UTILS_STATE_READY )
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

            Registers_Table[PortId]->Gpio_Bsrr = ((DataType_u32)1U << (PinId + (DataType_u32)16U));
            Return_Status = Success;
        }
    }
    return Return_Status;
}
