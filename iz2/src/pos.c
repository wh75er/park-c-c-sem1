#include "pos.h"

int
copy(const struct pos * const src, struct pos * const dst, const size_t size) {
  if(!src || !dst || !size) {
    return COPY_ERR;
  }

  memcpy(dst, src, size * sizeof(struct pos));

  return SUCCESS;
}

void
init_fields(struct pos* el) {
  el->x = 0;
  el->y = 0;
  el->z = 0;
}

void
print(FILE* stream, const struct pos * const el) {
  fprintf(stream, "%.4f %.4f %.4f\n", el->x, el->y, el->z);
}
