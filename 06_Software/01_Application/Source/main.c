// ============================================================
// Bare-metal STM32F401
// LCD test: scroll "Somaya Shaban"
// No HAL, no stdlib, freestanding
// GPIO via custom driver
// ============================================================

typedef volatile unsigned long vuint32_t;

#include <stddef.h>
#include <stdint.h>

//#include "CLOCK_Int.h"
#include "MCAL_Int.h"
#include "CHLCD_Int.h"

#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830)

/* ------------------------------------------------------------
 * Minimal memset (because no stdlib)
 * ------------------------------------------------------------ */
DataType_u8 SIGNALS[29];
void *memset(void *dest, int value, size_t len);

/* ------------------------------------------------------------
 * Delay (busy wait)
 * ------------------------------------------------------------ */
 void Delay_ms(DataType_u32 ms);
 void Delay_us(DataType_u32 us);




/* ------------------------------------------------------------
 * MAIN
 * ------------------------------------------------------------ */
int main(void)
{
    DataType_u8 Index = 0;
    RCC_AHB1ENR |= (1 << 0) | (1 << 1);
   (void)RCC_AHB1ENR;
    MCAL_GPIO_Init();




    /* 5. Main loop */
    while (1)
    {
        for(Index = 0; Index < 29u; Index++)
        {
        Delay_ms(5);
        MCAL_GPIO_WritePin(SIGNALS[Index], High);
        Delay_ms(5);

        }

		for(Index = 0; Index < 29u; Index++)
        {
        Delay_ms(5);
        MCAL_GPIO_WritePin(SIGNALS[Index], Low);
        Delay_ms(5);

        }
        /* Nothing to do */
        /* Nothing to do */
    }
}


/* ------------------------------------------------------------
 * Delay (busy wait)
 * ------------------------------------------------------------ */
    DataType_u8 SIGNALS[29] =
    {
       MCAL_GPIO_SIGNAL_0,
       MCAL_GPIO_SIGNAL_1,
       MCAL_GPIO_SIGNAL_2,
       MCAL_GPIO_SIGNAL_3,
       MCAL_GPIO_SIGNAL_4,
       MCAL_GPIO_SIGNAL_5,
       MCAL_GPIO_SIGNAL_6,
       MCAL_GPIO_SIGNAL_7,
       MCAL_GPIO_SIGNAL_8,
       MCAL_GPIO_SIGNAL_9,
       MCAL_GPIO_SIGNAL_10,
       MCAL_GPIO_SIGNAL_11,
       MCAL_GPIO_SIGNAL_12,
       MCAL_GPIO_SIGNAL_15,
       MCAL_GPIO_SIGNAL_16,
       MCAL_GPIO_SIGNAL_17,
       MCAL_GPIO_SIGNAL_18,
       MCAL_GPIO_SIGNAL_19,
       MCAL_GPIO_SIGNAL_20,
       MCAL_GPIO_SIGNAL_21,
       MCAL_GPIO_SIGNAL_22,
       MCAL_GPIO_SIGNAL_23,
       MCAL_GPIO_SIGNAL_24,
       MCAL_GPIO_SIGNAL_25,
       MCAL_GPIO_SIGNAL_26,
       MCAL_GPIO_SIGNAL_28,
       MCAL_GPIO_SIGNAL_29,
       MCAL_GPIO_SIGNAL_30,
       MCAL_GPIO_SIGNAL_31
    };
 void Delay_us(DataType_u32 us)
{
    volatile DataType_u32 count;

    while (us--)
    {
        for (count = 0U; count < 10U; count++)
        {
            __asm volatile ("nop");
        }
    }
}

 void Delay_ms(DataType_u32 ms)
{
    while (ms--)
    {
        Delay_us(1000U);
    }
}

void *memset(void *dest, int value, size_t len)
{
    unsigned char *p = (unsigned char *)dest;
    while (len--)
    {
        *p++ = (unsigned char)value;
    }
    return dest;
}
