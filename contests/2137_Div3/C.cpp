#include <iostream>
using namespace std;
using ll = long long;

#define FAST                                                                   \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);

int main() {
  FAST;

  int t;

  for (cin >> t; t--;) {
    ll a, b;
    cin >> a >> b;

    if (b % 2 != 0) {
      if (a % 2 != 0) {
        cout << a * b + 1 << "\n";
      } else {
        cout << -1 << "\n";
      }
      continue;
    }

    ll bb = b;
    int z = 0;
    while (bb % 2 == 0) {
      bb /= 2;
      ++z;
    }

    if ((a % 2 != 0) && z == 1) {
      cout << -1 << "\n";
      continue;
    }

    ll kmin = (a % 2 != 0) ? 2 : 1;
    ll s1 = a * kmin + b / kmin;
    ll s2 = a * (b / 2) + 2;

    cout << max(s1, s2) << "\n";
  }

  return 0;
}
