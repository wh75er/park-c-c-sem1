#include "errors_handler.h"

/*
 *  Outputs errors and frees memory
 */
void
error_handler(const int err, struct pos** arr) {
  if (err > 0) {
    fprintf(stderr, "Error occured: %s!\n", strerror(err));
  } else if (err == TYPE_ERR) {
    fprintf(stderr, "Incorrect type error!\n");
  } else if (err == COPY_ERR) {
    fprintf(stderr, "Failed to copy data!\n");
  } else if (err == ARGS_ERR) {
    fprintf(stderr, "Arguments error!\n");
  }

  arrfree(arr);
}
