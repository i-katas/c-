#include "gtest/gtest.h"


TEST(Reference, to_non_const_value) {
    int a{1};

    int &b = a;
    ASSERT_EQ(1, b);

    a = 2;
    ASSERT_EQ(2, b) << "value must be changed by `a`";

    b = 3;
    ASSERT_EQ(3, a) << "value must be changed by `b`";
}


TEST(Reference, const_reference) {
    int a{1};

    const int &b = a;
    ASSERT_EQ(1, b);

    a = 2; 
    ASSERT_EQ(2, b) << "value must be changed by `a`";
    //b = 3; //compiler error
}


TEST(Reference, const_value) {
    const int a{1};
    const int &b = a;

    ASSERT_EQ(1, b);

    //a = 2; //compiler error
    //b = 3; //compiler error
}


TEST(Reference, must_be_initialized) {
    int a{1};
    //int &b; //compiler error

    ASSERT_EQ(1, a);
}


TEST(Reference, can_not_be_reassigned) {
    int a{1}, c{2};
    int &b = a; 

    b = c;
    ASSERT_EQ(2, b);
    ASSERT_EQ(2, a);

    a = 3;
    ASSERT_EQ(3, b);
    ASSERT_EQ(2, c);
}


TEST(Reference, change_reference_parameter_value) {
    void (*lambda)(int &) = [](int &x){
        x *= 2;
    };
    int x{3};

    lambda(x);

    ASSERT_EQ(6, x);
}


TEST(Reference, pass_array_as_reference_does_not_decay_into_pointer_but_must_specify_array_with_fixed_size) {
    unsigned int (*size)(int (&)[2]) = [](int (&array)[2]) -> unsigned int {
        return sizeof(array);
    };
    int array[] = {1, 2};


    ASSERT_EQ(size(array), sizeof(array));
}


struct Product {
    std::string name;
};

TEST(Reference, reference_as_shortcut) {
    Product product{"apple"};

    std::string &productName{ product.name };

    productName = "orange";
    ASSERT_EQ("orange", product.name);
}


