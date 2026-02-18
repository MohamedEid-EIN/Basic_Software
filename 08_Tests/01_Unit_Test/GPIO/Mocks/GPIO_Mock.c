#include <string.h>
#include "GPIO_Mock.h"

#define INDEX_0 0U

DataType_Registers Mock_Registers_Table[HW_SUPPORTED_PORTS_NUM];

void MOCK_Reset(void)
{

    for(int Index = 0; Index < HW_SUPPORTED_PORTS_NUM; Index++)
    {
        memset(&Mock_Registers_Table[Index],INITIALIZE_ZERO, sizeof(DataType_Registers));

        memset(&PortLockStatus_Table[Index],INITIALIZE_ZERO, sizeof(DataType_PortLockStatus));

        ((DataType_GpioRegisters *)Registers_Table)[Index] = &Mock_Registers_Table[Index];

        PortUsage_Table[Index] = INITIALIZE_ZERO;
    }

    GPIO_Module_State = INITIALIZE_ZERO;
}
