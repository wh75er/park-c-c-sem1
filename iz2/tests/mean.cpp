#include <fstream>
#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

extern "C" {
  #include "mean.h"
  #include "pos.h"
}

TEST(MeanTestSuite, Testing) {
  ASSERT_EQ(0, 0);

  EXPECT_EQ(2, 2);
}
