#include "gtest/gtest.h"

TEST(Constants, compile_time_constants) {
    const double gravity{9.8};

    //gravity = 9.9; //compiler error
    ASSERT_EQ(9.8, gravity);
}


TEST(Constants, runtime_constants) {
    const auto value{ rand() /*runtime constant*/};

    ASSERT_EQ(typeid(int), typeid(value));
}


TEST(Constants, random_sized_array) {
    int array[rand() % 10];

    unsigned long size{sizeof(array) / sizeof(*array)};

    ASSERT_TRUE(size >= 0 && size < 10) << "array size was: " << size;
}


TEST(Constants, compile_time_constant_expression_must_be_initialized_with_compile_time_constants) {
    constexpr int size{ 10 };
    //constexpr int randomSize{ rand() % 10 }; //compiler error

    ASSERT_EQ(10, size);
}


//inline constexpr only avaiable with c++1z
inline constexpr double PI{ 3.1415926 };
TEST(Constants, inlining_constant_expression_into_callsite) {
    //inline constexpr int size{ 10 }; //inline constexpr can't be declared as local variables
    ASSERT_EQ(3.1415926, PI);
}

TEST(Constants, preprocessor_macro_symbolic_constant_will_be_replaced_in_translation_stage_before_the_compile_stage) {
    {
        //`size` will be replace with literal number 5 by preprocessor after the definition
        #define size 5
    }

    ASSERT_EQ(5, size);
}


