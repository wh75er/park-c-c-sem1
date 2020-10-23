#include "io.h"

/*
 *  Reads data from file and stores it into array
*/
int
read_data_from_file(const char * const filename, size_t* size, struct pos** const arr) {
  FILE* fd = fopen(filename, "r");

  if(!fd) {
    fprintf(stderr, "Failed to open file!\n");
    return errno;
  }

  int err = 0;
  if((err = read_data_from_stream(fd, size, arr))) {
    fprintf(stderr, "Failed to read data from stream!\n");
    return err;
  }

  fclose(fd);

  return 0;
}

/*
 *  Reads data from stream and stores it into array
*/
int
read_data_from_stream(FILE * const fd, size_t* size, struct pos** const arr) {
  size_t buf_size = BUFFER_SIZE;
  struct pos* buf = (struct pos*)malloc(buf_size * sizeof(struct pos));

  if(!buf) {
    fprintf(stderr, "Failed to allocate memory!\n");
    return errno;
  }
  
  size_t buf_idx = 0;
  for(;;) {
    if(buf_idx == buf_size) {
      buf_size *= 2;
      buf = (struct pos*)realloc(buf, buf_size * sizeof(struct pos));

      if(!buf) {
        fprintf(stderr, "Failed to reallocate memory!\n");
        free(buf);
        return errno;
      }
    }

    int n = fscanf(fd, "%f %f %f", 
                    &(buf[buf_idx].x), &(buf[buf_idx].y), &(buf[buf_idx].z)
                  );

    if(n == EOF) {
      break;
    } else if(n != 3 && !errno) {
      fprintf(stderr, "Incorrect input value type! Only digits expected.\n");
      free(buf);
      return TYPE_ERR;
    } else if (n != 3 && errno){
      fprintf(stderr, "Failed to read data from the stream!\n");
      free(buf);
      return errno;
    }

    buf_idx++;
  }
  
  int err = 0;
  if((err = arralloc(buf_idx, arr))) {
    fprintf(stderr, "Failed to allocate memory for array!\n");
    return err;
  }

  if((err = copy(buf, *arr, buf_idx))) {
    fprintf(stderr, "Failed to copy memory from src array to dst array!\n");
    return err;
  }

  *size = buf_idx;

  free(buf);

  return 0;
}

/*
 *  Writes data into the specified file 
*/
int
write_data_to_file(const char * const filename, const struct pos * const el) {
  return 0;
}

/*
 *  Writes data into the specified stream
*/
int
write_data_to_stream(FILE * const fd, const struct pos * const el) {
  return 0;
}
