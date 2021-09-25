#include <stdio.h>
#include <stdlib.h>

#define LOWER 0

// TODO: Error handling
int main(int argc, char *args[argc]) {
  int upper = atoi(args[1]);
  int step = atoi(args[2]);

  puts("  F\t  C");

  for (float fahr = LOWER; fahr <= upper; fahr += step) {
    float cels = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t%6.1f\n", fahr, cels);
  }

  return EXIT_SUCCESS;
}
