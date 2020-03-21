#include "gtest/gtest.h"


TEST(Operators, static_cast) {
    double a{5.2};

    ASSERT_EQ(5, static_cast<int>(a));
    ASSERT_EQ(5, int(a));
    ASSERT_EQ(5, (int)a);
}


TEST(Operators, comma_operator) {
    int x{1}, y{2};
    int a{(++x, ++y)};

    ASSERT_EQ(a, 3);
    ASSERT_EQ(x, 2);
    ASSERT_EQ(y, 3);
}


