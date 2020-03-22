#include "gtest/gtest.h"

TEST(TypeDef, create_type_definition) {
    typedef int width_t;
    typedef int width_t; // duplciate definition

    ASSERT_EQ(typeid(int), typeid(width_t));
}


TEST(TypeDef, create_type_alias) {
    using height_t = int;
    ASSERT_EQ(typeid(int), typeid(height_t));
}



