#include <iostream>
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

  ll total_sum = n * (n + 1) / 2;

  ll arr_sum = 0;
  for (ll i = 1; i < n; ++i) {
    ll x;
    cin >> x;
    arr_sum += x;
  }

  cout << total_sum - arr_sum << '\n';
  return 0;
}