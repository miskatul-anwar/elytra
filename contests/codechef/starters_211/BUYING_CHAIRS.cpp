#include <bits/stdc++.h>
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
  ll t;
  cin >> t;

  while (t--) {
    ll w, p, k;
    cin >> w >> p >> k;

    ll s = 0;
    while (k--) {
      if (w) {
        w--;
        s += 2;
      } else if (p) {
        p--;
        s += 1;
      }
    }

    cout << s << '\n';
  }
  return 0;
}