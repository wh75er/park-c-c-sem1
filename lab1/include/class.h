#ifndef __CLASS_H__
#define __CLASS_H__

#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

struct class {
  int weekday;        /* День недели [0..6], 0 - ПН, 6 - ВС */
  int time;           /* Время начала в минутах 8:30 - 510, 20:30 - 1230 */
  bool lecture;       /* Лекция или семинар? */
  int duration;       /* Продолжительность в минутах [5..90]*/
  char* subject;      /* Название предмета */
  char* professor;    /* Имя профессора */
  int year;           /* Курс(год) обучения */
  int group;          /* Номер группы */
};

int   arralloc(const int, struct class**);
void  init_fields(const int, struct class*);
void  free_fields(const int, struct class*);
void  arrfree(int, struct class*);
int   copy(struct class * const, struct class *);
void  swap(struct class * const, struct class * const);

#endif
