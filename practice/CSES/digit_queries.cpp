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

string s;
const ll k = 1e18;

void precompute() {
  for (ll i = 0; i < k; i++) {
    s += to_string(i);
  }
}

int main() {
  fast_io();
  precompute();

  ll t;
  cin >> t;
  while (t--) {
    ll q;
    cin >> q;

    cout << s[q] << endl;
  }

  return 0;
}