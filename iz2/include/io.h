#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <error.h>

#include "errors.h"

#include "pos.h"

int   read_data_from_file(const char * const filename, FILE* fd, size_t* size, struct pos** const arr);
int   write_data_to_file(const char * const filename, FILE* fd, const struct pos * const arr);

#endif
