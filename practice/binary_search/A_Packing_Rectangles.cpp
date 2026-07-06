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

inline bool canfit(ll x, ll w, ll h, ll n) { return (x / w) * (x / h) >= n; }

int main() {
  fast_io();

  ll w, h, n;
  cin >> w >> h >> n;

  ll left = 0, right = 1;
  while (!canfit(right, w, h, n)) {
    right *= 2;
  }

  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (canfit(mid, w, h, n)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << left << '\n';

  return 0;
}