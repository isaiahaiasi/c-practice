#include <stdio.h>
#include <stdlib.h>

// count digits, whitespace, other
int main() {
  int ndigit[10];
  int nwhite = 0;
  int nother = 0;

  for (int i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  int c;
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits =");
  for (int i = 0; i < 10; ++i) {
    printf(" %d", ndigit[i]);
  }

  printf(", white space = %d, other = %d\n", nwhite, nother);

  return EXIT_SUCCESS;
}