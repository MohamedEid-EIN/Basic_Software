/********************************************************************************************
* License     : MIT License
* Copyright   : (c) 2025 Mohamed Eid
*
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
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
*
*--------------------------------------------------------------------------------------------
* - Author      : Mohamed Eid
* - File Name   : PWM_Types.h
* - File Type   : Header Types File
* - Module      : PWM
* - Layer       : Hardware Abstraction / Low-Level Driver / MCAL
* - Description : This file used to define the required and specific data types for PWM mdule.
* - Design Note : TBD
* - Toolchain   : TBD
* - References  : TBD
*--------------------------------------------------------------------------------------------
* - Version History :
*   - 1.00.00  | 27-01-2025 | Mohamed Eid | File Creation
********************************************************************************************/

#ifndef PWM_TYPES_H
#define PWM_TYPES_H

#include "DataTypes.h"

/*****************************************************************************************************************
* Timer3 Registers address offset macros
*****************************************************************************************************************/
#define TIM3_BASE_ADDRESS     (DataType_u32)0x40000400U /* TIM3 BaseAddress value */
#define REG_TIM3_CR1_OFFSET   (DataType_u32)0x00000000U /* Timer3 Control register_1 offset address */
#define REG_TIM3_EGR_OFFSET   (DataType_u32)0x00000014U /* Timer3 event generation register offset address */
#define REG_TIM3_CCMR1_OFFSET (DataType_u32)0x00000018U /* Timer3 capture/compare mode register_1 offset address */
#define REG_TIM3_CCMR2_OFFSET (DataType_u32)0x0000001CU /* Timer3 capture/compare mode register_2 offset address */
#define REG_TIM3_CCER_OFFSET  (DataType_u32)0x00000020U /* Timer3 capture/compare enable register offset address */
#define REG_TIM3_PSC_OFFSET   (DataType_u32)0x00000028U /* Timer3 Prescaler register offset address */
#define REG_TIM3_ARR_OFFSET   (DataType_u32)0x0000002CU /* Timer3 Auto Reload register offset address */
#define REG_TIM3_CCR1_OFFSET  (DataType_u32)0x00000034U /* Timer3 capture/compare register_1 offset address */
#define REG_TIM3_CCR2_OFFSET  (DataType_u32)0x00000038U /* Timer3 capture/compare register_2 offset address */
#define REG_TIM3_CCR3_OFFSET  (DataType_u32)0x0000003CU /* Timer3 capture/compare register_3 offset address */
#define REG_TIM3_CCR4_OFFSET  (DataType_u32)0x00000040U /* Timer3 capture/compare register_4 offset address */

/*****************************************************************************************************************
* Timer3 Registers address macros
*****************************************************************************************************************/
#define REG_TIM3_CR1_ADDRESS   (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CR1_OFFSET)   ) /* Timer3 Control register_1 */
#define REG_TIM3_EGR_ADDRESS   (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_EGR_OFFSET)   ) /* Timer3 event generation register */
#define REG_TIM3_CCMR1_ADDRESS (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCMR1_OFFSET) ) /* Timer3 capture/compare mode register_1 */
#define REG_TIM3_CCMR2_ADDRESS (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCMR2_OFFSET) ) /* Timer3 capture/compare mode register_2 */
#define REG_TIM3_CCER_ADDRESS  (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCER_OFFSET)  ) /* Timer3 capture/compare enable register */
#define REG_TIM3_PSC_ADDRESS   (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_PSC_OFFSET)   ) /* Timer3 Prescaler register */
#define REG_TIM3_ARR_ADDRESS   (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_ARR_OFFSET)   ) /* Timer3 Auto Reload register */
#define REG_TIM3_CCR1_ADDRESS  (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCR1_OFFSET)  ) /* Timer3 capture/compare register_1 */
#define REG_TIM3_CCR2_ADDRESS  (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCR2_OFFSET)  ) /* Timer3 capture/compare register_2 */
#define REG_TIM3_CCR3_ADDRESS  (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCR3_OFFSET)  ) /* Timer3 capture/compare register_3 */
#define REG_TIM3_CCR4_ADDRESS  (volatile DataType_u32Ptr const )( (TIM3_BASE_ADDRESS) + (REG_TIM3_CCR4_OFFSET)  ) /* Timer3 capture/compare register_4 */

