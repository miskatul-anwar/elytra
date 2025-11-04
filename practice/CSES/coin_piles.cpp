#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll t;
  cin >> t;

  while (t--) {
    ll a, b;
    cin >> a >> b;

    if (a <= 2 * b && b <= 2 * a && (a + b) % 3 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}