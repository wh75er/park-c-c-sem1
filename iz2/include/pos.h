#ifndef __POS_H__
#define __POS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "errors.h"

struct pos {
  float x;
  float y;
  float z;
};

int   copy(const struct pos * const src, struct pos * const dst, const size_t size);
void  init_fields(struct pos* el);
void  print(FILE* stream, const struct pos * const arr);

#endif
