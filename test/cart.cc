#include "cart.h"

void Cart::add(price_t price, int qty) {
    Cart &self = *this;
    self.price += price * qty;
    self.qty += qty;
}

Cart::price_t Cart::totalPrice() {
    return price;
}

Cart::price_t Cart::totalQuantity() {
    return qty;
}
