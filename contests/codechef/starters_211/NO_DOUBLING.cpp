#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
    vll a(n);
    for (ll &i : a)
      cin >> i;

    sort(a.begin(), a.end(), greater<ll>());

    for (ll i : a) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}