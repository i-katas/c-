#include "gtest/gtest.h"


TEST(Boolean, initialize_boolean_variable) {
    bool truth{true};
    bool falsy{false};

    ASSERT_EQ(true, truth);
    ASSERT_EQ(false, falsy);
}


TEST(Boolean, initialize_boolean_variable_with_integer_value) {
    bool truth{1};
    bool falsy{0};

    ASSERT_EQ(true, truth);
    ASSERT_EQ(false, falsy);
}


