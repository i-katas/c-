#include "gtest/gtest.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
bool function(void) {
}
#pragma GCC diagnostic pop

TEST(Function, returns_zero_if_statement_is_missing) {
  ASSERT_EQ(0, function());
}


//make parameters immutable through pass by value
int triple(int n) {
  n *= 3;
  return n;
}

TEST(Function, pass_by_value) {
  int n = 2;

  ASSERT_EQ(6, triple(n));
  ASSERT_EQ(2, n);
}


//make parameters mutable through pass by reference
int tripled(int& n) {
  n *= 3;
  return n;
}

TEST(Function, pass_by_reference) {
  int n = 2;

  ASSERT_EQ(6, tripled(n));
  ASSERT_EQ(6, n);
}
