#ifndef __PATHER_C__
#define __PATHER_C__

#include <stdio.h>

#include "class.h"

void  sort(const int size, struct lesson* const arr, const int year, const int group_id, int* group_size);
int   find_path(const int year, const int group_id, const int arr_size, struct lesson* const arr, int* path_size, struct lesson** path);

#endif
