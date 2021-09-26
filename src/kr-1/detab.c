#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_WIDTH 4

int get_spaces(int argc, char* args[argc]);
void print_output(int spaces);

// replace tabs with a set number of spaces (default: 4)
// ex: detab 2 < input.c > output.c
int main(int argc, char* args[argc]) {
  int spaces = get_spaces(argc, args);
  print_output(spaces);
}

// set the number of spaces that counts as a tab (default 4)
int get_spaces(int argc, char* args[argc]) {
  return argc > 1 ? atoi(args[1]) : DEFAULT_WIDTH;
}

// output the input char-by-char, replacing '\t's with N spaces
void print_output(int spaces) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (int i = 0; i < spaces; ++i) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }
}
