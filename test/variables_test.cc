#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(Variable, definition) {
  int a, b = 1;

  ASSERT_NE(0, a) << "random value for the unassigned variable";
  ASSERT_EQ(1, b);
}

TEST(Variable, copy_initialization) {
  int a = 1;

  ASSERT_EQ(1, a);
}

TEST(Variable, direct_initialization_improve_performance_in_most_cases) {
  int a(1), b = (2);

  ASSERT_EQ(1, a);
  ASSERT_EQ(2, b);
}

TEST(Variable, uniform_initialization) {
  int a{1}; //direct initialization
  int b = {2}; //copy initialization

  ASSERT_EQ(1, a);
  ASSERT_EQ(2, b);
}

TEST(Variable, zero_initialization) {
  int a{}; 
  ASSERT_EQ(0, a);

  bool b{};
  ASSERT_EQ(false, b);
  
  string str{};
  ASSERT_EQ("", str);
}

TEST(Variable, narrowing_conversion) {
  int a(4.5); 
  ASSERT_EQ(4, a);

  //brace initialization disallowing "narrowing" conversions. e.g: 
  //int b{3.9}; //compiler error
  int b{(int)3.9}; 
  ASSERT_EQ(3, b);
}
