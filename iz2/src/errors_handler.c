#include "errors_handler.h"

/*
 *  Outputs errors and frees memory
 */
void
handle_errors(const int err, struct pos** arr) {
  switch(err) {
    case TYPE_ERR :
      fprintf(stderr, "Incorrect type error(Only digits expected)!\n");
    case COPY_ERR :
      fprintf(stderr, "Failed to copy data!\n");
    case ARGS_ERR :
      fprintf(stderr, "Arguments error!\n");
    case WRITE_ERR :
      fprintf(stderr, "Failed to write data!\n");
    case WRITE_OPEN_FILE_ERR :
      fprintf(stderr, "Failed to open file for writing!\n");
    case STREAM_READ_ERR :
      fprintf(stderr, "Failed to read values from stream!\n");
    case REALLOC_BUFFER_ERR :
      fprintf(stderr, "Failed to reallocate memory for buffer!\n");
    case ALLOC_BUFFER_ERR :
      fprintf(stderr, "Failed to allocate memory for buffer!\n");
    case READ_OPEN_FILE_ERR :
      fprintf(stderr, "Failed to open file for reading!\n");
    case ALLOC_POS_ARRAY_ERR :
      fprintf(stderr, "Failed to allocate memory for radius-vectors array!\n");
    case ALLOC_POS_ARRAY_PARAMS_ERR :
      fprintf(stderr, "Invalid params for array allocation!\n");
    case READ_PARAMS_ERR :
      fprintf(stderr, "Invalid params for data reading!\n");
    case WRITE_PARAMS_ERR :
      fprintf(stderr, "Invalid params for data writing!\n");
    case ARRAY_CREATE_PARAMS_ERR :
      fprintf(stderr, "Invalid params for array creation!\n");
  }

  if (err > 0) {
    fprintf(stderr, "Error occured: %s!\n", strerror(err));
  }

  arrfree(arr);
}
