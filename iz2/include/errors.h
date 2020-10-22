#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <stdio.h>
#include <error.h>

#include "pos.h"

enum custom_errors {
  TYPE_ERR = -2,
  COPY_ERR = -3
};

void  error_handler(const int err, struct pos** arr);

#endif
