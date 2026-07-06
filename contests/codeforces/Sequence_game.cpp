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
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vll a(n);

    for (ll &i : a) {
      cin >> i;
    }

    ll x;
    cin >> x;

    ll i = 0, found = 0;
    while (i + 1 < n) {
      if (min(a[i], a[i + 1]) <= x && x <= max(a[i], a[i + 1])) {
        found = 1;
        break;
      }
      i++;
    }

    cout << (found ? "YES" : "NO") << '\n';
  }

  return 0;
}