// read a character
// while (character is not EOF indicator)
// output the char just read
// read a character

#include <stdio.h>
#include <stdlib.h>

int main() {
  int c;
  int num_chars = 0;
  while ((c = getchar()) != EOF) {
    putchar(c);
    ++num_chars;
  }
  printf("\nnum chars\t%d\n", num_chars);
  return EXIT_SUCCESS;
}