#include "gtest/gtest.h"

TEST(Numbers, digit_separator) {
    ASSERT_EQ(1000, 1'000);
}


TEST(Numbers, binary_number) {
    ASSERT_EQ(2, 0b10);
}


TEST(Numbers, octal_number) {
    ASSERT_EQ(8, 010);
}


TEST(Numbers, hex_number) {
    ASSERT_EQ(16, 0x10);
}


TEST(Numbers, fixed_size_integers) {
    ASSERT_EQ(2u, sizeof(std::int_least16_t));
    ASSERT_EQ(4u, sizeof(std::int_least32_t));
    ASSERT_EQ(8u, sizeof(std::int_least64_t));
}


TEST(Numbers, minimum_size_integers) {
    ASSERT_LE(2u, sizeof(std::int_fast16_t));
    ASSERT_LE(4u, sizeof(std::int_fast32_t));
    ASSERT_LE(8u, sizeof(std::int_fast64_t));
}


TEST(Numbers, scientific_notation) {
    ASSERT_EQ(1230, 1.23E3);
    ASSERT_NE(typeid(int), typeid(1.23E3));
    ASSERT_EQ(typeid(double), typeid(1.23E3));
}


TEST(Numbers, overflow) {
    ASSERT_EQ(0x7fff, (short)0x7fff);
    //overflow
    ASSERT_EQ(-0x8000, (short)0x8000);
    ASSERT_NE(0x8000, (short)0x8000);
}


TEST(Numbers, integer_division_will_drop_any_fractional_portion) {
    ASSERT_EQ(2, 6/3);
    //fractional portion is dropped 
    ASSERT_EQ(2, 8/3);
}


TEST(Numbers, unsigned_number_will_be_wrapped_around_the_range) {
    //unsigned short range: [0, 0xffff]
    ASSERT_EQ((0x10000 - 1) % 0xffff, (unsigned short)0x10000);
}


