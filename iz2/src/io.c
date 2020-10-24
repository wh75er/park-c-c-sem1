#include "io.h"

int
read_data_from_file(const char * const filename, size_t* size, struct pos** const arr) {
  if(!filename || !size || !arr) {
    return READ_PARAMS_ERR;
  }

  FILE* fd = fopen(filename, "r");

  if(!fd) {
    return READ_OPEN_FILE_ERR;
  }

  int err = 0;
  if((err = read_data_from_stream(fd, size, arr))) {
    fclose(fd);
    return err;
  }

  fclose(fd);

  return SUCCESS;
}

int
read_data_from_stream(FILE * const fd, size_t* size, struct pos** const arr) {
  if(!fd || !size || !arr) {
    return READ_PARAMS_ERR;
  }
  size_t buf_size = BUFFER_SIZE;
  struct pos* buf = (struct pos*)malloc(buf_size * sizeof(struct pos));

  if(!buf) {
    return ALLOC_BUFFER_ERR;
  }
  
  size_t buf_idx = 0;
  for(;;) {
    if(buf_idx == buf_size) {
      buf_size *= 2;
      struct pos* new_buf = (struct pos*)realloc(buf, buf_size * sizeof(struct pos));

      if(!new_buf) {
        free(buf);
        return REALLOC_BUFFER_ERR;
      }
      
      buf = new_buf;
    }

    int n = fscanf(fd, "%f %f %f", 
                    &(buf[buf_idx].x), &(buf[buf_idx].y), &(buf[buf_idx].z)
                  );

    if(n == EOF) {
      break;
    } else if(n != 3 && !errno) {
      free(buf);
      return TYPE_ERR;
    } else if (n != 3 && errno){
      free(buf);
      return STREAM_READ_ERR;
    }

    buf_idx++;
  }
  
  int err = 0;
  if((err = create_array(buf_idx, arr))) {
    return err;
  }

  if((err = copy(buf, *arr, buf_idx))) {
    return err;
  }

  *size = buf_idx;

  free(buf);

  return SUCCESS;
}

int
write_data_to_file(const char * const filename, const struct pos * const el) {
  if(!filename || !el) {
    return WRITE_PARAMS_ERR;
  }

  FILE* fd = fopen(filename, "w");

  if(!fd) {
    return WRITE_OPEN_FILE_ERR;
  }

  int err = 0;
  if((err = write_data_to_stream(fd, el))) {
    fclose(fd);
    return err;
  }

  fclose(fd);

  return SUCCESS;
}

int
write_data_to_stream(FILE * const fd, const struct pos * const el) {
  if(!fd || !el) {
    return WRITE_PARAMS_ERR;
  }

  int n = fprintf(fd, "%.2f %.2f %.2f\n", el->x, el->y, el->z);

  if(n < 0) {
    return WRITE_ERR;
  }
  
  return SUCCESS;
}
