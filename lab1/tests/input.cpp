#include <gtest/gtest.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

extern "C" {
  #include "input.h"
  #include "class.h"
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
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
  ASSERT_NE(in_stream, nullptr);

  FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");
  ASSERT_NE(out_stream, nullptr);
  
  int group = 0;
  int err = get_group_from_stream(in_stream, out_stream, &group);

  fclose(in_stream);
  fclose(out_stream);
  
  EXPECT_EQ(err, 0);
  EXPECT_EQ(group, 100);
}

TEST(TestInputStream, ArrayInput) {
    std::ofstream file(TEST_DATA_FILENAME);
    file << "2\n";
    file << "2\n";
    file << "5\n";
    file << "0\n1230\n1\n90\nMath\nBelousov\n2\n2\n";
    file << "0\n600\n1\n90\nProga\nBekasov\n3\n2\n";
    file << "5\n560\n0\n60\nMathstat\nVlasov\n1\n1\n";
    file << "3\n510\n0\n90\nWeb\nBekasov\n2\n2\n";
    file << "0\n680\n0\n85\nAI\nVolkova\n2\n2\n";
    file.close();

    file = std::ofstream(TEST_OUTPUT_FILENAME);
    file.close();

    FILE* in_stream = fopen(TEST_DATA_FILENAME, "r");
    FILE* out_stream = fopen(TEST_OUTPUT_FILENAME, "w");

    ASSERT_NE(in_stream, nullptr);
    ASSERT_NE(out_stream, nullptr);

    int init_size = 5;

    struct lesson* expected_arr = (struct lesson*)malloc(init_size * sizeof(struct lesson));

    expected_arr[0] = {0, 1230, 1, 90, "Math", "Belousov", 2, 2};
    expected_arr[1] = {0, 600, 1, 90, "Proga", "Bekasov", 3, 2};
    expected_arr[2] = {5, 560, 0, 60, "Mathstat", "Vlasov", 1, 1};
    expected_arr[3] = {3, 510, 0, 90, "Web", "Bekasov", 2, 2};
    expected_arr[4] = {0, 680, 0, 85, "AI", "Volkova", 2, 2};
  
    struct lesson* arr = NULL;
    int size = 0;
    int year = 0;
    int group_id = 0;
    int err = get_user_input(in_stream, out_stream, &year, &group_id, &size, &arr);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(size, 5);
    EXPECT_EQ(year, 2);
    EXPECT_EQ(group_id, 2);
    
    for (int i = 0; i < size; i++) {
      EXPECT_EQ(expected_arr[i].weekday, arr[i].weekday);
      EXPECT_EQ(expected_arr[i].time, arr[i].time);
      EXPECT_EQ(expected_arr[i].lecture, arr[i].lecture);
      EXPECT_EQ(expected_arr[i].duration, arr[i].duration);
      EXPECT_EQ(strcmp(expected_arr[i].subject, arr[i].subject), 0);
      EXPECT_EQ(strcmp(expected_arr[i].professor, arr[i].professor), 0);
      EXPECT_EQ(expected_arr[i].year, arr[i].year);
      EXPECT_EQ(expected_arr[i].group, arr[i].group);
    }

    fclose(in_stream);
    fclose(out_stream);

    free(expected_arr);
    arrfree(size, &arr);
}
