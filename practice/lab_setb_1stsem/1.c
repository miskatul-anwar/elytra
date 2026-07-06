#include <stdio.h>

void pattern(int row, int col) {
  for (int i = 1; i <= row; ++i) {
    for (int j = 1; j <= col; ++j) {
      if (i % 2 != 0) {
        if (j == (col + 1) / 2) {
          printf("O ");
        } else {
          printf("$ ");
        }
      } else {
        if (j == (col + 1) / 2) {
          printf("$ ");
        } else {
          printf("* ");
        }
      }
    }
    printf("\n");
  }
}

int main(void) {
  int row, col;
  printf("Enter rows and cols: ");
  scanf("%d %d", &row, &col);

  pattern(row, col);

  return 0;
}
