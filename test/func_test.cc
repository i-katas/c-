#include "gtest/gtest.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
bool function(void) {
}
#pragma GCC diagnostic pop

TEST(Function, returns_zero_if_statement_is_missing) {
  ASSERT_EQ(0, function());
}


int return2() {
  return 1;
  return 2; //unreachable
}

TEST(Function, return_immediately_if_contains_multiple_return_statements) {
  ASSERT_EQ(1, return2());
}



//remove the below function declaration will resulting the compiler to fail
int sum(int, int);

TEST(Function, create_forward_declarations_to_avoid_compile_error_when_the_called_function_define_after_itself) {
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


static int option(int a = -1) {
  return a;
}
TEST(Function, optional_parameter_with_default_value) {
  ASSERT_EQ(1, option(1));
  ASSERT_EQ(-1, option());
}


static int repeat(int a = 1);
static int repeat(int a/* = 1*/) {
  return a;
}
TEST(Function, default_parameter_can_not_duplicated_between_declaration_and_definition) {
  ASSERT_EQ(2, repeat(2));
  ASSERT_EQ(1, repeat());
}


struct Place {
  int code = 0;
};
static Place global_place{};
static Place location(Place place = global_place) {
  return place;
}

TEST(Function, copy_value_for_default_parameter_of_every_callsite) {
  Place first{ location() };
  Place second{ location() };

  first.code = 1;

  ASSERT_EQ(0, second.code);
  ASSERT_EQ(1, first.code);
  ASSERT_NE(&first, &second);
  ASSERT_NE(&global_place, &first);
  ASSERT_NE(&global_place, &second);
}


