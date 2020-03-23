#include "gtest/gtest.h"

TEST(String, length) {
    std::string s{"string"};

    ASSERT_EQ(6u, s.length());

}


TEST(String, c_style_string_with_null_terminator) {
    char s[]{"string"};

    ASSERT_EQ(7u, std::size(s));
    ASSERT_EQ('s', s[0]);
    ASSERT_EQ('\0', s[6]) << "null terminator";
}
