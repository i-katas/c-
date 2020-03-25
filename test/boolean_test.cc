#include "gtest/gtest.h"


TEST(Boolean, initialize_with_boolean_literals) {
    bool truth{true};
    bool falsy{false};

    ASSERT_EQ(true, truth);
    ASSERT_EQ(false, falsy);
}


TEST(Boolean, initialize_with_integer_literals) {
    bool truth{1};
    bool falsy{0};

    ASSERT_EQ(true, truth);
    ASSERT_EQ(false, falsy);
}


