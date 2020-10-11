#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "class.h"

#define BUFFER_SIZE 10

int   get_user_input(FILE* istream, FILE* ostream, int* year, int* group_id, int* size, struct lesson** arr);

int   get_value_from_stream(FILE* istream, FILE* ostream, int* val);
int   get_string_from_stream(FILE* istream, FILE* ostream, char** str);

int   get_object_from_stream(FILE* istream, FILE* ostream, struct lesson* obj);

int   get_weekday_from_stream(FILE* istream, FILE* ostream, int* weekday);
int   get_time_from_stream(FILE* istream, FILE* ostream, int* time);
int   get_lecture_from_stream(FILE* istream, FILE* ostream, bool* lecture);
int   get_duration_from_stream(FILE* istream, FILE* ostream, int* duration);
int   get_subject_from_stream(FILE* istream, FILE* ostream, char** subject);
int   get_professor_from_stream(FILE* istream, FILE* ostream, char** professor);
int   get_year_from_stream(FILE* istream, FILE* ostream, int* year);
int   get_group_from_stream(FILE* istream, FILE* ostream, int* group);

int   get_array_from_stream(FILE* istream, FILE* ostream, const int, struct lesson** arr);

void  fflush_stream(FILE* stream);

#endif
