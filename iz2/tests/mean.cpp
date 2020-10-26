#include <gtest/gtest.h>
#include <iostream>

extern "C" {
  #include "errors.h"
  #include "mean.h"
  #include "pos.h"
  #include "pos_array.h"
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

  int err = find_mean(&arr, 1, &mean);

  ASSERT_NE(err, SUCCESS);
}

TEST(MeanTestSuite, InvalidParamSize) {
  struct pos* arr = nullptr;
  int err = create_array(1, &arr);
  ASSERT_EQ(err, SUCCESS);

  struct pos mean = {0, 0, 0};

  err = find_mean(&arr, 0, &mean);
  ASSERT_NE(err, SUCCESS);

  arrfree(&arr);
}

TEST(MeanTestSuite, InvalidParamMean) {
  struct pos* arr = nullptr;
  int err = create_array(1, &arr);
  ASSERT_EQ(err, SUCCESS);

  struct pos* mean = NULL;

  err = find_mean(&arr, 1, mean);
  ASSERT_NE(err, SUCCESS);

  arrfree(&arr);
}

TEST(MeanTestSuite, AllOnesShouldReturnOnesVolume10) {
  size_t size = 10;
  struct pos* positions = nullptr;
  int err = create_array(size, &positions);
  ASSERT_EQ(err, SUCCESS);

  for(size_t i = 0; i < size; i++) {
    positions[i].x = 1;
    positions[i].y = 1;
    positions[i].z = 1;
  }

  struct pos mean_expected = {1, 1, 1};
  struct pos mean = {0, 0, 0};

  err = find_mean(&positions, size, &mean);
  ASSERT_EQ(err, SUCCESS);
  ASSERT_EQ(cmp(&mean, &mean_expected), true);

  arrfree(&positions);
}

TEST(MeanTestSuite, ArithmeticProgressionMeanVolume100) {
  size_t size = 100;
  struct pos* positions = nullptr;
  int err = create_array(size, &positions);
  ASSERT_EQ(err, SUCCESS);

  for(size_t i = 0; i < size; i++) {
    positions[i].x = i+1;
    positions[i].y = i+1;
    positions[i].z = i+1;
  }

  double exptd_value = (1 + 100) / (double)2;
  struct pos mean_expected = {exptd_value, exptd_value, exptd_value};
  struct pos mean = {0, 0, 0};

  err = find_mean(&positions, size, &mean);
  ASSERT_EQ(err, SUCCESS);
  ASSERT_EQ(cmp(&mean, &mean_expected), true);

  arrfree(&positions);
}

TEST(MeanTestSuite, ArithmeticProgressionMeanVolume33000000) {
  size_t size = 33000000;
  struct pos* positions = nullptr;
  int err = create_array(size, &positions);
  ASSERT_EQ(err, SUCCESS);

  for(size_t i = 0; i < size; i++) {
    positions[i].x = i+1;
    positions[i].y = i+1;
    positions[i].z = i+1;
  }

  double exptd_value = (1 + 33000000) / (double)2;
  struct pos mean_expected = {exptd_value, exptd_value, exptd_value};
  struct pos mean = {0, 0, 0};

  err = find_mean(&positions, size, &mean);
  ASSERT_EQ(err, SUCCESS);
  ASSERT_EQ(cmp(&mean, &mean_expected), true);

  arrfree(&positions);
}
