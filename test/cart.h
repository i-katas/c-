#ifndef CART_INTERNAL_H
#define CART_INTERNAL_H
class Cart {
    public:
        using price_t = double;
        void add(price_t price, int qty); 
        price_t totalPrice();
        price_t totalQuantity();
    private:
        price_t price { 0 };
        int qty{ 0 };
};
#endif
