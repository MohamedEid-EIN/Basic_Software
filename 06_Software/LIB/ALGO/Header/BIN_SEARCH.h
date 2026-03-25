#ifndef BIN_SEARCH_H
#define BIN_SEARCH_H

#include "DataTypes.h"

DataType_U32 LIB_8BitBinarySearch(DataType_u8Ptr Data, DataType_U32 DataSize, DataType_U8 Value);
DataType_U32 LIB_16BitBinarySearch(DataType_u16Ptr Data, DataType_U32 DataSize, DataType_U16 Value);
DataType_U32 LIB_32BitBinarySearch(DataType_u32Ptr Data, DataType_U32 DataSize, DataType_U32 Value);
DataType_U32 LIB_64BitBinarySearch(DataType_u64Ptr Data, DataType_U32 DataSize, DataType_U64 Value);

#endif /* BIN_SEARCH_H */
