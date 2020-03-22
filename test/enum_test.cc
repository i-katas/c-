#include "gtest/gtest.h"
#include <type_traits>


TEST(Enum, enumerator_values) {
    enum Color {
        RED,
        GREEN,
        BLUE
    };

    bool isUnsigned = std::is_same<unsigned ,typename std::underlying_type<Color>::type>::value;

    ASSERT_TRUE(isUnsigned);
    ASSERT_EQ(0, RED);
    ASSERT_EQ(1, GREEN);
    ASSERT_EQ(2, BLUE);
}


TEST(Enum, custom_enumerator_type) {
    enum Color: int {
        RED,
        GREEN,
        BLUE
    };

    bool isUnsigned = std::is_same<unsigned ,typename std::underlying_type<Color>::type>::value;
    bool isSignedInt = std::is_same<int ,typename std::underlying_type<Color>::type>::value;

    ASSERT_FALSE(isUnsigned);
    ASSERT_TRUE(isSignedInt);
    ASSERT_EQ(0, RED);
    ASSERT_EQ(1, GREEN);
    ASSERT_EQ(2, BLUE);
}



TEST(Enum, custom_enumerator_value) {
    enum Color{
        RED = -1,
        GREEN,
        BLUE
    };

    ASSERT_EQ(-1, RED);
    ASSERT_EQ(0, GREEN);
    ASSERT_EQ(1, BLUE);
}


TEST(Enum, duplicated_enumerator_values) {
    enum Color{
        RED = -1,
        GREEN = -1,
        BLUE
    };

    ASSERT_EQ(-1, RED);
    ASSERT_EQ(-1, GREEN);
    ASSERT_EQ(0, BLUE);
}


TEST(Enum, convert_integer_to_enumerator) {
    enum Color {
        RED,
        GREEN,
        BLUE
    };

    Color color{static_cast<Color>(1)};

    ASSERT_EQ(GREEN, color);
}


