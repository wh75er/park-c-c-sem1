#include "input.h"

/*
 * Получение пользовательских данных
 */
int
get_user_input(int* size, struct Class* arr) {
  int err = 0;
  if ((err = get_size(size))) {
    fprintf(stderr, "Возникла ошибка при получении размера массива!\n");
    return err;
  }

  if ((err = get_array(size, arr))) {
    fprintf(stderr, "Возникла ошибка при чтении расписания!\n");
    return err;
  }

  return 0;
}

/*
 * Считывание размера массива
 */
int
get_size(int* size) {
  bool isNumber = false;
  while (isNumber == false) {
    printf("Пожалуйста, введите размер массива: ");

    char buffer[BUFFER_SIZE];
    if (!fgets(buffer, BUFFER_SIZE, stdin)) {
      fprintf(stderr, "Возникла ошибка при заполнения буфера из stdin!\n");
      return errno;
    }

    int n = sscanf(" %d", size);
    
    fflush_stdin();

    if (n == 1) {
      isNumber = true;
    } else if (!errno)  {
      printf("Введенное вами значение не является числом. Повторите...\n");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения");
      return errno;
    }
  }

  return 0;
}

int   get_array(int* size, struct Class* arr);

/*
 * Чистит поток stdin до начала новой строки
 * или до конца потока
 */
void
fflush_stdin(void) {
  int c;
  while ((c = fgetc(stdin)) != EOF && c != '\n');
}
