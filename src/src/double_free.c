#include "so_long.h"

void double_free(char **matrix) {
  int i;

  i = 0;
  while (matrix[i]) {
    free(matrix[i]);
    i++;
  }
  free(matrix);
}
