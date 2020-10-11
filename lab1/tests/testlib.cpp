#include <gtest/gtest.h>
#include <fstream>
#include <stdio.h>

extern "C" {
  #include "input.h"
}

#define TEST_DATA_FILENAME "test.data"

TEST(TestInputStream, WeekdayInput) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "2\n";
  file.close();

  FILE* stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(stream);
  
  int weekday = 0;
  int err = get_weekday_from_stream(stream, &weekday);

  fclose(stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(weekday, 2);
}

TEST(TestInputStream, WeekdayInputValidation) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "-1\n";
  file << "2\n";
  file.close();

  FILE* stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(stream);
  
  int weekday = 0;
  int err = get_weekday_from_stream(stream, &weekday);

  fclose(stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(weekday, 2);
}
