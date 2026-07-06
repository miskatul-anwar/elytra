#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char x[100001];
  scanf("%s", x);

  for (size_t c = 0; c < strlen(x); ++c) {
    if (x[c] >= '5') {
      if (c == 0 && x[c] == '9') {
        continue;
      }
      x[c] = '9' - x[c] + '0';
    }
  }

  printf("%s\n", x);
}