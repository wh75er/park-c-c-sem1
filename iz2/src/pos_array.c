#include "pos_array.h"

int
create_array(const size_t size, struct pos** arr) {
  if(arr == NULL || size == 0) {
    return ARRAY_CREATE_PARAMS_ERR;
  }

  int err = 0;
  if((err = arralloc(size, arr))) {
    return err;
  }

  for(size_t i = 0; i < size; i++) {
    init_fields(&(*arr)[i]);
  }

  return SUCCESS;
}

int
arralloc(const size_t size, struct pos** arr) {
  if(arr == NULL || size == 0) {
    return ALLOC_POS_ARRAY_PARAMS_ERR;
  }

  *arr = (struct pos*)malloc(size * sizeof(struct pos));

  if (!(*arr)) {
    return ALLOC_POS_ARRAY_ERR;
  }

  return SUCCESS;
}

void
arrfree(struct pos** arr) {
  if(!arr) {
    return;
  }

  free(*arr);
  *arr = NULL;
}
