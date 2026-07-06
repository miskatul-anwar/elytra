#include <iostream>
using namespace std;

using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
// Number of copies in 'mid' seconds (excluding the first copy)
// n-1 because the first copy is made separately
bool is_valid(ll m, ll x, ll y, ll n) { return (m / x) + (m / y) >= n - 1; }

int main() {
  fast_io();
  ll n, x, y;
  cin >> n >> x >> y;

  if (n == 1) {
    cout << min(x, y) << "\n";
    return 0;
  }

  ll left = 0, right = 1e18;
  ll ans = 0;

  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (is_valid(mid, x, y, n)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  // Add the time to make the very first copy (min(x, y))
  cout << ans + min(x, y) << "\n";
  return 0;
}