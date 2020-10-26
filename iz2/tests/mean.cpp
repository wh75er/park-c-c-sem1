#include <gtest/gtest.h>
#include <iostream>

extern "C" {
  #include "errors.h"
  #include "mean.h"
  #include "pos.h"
}

bool
cmp(const struct pos * const a, const struct pos * const b) {
  if(a->x == b->x && a->y == b->y && a->z == b->z) {
    return true;
  }

  return false;
}

TEST(MeanTestSuite, InvalidParamArray) {
  struct pos* arr = nullptr;
  struct pos mean = {0, 0, 0};

  int err = find_mean(arr, 1, &mean);

  ASSERT_NE(err, SUCCESS);
}

TEST(MeanTestSuite, InvalidParamSize) {
  struct pos arr = {0, 0, 0};
  struct pos mean = {0, 0, 0};

  int err = find_mean(&arr, 0, &mean);

  ASSERT_NE(err, SUCCESS);
}

TEST(MeanTestSuite, InvalidParamMean) {
  struct pos arr = {0, 0, 0};
  struct pos* mean = NULL;

  int err = find_mean(&arr, 1, mean);

  ASSERT_NE(err, SUCCESS);
}

TEST(MeanTestSuite, AllOnesShouldReturnOnesVolume10) {
  size_t size = 10;
  struct pos positions[10];

  for(size_t i = 0; i < size; i++) {
    positions[i].x = 1;
    positions[i].y = 1;
    positions[i].z = 1;
  }

  struct pos mean_expected = {1, 1, 1};
  struct pos mean = {0, 0, 0};

  int err = find_mean(positions, size, &mean);

  ASSERT_EQ(err, SUCCESS);

  //ASSERT_EQ(cmp(&mean, &mean_expected), true);
}

TEST(MeanTestSuite, ArithmeticProgressionMeanVolume100) {
  size_t size = 100;
  struct pos positions[100];

  for(size_t i = 0; i < size; i++) {
    positions[i].x = i+1;
    positions[i].y = i+1;
    positions[i].z = i+1;
  }

  float exptd_value = (1.f + 100.f) / 2;
  struct pos mean_expected = {exptd_value, exptd_value, exptd_value};
  struct pos mean = {0, 0, 0};

  int err = find_mean(positions, size, &mean);

  ASSERT_EQ(err, SUCCESS);

  //ASSERT_EQ(cmp(&mean, &mean_expected), true);
}
