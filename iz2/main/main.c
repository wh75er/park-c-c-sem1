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
    handle_errors(err, NULL);
    exit(EXIT_FAILURE);
  }

  size_t size = 0;
  struct pos* arr = NULL;
  if((err = read_data_from_file(input_fname, &size, &arr))) {
    handle_errors(err, &arr);
    exit(EXIT_FAILURE);
  }

  struct pos mean = {0, 0, 0};
  double start = omp_get_wtime();
  if((err = find_mean(&arr, size, &mean))) {
    handle_errors(err, &arr);
    exit(EXIT_FAILURE);
  }
  double end = omp_get_wtime();

  printf("Elapsed time: %lf\n", end - start);

  if((err = write_data_to_file(output_fname, &mean))) {
    handle_errors(err, &arr);
    exit(EXIT_FAILURE);
  }

  arrfree(&arr);

  return 0;
}
