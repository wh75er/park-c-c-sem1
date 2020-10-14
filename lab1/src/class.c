#include "class.h"

/*
 * Выделяет память под массив структур и инициализирует
 * поля с указателями NULL значением. В случае возникновения
 * ошибки возвращает errno, в случае успеха 0;
 */
int
arralloc(const int size, struct lesson** arr) {
  *arr = (struct lesson*)malloc(size * sizeof(struct lesson));

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
init_fields(const int size, struct lesson* arr) {
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
free_fields(const int size, struct lesson* arr) {
  if (!arr) {
    return;
  }

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
arrfree(const int size, struct lesson** arr) {
  if (!arr) {
    return;
  }

  free_fields(size, *arr);
  free(*arr);
  *arr = NULL;
}

/*
 * Копирует элемент a в b
 */
int
copy(struct lesson * const src, struct lesson * dst) {
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
    return -2;
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
    return -2;
  }
  (*dst).professor = dst_str;
  
  (*dst).year = (*src).year;
  (*dst).group = (*src).group;

  return 0;
}

/*
 * Выводит данные массива в указанный поток
 */
void arrprint(FILE* stream, const int size, const struct lesson * const arr)
{
  if(size <= 0) {
    fprintf(stream, "Массив пуст!\n");
    return;
  }

  for(int i = 0; i < size; i++) {
    fprintf(stream, "%d Предмет из %d: \n", i+1, size);

    fprintf(stream, "День недели: %d\n", arr[i].weekday);
    fprintf(stream, "Время начала: %d\n", arr[i].time);
    fprintf(stream, "Лекция: %d\n", arr[i].lecture);
    fprintf(stream, "Продолжительность: %d\n", arr[i].duration);
    fprintf(stream, "Название предмета: %s\n", arr[i].subject);
    fprintf(stream, "Имя преподавателя: %s\n", arr[i].professor);
    fprintf(stream, "Курс: %d\n", arr[i].year);
    fprintf(stream, "Номер группы: %d\n", arr[i].group);

    fprintf(stream, "---------n");
  }
}
