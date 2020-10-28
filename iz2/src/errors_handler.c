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
      break;
    case ARGS_ERR :
      fprintf(stderr, "Arguments error!\n");
      break;
    case WRITE_ERR :
      fprintf(stderr, "Failed to write data!\n");
      break;
    case WRITE_OPEN_FILE_ERR :
      fprintf(stderr, "Failed to open file for writing!\n");
      break;
    case STREAM_READ_ERR :
      fprintf(stderr, "Failed to read values from stream!\n");
      break;
    case REALLOC_BUFFER_ERR :
      fprintf(stderr, "Failed to reallocate memory for buffer!\n");
      break;
    case ALLOC_BUFFER_ERR :
      fprintf(stderr, "Failed to allocate memory for buffer!\n");
      break;
    case READ_OPEN_FILE_ERR :
      fprintf(stderr, "Failed to open file for reading!\n");
      break;
    case ALLOC_POS_ARRAY_ERR :
      fprintf(stderr, "Failed to allocate memory for radius-vectors array!\n");
      break;
    case ALLOC_POS_ARRAY_PARAMS_ERR :
      fprintf(stderr, "Invalid params for array allocation!\n");
      break;
    case READ_PARAMS_ERR :
      fprintf(stderr, "Invalid params for data reading!\n");
      break;
    case WRITE_PARAMS_ERR :
      fprintf(stderr, "Invalid params for data writing!\n");
      break;
    case ARRAY_CREATE_PARAMS_ERR :
      fprintf(stderr, "Invalid params for array creation!\n");
      break;
    case NAIVE_MEAN_PARAMS_ERR :
      fprintf(stderr, "Invalid params for naive mean calculation!\n");
      break;
    case SUM_BORDERS_ERR :
      fprintf(stderr, "Invalid borders for mean calculation function!Left border should be less than right border.\n");
      break;
    case SUM_PARAMS_ERR :
      fprintf(stderr, "Invalid params for parallel calculation function!\n");
      break;
    case PARALLEL_PARAMS_ERR :
      fprintf(stderr, "Invalid params for parallel mean implementation!\n");
      break;
    case PARALLEL_PIPE_ERR :
      fprintf(stderr, "Failed to create a pipe!\n");
      break;
    case PARALLEL_CHILD_CREATE_ERR :
      fprintf(stderr, "Failed to create a child process!\n");
      break;
    case PARALLEL_CHILD_FAILURE_ERR :
      fprintf(stderr, "Child process failed during processing!\n");
      break;
    case PARALLEL_PROC_BUSY_ERR :
      fprintf(stderr, "Processes are not available!\n");
      break;
    case PARALLEL_SHMEM_MAP_ERR :
      fprintf(stderr, "Failed to map shared memory!\n");
      break;
    case PARALLEL_SEM_OPEN_ERR :
      fprintf(stderr, "Failed to open semaphore!\n");
      break;
    case PARALLEL_SEM_POST_ERR :
      fprintf(stderr, "Failed to unlock semaphore!\n");
      break;
    case PARALLEL_PWAIT_ERR :
      fprintf(stderr, "Error occured while waiting for child process!\n");
      break;
  }

  if (err > 0) {
    fprintf(stderr, "Error occured: %s!\n", strerror(err));
  }

  arrfree(arr);
}
