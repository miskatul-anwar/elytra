#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll n;
  cin >> n;
  vll x(n);
  for (ll &i : x)
    cin >> i;

  vll cp = x;
  sort(x.begin(), x.end());

  ll cnt = 0;
  for (ll i = 0; i < n; i++)
    if (x[i] != cp[i])
      cnt++;

  cout << cnt - 1 << '\n';

  return 0;
}