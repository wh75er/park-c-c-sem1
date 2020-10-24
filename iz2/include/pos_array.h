#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>

#include "pos.h"

int   create_array(const size_t size, struct pos** arr);
int   arralloc(const size_t size, struct pos** arr);
void  arrfree(struct pos** arr);

#endif
