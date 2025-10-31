// A. K-divisible Sum
#include <iostream>
using namespace std;
using ll = long long;

int main(void) {
  ll t;
  cin >> t;

  while (t--) {
    ll n, k;
    cin >> n >> k;
    long long cf = (n + k - 1) / k;
    k *= cf;

    cout << (k + n - 1) / n << endl;
  }

  return 0;
}