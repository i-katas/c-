#include "gtest/gtest.h"

int value{3};

TEST(Namespace, access_global_namespace) {
  int value{2};

  ASSERT_EQ(2, value);
  ASSERT_EQ(3, ::value);
}



namespace x {
  int value{2};
  int code{200};
}

namespace y {
  int value{3};
}

TEST(Namespace, avoid_identifier_conflict) {
  ASSERT_EQ(2, x::value);
  ASSERT_EQ(3, y::value);
}


TEST(Namespace, using_namespace) {
  using namespace x;

  ASSERT_EQ(x::code, code);
  ASSERT_EQ(3, ::value);
  //ASSERT_EQ(3, value); //ambigous 
}

TEST(Namespace, alias_namespace) {
  namespace c = x;

  ASSERT_EQ(x::code, c::code);
}


namespace foo {
  const int a = 1;
}
namespace foo {
  const int b = 2;
}

TEST(Namespace, merge_namespace_definitions) {
  ASSERT_EQ(1, foo::a);
  ASSERT_EQ(2, foo::b);
}


