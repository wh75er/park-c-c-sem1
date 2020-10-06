#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stderr.h>

#include "class.h"

#define BUFFER_SIZE 10

int   get_user_input(int *, struct Class *);
int   get_size(int *);
int   get_array(int *, struct Class *);
void  fflush_stdin(void);

#endif
