#include "gtest/gtest.h"

class Item {
    public/*access specifiers*/:
        using quantity_t = int;
        int price;
        quantity_t qty = 0;
        int totalPrice();
};
TEST(Class, initializer_list_with_public_fields) {
    Item item{ 3 };

    ASSERT_EQ(3, item.price);
    ASSERT_EQ(0, item.qty);
}


int Item::totalPrice() {
    return price * qty;
}
TEST(Class, member_function_definition) {
    Item item{ 3, 2 };

    ASSERT_EQ(6, item.totalPrice());
}


TEST(Class, member_types) {
    ASSERT_EQ(typeid(int), typeid(Item::quantity_t));
}


#include "cart.h"
TEST(Class, private_members) {
    Cart cart;
    ASSERT_EQ(0, cart.totalQuantity());
    ASSERT_EQ(0., cart.totalPrice());

    cart.add(2.5, 3);
    ASSERT_EQ(7.5, cart.totalPrice());
    ASSERT_EQ(3, cart.totalQuantity());

    cart.add(2, 2);
    ASSERT_EQ(11.5, cart.totalPrice());
    ASSERT_EQ(5, cart.totalQuantity());
    //ASSERT_EQ(5, cart.qty); //compile error
}
