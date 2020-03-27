#include "gtest/gtest.h"

class Counter {
    public:
        const int count;
        Counter(int count = 0): count{ count } {}
        //copy constructor
        Counter(const Counter& that): count{ 0 } {}
};

TEST(Constructor, custom_direct_initialization_by_copy_constructor) {
    Counter counter { 1 };

    ASSERT_EQ(1, counter.count);

    Counter uniform { counter }; 
    ASSERT_EQ(0, uniform.count);

    Counter direct(counter); 
    ASSERT_EQ(0, direct.count);

    Counter copy = counter; 
    ASSERT_EQ(0, copy.count);
}


TEST(Constructor, multiple_initializations_result_copy_initialization_will_be_elided_is_called_elision) {
    Counter direct(Counter(2)); //shortend by compiler as: direct(2)
    Counter uniform{ Counter{ 2 } }; //shortend by compiler as: direct{ 2 }
    Counter copy = Counter(2); //shortend by compiler as: direct = 2

    ASSERT_EQ(2, direct.count) << "copy constructor should not be called";
    ASSERT_EQ(2, uniform.count) << "copy constructor should not be called";
    ASSERT_EQ(2, copy.count) << "copy constructor should not be called";
}
