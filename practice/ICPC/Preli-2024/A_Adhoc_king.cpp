#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<long long>;

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
    for (ll i = 2, cnt = 1; i <= 3 * n && cnt <= n; i += 2, cnt++)
      cout << i << ' ';
    cout << endl;
  }
  return 0;
}