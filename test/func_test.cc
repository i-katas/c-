#include "gtest/gtest.h"


bool function(void) {
}

TEST(Function, returns_zero_if_statement_is_missing) {
  ASSERT_EQ(0, function());
}
