#include "gtest/gtest.h"
#define NAME "bob"


TEST(Macro, identifier_is_substituted) {
  ASSERT_EQ("bob", NAME);
}

#include <string>
using std::string;

string stack();

TEST(Macro, conditional) {
  ASSERT_EQ("fuzz", stack());
}

#define fuzz 
string stack() {
  string stack{""};

  #ifdef fuzz
    stack += "fuzz";
  #else
    stack += "";
  #endif

  #ifdef buzz
    stack += "buzz";
  #else
    stack += "";
  #endif

  return stack;
}


TEST(Macro, use_if_0_to_skip_compilation) {
  #if 0
    undefinedVar = 5;
  #endif
}

