// ============================================================
// Bare-metal STM32F401
// USART2 TX (PA2) sends 0xA5
// GPIOB PB5 toggled
// No HAL, no stdlib, freestanding
// ============================================================

typedef volatile unsigned long vuint32_t;
#include <stddef.h>

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
 * RCC
 * ------------------------------------------------------------ */
#define RCC_AHB1ENR   (*(vuint32_t *)0x40023830)
#define RCC_APB1ENR   (*(vuint32_t *)0x40023840)

/* ------------------------------------------------------------
 * GPIOA (USART2 TX = PA2)
 * ------------------------------------------------------------ */
#define GPIOA_MODER   (*(vuint32_t *)0x40020000)
#define GPIOA_AFRL    (*(vuint32_t *)0x40020020)

/* ------------------------------------------------------------
 * GPIOB (LED on PB5)
 * ------------------------------------------------------------ */
#define GPIOB_MODER   (*(vuint32_t *)0x40020400)
#define GPIOB_ODR     (*(vuint32_t *)0x40020414)

/* ------------------------------------------------------------
 * USART2 registers
 * ------------------------------------------------------------ */
#define USART2_SR     (*(vuint32_t *)0x40004400)
#define USART2_DR     (*(vuint32_t *)0x40004404)
#define USART2_BRR    (*(vuint32_t *)0x40004408)
#define USART2_CR1    (*(vuint32_t *)0x4000440C)

/* ------------------------------------------------------------
 * Simple delay
 * ------------------------------------------------------------ */
static void delay(volatile unsigned int count)
{
    while (count--)
    {
        __asm__("nop");
    }
}

/* ------------------------------------------------------------
 * USART2 init: TX only, 9600 baud @ 16 MHz
 * ------------------------------------------------------------ */
static void USART2_Init(void)
{
    /* Enable clocks */
    RCC_AHB1ENR |= (1 << 0);   // GPIOA
    RCC_APB1ENR |= (1 << 17);  // USART2

    /* PA2 -> Alternate Function (AF7) */
    GPIOA_MODER &= ~(3U << (2 * 2));
    GPIOA_MODER |=  (2U << (2 * 2));   // AF mode

    GPIOA_AFRL &= ~(0xFU << (2 * 4));
    GPIOA_AFRL |=  (7U  << (2 * 4));   // AF7 = USART2

    /* Baud rate = 9600 (16 MHz / 9600 = 1666 = 0x0682~0x0683) */
    USART2_BRR = 0x0683;

    /* Enable USART + TX */
    USART2_CR1 =
        (1 << 13) |   // UE
        (1 << 3);     // TE
}

/* ------------------------------------------------------------
 * Send one byte (blocking)
 * ------------------------------------------------------------ */
static void USART2_SendByte(unsigned char data)
{
    while (!(USART2_SR & (1 << 7)))
    {
        /* wait until TXE */
    }
    USART2_DR = data;
}

/* ------------------------------------------------------------
 * MAIN
 * ------------------------------------------------------------ */
int main(void)
{
    /* Enable GPIOB clock */
    RCC_AHB1ENR |= (1 << 1);

    /* PB5 as output */
    GPIOB_MODER &= ~(3U << (5 * 2));
    GPIOB_MODER |=  (1U << (5 * 2));

    /* Init USART */
    USART2_Init();

    while (1)
    {
        GPIOB_ODR ^= (1 << 5);   // Toggle LED
        USART2_SendByte(0xA5);   // Send 0xA5
        delay(1000000);
    }
}
