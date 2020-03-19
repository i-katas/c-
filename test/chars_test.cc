#include "gtest/gtest.h"


TEST(Chars, control_chars) {
    constexpr int MAX_CONTRL_CHAR{31};

    ASSERT_GT(MAX_CONTRL_CHAR, '\t');
    ASSERT_GT(MAX_CONTRL_CHAR, '\n');
    ASSERT_GT(MAX_CONTRL_CHAR, '\r');
    ASSERT_GT(MAX_CONTRL_CHAR, '\b');
}


TEST(Chars, hex_chars) {
    ASSERT_EQ(0x6F, '\x6F');
}


TEST(Chars, octal_chars) {
    ASSERT_EQ(071, '\71');
}


