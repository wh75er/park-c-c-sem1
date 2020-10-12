#include "input.h"

/*
 * Получение пользовательских данных
 */
int
get_user_input(FILE* istream, FILE* ostream, int* year, int* group_id, int* size, struct lesson** arr) {
  fprintf(ostream, "Пожалуйста, введите номер курса: ");

  int err = 0;
  if ((err = get_value_from_stream(istream, ostream, year))) {
    fprintf(stderr, "Возникла ошибка при получении номера курса!\n");
    return err;
  }

  fprintf(ostream, "Пожалуйста, введите номер группы: ");
  if ((err = get_value_from_stream(istream, ostream, group_id))) {
    fprintf(stderr, "Возникла ошибка при получении номера группы!\n");
    return err;
  }

  fprintf(ostream, "Пожалуйста, введите размер массива: ");
  if ((err = get_value_from_stream(istream, ostream, size))) {
    fprintf(stderr, "Возникла ошибка при получении размера массива!\n");
    return err;
  }

  if ((err = get_array_from_stream(istream, ostream, *size, arr))) {
    fprintf(stderr, "Возникла ошибка при чтении расписания!\n");
    return err;
  }

  return 0;
}

/*
 * Считывание целочисленного значения из потока
 */
int
get_value_from_stream(FILE* istream, FILE* ostream, int* val) {
  bool is_number = false;

  while (is_number == false) {
    int n = fscanf(istream, "%d", val);

    if (n == 1) {
      is_number = true;
    } else if (n == -1) {
      fprintf(stderr, "Возникла ошибка при чтении буфера(EOF)\n");
      return -1;
    } else if (!errno)  {
      fprintf(ostream, "Введенное вами значение не является числом. Повторите: ");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения!\n");
      return errno;
    }

    fflush_stream(istream);
  }

  return 0;
}

/*
 * Считывание строки из потока
 */
int
get_string_from_stream(FILE* istream, FILE* ostream, char** str) {
  *str = NULL;

  bool is_string = false;
  while (is_string == false) {
    int n = fscanf(istream, "%ms", str);

    if (n == 1) {
      is_string = true;
    } else if (n == -1) {
      fprintf(stderr, "Возникла ошибка при чтении буфера(EOF)\n");
      return -1;
    } else if (!errno)  {
      fprintf(ostream, "Введенное вами значение не является строкой. Повторите: ");
    } else {
      fprintf(stderr, "Возникла ошибка при считывании значения!\n");
      free(*str);
      *str = NULL;
      return errno;
    }

    fflush_stream(istream);
  }

  return 0;
}

/*
 * Считывание дня недели из потока
 */
int
get_weekday_from_stream(FILE* istream, FILE* ostream, int* weekday) {
  fprintf(ostream, "Введите день недели[0-ПН, 6-ВС]: ");

  *weekday = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(istream, ostream, weekday))) {
      return err;
    }

    if (*weekday < 0 || *weekday > 6) {
      fprintf(ostream, "Ваше значение не является днем недели. Пожалуйста, введите корректное число[0-ПН, 6-ВС]: ");
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
get_time_from_stream(FILE* istream, FILE* ostream, int* time) {
  fprintf(ostream, "Введите время начала занятия в минутах[8:30 - 510, 20:30 - 1230]: ");

  *time = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(istream, ostream, time))) {
      return err;
    }

    if (*time < 510 || *time > 1230) {
      fprintf(ostream, "Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[510, 1230]: ");
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
get_lecture_from_stream(FILE* istream, FILE* ostream, bool* lecture) {
  fprintf(ostream, "Введите тип занятия[0 - семинар, 1 - лекция]: ");

  int type = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(istream, ostream, &type))) {
      return err;
    }

    if (type < 0 || type > 1) {
      fprintf(ostream, "Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[0 - семинар или 1 - лекция]: ");
    } else {
      *lecture = type;
      break;
    }
  }

  return 0;
}