/*****************************************************************************************************************
* Timer3 Registers macros
*****************************************************************************************************************/
#define REG_TIM3_CR1   *(REG_TIM3_CR1_ADDRESS  ) /* Timer3 Control register_1 */
#define REG_TIM3_EGR   *(REG_TIM3_EGR_ADDRESS  ) /* Timer3 event generation register */
#define REG_TIM3_CCMR1 *(REG_TIM3_CCMR1_ADDRESS) /* Timer3 capture/compare mode register_1 */
#define REG_TIM3_CCMR2 *(REG_TIM3_CCMR2_ADDRESS) /* Timer3 capture/compare mode register_2 */
#define REG_TIM3_CCER  *(REG_TIM3_CCER_ADDRESS ) /* Timer3 capture/compare enable register */
#define REG_TIM3_PSC   *(REG_TIM3_PSC_ADDRESS  ) /* Timer3 Prescaler register */
#define REG_TIM3_ARR   *(REG_TIM3_ARR_ADDRESS  ) /* Timer3 Auto Reload register */
#define REG_TIM3_CCR1  *(REG_TIM3_CCR1_ADDRESS ) /* Timer3 capture/compare register_1 */
#define REG_TIM3_CCR2  *(REG_TIM3_CCR2_ADDRESS ) /* Timer3 capture/compare register_2 */
#define REG_TIM3_CCR3  *(REG_TIM3_CCR3_ADDRESS ) /* Timer3 capture/compare register_3 */
#define REG_TIM3_CCR4  *(REG_TIM3_CCR4_ADDRESS ) /* Timer3 capture/compare register_4 */

/*****************************************************************************************************************
* Timer3 Bits configuration macros
*****************************************************************************************************************/
#define COUNTER_DISABLE    (DataType_u16)0x0000U /* |REG: TIM3_CR1 BIT: CEN|: TIMER3 counter disable value */
#define COUNTER_ENABLE     (DataType_u16)0x0001U /* |REG: TIM3_CR1 BIT: CEN|: TIMER3 counter enable value */

#define AUTORELOAD_DISABLE  (DataType_u16)0x0000U /* |REG: TIM3_CR1 BIT: ARPE|: TIMER3 Auto-reload preload value TIM3_ARR register is not buffered */
#define AUTORELOAD_ENABLED  (DataType_u16)0x0080U /* |REG: TIM3_CR1 BIT: ARPE|: TIMER3 Auto-reload preload value TIM3_ARR register is buffered */

#define OUTPUT_PWM_MODE1   (DataType_u16)0x0006U /* |REG: TIM3_CCMRx BIT: OCxM|: TIMER3 Output compare 1 mode value */
#define OUTPUT_PWM_MODE2   (DataType_u16)0x0007U /* |REG: TIM3_CCMRx BIT: OCxM|: TIMER3 Output compare 1 mode value */

#define PRELOAD_DISABLE    (DataType_u16)0x0000U /* |REG: TIM3_CCMRx BIT: OCxPE|: TIMER3 Output compare 1 preload disable value */
#define PRELOAD_ENABLE     (DataType_u16)0x0001U /* |REG: TIM3_CCMRx BIT: OCxPE|: TIMER3 Output compare 1 preload enable value */

#define CHANNEL_OUPUT_NOT_ACTIVE (DataType_u16)0x0000U /* |REG: TIM3_CCER BIT: CCxE|: TIMER3 Capture/Compare 1 output disable value */
#define CHANNEL_OUPUT_ACTIVE     (DataType_u16)0x0001U /* |REG: TIM3_CCER BIT: CCxE|: TIMER3 cCapture/Compare 1 output enable value */

#define CHANNEL_POLARITY_ACTIVE_LOW  (DataType_u16)0x0000U /* |REG: TIM3_CCER BIT: CCxP|: TIMER3 Capture/Compare 1 output Polarity value LOW */
#define CHANNEL_POLARITY_ACTIVE_HIGH (DataType_u16)0x0001U /* |REG: TIM3_CCER BIT: CCxP|: TIMER3 Capture/Compare 1 output Polarity value HIGH */

#define PRESCALER_DIV_1     (DataType_u16)1U
#define PRESCALER_DIV_2     (DataType_u16)2U
#define PRESCALER_DIV_4     (DataType_u16)4U
#define PRESCALER_DIV_8     (DataType_u16)8U
#define PRESCALER_DIV_16    (DataType_u16)16U
#define PRESCALER_DIV_32    (DataType_u16)32U
#define PRESCALER_DIV_64    (DataType_u16)64U
#define PRESCALER_DIV_128   (DataType_u16)128U
#define PRESCALER_DIV_256   (DataType_u16)256U
#define PRESCALER_DIV_512   (DataType_u16)512U
#define PRESCALER_DIV_1024  (DataType_u16)1024U

