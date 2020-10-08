#include "class.h"

/*
 * Выделяет память под массив структур и инициализирует
 * поля с указателями NULL значением. В случае возникновения
 * ошибки возвращает errno, в случае успеха 0;
 */
int
arralloc(const int size, struct class** arr) {
  *arr = (struct class*)malloc(size * sizeof(struct class));
  if (!(*arr)) {
    return errno;
  }

  init_fields(size, *arr);

  return 0;
}

/*
 * Инициализирует поля указателей структур в массиве 
 * NULL значением
 */
void
init_fields(const int size, struct class* arr) {
  for (int i = 0; i < size; i++) {
    arr[i].subject = NULL;
    arr[i].professor = NULL;
  }
}

/*
 * Высвобождает память из все полей с указателями и
 * затирает значения указателей значением NULL
 */
void
free_fields(const int size, struct class* arr) {
  for (int i = 0; i < size; i++) {
    free(arr[i].subject);
    free(arr[i].professor);
    arr[i].subject = NULL;
    arr[i].professor = NULL;
  }
}

/*
 * Высвобождает память массива.
 */
void
arrfree(struct class* arr) {
  free(arr);
}
