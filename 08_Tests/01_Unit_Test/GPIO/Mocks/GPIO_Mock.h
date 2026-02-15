#ifndef GPIO_MOCK_H
#define GPIO_MOCK_H

#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "GPIO_Int.h"
#include "UTILS_Int.h"

void MOCK_Reset(void);

extern DataType_Registers Mock_Registers_Table[HW_SUPPORTED_PORTS_NUM];

#endif /* GPIO_MOCK_H */
