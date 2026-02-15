#include <gtest/gtest.h>

extern "C" {
#include "GPIO_Mock.h"
}

/* ============================================================
   Test Fixture
   - Reset mock memory before each test
   ============================================================ */
class GpioTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        MOCK_Reset();
    }
};

/* ============================================================
   Initialization Behaviour Tests
   ============================================================ */

/* Test: Initialization returns Success and sets module READY */
TEST_F(GpioTest, Init_ReturnsSuccessAndSetsReady)
{
    DataType_Request_Status status = GPIO_Intitialization();
    ASSERT_EQ(status, Success);

    DataType_u32 state = GPIO_GetModuleState();
    EXPECT_EQ(state, LIB_UTILS_STATE_READY);
}

/* Test: Module state is not READY before initialization */
TEST_F(GpioTest, Init_ModuleNotReadyBeforeInit)
{
    DataType_u32 state = GPIO_GetModuleState();
    EXPECT_NE(state, LIB_UTILS_STATE_READY);
}

/* ============================================================
   Register-Level Structural Verification
   ============================================================ */

/* Test: MODER register matches configuration table */
TEST_F(GpioTest, Init_ConfiguresModerCorrectly)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 i = 0; i < NUMBER_PINS_CFG; i++)
    {
        DataType_PortName port = PinSetUp_TableCfg[i].Port_Id;
        DataType_PinNumber pin = PinSetUp_TableCfg[i].Pin_Id;
        DataType_u32 mode = PinSetUp_TableCfg[i].Pin_Mode;

        DataType_u32 expected = (mode << (pin * REG_MODER_BITS));
        DataType_u32 mask = (0x3U << (pin * REG_MODER_BITS));

        EXPECT_EQ(Registers_Table[port]->Gpio_Moder & mask, expected);
    }
}

/* Test: OTYPER register matches configuration */
TEST_F(GpioTest, Init_ConfiguresOtyperCorrectly)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 i = 0; i < NUMBER_PINS_CFG; i++)
    {
        DataType_PortName port = PinSetUp_TableCfg[i].Port_Id;
        DataType_PinNumber pin = PinSetUp_TableCfg[i].Pin_Id;
        DataType_u32 type = PinSetUp_TableCfg[i].Pin_Output_Type;

        EXPECT_EQ(
            Registers_Table[port]->Gpio_Otyper & (1U << pin),
            (type << pin)
        );
    }
}

/* Test: OSPEEDR register matches configuration */
TEST_F(GpioTest, Init_ConfiguresOspeedrCorrectly)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 i = 0; i < NUMBER_PINS_CFG; i++)
    {
        DataType_PortName port = PinSetUp_TableCfg[i].Port_Id;
        DataType_PinNumber pin = PinSetUp_TableCfg[i].Pin_Id;
        DataType_u32 speed = PinSetUp_TableCfg[i].Pin_Output_Speed;

        DataType_u32 expected = (speed << (pin * REG_OSPEEDR_BITS));
        DataType_u32 mask = (0x3U << (pin * REG_OSPEEDR_BITS));

        EXPECT_EQ(Registers_Table[port]->Gpio_Ospeedr & mask, expected);
    }
}

/* Test: PUPDR register matches configuration */
TEST_F(GpioTest, Init_ConfiguresPupdrCorrectly)
{

}

/* Test: AFRL and AFRH alternate function configuration */
TEST_F(GpioTest, Init_ConfiguresAlternateFunctionCorrectly)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 i = 0; i < NUMBER_PINS_CFG; i++)
    {
        DataType_PortName port = PinSetUp_TableCfg[i].Port_Id;
        DataType_PinNumber pin = PinSetUp_TableCfg[i].Pin_Id;
        DataType_u32 af = PinSetUp_TableCfg[i].Pin_Alternate_Function;

        if (pin <= Pin_7)
        {
            DataType_u32 mask = (0xFU << (pin * REG_AFRL_BITS));
            DataType_u32 expected = (af << (pin * REG_AFRL_BITS));

            EXPECT_EQ(Registers_Table[port]->Gpio_Afrl & mask, expected);
        }
        else
        {
            DataType_u32 mask = (0xFU << ((pin - REG_AFRH_PINS_OFFSET) * REG_AFRH_BITS));
            DataType_u32 expected = (af << ((pin - REG_AFRH_PINS_OFFSET) * REG_AFRH_BITS));

            EXPECT_EQ(Registers_Table[port]->Gpio_Afrh & mask, expected);
        }
    }
}

