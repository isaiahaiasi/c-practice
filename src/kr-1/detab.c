#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// replace tabs with a set number of spaces (default: 4)
// ex: detab 2 < input.c > output.c
int main(int argc, char* args[argc]) {
  // set the number of spaces that counts as a tab (default 4)
  int spaces = 4;
  if (argc > 1) {
    spaces = atoi(args[1]);
  }

  int c;
  while ((c = getchar()) != EOF) {
    // if c is a tab, instead of printing c print spaces
    if (c == '\t') {
      for (int i = 0; i < spaces; ++i) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }
}
