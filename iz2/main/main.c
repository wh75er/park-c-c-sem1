#include "main.h"

/*
 *  Finds mean of X, Y, Z coords in radius-vector's array. Executable uses one of
 * the proposed implementations: naive algorithm or process parallel algorithm.
 * Implementation choice depends on build configuration
*/
int
main(int argc, char *argv[]) {
  char* input_fname = NULL;
  char* output_fname = NULL;

  int err = 0;
  if((err = get_args(argc, argv, &input_fname, &output_fname))) {
    error_handler(err, NULL);
    exit(EXIT_FAILURE);
  }

  printf("Arg1: %s\n", input_fname);
  printf("Arg2: %s\n", output_fname);


  size_t size = 0;
  struct pos* arr = NULL;
  if((err = read_data_from_file(input_fname, &size, &arr))) {
    error_handler(err, &arr);
    exit(EXIT_FAILURE);
  }

  return 0;
}
