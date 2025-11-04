#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1)
      res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return res;
}

int main() {
  long long n;
  cin >> n;
  cout << mod_pow(2, n, MOD) << '\n';
}
