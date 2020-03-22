#include "gtest/gtest.h"

TEST(String, length) {
    std::string s{"string"};

    ASSERT_EQ(6u, s.length());
}
