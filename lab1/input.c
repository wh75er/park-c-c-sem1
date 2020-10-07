#include "input.h"

/*
 * Получение пользовательских данных
 */
int
get_user_input(FILE* stream, int* size, struct Class* arr) {
  int err = 0;
  if ((err = get_value_from_stream(stream, size))) {
    fprintf(stderr, "Возникла ошибка при получении размера массива!\n");
    return err;
  }

  if ((err = get_array_from_stream(stream, size, arr))) {
    fprintf(stderr, "Возникла ошибка при чтении расписания!\n");
    return err;
  }

  return 0;
}

/*
 * Считывание целочисленных значений из потока
 */
int
get_value_from_stream(FILE* stream, int* val) {
  bool is_number = false;
  while (is_number == false) {
    printf("Пожалуйста, введите размер массива: ");

    char buffer[BUFFER_SIZE];
    if (!fgets(buffer, BUFFER_SIZE, stream)) {
      fprintf(stderr, "Возникла ошибка при заполнения буфера из потока!\n");
      return errno;
    }

    int n = sscanf(buffer, " %d", val);

    if (n == 1) {
      is_number = true;
    } else if (!errno)  {
      printf("Введенное вами значение не является числом. Повторите...\n");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения!\n");
      return errno;
    }

    fflush_stream();
    if (errno) {
      fprintf(stderr, "Возникла ошибка при чистке буфера потока!\n");
      return errno;
    }
  }

  return 0;
}

/*
 * Считывание строк из потока
 */
int
get_string_from_stream(FILE* stream, char* str) {
  bool is_number = false;
  while (is_number == false) {
    printf("Пожалуйста, введите размер массива: ");

    char buffer[BUFFER_SIZE];
    if (!fgets(buffer, BUFFER_SIZE, stream)) {
      fprintf(stderr, "Возникла ошибка при заполнения буфера из потока!\n");
      return errno;
    }

    int n = sscanf(buffer, " %ms", str);

    if (n == 1) {
      is_number = true;
    } else if (!errno)  {
      printf("Введенное вами значение не является строкой. Повторите...\n");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения!\n");
      return errno;
    }

    fflush_stream();
    if (errno) {
      fprintf(stderr, "Возникла ошибка при чистке буфера потока!\n");
      return errno;
    }
  }

  return 0;
}

int   get_array_from_stream(FILE* stream, int* size, struct Class* arr);

/*
 * Чистит поток до начала новой строки
 * или до конца потока
 */
void
fflush_stream(FILE* stream) {
  int c;
  while ((c = fgetc(stream)) != EOF && c != '\n');
}
