#include <iostream>
using namespace std;
using ll = long long;

#define fast_io                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);

int main(void) {
  fast_io ll t;

  for (cin >> t; t--;) {
    ll k, x;
    cin >> k >> x;

    cout << (x << k) << '\n';
  }

  return 0;
}
