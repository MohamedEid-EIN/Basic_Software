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
void *memset(void *dest, int value, size_t len)
{
    unsigned char *p = (unsigned char *)dest;
    while (len--)
    {
        *p++ = (unsigned char)value;
    }
    return dest;
}

/* ------------------------------------------------------------
 * Delay (busy wait)
 * ------------------------------------------------------------ */
static void delay(volatile unsigned int d)
{
    while (d--)
    {
        __asm volatile ("nop");
    }
}
/* ------------------------------------------------------------
 * MAIN
 * ------------------------------------------------------------ */
int main(void)
{
    RCC_AHB1ENR |= (1 << 0) | (1 << 1);
   (void)RCC_AHB1ENR;


    MCAL_GPIO_Init();

    /* 3. LCD initialization */
    LCD_Initialization();
    /* 4. Write data to LCD */

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


    /* 5. Main loop */
    while (1)
    {
        /* Nothing to do */
    }
}
