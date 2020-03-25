#include "gtest/gtest.h"


void pass_by_value(int a) {
    a = 2;
}
TEST(Parameters, pass_by_value_will_copy_the_value_into_parameter) {
    int a { 1 };

    pass_by_value(a);

    ASSERT_EQ(1, a);
}


void pass_by_reference(int &a) {
    a = 2;
}
TEST(Parameters, pass_by_reference_will_create_aliases_for_the_value) {
    int a { 1 };

    pass_by_reference(a);

    ASSERT_EQ(2, a);
}

static int global{ 3 };

void pass_by_pointer(int *a) {
    *a = 2;
    a = &global;
}
TEST(Parameters, pass_by_pointer_changes_value_but_pointer_can_not_be_changed) {
    int a { 1 };
    int *ptr{ &a };

    pass_by_pointer(ptr);

    ASSERT_EQ(2, a);
    ASSERT_EQ(&a, ptr);
}


void pass_by_pointer2(int **a) {
    **a = 2;
    *a = &global;
}
TEST(Parameters, pass_by_pointer2_to_changes_pointer) {
    int a { 1 };
    int *ptr{ &a };

    pass_by_pointer2(&ptr);

    ASSERT_EQ(2, a);
    ASSERT_EQ(&global, ptr);
}


void pass_pointer_by_reference(int *&a) {
    *a = 2;
    a = &global;
}
TEST(Parameters, pass_pointer_by_reference_to_changes_pointer) {
    int a { 1 };
    int *ptr{ &a };

    pass_pointer_by_reference(ptr);

    ASSERT_EQ(2, a);
    ASSERT_EQ(&global, ptr);
}


