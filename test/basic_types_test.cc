#include "gtest/gtest.h"


TEST(BasicTypes, size) {
    ASSERT_EQ(1u, sizeof(bool));
    ASSERT_EQ(1u, sizeof(char));
    ASSERT_EQ(2u, sizeof(short));
    ASSERT_EQ(4u, sizeof(int));
    ASSERT_EQ(8u, sizeof(long));
    ASSERT_EQ(4u, sizeof(float));
    ASSERT_EQ(8u, sizeof(double));
}




