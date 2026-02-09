# 0 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/01_Application/Source/main.c"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/01_Application/Source/main.c"







typedef volatile unsigned long vuint32_t;

# 1 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 1 3 4
# 145 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4

# 145 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 214 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 329 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 425 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 436 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
} max_align_t;
# 11 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/01_Application/Source/main.c" 2
# 1 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stdint.h" 1 3 4
# 34 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stdint.h" 3 4
typedef signed char int8_t;


typedef short int int16_t;


typedef long int int32_t;


typedef long long int int64_t;


typedef unsigned char uint8_t;


typedef short unsigned int uint16_t;


typedef long unsigned int uint32_t;


typedef long long unsigned int uint64_t;




typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef long int int_least32_t;
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef short unsigned int uint_least16_t;
typedef long unsigned int uint_least32_t;
typedef long long unsigned int uint_least64_t;



typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef long long unsigned int uint_fast64_t;




typedef int intptr_t;


typedef unsigned int uintptr_t;




typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
# 12 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/01_Application/Source/main.c" 2


# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/Include/GPIO_Int.h" 1

# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h" 1
# 41 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/DataTypes.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h" 1
# 43 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/DataTypes_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h" 1
# 35 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Cfg/PlatformDataTypes_Cfg.h"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/PlatformTypes.h" 1
# 38 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/03_Libraries/STD_TYPES/Include/PlatformTypes.h"

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
# 3 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/Include/GPIO_Int.h" 2
# 36 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/08_MCAL/GPIO/Header/Include/GPIO_Int.h"
DataType_Request_Status Gpio_Intitialization(void);
DataType_Request_Status GPIO_Toggel_Pin(DataType_u16 SignalId);
DataType_Request_Status GPIO_Write_Pin(DataType_u16 SignalId, DataType_Output_Level SignalValue);
DataType_Request_Status GPIO_Set_Pin(DataType_u16 SignalId);
DataType_Request_Status GPIO_Reset_Pin(DataType_u16 SignalId);
DataType_Request_Status GPIO_WritePinsGroup(DataType_u16 SignalGroupId, DataType_Output_Level SignalGroupValue);
# 15 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/01_Application/Source/main.c" 2
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/07_HAL/CHLCD/Header/Include/CHLCD_Int.h" 1
# 39 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/07_HAL/CHLCD/Header/Include/CHLCD_Int.h"
void LCD_Initialization(void);
void LCD_Print(DataType_u8 Data);
void LCD_CreateCustomChar(DataType_u8 Location, const DataType_u8 Pattern[8])
;static const DataType_u8 LCD_HeartChar[8];
# 16 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Basic_Software/06_Software/01_Application/Source/main.c" 2






void *memset(void *dest, int value, size_t len)
{
    unsigned char *p = (unsigned char *)dest;
    while (len--)
    {
        *p++ = (unsigned char)value;
    }
    return dest;
}




static void delay(volatile unsigned int d)
{
    while (d--)
    {
        __asm volatile ("nop");
    }
}



int main(void)
{
    (*(volatile unsigned int*)0x40023830) |= (1 << 0) | (1 << 1);
   (void)(*(volatile unsigned int*)0x40023830);


    Gpio_Intitialization();


    LCD_Initialization();
    LCD_CreateCustomChar(0U, LCD_HeartChar);


     LCD_Print('B');
        LCD_Print('A');
        LCD_Print('7');
        LCD_Print('B');
        LCD_Print('K');
  LCD_Print(' ');

  LCD_Print('Y');
        LCD_Print('A');
  LCD_Print(' ');

        LCD_Print('S');
        LCD_Print('O');
        LCD_Print('M');
        LCD_Print('A');
        LCD_Print('Y');
        LCD_Print('A');
  LCD_Print(0);



    while (1)
    {

    }
}
