#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <error.h>

#include "errors.h"
#include "pos.h"

#define BUFFER_SIZE 8

int   read_data_from_file(const char * const filename, size_t* size, struct pos** const arr);
int   read_data_from_stream(FILE * const fd, size_t* size, struct pos** const arr);
int   write_data_to_file(const char * const filename, const struct pos * const el);
int   write_data_to_stream(FILE * const fd, const struct pos * const el);

#endif