#define FREQ_5_HZ    (DataType_u32)5U
#define FREQ_10_HZ   (DataType_u32)10U
#define FREQ_25_HZ   (DataType_u32)25U
#define FREQ_50_HZ   (DataType_u32)50U
#define FREQ_100_HZ  (DataType_u32)100U
#define FREQ_200_HZ  (DataType_u32)200U
#define FREQ_500_HZ  (DataType_u32)500U
#define FREQ_1_KHZ   (DataType_u32)1000U
#define FREQ_2_KHZ   (DataType_u32)2000U
#define FREQ_5_KHZ   (DataType_u32)5000U
#define FREQ_10_KHZ  (DataType_u32)10000U
#define FREQ_20_KHZ  (DataType_u32)20000U
#define FREQ_25_KHZ  (DataType_u32)25000U
#define FREQ_50_KHZ  (DataType_u32)50000U
#define FREQ_100_KHZ (DataType_u32)100000U

#define DUTY_CYCLE_0_PERCENT   (DataType_u32)0U
#define DUTY_CYCLE_5_PERCENT   (DataType_u32)5U
#define DUTY_CYCLE_10_PERCENT  (DataType_u32)10U
#define DUTY_CYCLE_25_PERCENT  (DataType_u32)25U
#define DUTY_CYCLE_50_PERCENT  (DataType_u32)50U
#define DUTY_CYCLE_75_PERCENT  (DataType_u32)75U
#define DUTY_CYCLE_90_PERCENT  (DataType_u32)90U
#define DUTY_CYCLE_95_PERCENT  (DataType_u32)95U
#define DUTY_CYCLE_100_PERCENT (DataType_u32)100U

#define PWM_CHANNEL_1 (DataType_u8)0U
#define PWM_CHANNEL_2 (DataType_u8)1U
#define PWM_CHANNEL_3 (DataType_u8)2U
#define PWM_CHANNEL_4 (DataType_u8)3U



#define PWM_MAX_CHANNEL_NUM (DataType_u8)4U

/*****************************************************************************************************************
* These tables are cretaed for easy configuration of the registers because some bits in the Timers
* shears same register with different channels.
*****************************************************************************************************************/
extern volatile DataType_u32Ptr const CCMR_Register[PWM_MAX_CHANNEL_NUM] =
{
    REG_TIM3_CCMR1_ADDRESS,
    REG_TIM3_CCMR1_ADDRESS,
    REG_TIM3_CCMR2_ADDRESS,
    REG_TIM3_CCMR2_ADDRESS
};

extern volatile DataType_u32Ptr const CCR_Register[PWM_MAX_CHANNEL_NUM] =
{
    REG_TIM3_CCR1_ADDRESS,
    REG_TIM3_CCR2_ADDRESS,
    REG_TIM3_CCR3_ADDRESS,
    REG_TIM3_CCR4_ADDRESS
};

extern const DataType_u8 CCxE_Bit[PWM_MAX_CHANNEL_NUM] =
{
    0, /* REg:TIMx_CCER BIT:CC1E position */
    4, /* REg:TIMx_CCER BIT:CC2E position */
    8, /* REg:TIMx_CCER BIT:CC3E position */
    12 /* REg:TIMx_CCER BIT:CC4E position */
};

extern const DataType_u8 CCxP_Bit[PWM_MAX_CHANNEL_NUM] =
{
    1, /* REg:TIMx_CCER BIT:CC1P position */
    5, /* REg:TIMx_CCER BIT:CC2P position */
    9, /* REg:TIMx_CCER BIT:CC3P position */
    13 /* REg:TIMx_CCER BIT:CC4P position */
};

extern const DataType_u8 OCxM_Bit[PWM_MAX_CHANNEL_NUM] =
{
    4,  /* REg:TIMx_CCMR1 BIT:OC1M position */
    12, /* REg:TIMx_CCMR1 BIT:OC2M position */
    4,  /* REg:TIMx_CCMR2 BIT:OC1M position */
    12  /* REg:TIMx_CCMR2 BIT:OC2M position */
};

extern const DataType_u8 OCxPE_Bit[PWM_MAX_CHANNEL_NUM] =
{
    3,  /* REg:TIMx_CCMR1 BIT:OC1PE position */
    11, /* REg:TIMx_CCMR1 BIT:OC2PE position */
    3,  /* REg:TIMx_CCMR2 BIT:OC1PE position */
    11  /* REg:TIMx_CCMR2 BIT:OC2PE position */
};

typedef struct 
{
    DataType_u16 Channel_Cfg;
    DataType_u16 AutoReload_Cfg;
    DataType_u16 PreLoad_Cfg;
    DataType_u16 OutputLevel_Cfg;
    DataType_u16 PwmMode_Cfg;
    DataType_u16 OutputPolarity_Cfg;
    DataType_u16 DutyCycle_Cfg;
}Pwm_Configuration;



#endif /* PWM_TYPES_H */