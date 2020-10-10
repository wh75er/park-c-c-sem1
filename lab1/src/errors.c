#include "errors.h"

/*
 * Выводит сообщение об ошибке и высвобождает память
 */
void
error_handler(const int err, const int arr_size, struct lesson** arr, const int path_size, struct lesson** path) {
  if (err > 0) {
    fprintf(stderr, "Error occured: %s!\n", strerror(err));
  } else {
    fprintf(stderr, "Error occured!\n");
  }

  arrfree(arr_size, arr);
  arrfree(path_size, path);
}
