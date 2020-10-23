#ifndef __MEAN_H__
#define __MEAN_H__

#include <sys/sysinfo.h>

#include "pos.h"

int   find_mean(const struct pos * const arr, const size_t size, struct pos * const mean);

#endif
