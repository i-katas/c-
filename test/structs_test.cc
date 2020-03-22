#include "gtest/gtest.h"

TEST(Struct, initializer_list) {
    struct Item {
        int id;
        std::string name;
    };

    Item item{1, "iPhone"};

    ASSERT_EQ(1, item.id);
    ASSERT_EQ("iPhone", item.name);
}


TEST(Struct, zero_initialization) {
    struct Unit {
        int kg;
    };

    Unit unit{};

    ASSERT_EQ(0, unit.kg);
}


TEST(Struct, initialized_with_default_value) {
    struct Time {
        int hours;
        int seconds{1};
    };

    Time time{2};

    ASSERT_EQ(2, time.hours);
    ASSERT_EQ(1, time.seconds);
}


TEST(Struct, define_methods) {
    struct Item {
        int price;
        int quantity;

        int totalPrice() {
            return price * quantity;
        }
    };

    Item iPhone{6000, 3};
    Item viso{2000, 2};

    ASSERT_EQ(18000, iPhone.totalPrice());
    ASSERT_EQ(4000, viso.totalPrice());
}
