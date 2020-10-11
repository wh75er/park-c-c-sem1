#include "main.h"

/*
 * Программа отображает последовательное посещение пар
 * студентов определенной группы с помощью использования
 * специальной структуры
 */
int
main(int argc, char *argv[]) {
  struct lesson* arr = NULL;
  int size = 0;
  int year = 0;
  int group_id = 0;
  int err = 0;
  if ((err = get_user_input(stdin, stdout, &year, &group_id, &size, &arr))) {
    error_handler(err, size, &arr, 0, NULL);
    exit(EXIT_FAILURE);
  }

  int path_size = 0;
  struct lesson* path = NULL;
  if ((err = find_path(year, group_id, size, arr, &path_size, &path))) {
    error_handler(err, size, &arr, path_size, &path);
    exit(EXIT_FAILURE);
  }

  arrfree(size, &arr);
  arrfree(path_size, &path);

  return 0;
}
