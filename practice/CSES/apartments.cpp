#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n), b(m);
  for (ll &x : a)
    cin >> x;
  for (ll &x : b)
    cin >> x;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll i = 0, j = 0, cnt = 0;

  while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= k) {
      // Applicant i gets apartment j
      cnt++;
      i++;
      j++;
    } else if (b[j] < a[i] - k) {
      // Apartment too small -> try a larger one
      j++;
    } else {
      // Apartment too large -> try next applicant
      i++;
    }
  }

  cout << cnt << '\n';
  return 0;
}
