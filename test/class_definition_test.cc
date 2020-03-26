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



class Cart {
    using price_t = double;
    price_t price = 0;
    int qty = 0;

    public:
        void add(price_t price, int qty) {
            this->price += price * qty;
            this->qty += qty;
        }

        price_t totalPrice() {
            return price;
        }

        price_t totalQuantity() {
            return qty;
        }
};
TEST(Class, private_members) {
    Cart cart{};

    cart.add(2.5, 3);
    ASSERT_EQ(7.5, cart.totalPrice());
    ASSERT_EQ(3, cart.totalQuantity());

    cart.add(2, 2);
    ASSERT_EQ(11.5, cart.totalPrice());
    ASSERT_EQ(5, cart.totalQuantity());
    //ASSERT_EQ(5, cart.qty); //compile error
}
