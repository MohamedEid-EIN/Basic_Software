#include <gtest/gtest.h>

extern "C" {
#include "GPIO.h"
}

TEST(SanityCheck, AlwaysPasses)
{
    EXPECT_EQ(1, 1);
}
