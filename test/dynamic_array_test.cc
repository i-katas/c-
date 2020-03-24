#include "gtest/gtest.h"

TEST(DynamicArray, initializer_list) {
    int size{2};

    int* array = new int[size]{5};

    ASSERT_EQ(5, array[0]);
    ASSERT_EQ(0, array[1]);
}


