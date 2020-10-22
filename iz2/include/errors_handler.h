#ifndef __ERRORS_HANDLER_H__
#define __ERRORS_HANDLER_H__

#include <stdio.h>
#include <errno.h>

#include "pos.h"
#include "errors.h"

void  error_handler(const int err, struct pos** arr);

#endif
