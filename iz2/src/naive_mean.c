#include "mean.h"

int
find_mean(struct pos ** arr, const size_t size, struct pos * const mean) {
  if(!arr || !(*arr) || !size || !mean) {
    return NAIVE_MEAN_PARAMS_ERR; 
  }

  mean->x = 0;
  mean->y = 0;
  mean->z = 0;

  for(size_t i = 0; i < size; i++) {
    mean->x += (*arr)[i].x;
    mean->y += (*arr)[i].y;
    mean->z += (*arr)[i].z;
  }

  mean->x /= size;
  mean->y /= size;
  mean->z /= size;

  return SUCCESS;
}
