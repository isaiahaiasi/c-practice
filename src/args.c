#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[argc + 1]) {
  puts("These were the arguments given to the program:");
  for (int i = 0; i < argc; i++) {
    printf("arg %d\t%s\n", i, argv[i]);
  }
  return EXIT_SUCCESS;
}