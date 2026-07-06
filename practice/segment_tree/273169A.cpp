#include <bits/stdc++.h>
using namespace std;

vector<long long> A, ST;

void build(int node, int L, int R) {
  if (L == R) {
    ST[node] = A[L];
  } else {
    int mid = (L + R) / 2;
    build(2 * node, L, mid);
    build(2 * node + 1, mid + 1, R);
    ST[node] = ST[2 * node] + ST[2 * node + 1];
  }
}

// Update for "set" operation (a[i] = val)
void update(int node, int L, int R, int idx, long long val) {
  if (L == R) {
    A[idx] = val;
    ST[node] = val;
  } else {
    int mid = (L + R) / 2;
    if (idx <= mid)
      update(2 * node, L, mid, idx, val);
    else
      update(2 * node + 1, mid + 1, R, idx, val);
    ST[node] = ST[2 * node] + ST[2 * node + 1];
  }
}

long long query(int node, int tl, int tr, int l, int r) {
  if (r < tl || tr < l)
    return 0; // out of range
  if (l <= tl && tr <= r)
    return ST[node]; // fully inside
  int tm = (tl + tr) / 2;
  return query(2 * node, tl, tm, l, r) + query(2 * node + 1, tm + 1, tr, l, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  A.resize(n);
  ST.resize(4 * n);

  for (int i = 0; i < n; i++)
    cin >> A[i];
  build(1, 0, n - 1);

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      long long v;
      cin >> i >> v;
      update(1, 0, n - 1, i, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l, r - 1) << "\n";
    }
  }
  return 0;
}
