#include "gtest/gtest.h"

enum class Color {
    RED,
    GREEN,
    BLUE
};


TEST(EnumClass, enumerator_values) {
    ASSERT_EQ(0, static_cast<int>(Color::RED));
    ASSERT_EQ(1, static_cast<int>(Color::GREEN));
    ASSERT_EQ(2, static_cast<int>(Color::BLUE));
}


TEST(EnumClass, convert_integer_to_enumerator) {
    Color color{static_cast<Color>(1)};

    ASSERT_EQ(Color::GREEN, color);
}
