#include "gtest/gtest.h"


TEST(ControlFlow, if_init_statement) {
    int a{2};

    if(int b{2 * a}; b > 3) {
        a *= 3;
    }

    ASSERT_EQ(6, a);
}


TEST(ControlFlow, null_statement) {
    int a{1};

    while(++a < 10);

    ASSERT_EQ(10, a);
}


