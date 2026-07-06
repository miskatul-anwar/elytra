#include <bits/stdc++.h>
#include <cmath>
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << ((c >= a && d < b) ? "Yes\n" : "No\n");

  return 0;
}