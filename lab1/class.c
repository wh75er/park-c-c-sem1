#include "class.h"

/*
 * Выделяет память под массив структур и инициализирует
 * поля с указателями NULL значением. В случае возникновения
 * ошибки возвращает errno, в случае успеха 0;
 */
int
arralloc(int n, struct Class* arr) {
  arr = (struct Class*)malloc(n * sizeof(struct Class));
  if (!arr) {
    return errno;
  }

  init_fields(arr);

  return 0;
}

/*
 * Инициализирует поля указателей структур в массиве 
 * NULL значением
 */
void
init_fields(int n, struct Class* arr) {
  for (int i = 0; i < n; i++) {
    arr[i].subject = NULL;
    arr[i].professor = NULL;
  }
}

/*
 * Высвобождает память из все полей с указателями и
 * затирает значения указателей значением NULL
 */
void
free_fields(int n, struct Class* arr) {
  for (int i = 0; i < n; i++) {
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
arrfree(struct Class* arr) {
  free(arr);
}
