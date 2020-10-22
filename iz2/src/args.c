#include "args.h"

int get_args(int argc, char* argv[], char** const arg1, char** const arg2) {
  if(argc < 3) {
    fprintf(stderr, "Incorrect amount of arguments!\n");
    return ARGS_ERR;
  }

  *arg1 = argv[1];
  *arg2 = argv[2];

  return 0;
}
