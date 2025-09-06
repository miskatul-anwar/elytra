#include <stdio.h>

#define MAXN 305
typedef long long ll;

static ll d[MAXN][MAXN];

static inline ll minll(ll a, ll b) { return a < b ? a : b; }

/* Relax all pairs using a single intermediate node k */
static void relax_with_k(int n, int k) {
  for (int i = 1; i <= n; ++i) {
    ll dik = d[i][k];
    for (int j = 1; j <= n; ++j) {
      ll cand = dik + d[k][j];
      if (cand < d[i][j])
        d[i][j] = cand;
    }
  }
}

/* After setting/shortening edge (x,y) to length l, update APSP using only x and
 * y */
static void add_edge_and_update(int n, int x, int y, ll l) {
  if (d[x][y] <= l) {
    // New edge can't improve anything; keep matrix as is.
    return;
  }
  d[x][y] = d[y][x] = l;

  // Two targeted Floyd passes are enough:
  relax_with_k(n, x);
  relax_with_k(n, y);
}

/* Sum of shortest distances over unordered pairs (i < j) */
static ll sum_over_pairs(int n) {
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      sum += d[i][j];
    }
  }
  return sum;
}

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld", &d[i][j]);
    }
  }

  int q;
  scanf("%d", &q);
  for (int t = 0; t < q; ++t) {
    int x, y;
    ll l;
    scanf("%d %d %lld", &x, &y, &l);

    add_edge_and_update(n, x, y, l);

    ll ans = sum_over_pairs(n);
    printf("%lld", ans);
    if (t + 1 < q)
      putchar(' ');
  }
  putchar('\n');
  return 0;
}
