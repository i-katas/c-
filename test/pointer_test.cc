#include "gtest/gtest.h"


TEST(Pointer, derefernceing) {
  auto s = "abc";
  const char **buff{&s};

  auto dereferenced = *buff;

  ASSERT_EQ("abc", dereferenced);
}


int run(double);

TEST(Pointer, function_pointer_type) {
  int(*fun)(double) = run;

  ASSERT_EQ(10, fun(5));
}


TEST(Pointer, call_member_function) {
  std::string s{"value"};

  std::string *ptr{&s};

  ASSERT_EQ(5u, ptr->length());
}


TEST(Pointer, reassign_value_to_pointer) {
  int value{1};
  int *ptr{&value};

  *ptr = 2;

  ASSERT_EQ(2, value);
}


TEST(Pointer, null_pointer) {
  int *ptr{0};

  ASSERT_FALSE(ptr);
  ASSERT_EQ(nullptr, ptr);
}


TEST(Pointer, using_scaling_to_iterate_an_array) {
  int array[]{9, 8, 7};

  int *first { array };
  int *second { first + 1};


  ASSERT_EQ(9, *first);
  ASSERT_EQ(8, *second);
}