int
get_duration_from_stream(FILE* istream, FILE* ostream, int* duration) {
  fprintf(ostream, "Введите время продолжительности занятия в минутах[5 - 90]: ");

  *duration = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(istream, ostream, duration))) {
      return err;
    }

    if (*duration < 5 || *duration > 90) {
      fprintf(ostream, "Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[5, 90]: ");
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
get_subject_from_stream(FILE* istream, FILE* ostream, char** subject) {
  fprintf(ostream, "Введите название предмета: ");

  *subject = NULL;
  int err = 0;
  if ((err = get_string_from_stream(istream, ostream , subject))) {
    return err;
  }

  return 0;
}

/*
 * Заполнение имени преподавателя
 */
int
get_professor_from_stream(FILE* istream, FILE* ostream, char** professor) {
  fprintf(ostream, "Введите имя преподавателя: ");

  *professor = NULL;
  int err = 0;
  if ((err = get_string_from_stream(istream, ostream, professor))) {
    return err;
  }

  return 0;
}

/*
 * Заполнение курса
 */
int
get_year_from_stream(FILE* istream, FILE* ostream, int* year) {
  fprintf(ostream, "Введите курс[1, 10]: ");

  *year = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(istream, ostream, year))) {
      return err;
    }

    if (*year < 1 || *year > 10) {
      fprintf(ostream, "Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[1, 10]: ");
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
get_group_from_stream(FILE* istream, FILE* ostream, int* group) {
  fprintf(ostream, "Введите номер группы[1, 100]: ");

  *group = -1;
  int err = 0;
  for (;;) {
    if ((err = get_value_from_stream(istream, ostream, group))) {
      return err;
    }

    if (*group < 1 || *group > 100) {
      fprintf(ostream, "Ваше значение не удовлетворяет условию. Пожалуйста, введите корректное число[1, 100]: ");
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
get_object_from_stream(FILE* istream, FILE* ostream, struct lesson* obj) {
  int weekday = -1;
  int err = 0;
  if ((err = get_weekday_from_stream(istream, ostream, &weekday))) {
    fprintf(stderr, "Возникла ошибка при чтении дня недели!\n");
    return err;
  }
  (*obj).weekday = weekday;

  int time;
  if ((err = get_time_from_stream(istream, ostream, &time))) {
    fprintf(stderr, "Возникла ошибка при чтении времени начала занятия!\n");
    return err;
  }
  (*obj).time = time;

  bool lecture = 0;
  if ((err = get_lecture_from_stream(istream, ostream, &lecture))) {
    fprintf(stderr, "Возникла ошибка при чтении типа занятия!\n");
    return err;
  }
  (*obj).lecture = lecture;

  int duration = -1;
  if ((err = get_duration_from_stream(istream, ostream, &duration))) {
    fprintf(stderr, "Возникла ошибка при чтении времени продолжительности занятия!\n");
    return err;
  }
  (*obj).duration = duration;

  char* subject = NULL;
  if ((err = get_subject_from_stream(istream, ostream, &subject))) {
    fprintf(stderr, "Возникла ошибка при чтении названия занятия!\n");
    return err;
  }
  (*obj).subject = subject;

  char* professor = NULL;
  if ((err = get_professor_from_stream(istream, ostream, &professor))) {
    fprintf(stderr, "Возникла ошибка при чтении имени преподавателя!\n");
    return err;
  }
  (*obj).professor = professor;

  int year = -1;
  if ((err = get_year_from_stream(istream, ostream, &year))) {
    fprintf(stderr, "Возникла ошибка при чтении номера курса!\n");
    return err;
  }
  (*obj).year = year;

  int group = -1;
  if ((err = get_group_from_stream(istream, ostream, &group))) {
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
get_array_from_stream(FILE* istream, FILE* ostream, const int size, struct lesson** arr) {
  int err = 0;
  if ((err = arralloc(size, arr))) {
    fprintf(stderr, "Возникла ошибка при выделении памяти под массив!\n");
    return err;
  }

  for (int i = 0; i < size; i++) {
    if((err = get_object_from_stream(istream, ostream, &(*arr)[i]))) {
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
