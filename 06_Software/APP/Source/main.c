#include "MCAL_API.h"

#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830)

void *memset(void *dest, int value, long unsigned int len);

 void Delay_ms(DataType_u32 ms);
 void Delay_us(DataType_u32 us);

int main(void)
{
    RCC_AHB1ENR |= (1 << 0);
   (void)RCC_AHB1ENR;

    MCAL_GPIO_Init();

    /* 5. Main loop */
    while (1)
    {
        Delay_ms(30);
        MCAL_GPIO_TogglePin(MCAL_GPIO_SIGNAL_0);
        Delay_ms(30);
        MCAL_GPIO_TogglePin(MCAL_GPIO_SIGNAL_1);
        Delay_ms(30);
        MCAL_GPIO_TogglePin(MCAL_GPIO_SIGNAL_2);
        Delay_ms(30);
    }
}


















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

void *memset(void *dest, int value, long unsigned int len)
{
    unsigned char *p = (unsigned char *)dest;
    while (len--)
    {
        *p++ = (unsigned char)value;
    }
    return dest;
}
