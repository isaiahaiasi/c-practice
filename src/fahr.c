#include <stdio.h>
#include <stdlib.h>

// TODO: Error handling
int main(int argc, char *args[argc]) {
  int lower = atoi(args[1]);
  int upper = atoi(args[2]);
  int step = atoi(args[3]);

  int fahr = lower;

  puts("  F\t  C");
  while (fahr <= upper) {
    int cels = 5 * (fahr - 32) / 9;
    printf("%3d\t%3d\n", fahr, cels);
    fahr += step;
  }

  return EXIT_SUCCESS;
}