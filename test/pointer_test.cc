#include "gtest/gtest.h"


TEST(Pointer, dereferencing) {
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


TEST(Pointer, alias_function_pointer_type_with_typedef) {
  typedef int(*Eval)(double);

  Eval eval { run };

  ASSERT_EQ(10, eval(5));
}


TEST(Pointer, alias_function_pointer_type_with_using_statement) {
  using Eval = int(*)(double);

  Eval eval { run };

  ASSERT_EQ(10, eval(5));
}


TEST(Pointer, using_std_function_to_define_function_pointer) {
  std::function<int(double)> eval{ run };

  ASSERT_EQ(10, eval(5));
}


TEST(Pointer, use_arrow_operator_to_access_member_function) {
  std::string s{"value"};

  std::string *ptr{&s};

  ASSERT_EQ(5u, ptr->length());
  //equality
  ASSERT_EQ(5u, (*ptr).length());
}


TEST(Pointer, change_value_by_pointer) {
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


TEST(Pointer, using_scaling_to_iterate_an_array_because_array_will_use_consequence_memory_address_to_save_its_own_data) {
  int array[]{9, 8, 7};

  int *first { array };
  int *second { first + 1};


  ASSERT_EQ(9, *first);
  ASSERT_EQ(8, *second);
}


TEST(Pointer, pointer_to_const_value) {
  const int value{ 5 };

  const int *ptr{ &value };

  ASSERT_EQ(5, *ptr);
}


TEST(Pointer, const_value_pointer) {
  int value{ 5 };

  const int *ptr{ &value };

  value = 6;
  ASSERT_EQ(6, *ptr);
}


TEST(Pointer, const_pointer) {
  int value{ 5 };

  int *const ptr{ &value };

  //ptr = &value; //compiler error
  ASSERT_EQ(5, *ptr);
}


TEST(Pointer, void_pointer_can_point_to_any_type_pointer_but_can_not_dereference_directly) {
  std::string s{ "string" };

  void *ptr = &s;
  //ASSERT_EQ("string", *ptr); //compiler error

  std::string *s_ptr { static_cast<std::string*>(ptr) };

  ASSERT_EQ("string", *s_ptr);
}


TEST(Pointer, point_to_a_pointer) {
  std::string s{ "string" };
  std::string *ptr = &s;

  std::string **ptrptr = &ptr;

  ASSERT_EQ("string", **ptrptr);
}


TEST(Pointer, dynamic_2_dimensional_array_creation) {
  int **array = { new int*[2] };
  *(array) = new int[3];

  *(*array + 2) = 1;

  ASSERT_EQ(1, array[0][2]);

  delete [] array[0];
  delete [] array[1];
  delete []array;
}


