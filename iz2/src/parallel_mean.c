#include <errno>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#include "mean.h"

int get_sum(const struct pos * const arr, const size_t left_border, const size_t right_border, struct pos * const sum) {
  if(left_border > right_border) {
    return SUM_BORDERS_ERR;
  }

  if(!arr || !sum) {
    return SUM_PARAMS_ERR;
  }

  sum->x = 0;
  sum->y = 0;
  sum->z = 0;

  for(size_t i = left_border; i < right_border; i++) {
    sum->x += arr[i].x;
    sum->y += arr[i].y;
    sum->z += arr[i].z;
  }

  return SUCCESS;
}

int
find_mean(const struct pos * const arr, const size_t size, struct pos * const mean) {
  int fd[2];

  if(pipe(fd)) {
    return PARALLEL_PIPE_ERR;
  }
}
