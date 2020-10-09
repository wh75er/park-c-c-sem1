#include "main.h"

/*
 * Программа отображает последовательное посещение пар
 * студентов определенной группы с помощью использования
 * специальной структуры
 */
int
main(int argc, char *argv[]) {
  struct class* arr = NULL;
  int size;
  int err = get_user_input(stdin, &size, &arr);

  int group_id = 2;
  int path_size = 0;
  struct class* path = NULL;
  err = find_path(group_id, size, arr, &path_size, &path);

  arrfree(size, arr);
  arrfree(path_size, path);
}
