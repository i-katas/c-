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


TEST(Variable, name_shadowing) {
  int value{2};

  {
    ASSERT_EQ(2, value);
    int value{3};

    ASSERT_EQ(3, value++);
  }

  ASSERT_EQ(2, value);
}


static int bValue();
static const int i{bValue()};
static constexpr int b{2};

static int bValue() {
  return b;
}

TEST(Variable, static_initialization_first) {
  ASSERT_EQ(2, i);
  ASSERT_EQ(2, b);
}


int tick() {
  static int tick{1};
  return tick++;
}
TEST(Variable, static_local_variables_change_duration) {
  ASSERT_EQ(1, tick());
  ASSERT_EQ(2, tick());
}


