#include <gtest/gtest.h>
#include <fstream>
#include <stdio.h>

extern "C" {
  #include "input.h"
}

#define TEST_DATA_FILENAME "test.data"
#define TEST_OUTPUT_FILENAME "test.out"

TEST(TestInputStream, WeekdayInput) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "2\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int weekday = 0;
  int err = get_weekday_from_stream(in_stream, out_stream, &weekday);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(weekday, 2);
}

TEST(TestInputStream, WeekdayInputValidation) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "-1\n";
  file << "2\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int weekday = 0;
  int err = get_weekday_from_stream(in_stream, out_stream, &weekday);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(weekday, 2);
}
