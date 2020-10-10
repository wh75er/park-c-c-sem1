#ifndef __PATHER_C__
#define __PATHER_C__

#include <stdio.h>

#include "class.h"

void  sort(const int size, struct class* const arr, const int year, const int group_id, int* group_size);
int   find_path(const int year, const int group_id, const int arr_size, struct class* const arr, int* path_size, struct class** path);

#endif
