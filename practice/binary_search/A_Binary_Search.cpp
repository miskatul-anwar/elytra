#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

  ll n, k;
  cin >> n >> k;

  vector<ll> arr(n);
  vector<ll> que(k);

  for (ll &i : arr) {
    cin >> i;
  }
  for (ll &q : que) {
    cin >> q;
  }

  for (ll q : que) {
    if (binary_search(arr.begin(), arr.end(), q)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}