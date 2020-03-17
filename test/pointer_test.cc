#include "gtest/gtest.h"


TEST(Pointer, get_value_from_pointer) {
  auto s = "abc";

  const char** buff{&s};

  ASSERT_EQ("abc", *buff);
}


int run(double);

TEST(Function, type) {
  int(*fun)(double) = run;

  ASSERT_EQ(10, fun(5));
}

