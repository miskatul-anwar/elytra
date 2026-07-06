#include <bits/stdc++.h>
#include <iostream>
#include <string>
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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll safe = 0;

    for (char c : s) {
      if (c == '0') {
        safe++;
      } else {
        break;
      }
    }

    cout << safe << '\n';
  }
  return 0;
}