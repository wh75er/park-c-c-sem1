#include "pather.h"

/*
 * Сортирует массив и считает количество предметов для
 * указанной группы, указанного курса
 */
void
sort(const int size, struct class* const arr, const int year, const int group_id, int* group_size) {
  if (arr[0].year == year && arr[0].group == group_id)
    (*group_size)++;

  for (int i = 1; i < size; i++) {
    if (arr[i].year == year && arr[i].group == group_id)
      (*group_size)++;

    struct class temp = arr[i];
    int j = i - 1;

    while (j >= 0) {
      if (( temp.weekday < arr[j].weekday && temp.time < arr[j].time) || 
          ( temp.weekday == arr[j].weekday && temp.time < arr[j].time)) {
        arr[j+1] = arr[j];
        j--;
      } else 
        break;
    }
    
    arr[j+1] = temp;
  }
}

/*
 * Находит последовательный путь обхода всех предметов для указанной группы
 * указаннного курса
 */
int
find_path(const int year, const int group_id, const int arr_size, struct class* const arr, int* path_size, struct class** path) {
  *path_size = 0;
  sort(arr_size, arr, year, group_id, path_size);

  if (!(*path_size)) {
    return 0;
  }
  
  int err = 0;
  if ((err = arralloc(*path_size, path))) {
    fprintf(stderr, "Возникла ошибка при выделении памяти под массив!\n");
    return err;
  }
  
  int path_index = 0;
  for (int i = 0; i < arr_size; i++) {
    if (arr[i].year == year && arr[i].group == group_id) {
      if (path_index < *path_size) {
        copy(&arr[i], &(*path)[path_index]);
        path_index++;
      }
    }
  }

  return 0;
}
