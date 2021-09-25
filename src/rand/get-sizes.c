#include <stdint.h>
#include <stdio.h>

void get_size(size_t _size, char* size_name) {
  printf("%s is sizeof\t%zu\t%zu\n", size_name, _size, _size * 8);
}

int main() {
  get_size(sizeof(int), "int");
  get_size(sizeof(int_least8_t), "int_least8_t");
  get_size(sizeof(int_least16_t), "int_least16_t");
  get_size(sizeof(int_fast8_t), "int_fast8_t");
  get_size(sizeof(int_fast16_t), "int_fast16_t");
  get_size(sizeof(intmax_t), "intmax_t");
  get_size(sizeof(size_t), "size_t");
}