/* Test: Initial ODR levels match configuration */
TEST_F(GpioTest, Init_ConfiguresInitialOutputLevelsCorrectly)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 i = 0; i < NUMBER_PINS_CFG; i++)
    {
        DataType_PortName port = PinSetUp_TableCfg[i].Port_Id;
        DataType_PinNumber pin = PinSetUp_TableCfg[i].Pin_Id;
        DataType_u32 level = PinSetUp_TableCfg[i].Pin_Output_Status_Setup;

        if (level == High)
            EXPECT_TRUE(Registers_Table[port]->Gpio_Odr & (1U << pin));
        else
            EXPECT_FALSE(Registers_Table[port]->Gpio_Odr & (1U << pin));
    }
}

/* ============================================================
   Unused Ports Must Be Zero
   ============================================================ */
TEST_F(GpioTest, Init_UnusedPortsAreZero)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 port = 0; port < HW_SUPPORTED_PORTS_NUM; port++)
    {
        if (PortUsage_Table[port] == Unused)
        {
            EXPECT_EQ(Registers_Table[port]->Gpio_Moder, 0U);
            EXPECT_EQ(Registers_Table[port]->Gpio_Otyper, 0U);
            EXPECT_EQ(Registers_Table[port]->Gpio_Ospeedr, 0U);
            EXPECT_EQ(Registers_Table[port]->Gpio_Pupdr, 0U);
        }
    }
}

/* ============================================================
   Negative / Boundary Testing
   ============================================================ */

TEST_F(GpioTest, WritePin_InvalidIndex)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    DataType_Request_Status status = GPIO_WritePin(NUMBER_PINS_CFG, High);
    EXPECT_EQ(status, Invalid_Parameter);
}



TEST_F(GpioTest, WritePin_FailsIfNotInitialized)
{
    DataType_Request_Status status = GPIO_WritePin(0, High);
    EXPECT_EQ(status, Invalid);
}

/* ============================================================
   Functional Behaviour Tests
   ============================================================ */

TEST_F(GpioTest, WritePin_SetsAndClearsBitCorrectly)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    DataType_u8 index = 1;

    ASSERT_EQ(GPIO_WritePin(index, High), Success);
    EXPECT_TRUE(
        Registers_Table[PinSetUp_TableCfg[index].Port_Id]->Gpio_Odr &
        (1U << PinSetUp_TableCfg[index].Pin_Id)
    );

    ASSERT_EQ(GPIO_WritePin(index, Low), Success);
    EXPECT_FALSE(
        Registers_Table[PinSetUp_TableCfg[index].Port_Id]->Gpio_Odr &
        (1U << PinSetUp_TableCfg[index].Pin_Id)
    );
}

TEST_F(GpioTest, TogglePin_FlipsBit)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    DataType_u8 index = 1;

    GPIO_WritePin(index, Low);
    ASSERT_EQ(GPIO_ToggelPin(index), Success);

    EXPECT_TRUE(
        Registers_Table[PinSetUp_TableCfg[index].Port_Id]->Gpio_Odr &
        (1U << PinSetUp_TableCfg[index].Pin_Id)
    );
}

/* ============================================================
   Looping Over All Pins
   ============================================================ */

TEST_F(GpioTest, WritePin_AllConfiguredPins)
{
    ASSERT_EQ(GPIO_Intitialization(), Success);

    for (DataType_u8 i = 0; i < NUMBER_PINS_CFG; i++)
    {
        ASSERT_EQ(GPIO_WritePin(i, High), Success);

        EXPECT_TRUE(
            Registers_Table[PinSetUp_TableCfg[i].Port_Id]->Gpio_Odr &
            (1U << PinSetUp_TableCfg[i].Pin_Id)
        );
    }
}
