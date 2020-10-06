#ifndef __CLASS_H__
#define __CLASS_H__

#include <stdlib.h>
#include <errno.h>

int   arralloc(int, struct Class *);
void  init_fields(int, struct Class *);
void  free_fields(int, struct Class *);
void  arrfree(struct Class *);

struct Class {
  int weekday;        /* День недели [0..6], 0 - ПН, 6 - ВС */
  int time;           /* Время начала в минутах 00:00 - 0, 23:59 - 1439 */
  bool lecture;       /* Лекция или семинар? */
  int duration;       /* Продолжительность в минутах */
  char* subject;      /* Название предмета */
  char* professor;    /* Имя профессора */
  int year;           /* Курс(год) обучения */
  int group;          /* Номер группы */
}

#endif __CLASS_H__
