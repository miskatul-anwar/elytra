#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main() {
  fast_io();
  ll n;
  cin >> n;
  cout << n << ' ';

  while (n != 1) {
    (n % 2 == 0) ? n /= 2 : n = n * 3 + 1;
    cout << n << ' ';
  }

  cout << '\n';

  return 0;
}