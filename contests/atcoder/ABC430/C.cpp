#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();

  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  int cnt = 0;

  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      int as = 0, bs = 0;
      for (int i = l; i <= r; i++) {
        if (s[i] == 'a')
          as++;
        else
          bs++;
      }
      if (as >= a && bs < b)
        cnt++;
    }
  }

  cout << cnt << '\n';
  return 0;
}