#include "input.h"

/*
 * Получение пользовательских данных
 */
int
get_user_input(FILE* stream, int* size, struct class** arr) {
  printf("Пожалуйста, введите размер массива: ");
  int err = 0;
  if ((err = get_value_from_stream(stream, size))) {
    fprintf(stderr, "Возникла ошибка при получении размера массива!\n");
    return err;
  }

  if ((err = get_array_from_stream(stream, *size, arr))) {
    fprintf(stderr, "Возникла ошибка при чтении расписания!\n");
    return err;
  }

  return 0;
}

/*
 * Считывание целочисленного значения из потока
 */
int
get_value_from_stream(FILE* stream, int* val) {
  bool is_number = false;
  while (is_number == false) {
    int n = fscanf(stream, "%d", val);

    if (n == 1) {
      is_number = true;
    } else if (!errno)  {
      printf("Введенное вами значение не является числом. Повторите: ");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения!\n");
      return errno;
    }

    fflush_stream(stream);
  }

  return 0;
}

/*
 * Считывание строки из потока
 */
int
get_string_from_stream(FILE* stream, char** str) {
  bool is_string = false;
  while (is_string == false) {
    int n = fscanf(stream, "%ms", str);

    if (n == 1) {
      is_string = true;
    } else if (!errno)  {
      printf("Введенное вами значение не является строкой. Повторите: ");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения!\n");
      free(str);
      str = NULL;
      return errno;
    }

    fflush_stream(stream);
  }

  return 0;
}

/*
 * Считывание дня недели из потока
 */
int
get_weekday_from_stream(FILE* stream, int* weekday) {
  printf("Введите день недели[0-ПН, 6-ВС]: ");
  *weekday = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(stream, weekday))) {
      return err;
    }

    if (*weekday < 0 || *weekday > 6) {
      printf("Ваше значение не является днем недели. Пожалуйста, введите корректное число[0-ПН, 6-ВС]: ");
    } else {
      break;
    }
  }

  return 0;
}

/*
 * Считывание времени из потока
 */
int
get_time_from_stream(FILE* stream, int* time) {
  printf("Введите время начала занятия в минутах[8:30 - 510, 20:30 - 1230]: ");
  *time = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(stream, time))) {
      return err;
    }

    if (*time < 510 || *time > 1230) {
      printf("Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[510, 1230]: ");
    } else {
      break;
    }
  }

  return 0;
}

/*
 * Считывании информации о типе занятия
 */
int
get_lecture_from_stream(FILE* stream, bool* lecture) {
  printf("Введите тип занятия[0 - семинар, 1 - лекция]: ");
  int type = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(stream, &type))) {
      return err;
    }

    if (type < 0 || type > 1) {
      printf("Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[0 - семинар или 1 - лекция]: ");
    } else {
      *lecture = type;
      break;
    }
  }

  return 0;
}

int
get_duration_from_stream(FILE* stream, int* duration) {
  printf("Введите время продолжительности занятия в минутах[5 - 90]: ");
  *duration = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(stream, duration))) {
      return err;
    }

    if (*duration < 5 || *duration > 90) {
      printf("Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[5, 90]: ");
    } else {
      break;
    }
  }

  return 0;
}

/*
 * Заполнение названия предмета
 */
int
get_subject_from_stream(FILE* stream, char** subject) {
  printf("Введите название предмета: ");
  *subject = NULL;
  int err = 0;
  if ((err = get_string_from_stream(stream, subject))) {
    return err;
  }

  return 0;
}

/*
 * Заполнение имени преподавателя
 */
int
get_professor_from_stream(FILE* stream, char** professor) {
  printf("Введите имя преподавателя: ");
  *professor = NULL;
  int err = 0;
  if ((err = get_string_from_stream(stream, professor))) {
    return err;
  }

  return 0;
}

/*
 * Заполнение курса
 */
int
get_year_from_stream(FILE* stream, int* year) {
  printf("Введите курс[1, 10]: ");
  *year = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(stream, year))) {
      return err;
    }

    if (*year < 1 || *year > 10) {
      printf("Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[1, 10]: ");
    } else {
      break;
    }
  }

  return 0;
}

/*
 * Заполнение номера группы
 */
int
get_group_from_stream(FILE* stream, int* group) {
  printf("Введите номер группы[1, 100]: ");
  *group = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(stream, group))) {
      return err;
    }

    if (*group < 1 || *group > 100) {
      printf("Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[1, 100]: ");
    } else {
      break;
    }
  }

  return 0;
}

/*
 * Заполнение одного объекта из потока по указателю
 */
int
get_object_from_stream(FILE* stream, struct class* obj) {
  int weekday = -1;
  int err = 0;
  if ((err = get_weekday_from_stream(stream, &weekday))) {
    fprintf(stderr, "Возникла ошибка при чтении дня недели!\n");
    return err;
  }
  (*obj).weekday = weekday;

  int time;
  if ((err = get_time_from_stream(stream, &time))) {
    fprintf(stderr, "Возникла ошибка при чтении времени начала занятия!\n");
    return err;
  }
  (*obj).time = time;

  bool lecture = 0;
  if ((err = get_lecture_from_stream(stream, &lecture))) {
    fprintf(stderr, "Возникла ошибка при чтении типа занятия!\n");
    return err;
  }
  (*obj).lecture = lecture;

  int duration = -1;
  if ((err = get_duration_from_stream(stream, &duration))) {
    fprintf(stderr, "Возникла ошибка при чтении времени продолжительности занятия!\n");
    return err;
  }
  (*obj).duration = duration;

  char* subject = NULL;
  if ((err = get_subject_from_stream(stream, &subject))) {
    fprintf(stderr, "Возникла ошибка при чтении названия занятия!\n");
    return err;
  }
  (*obj).subject = subject;

  char* professor = NULL;
  if ((err = get_professor_from_stream(stream, &professor))) {
    fprintf(stderr, "Возникла ошибка при чтении имени преподавателя!\n");
    return err;
  }
  (*obj).professor = professor;

  int year = -1;
  if ((err = get_year_from_stream(stream, &year))) {
    fprintf(stderr, "Возникла ошибка при чтении номера курса!\n");
    return err;
  }
  (*obj).year = year;

  int group = -1;
  if ((err = get_group_from_stream(stream, &group))) {
    fprintf(stderr, "Возникла ошибка при чтении номера группы!\n");
    return err;
  }
  (*obj).group = group;

  return 0;
}

/*
 * Выделение памяти под массив и его заполнение из потока
 */
int
get_array_from_stream(FILE* stream, const int size, struct class** arr) {
  int err = 0;
  if ((err = arralloc(size, arr))) {
    fprintf(stderr, "Возникла ошибка при выделении памяти под массив!\n");
    return err;
  }

  for (int i = 0; i < size; i++) {
    if((err = get_object_from_stream(stream, &(*arr)[i]))) {
      fprintf(stderr, "Возникла ошибка при заполнении массива!\n");
      return err;
    }
  }

  return 0;
}

/*
 * Чистит поток до начала новой строки
 * или до конца потока
 */
void
fflush_stream(FILE* stream) {
  int c;
  while ((c = fgetc(stream)) != EOF && c != '\n');
}
