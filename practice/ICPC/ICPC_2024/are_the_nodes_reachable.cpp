#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << 1 << ':' << '\n';
    int n, m;
    cin >> n >> m;
    int graph[n + 1][n + 1];
    memset(graph, 0, sizeof(graph));
    for (; m--;) {
      int u, v;
      cin >> u >> v;
      graph[u][v] = 1;
    }

    int q;
    for (; q--;) {
      int u, v;
      cin >> u >> v;
      if (graph[u][v] == 1) {
        cout << 0 << '\n';
      } else {
        cout << 1 << '\n';
      }
    }
  }
  return 0;
}