#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  int t;
  scanf("%d", &t);

  while (t--) {
    char x[100001];
    int ans[100001];
    scanf("%s", x);
    size_t n = strlen(x);
    int cnt = 0;

    for (size_t c = 0; x[c] != '\0'; ++c) {
      if (x[c] != '0') {
        ans[cnt] = x[c] - '0';
        for (size_t i = 0; i < n - c - 1; ++i) {
          ans[cnt] *= 10;
        }
        cnt++;
      }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
}