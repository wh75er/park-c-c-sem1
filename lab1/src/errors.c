#include "errors.h"

void
error_handler(const int err, const int arr_size, struct class** arr, const int path_size, struct class** path) {
  if (err > 0) {
    printf("Error occured: %s!\n", strerror(err));
  } else {
    printf("Error occured!\n");
  }

  arrfree(arr_size, arr);
  arrfree(path_size, path);
}
