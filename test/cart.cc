#include "cart.h"

int Cart::version { 0 };

void Cart::add(price_t price, int qty) {
    Cart &self = *this;
    self.price += price * qty;
    self.qty += qty;
}

Cart::price_t Cart::totalPrice() const {
    return price;
}

Cart::price_t Cart::totalQuantity() const {
    return qty;
}
