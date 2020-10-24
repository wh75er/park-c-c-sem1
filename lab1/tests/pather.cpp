#include <gtest/gtest.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

extern "C" {
  #include "pather.h"
  #include "input.h"
  #include "class.h"
}

class StructTest : public ::testing::Test {
 protected:
  void SetUp() override {
    arr_ = (struct lesson*)malloc(size_ * sizeof(struct lesson));
    ASSERT_NE(arr_, nullptr);

    arr_[1] = {3, 510, 0, 90, "Web", "Bekasov", 2, 2};
    arr_[0] = {5, 510, 0, 60, "Mathstat", "Vlasov", 1, 1};
    arr_[2] = {0, 1230, 1, 90, "Math", "Belousov", 2, 2};
    arr_[3] = {0, 680, 0, 85, "AI", "Volkova", 2, 2};
    arr_[4] = {0, 600, 1, 90, "Proga", "Bekasov", 3, 2};
  }

  void TearDown() override {
    free(arr_);
  }

  int year_ = 2;
  int group_ = 2;
  int size_ = 5;
  struct lesson* arr_ = nullptr;
};

TEST_F(StructTest, Sort) {
  struct lesson* expected_arr = (struct lesson*)malloc(size_ * sizeof(struct lesson));

  ASSERT_NE(arr_, nullptr);

  expected_arr[0] = {0, 600, 1, 90, "Proga", "Bekasov", 3, 2};
  expected_arr[1] = {0, 680, 0, 85, "AI", "Volkova", 2, 2};
  expected_arr[2] = {0, 1230, 1, 90, "Math", "Belousov", 2, 2};
  expected_arr[3] = {3, 510, 0, 90, "Web", "Bekasov", 2, 2};
  expected_arr[4] = {5, 510, 0, 60, "Mathstat", "Vlasov", 1, 1};
  
  int group_size = 0;
  sort(size_, arr_, year_, group_, &group_size);

  EXPECT_EQ(group_size, 3);
  for (int i = 0; i < size_; i++) {
    EXPECT_EQ(expected_arr[i].weekday, arr_[i].weekday);
    EXPECT_EQ(expected_arr[i].time, arr_[i].time);
    EXPECT_EQ(expected_arr[i].lecture, arr_[i].lecture);
    EXPECT_EQ(expected_arr[i].duration, arr_[i].duration);
    EXPECT_EQ(strcmp(expected_arr[i].subject, arr_[i].subject), 0);
    EXPECT_EQ(strcmp(expected_arr[i].professor, arr_[i].professor), 0);
    EXPECT_EQ(expected_arr[i].year, arr_[i].year);
    EXPECT_EQ(expected_arr[i].group, arr_[i].group);
  }

  free(expected_arr);
}

TEST_F(StructTest, PathExists) {
  int expected_path_size = 3;
  struct lesson* expected_arr = (struct lesson*)malloc(expected_path_size * sizeof(struct lesson));

  ASSERT_NE(arr_, nullptr);

  expected_arr[0] = {0, 680, 0, 85, "AI", "Volkova", 2, 2};
  expected_arr[1] = {0, 1230, 1, 90, "Math", "Belousov", 2, 2};
  expected_arr[2] = {3, 510, 0, 90, "Web", "Bekasov", 2, 2};

  int path_size = 0;
  struct lesson* path = nullptr;
  int err = find_path(year_, group_, size_, arr_, &path_size, &path);

  ASSERT_EQ(err, 0);
  ASSERT_EQ(path_size, expected_path_size);

  for (int i = 0; i < path_size; i++) {
    EXPECT_EQ(expected_arr[i].weekday, path[i].weekday);
    EXPECT_EQ(expected_arr[i].time, path[i].time);
    EXPECT_EQ(expected_arr[i].lecture, path[i].lecture);
    EXPECT_EQ(expected_arr[i].duration, path[i].duration);
    EXPECT_EQ(strcmp(expected_arr[i].subject, path[i].subject), 0);
    EXPECT_EQ(strcmp(expected_arr[i].professor, path[i].professor), 0);
    EXPECT_EQ(expected_arr[i].year, path[i].year);
    EXPECT_EQ(expected_arr[i].group, path[i].group);
  }

  free(expected_arr);
  arrfree(path_size, &path);
}
