#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define ull unsigned long long
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f

// Set to true to run multiple test cases
const bool TEST_CASES = false;

static inline void solve() {
  int a;

  for (int i = 1; i < 6; ++i) {
    for (int j = 1; j < 6; ++j) {
      scanf("%d", &a);

      if (a == 1) {
        printf("%d\n", abs(i - 3) + abs(j - 3));
      }
    }
  }
}

int main() {
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
