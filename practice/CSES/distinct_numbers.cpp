#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
using namespace std;

using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll n;
  cin >> n;
  set<ll> s;

  while (n--) {
    ll i;
    cin >> i;
    s.insert(i);
  }

  cout << s.size() << '\n';
  return 0;
}