#include <bits/stdc++.h>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int n, m;
  if (!(cin >> n >> m))
    return 0;

  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    ++cnt[h];
  }

  while (m--) {
    int t;
    cin >> t;
    auto it = cnt.upper_bound(t);
    if (it == cnt.begin()) {
      cout << -1 << '\n';
    } else {
      --it;
      cout << it->first << '\n';
      if (--(it->second) == 0)
        cnt.erase(it);
    }
  }
  return 0;
}