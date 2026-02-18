/********************************************************************************************
* License     : MIT License
* Copyright (c) 2025 Mohamed Eid
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* - Description : This file is used to define all used data types,
*                 All sizes based on Architecture or compiler dependent.
* - Author      : Mohamed Eid
* - File Name   : PlatformTypes.h
* - File Type   : Header file
* - References  : TBD
* - Toolchain   : TBD
* - Version     : History
* - 1.00.00     : File Creation
********************************************************************************************/
#ifndef PLATFORMTYPES_H
#define PLATFORMTYPES_H

/**********************************************************************************
 * 1. Unsigned primitive types (architecture-defined widths)
 **********************************************************************************/
typedef unsigned char        Uc_Arch;                 
typedef unsigned short       Us_Arch;                 
typedef unsigned int         Ui_Arch;                 
typedef unsigned long        Ul_Arch;                 
typedef unsigned long long   Ull_Arch;                

/**********************************************************************************
 * 2. Signed primitive types (architecture-defined widths)
 **********************************************************************************/
typedef signed char          Sc_Arch;                 
typedef signed short         Ss_Arch;                 
typedef signed int           Si_Arch;                 
typedef signed long          Sl_Arch;                 
typedef signed long long     Sll_Arch;

/**********************************************************************************
 * 3. Floating point types (architecture-defined widths)
 **********************************************************************************/
typedef float                Float_Arch;    
typedef double               Double_Arch;    
typedef long double          LongDouble_Arch;

/**********************************************************************************
 * 4. Boolean type (fixed-width boolean storage)
 **********************************************************************************/
typedef unsigned char        Boolean_Arch;

/**********************************************************************************
 * 5. Pointer to unsigned types (architecture-defined pointer width)
 **********************************************************************************/
typedef unsigned char *      UcPtr_Arch;                 
typedef unsigned short *     UsPtr_Arch;                 
typedef unsigned int *       UiPtr_Arch;                 
typedef unsigned long *      UlPtr_Arch;                 
typedef unsigned long long * UllPtr_Arch;                

/**********************************************************************************
 * 6. Pointer to signed types (architecture-defined pointer width)
 **********************************************************************************/
typedef signed char *        ScPtr_Arch;                   
typedef signed short *       SsPtr_Arch;                   
typedef signed int *         SiPtr_Arch;                   
typedef signed long *        SlPtr_Arch;                   
typedef signed long long *   SllPtr_Arch;

/**********************************************************************************
 * 7. Pointer to floating point types (architecture-defined pointer width)
 **********************************************************************************/
typedef float *              FloatPtr_Arch;    
typedef double *             DoublePtr_Arch;    
typedef long double *        LongDoublePtr_Arch;

/**********************************************************************************
 * 8. Generic pointer type
 **********************************************************************************/
typedef void *               Ptr_Arch;

#endif /* PLATFORMTYPES_H */