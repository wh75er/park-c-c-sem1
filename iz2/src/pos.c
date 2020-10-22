#include "pos.h"

/*
 *  Allocates memory for array and initializes struct's fields
 * with zeroes. If error occurs, returns errno, else 0
*/
int
arralloc(const size_t size, struct pos** arr) {
  *arr = (struct pos*)malloc(size * sizeof(struct pos));

  if (!(*arr)) {
    return errno;
  }

  init_fields(size, *arr);

  return 0;
}

/*
 *  Free memory and change pointer to NULL
*/
void
arrfree(struct pos** arr) {
  if(!arr) {
    return;
  }

  free(*arr);
  *arr = NULL;
}

/*
 *  Copies array src to array dst 
*/
int
copy(const struct pos * const src, struct pos * const dst, const size_t size) {
  if(!src || !dst) {
    return COPY_ERR;
  }

  memcpy(dst, src, size * sizeof(struct pos));

  return 0;
}

/*
 *  Initializes fields of the struct
*/
void
init_fields(const size_t size, struct pos* arr) {
  for (size_t i = 0; i < size; i++) {
    arr[i].x = 0;
    arr[i].y = 0;
    arr[i].z = 0;
  }
}

/*
 *  Writes struct to stream
*/
void
print(FILE* stream, const struct pos * const el) {
  fprintf(stream, "%.4f %.4f %.4f", el->x, el->y, el->z);
}
