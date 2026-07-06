#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

ll forward_search(const vector<ll> &arr, ll n, ll l) {
  ll left = 0, right = n - 1, res = n;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (arr[mid] >= l) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}

ll backward_search(const vector<ll> &arr, ll n, ll r) {
  ll left = 0, right = n - 1, res = -1;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (arr[mid] <= r) {
      res = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return res;
}

int main() {
  fast_io();
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll &i : arr)
    cin >> i;

  sort(arr.begin(), arr.end());

  ll k;
  cin >> k;

  while (k--) {
    ll l, r;
    cin >> l >> r;
    ll a = forward_search(arr, n, l);
    ll b = backward_search(arr, n, r);

    if (a > b)
      cout << 0 << '\n';
    else
      cout << (b - a + 1) << '\n';
  }

  return 0;
}
