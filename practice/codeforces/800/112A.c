#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char s1[101], s2[101];
  scanf("%100s %100s", s1, s2);

  int n = strlen(s1);

  for (int i = 0; i < n; i++) {
    char c1 = tolower((unsigned char)s1[i]);
    char c2 = tolower((unsigned char)s2[i]);

    if (c1 < c2) {
      printf("-1\n");
      return 0;
    } else if (c1 > c2) {
      printf("1\n");
      return 0;
    }
  }

  printf("0\n");
  return 0;
}
