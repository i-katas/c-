#include "gtest/gtest.h"


TEST(FixedArray, fixed_array) {
    int array[2]{};

    array[0] = 2;

    ASSERT_EQ(2, array[0]);
    ASSERT_EQ(0, array[1]);
}

TEST(FixedArray, initializer_list) {
    int array[3] = {5, 6};

    ASSERT_EQ(5, array[0]);
    ASSERT_EQ(6, array[1]);
    ASSERT_EQ(0, array[2]);
}


TEST(FixedArray, length) {
    int array[3];

    ASSERT_EQ(3u, sizeof(array) / sizeof(*array));
}


TEST(FixedArray, use_macro_symbolic_constant_to_create_a_fixed_array) {
    #define ARRAY_SIZE 5

    int array[ARRAY_SIZE];

    ASSERT_EQ(5u, sizeof(array) / sizeof(*array));
}


TEST(FixedArray, use_constexpr_constant_to_create_a_fixed_array) {
    constexpr int arraySize{5};

    int array[arraySize];

    ASSERT_EQ(5u, sizeof(array) / sizeof(*array));
}


