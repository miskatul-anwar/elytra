/**
 * @author: miskatul-anwar
 * @problem: A. In The Dreams
 */

#include <stdbool.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

const bool TEST_CASES = true;

static inline bool ok(int x, int y) {
  int a = max(x, y), b = min(x, y);
  return a <= 2 * (b + 1);
}

static inline void solve(void) {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  bool first = ok(a, b);
  bool second = ok(c - a, d - b);

  printf(first && second ? "YES\n" : "NO\n");
}

int main(void) {
  if (TEST_CASES) {
    int t;
    if (scanf("%d", &t) != 1)
      return 1;
    while (t--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
