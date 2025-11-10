#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

using ll = long long;
using vll = vector<ll>;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll n, x;
  cin >> n >> x;
  vll a(n);
  for (ll &i : a) {
    cin >> i;
  }

  vll copy = a;

  sort(a.begin(), a.end());

  ll i = 0, j = n - 1, x1 = 0, x2 = 0;
  bool found = false;
  while (i < j) {
    ll sum = a[i] + a[j];
    if (sum == x) {
      found = true;
      x1 = a[i], x2 = a[j];
      break;
    } else if (sum > x) {
      j--;
    } else {
      i++;
    }
  }

  if (found) {
    ll idx1 = -1, idx2 = -1;

    for (ll k = 0; k < n; k++) {
      if (copy[k] == x1 && idx1 == -1)
        idx1 = k;
      else if (copy[k] == x2 && idx2 == -1)
        idx2 = k;
    }

    if (idx1 < idx2) {
      cout << idx1 + 1 << ' ' << idx2 + 1 << '\n';
    } else {
      cout << idx2 + 1 << ' ' << idx1 + 1 << '\n';
    }

  } else {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}