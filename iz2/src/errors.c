#include "errors.h"

/*
 *  Outputs errors and frees memory
 */
void
error_handler(const int err, struct lesson** arr) {
  if (err > 0) {
    fprintf(stderr, "Error occured: %s!\n", strerror(err));
  } else if (err == TYPE_ERROR) {
    fprintf(stderr, "Incorrect type error!\n");
  }

  arrfree(arr);
}
