
#include "DataTypes.h"

#ifndef GPIO_INT_H
#define GPIO_ONT_H


DataType_Request_Status API_GPIO_Intitialization(void);
DataType_Request_Status GPIO_Toggel_Pin(DataType_u16 SignalId);
#endif /* GPIO_INT_H */