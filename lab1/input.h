#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stderr.h>

#include "class.h"

#define BUFFER_SIZE 10

int   get_user_input(FILE *, int *, struct Class *);
int   get_value_from_stream(FILE *, int *);
int   get_string_from_stream(FILE *, char *);
int   get_array_from_stream(FILE *, int *, struct Class *);
void  fflush_stream(FILE *);

#endif
