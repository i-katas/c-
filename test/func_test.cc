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



int return2() {
  return 1;
  return 2; //unreachable
}

TEST(Function, multiple_return_statements) {
  ASSERT_EQ(1, return2());
}



//remove the below function declaration will resulting the compiler to fail
int sum(int, int);

TEST(Function, forward_declarations) {
  ASSERT_EQ(5, sum(2, 3));
}

int sum(int a, int b) {
  return a + b;
}



//bind function calls at compiler stage if the forward declaration exists
int run(double);

TEST(Function, bind_forward_declaration_at_compile_stage) {
  //call run(double) rather than run(int)
  ASSERT_EQ(10, run(5));
}



int run(double);
int run(double);

TEST(Function, declaration_can_be_duplicated) {
  //call run(double) rather than run(int)
  ASSERT_EQ(10, run(5));
}


static inline int plus(int a, int b) {
  return a + b;
}

TEST(Function, inline_function_code_into_callsite) {
  ASSERT_EQ(3, plus(1, 2));
}


