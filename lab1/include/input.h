#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stderr.h>

#include "class.h"

#define BUFFER_SIZE 10

int   get_user_input(FILE *, int *, struct Class *);

int   get_value_from_stream(FILE *, int *);
int   get_string_from_stream(FILE *, char *);

int   get_object_from_stream(FILE *, struct Class *);

int   get_weekday_from_stream(FILE *, int *);
int   get_time_from_stream(FILE *, int *);
int   get_lecture_from_stream(FILE *, bool *);
int   get_duration_from_stream(FILE *, int *);
int   get_subject_from_stream(FILE *, char *);
int   get_professor_from_stream(FILE *, char *);
int   get_year_from_stream(FILE *, int *);
int   get_group_from_stream(FILE *, int *);

int   get_array_from_stream(FILE *, int, struct Class *);

void  fflush_stream(FILE *);

#endif
