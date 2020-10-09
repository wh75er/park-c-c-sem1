#ifndef __PATHER_C__
#define __PATHER_C__

#include <stdio.h>

#include "class.h"

void  sort(const int, struct class * const, const int, int *);
int   find_path(const int, const int, struct class * const, int *, struct class **);

#endif
