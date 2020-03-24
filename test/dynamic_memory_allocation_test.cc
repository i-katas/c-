#include "gtest/gtest.h"


TEST(DynamicMemoryAllocation, allocate_memory_dynamically_by_use_the_scalar_form_new_operator) {
    int *ptr = new int;

    ASSERT_EQ(0, *ptr);

    delete ptr;
}


TEST(DynamicMemoryAllocation, deallocate_array) {
    int *array{ new int[3] };

    delete[] array;
}


