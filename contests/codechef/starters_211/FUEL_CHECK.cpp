#include <iostream>
using namespace std;

using ll = long long;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  ll x, y;
  cin >> x >> y;
  if (x * y >= 100) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}