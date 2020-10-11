#include <gtest/gtest.h>
#include <fstream>
#include <stdio.h>

extern "C" {
  #include "input.h"
}

#define TEST_DATA_FILENAME "test.data"
#define TEST_OUTPUT_FILENAME "test.out"

/*
 
_ _ _ ____ ____ _  _ ___  ____ _   _
| | | |___ |___ |_/  |  \ |__|  \_/
|_|_| |___ |___ | \_ |__/ |  |   |

*/

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

TEST(TestInputStream, WeekdayInputValidationLeft) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "-1\n";
  file << "0\n";
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
  EXPECT_EQ(weekday, 0);
}

TEST(TestInputStream, WeekdayInputValidationRight) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "7\n";
  file << "6\n";
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
  EXPECT_EQ(weekday, 6);
}

/*

___ _ _  _ ____ 
 |  | |\/| |___ 
 |  | |  | |___ 
                
*/

TEST(TestInputStream, TimeInputValidation) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "-1\n";
  file << "600\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int time = 0;
  int err = get_time_from_stream(in_stream, out_stream, &time);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(time, 600);
}

TEST(TestInputStream, TimeInputValidationLeft) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "509\n";
  file << "510\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int time = 0;
  int err = get_time_from_stream(in_stream, out_stream, &time);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(time, 510);
}

TEST(TestInputStream, TimeInputValidationRight) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "1231\n";
  file << "1230\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int time = 0;
  int err = get_time_from_stream(in_stream, out_stream, &time);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(time, 1230);
}

/*

_    ____ ____ ___ _  _ ____ ____ 
|    |___ |     |  |  | |__/ |___ 
|___ |___ |___  |  |__| |  \ |___ 
                                  
*/

TEST(TestInputStream, LectureInputValidationLeft) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "-1\n";
  file << "0\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  bool lecture = 0;
  int err = get_lecture_from_stream(in_stream, out_stream, &lecture);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(lecture, 0);
}

TEST(TestInputStream, LectureInputValidationRight) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "2\n";
  file << "1\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  bool lecture = 0;
  int err = get_lecture_from_stream(in_stream, out_stream, &lecture);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(lecture, 1);
}

/*

___  _  _ ____ ____ ___ _ ____ _  _ 
|  \ |  | |__/ |__|  |  | |  | |\ | 
|__/ |__| |  \ |  |  |  | |__| | \| 
                                    
*/

TEST(TestInputStream, DurationInputValidationLeft) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "4\n";
  file << "5\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int duration = 0;
  int err = get_duration_from_stream(in_stream, out_stream, &duration);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(duration, 5);
}

TEST(TestInputStream, DurationInputValidationRight) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "91\n";
  file << "90\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int duration = 0;
  int err = get_duration_from_stream(in_stream, out_stream, &duration);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(duration, 90);
}

/*

_   _ ____ ____ ____ 
 \_/  |___ |__| |__/ 
  |   |___ |  | |  \\
                     
*/

TEST(TestInputStream, YearInputValidationLeft) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "0\n";
  file << "1\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int year = 0;
  int err = get_year_from_stream(in_stream, out_stream, &year);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(year, 1);
}

TEST(TestInputStream, YearInputValidationRight) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "11\n";
  file << "10\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int year = 0;
  int err = get_year_from_stream(in_stream, out_stream, &year);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(year, 10);
}

/*

____ ____ ____ _  _ ___  
| __ |__/ |  | |  | |__] 
|__] |  \ |__| |__| |    
                         
*/

TEST(TestInputStream, GroupInputValidationLeft) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "0\n";
  file << "1\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int group = 0;
  int err = get_group_from_stream(in_stream, out_stream, &group);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(group, 1);
}

TEST(TestInputStream, GroupInputValidationRight) {
  std::ofstream file(TEST_DATA_FILENAME);
  file << "101\n";
  file << "100\n";
  file.close();

  file = std::ofstream(TEST_OUTPUT_FILENAME);
  file.close();

  FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
  ASSERT_TRUE(in_stream);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_TRUE(out_stream);
  
  int group = 0;
  int err = get_group_from_stream(in_stream, out_stream, &group);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(group, 100);
}
