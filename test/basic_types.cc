#include "gtest/gtest.h"


TEST(BasicTypes, overflow) {
    ASSERT_EQ(0x7fff, (short)0x7fff);
    //overflow
    ASSERT_EQ(-0x8000, (short)0x8000);
    ASSERT_NE(0x8000, (short)0x8000);
}


TEST(BasicTypes, integer_division_will_drop_any_fractional_portion) {
    ASSERT_EQ(2, 6/3);
    //fractional portion is dropped 
    ASSERT_EQ(2, 8/3);
}


TEST(BasicTypes, unsigned_number_will_be_wrapped_around_the_range) {
    //unsigned short range: [0, 0xffff]
    ASSERT_EQ((0x10000 - 1) % 0xffff, (unsigned short)0x10000);
}


TEST(BasicTypes, initialize_boolean_variable) {
    bool truth{true};
    bool falsy{false};

    ASSERT_EQ(true, truth);
    ASSERT_EQ(false, falsy);
}


TEST(BasicTypes, initialize_boolean_variable_with_integer_value) {
    bool truth{1};
    bool falsy{0};

    ASSERT_EQ(true, truth);
    ASSERT_EQ(false, falsy);
}


TEST(BasicTypes, size) {
    ASSERT_EQ(1u, sizeof(bool));
    ASSERT_EQ(1u, sizeof(char));
    ASSERT_EQ(2u, sizeof(short));
    ASSERT_EQ(4u, sizeof(int));
    ASSERT_EQ(8u, sizeof(long));
    ASSERT_EQ(4u, sizeof(float));
    ASSERT_EQ(8u, sizeof(double));
}


TEST(BasicTypes, digit_separator) {
    ASSERT_EQ(1000, 1'000);
}


TEST(BasicTypes, compile_time_constants) {
    const double gravity{9.8};

    //gravity = 9.9; //compiler error
    ASSERT_EQ(9.8, gravity);
}


TEST(BasicTypes, runtime_constants) {
    const auto value{ rand() /*runtime constant*/};

    ASSERT_EQ(typeid(int), typeid(value));
}


TEST(BasicTypes, random_sized_array) {
    int array[rand() % 10];

    unsigned long size{sizeof(array) / sizeof(*array)};

    ASSERT_TRUE(size >= 0 && size < 10) << "array size was: " << size;
}


TEST(BasicTypes, compile_time_constant_expression) {
    constexpr int size{ 10 };
    //constexpr int randomSize{ rand() % 10 }; //compiler error

    ASSERT_EQ(10, size);
}


//inline constexpr only avaiable with c++1z
inline constexpr double PI{ 3.1415926 };
TEST(BasicTypes, inlining_constant_expression) {
    //inline constexpr int size{ 10 }; //inline constexpr can't be declared as local variables
    ASSERT_EQ(3.1415926, PI);
}


