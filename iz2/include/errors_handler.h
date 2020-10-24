#ifndef __ERRORS_HANDLER_H__
#define __ERRORS_HANDLER_H__

#include <errno.h>
#include <stdio.h>

#include "errors.h"
#include "pos.h"
#include "pos_array.h"

void  handle_errors(const int err, struct pos** arr);

#endif
