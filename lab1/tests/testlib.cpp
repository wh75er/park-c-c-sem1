#include <gtest/gtest.h>
#include <iostream>

#include "input.h"

TEST(TestInputStream, WeekdayInput) {
  std::stringstream stream;
  stream << "2\n";
  
  int weekday = 0;
  int err = get_weekday_from_stream(stream, &weekday);
  
  EXPECT_EQ(weekday, 2);
}
