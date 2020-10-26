#include <gtest/gtest.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

extern "C" {
  #include "mean.h"
  #include "pos.h"
}

TEST(TestParallelImpl, TestCase) {
  ASSERT_EQ(0, 0);

  EXPECT_EQ(2, 2);
}

