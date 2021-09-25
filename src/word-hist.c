// write a program to print a histogram of the length of words in its input

#include <stdbool.h>
#include <stdio.h>

bool is_whitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n';
}

int get_last_not_empty(int arr[], int arr_size) {
  int ne_i = 0;
  for (int i = 0; i < arr_size; ++i) {
    if (arr[i] > 0) {
      ne_i = i;
    }
  }
  return ne_i;
}

void fill_histogram(int hist[], int h_size, int fill_value) {
  for (int i = 0; i < h_size; ++i) {
    hist[i] = fill_value;
  }
}

void print_bar(int len, char c) {
  for (int i = 0; i < len; ++i) {
    printf("%c", c);
  }
  printf("\n");
}

void print_histogram(int hist[], int h_size) {
  // get furthest index filled (eg, everything past 20 might be 0) to truncate
  int len = get_last_not_empty(hist, h_size);
  for (int i = 0; i < len; ++i) {
    printf("%2d\t%3d\t", i + 1, hist[i]);
    print_bar(hist[i], '#');
  }
}

int main() {
  // index for each length. lengths above 30 grouped together
  // just because I don't want to write a hashing algo in c
  int hist_size = 30;
  int hist[hist_size];
  fill_histogram(hist, hist_size, 0);

  int ch;
  int wi = 0;
  while ((ch = getchar()) != EOF) {
    if (is_whitespace(ch)) {
      if (wi > 0) {
        // push wi to histogram
        if (wi > 30) {
          // avoid overflow
          wi = 30;
        }
        ++hist[wi - 1];
        wi = 0;
      }
      // if ch is whitespace but wi is zero, do nothing
    } else {
      ++wi;
    }
  }

  print_histogram(hist, hist_size);
}