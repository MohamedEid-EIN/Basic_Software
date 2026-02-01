# 0 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/01_Build_System//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c"







typedef volatile unsigned long vuint32_t;
# 1 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 1 3 4
# 145 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4

# 145 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 214 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 329 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 425 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 436 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h" 3 4
} max_align_t;
# 10 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c" 2





# 14 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c"
void *memset(void *dest, int value, size_t len)
{
    unsigned char *p = (unsigned char *)dest;
    while (len--)
    {
        *p++ = (unsigned char)value;
    }
    return dest;
}
# 53 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c"
static void delay(volatile unsigned int count)
{
    while (count--)
    {
        __asm__("nop");
    }
}




static void USART2_Init(void)
{

    (*(vuint32_t *)0x40023830) |= (1 << 0);
    (*(vuint32_t *)0x40023840) |= (1 << 17);


    (*(vuint32_t *)0x40020000) &= ~(3U << (2 * 2));
    (*(vuint32_t *)0x40020000) |= (2U << (2 * 2));

    (*(vuint32_t *)0x40020020) &= ~(0xFU << (2 * 4));
    (*(vuint32_t *)0x40020020) |= (7U << (2 * 4));


    (*(vuint32_t *)0x40004408) = 0x0683;


    (*(vuint32_t *)0x4000440C) =
        (1 << 13) |
        (1 << 3);
}




static void USART2_SendByte(unsigned char data)
{
    while (!((*(vuint32_t *)0x40004400) & (1 << 7)))
    {

    }
    (*(vuint32_t *)0x40004404) = data;
}




int main(void)
{

    (*(vuint32_t *)0x40023830) |= (1 << 1);


    (*(vuint32_t *)0x40020400) &= ~(3U << (5 * 2));
    (*(vuint32_t *)0x40020400) |= (1U << (5 * 2));


    USART2_Init();

    while (1)
    {
        (*(vuint32_t *)0x40020414) ^= (1 << 5);
        USART2_SendByte(0xA5);
        delay(1000000);
    }
}
