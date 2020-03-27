#ifndef CART_INTERNAL_H
#define CART_INTERNAL_H
class Cart {
    public:
        static int version;
        using price_t = double;
        void add(price_t price, int qty); 
        price_t totalPrice() const;
        price_t totalQuantity() const;
        friend void reset(Cart &cart);
    private:
        price_t price { 0 };
        int qty{ 0 };
};
#endif
