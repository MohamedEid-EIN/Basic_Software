	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 1 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c"
	.align	1
	.global	memset
	.syntax unified
	.thumb
	.thumb_func
	.type	memset, %function
memset:
.LFB0:
	.loc 1 15 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	sub	sp, sp, #28
	.cfi_def_cfa_offset 32
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	str	r0, [r7, #12]
	str	r1, [r7, #8]
	str	r2, [r7, #4]
	.loc 1 16 20
	ldr	r3, [r7, #12]
	str	r3, [r7, #20]
	.loc 1 17 11
	b	.L2
.L3:
	.loc 1 19 11
	ldr	r3, [r7, #20]
	adds	r2, r3, #1
	str	r2, [r7, #20]
	.loc 1 19 16
	ldr	r2, [r7, #8]
	uxtb	r2, r2
	.loc 1 19 14
	strb	r2, [r3]
.L2:
	.loc 1 17 15
	ldr	r3, [r7, #4]
	subs	r2, r3, #1
	str	r2, [r7, #4]
	.loc 1 17 12
	cmp	r3, #0
	bne	.L3
	.loc 1 21 12
	ldr	r3, [r7, #12]
	.loc 1 22 1
	mov	r0, r3
	adds	r7, r7, #28
	.cfi_def_cfa_offset 4
	mov	sp, r7
	.cfi_def_cfa_register 13
	@ sp needed
	pop	{r7}
	.cfi_restore 7
	.cfi_def_cfa_offset 0
	bx	lr
	.cfi_endproc
.LFE0:
	.size	memset, .-memset
	.align	1
	.syntax unified
	.thumb
	.thumb_func
	.type	delay, %function
delay:
.LFB1:
	.loc 1 54 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	str	r0, [r7, #4]
	.loc 1 55 11
	b	.L6
.L7:
	.loc 1 57 9
	.syntax unified
@ 57 "/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/Basic_Software_STM32F401xC/06_Software/01_Application/Source/main.c" 1
	nop
@ 0 "" 2
	.thumb
	.syntax unified
.L6:
	.loc 1 55 17
	ldr	r3, [r7, #4]
	subs	r2, r3, #1
	str	r2, [r7, #4]
	.loc 1 55 12
	cmp	r3, #0
	bne	.L7
	.loc 1 59 1
	nop
	nop
	adds	r7, r7, #12
	.cfi_def_cfa_offset 4
	mov	sp, r7
	.cfi_def_cfa_register 13
	@ sp needed
	pop	{r7}
	.cfi_restore 7
	.cfi_def_cfa_offset 0
	bx	lr
	.cfi_endproc
.LFE1:
	.size	delay, .-delay
	.align	1
	.syntax unified
	.thumb
	.thumb_func
	.type	USART2_Init, %function
USART2_Init:
.LFB2:
	.loc 1 65 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	.loc 1 67 5
	ldr	r3, .L9
	ldr	r3, [r3]
	ldr	r2, .L9
	.loc 1 67 17
	orr	r3, r3, #1
	str	r3, [r2]
	.loc 1 68 5
	ldr	r3, .L9+4
	ldr	r3, [r3]
	ldr	r2, .L9+4
	.loc 1 68 17
	orr	r3, r3, #131072
	str	r3, [r2]
	.loc 1 71 5
	ldr	r3, .L9+8
	ldr	r3, [r3]
	ldr	r2, .L9+8
	.loc 1 71 17
	bic	r3, r3, #48
	str	r3, [r2]
	.loc 1 72 5
	ldr	r3, .L9+8
	ldr	r3, [r3]
	ldr	r2, .L9+8
	.loc 1 72 17
	orr	r3, r3, #32
	str	r3, [r2]
	.loc 1 74 5
	ldr	r3, .L9+12
	ldr	r3, [r3]
	ldr	r2, .L9+12
	.loc 1 74 16
	bic	r3, r3, #3840
	str	r3, [r2]
	.loc 1 75 5
	ldr	r3, .L9+12
	ldr	r3, [r3]
	ldr	r2, .L9+12
	.loc 1 75 16
	orr	r3, r3, #1792
	str	r3, [r2]
	.loc 1 78 5
	ldr	r3, .L9+16
	.loc 1 78 16
	movw	r2, #1667
	str	r2, [r3]
	.loc 1 81 5
	ldr	r3, .L9+20
	.loc 1 81 16
	movw	r2, #8200
	str	r2, [r3]
	.loc 1 84 1
	nop
	mov	sp, r7
	.cfi_def_cfa_register 13
	@ sp needed
	pop	{r7}
	.cfi_restore 7
	.cfi_def_cfa_offset 0
	bx	lr
.L10:
	.align	2
.L9:
	.word	1073887280
	.word	1073887296
	.word	1073872896
	.word	1073872928
	.word	1073759240
	.word	1073759244
	.cfi_endproc
.LFE2:
	.size	USART2_Init, .-USART2_Init
	.align	1
	.syntax unified
	.thumb
	.thumb_func
	.type	USART2_SendByte, %function
USART2_SendByte:
.LFB3:
	.loc 1 90 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	mov	r3, r0
	strb	r3, [r7, #7]
	.loc 1 91 11
	nop
.L12:
	.loc 1 91 14 discriminator 1
	ldr	r3, .L13
	ldr	r3, [r3]
	.loc 1 91 24 discriminator 1
	and	r3, r3, #128
	.loc 1 91 12 discriminator 1
	cmp	r3, #0
	beq	.L12
	.loc 1 95 5
	ldr	r2, .L13+4
	.loc 1 95 15
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	str	r3, [r2]
	.loc 1 96 1
	nop
	adds	r7, r7, #12
	.cfi_def_cfa_offset 4
	mov	sp, r7
	.cfi_def_cfa_register 13
	@ sp needed
	pop	{r7}
	.cfi_restore 7
	.cfi_def_cfa_offset 0
	bx	lr
.L14:
	.align	2
.L13:
	.word	1073759232
	.word	1073759236
	.cfi_endproc
.LFE3:
	.size	USART2_SendByte, .-USART2_SendByte
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
.LFB4:
	.loc 1 102 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	.loc 1 104 5
	ldr	r3, .L17
	ldr	r3, [r3]
	ldr	r2, .L17
	.loc 1 104 17
	orr	r3, r3, #2
	str	r3, [r2]
	.loc 1 107 5
	ldr	r3, .L17+4
	ldr	r3, [r3]
	ldr	r2, .L17+4
	.loc 1 107 17
	bic	r3, r3, #3072
	str	r3, [r2]
	.loc 1 108 5
	ldr	r3, .L17+4
	ldr	r3, [r3]
	ldr	r2, .L17+4
	.loc 1 108 17
	orr	r3, r3, #1024
	str	r3, [r2]
	.loc 1 111 5
	bl	USART2_Init
.L16:
	.loc 1 115 9
	ldr	r3, .L17+8
	ldr	r3, [r3]
	ldr	r2, .L17+8
	.loc 1 115 19
	eor	r3, r3, #32
	str	r3, [r2]
	.loc 1 116 9
	movs	r0, #165
	bl	USART2_SendByte
	.loc 1 117 9 discriminator 1
	ldr	r0, .L17+12
	bl	delay
	.loc 1 115 19
	b	.L16
.L18:
	.align	2
.L17:
	.word	1073887280
	.word	1073873920
	.word	1073873940
	.word	1000000
	.cfi_endproc
.LFE4:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/lib/gcc/arm-none-eabi/13.2.1/include/stddef.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x138
	.2byte	0x5
	.byte	0x1
	.byte	0x4
	.4byte	.Ldebug_abbrev0
	.uleb128 0x6
	.4byte	.LASF13
	.byte	0x1d
	.4byte	.LASF14
	.4byte	.LASF15
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x3
	.4byte	.LASF1
	.byte	0x1
	.byte	0x8
	.byte	0x20
	.4byte	0x39
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.4byte	.LASF0
	.uleb128 0x4
	.4byte	0x32
	.uleb128 0x7
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.4byte	.LASF2
	.byte	0x2
	.byte	0xd6
	.byte	0x17
	.4byte	0x51
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x4
	.4byte	0x51
	.uleb128 0x1
	.byte	0x8
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x1
	.byte	0x8
	.byte	0x4
	.4byte	.LASF5
	.uleb128 0x8
	.4byte	.LASF16
	.byte	0x1
	.byte	0x65
	.byte	0x5
	.4byte	0x3e
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x5
	.4byte	.LASF7
	.byte	0x59
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xa4
	.uleb128 0x2
	.4byte	.LASF9
	.byte	0x59
	.byte	0x2b
	.4byte	0xa4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -9
	.byte	0
	.uleb128 0x1
	.byte	0x1
	.byte	0x8
	.4byte	.LASF6
	.uleb128 0x9
	.4byte	.LASF17
	.byte	0x1
	.byte	0x40
	.byte	0xd
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x5
	.4byte	.LASF8
	.byte	0x35
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xe0
	.uleb128 0x2
	.4byte	.LASF10
	.byte	0x35
	.byte	0x29
	.4byte	0x58
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xa
	.4byte	.LASF18
	.byte	0x1
	.byte	0xe
	.byte	0x7
	.4byte	0x133
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x133
	.uleb128 0x2
	.4byte	.LASF11
	.byte	0xe
	.byte	0x14
	.4byte	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2
	.4byte	.LASF12
	.byte	0xe
	.byte	0x1e
	.4byte	0x3e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xb
	.ascii	"len\000"
	.byte	0x1
	.byte	0xe
	.byte	0x2c
	.4byte	0x45
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xc
	.ascii	"p\000"
	.byte	0x1
	.byte	0x10
	.byte	0x14
	.4byte	0x135
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xd
	.byte	0x4
	.uleb128 0xe
	.byte	0x4
	.4byte	0xa4
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 13
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF4:
	.ascii	"long long int\000"
.LASF12:
	.ascii	"value\000"
.LASF2:
	.ascii	"size_t\000"
.LASF11:
	.ascii	"dest\000"
.LASF17:
	.ascii	"USART2_Init\000"
.LASF14:
	.ascii	"/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/"
	.ascii	"Basic_Software_STM32F401xC/06_Software/01_Applicati"
	.ascii	"on/Source/main.c\000"
.LASF0:
	.ascii	"long unsigned int\000"
.LASF9:
	.ascii	"data\000"
.LASF1:
	.ascii	"vuint32_t\000"
.LASF13:
	.ascii	"GNU C17 13.2.1 20231009 -mcpu=cortex-m4 -mthumb -mf"
	.ascii	"loat-abi=soft -march=armv7e-m -g -O0 -ffreestanding"
	.ascii	" -fno-builtin-memset\000"
.LASF6:
	.ascii	"unsigned char\000"
.LASF16:
	.ascii	"main\000"
.LASF10:
	.ascii	"count\000"
.LASF7:
	.ascii	"USART2_SendByte\000"
.LASF18:
	.ascii	"memset\000"
.LASF5:
	.ascii	"long double\000"
.LASF8:
	.ascii	"delay\000"
.LASF3:
	.ascii	"unsigned int\000"
.LASF15:
	.ascii	"/home/mohamed/Desktop/GitHub_Repo/My_Repo/Projects/"
	.ascii	"Basic_Software_STM32F401xC/01_Build_System\000"
	.ident	"GCC: (15:13.2.rel1-2) 13.2.1 20231009"
