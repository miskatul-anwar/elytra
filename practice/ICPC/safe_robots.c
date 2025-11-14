#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int t;
  scanf("%i", &t);
  while (t--) {
    char s[(int)1e6];
    scanf("%s", s);
    int n = sizeof(s);
    int sa, sb;
    scanf("%i %i", &sa, &sb);

    int i, j;
    for (int c = 0; c < n; ++c)
      if (s[c] == 'A')
        i = c;
      else if (s[c] == 'B')
        j = c;
    bool collision = false;
    while (j >= 0 && i < n) {
      if (i == j)
        collision = true;
      i += sa, j -= sb;
    }

    printf("%s", (collision ? "unsafe\n" : "safe\n"));
  }

  return 0;
}