#include "mean.h"

/*
 *  Naive method for each coord mean calculation
 * Result stored into the struct
*/
int
find_mean(const struct pos * const arr, const size_t size, struct pos * const mean) {
  mean->x = 0;
  mean->y = 0;
  mean->z = 0;

  for(size_t i = 0; i < size; i++) {
    mean->x += arr[i].x;
    mean->y += arr[i].y;
    mean->z += arr[i].z;
  }

  mean->x /= size;
  mean->y /= size;
  mean->z /= size;

  return SUCCESS;
}
