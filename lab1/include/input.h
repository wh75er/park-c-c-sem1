#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "class.h"

#define BUFFER_SIZE 10

int   get_user_input(FILE* stream, int* year, int* group_id, int* size, struct lesson** arr);

int   get_value_from_stream(FILE* stream, int* val);
int   get_string_from_stream(FILE* stream, char** str);

int   get_object_from_stream(FILE* stream, struct lesson* obj);

int   get_weekday_from_stream(FILE* stream, int* weekday);
int   get_time_from_stream(FILE* stream, int* time);
int   get_lecture_from_stream(FILE* stream, bool* lecture);
int   get_duration_from_stream(FILE* stream, int* duration);
int   get_subject_from_stream(FILE* stream, char** subject);
int   get_professor_from_stream(FILE* stream, char** professor);
int   get_year_from_stream(FILE* stream, int* year);
int   get_group_from_stream(FILE* stream, int* group);

int   get_array_from_stream(FILE* stream, const int, struct lesson** arr);

void  fflush_stream(FILE* stream);

#endif
