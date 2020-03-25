#include "gtest/gtest.h"


TEST(Operators, static_cast) {
    double a{5.2};

    ASSERT_EQ(5, static_cast<int>(a));
    ASSERT_EQ(5, int(a));
    ASSERT_EQ(5, (int)a);
}


TEST(Operators, compute_all_exppressions_in_comma_operator_and_return_the_value_of_the_last_expression) {
    int x{1}, y{2};
    int a{(++x, ++y)};

    ASSERT_EQ(a, 3);
    ASSERT_EQ(x, 2);
    ASSERT_EQ(y, 3);
}


