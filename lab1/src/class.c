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
  if (!arr)
    return;

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
arrfree(const int size, struct class** arr) {
  if (!arr)
    return;

  free_fields(size, *arr);
  free(*arr);
  *arr = NULL;
}

/*
 * Копирует элемент a в b
 */
int
copy(struct class * const src, struct class * dst) {
  (*dst).weekday = (*src).weekday;
  (*dst).time = (*src).time;
  (*dst).lecture = (*src).lecture;
  (*dst).duration = (*src).duration;

  char* src_str = (*src).subject;
  char* dst_str = (*dst).subject;
  if(!dst_str) {
    dst_str = (char*)malloc(strlen(src_str)+1);
    if (!dst_str) {
      return errno;
    }
  }
  if (src_str && dst_str) {
    memcpy(dst_str, src_str, strlen(src_str)+1);
  } else {
    return -1;
  }
  (*dst).subject = dst_str;

  src_str = (*src).professor;
  dst_str = (*dst).professor;
  if(!dst_str) {
    dst_str = (char*)malloc(strlen(src_str)+1);
    if (!dst_str) {
      return errno;
    }
  }
  if (src_str && dst_str) {
    memcpy(dst_str, src_str, strlen(src_str)+1);
  } else {
    return -1;
  }
  (*dst).professor = dst_str;
  
  (*dst).year = (*src).year;
  (*dst).group = (*src).group;

  return 0;
}

/*
 * Меняет местами два элемента массива
 */
void
swap(struct class * const a, struct class * const b) {
  struct class temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
