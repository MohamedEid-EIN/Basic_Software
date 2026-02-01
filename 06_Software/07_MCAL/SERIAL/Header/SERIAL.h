#ifndef SERIAL_H
#define SERIAL_H

#include "DataTypes.h"

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_Initialization(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_DeInitialization(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_SetBaudRate(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_SetDataLength(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_SetStopBit(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_SetParity(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_SetOverSampling(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_SetClockSource(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_Enable(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_Disable(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_EnableTx(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_DisableTx(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_EnableRx(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_DisableRx(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_TransmiteByte(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_ReceiveByte(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_TransmiteBuffer(void);


/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_ReceiveBuffer(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_GetTxEmptyStatus(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_GetRxNotEmptyStatus(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_EnableInterrupt(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_DisableInterrupt(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_ClearInterruptFlag(void);

/*==================================================================================================
 | Function Name : <Function_Name>
 | Description   : <Clear, single-responsibility description of what the function does.
 |                  No implementation details. No register names.>
 |--------------------------------------------------------------------------------------------------
 | Service ID    : <Hex ID>
 | Requirement ID: <REQ-XXX, SYS-YYY> / N/A
 |--------------------------------------------------------------------------------------------------
 | Interface
 |   Sync/Async  : Synchronous | Asynchronous
 |   Reentrancy  : Reentrant | Non-Reentrant
 |   Thread Safe : Yes | No | Caller Protected
 |--------------------------------------------------------------------------------------------------
 | Parameters
 |   Input       : <name> (<type>) – <description> | None
 |   InOut       : <name> (<type>) – <description> | None
 |   Output      : <name> (<type>) – <description> | None
 |
 | Return        : <Type>
 |                 - <Value> : <Meaning>
 |--------------------------------------------------------------------------------------------------
 | Preconditions :
 |   - MCU clock initialized
 |   - Configuration tables valid
 |   - Module not already initialized
 |
 | Postconditions:
 |   - Peripheral registers configured
 |   - Module state set to READY
 |--------------------------------------------------------------------------------------------------
 | Resource Usage:
 |   Code Size   : ~XXX bytes (Toolchain, optimization level)
 |   Stack Usage : ~XX bytes
 |   RAM Usage   : Static / Dynamic / None
 |--------------------------------------------------------------------------------------------------
 | Timing:
 |   Execution   : ~XX µs @ YY MHz (worst-case, configuration dependent)
 |   Blocking    : Yes | No
 |   Timeout     : N/A | <value>
 |--------------------------------------------------------------------------------------------------
 | Interrupts:
 |   IRQ Usage   : Enables / Disables / None
 |   ISR Safe    : Yes | No
 |--------------------------------------------------------------------------------------------------
 | Concurrency:
 |   Shared Data : Yes | No
 |   Protection  : Critical Section / Mutex / N/A
 |--------------------------------------------------------------------------------------------------
 | Memory Layout:
 |   Section     : .text | .ramfunc | Custom
 |--------------------------------------------------------------------------------------------------
 | Configuration:
 |   Variant     : Pre-Compile | Link-Time | Post-Build
 |--------------------------------------------------------------------------------------------------
 | Context:
 |   Callable From : Startup | Task | ISR
 |--------------------------------------------------------------------------------------------------
 | Notes:
 |   - All timing and size values are estimates and toolchain dependent.
 *==================================================================================================*/
DataType_Request_Status Serial_TransmiteBuffer(void);


#endif /* SERIAL_H */