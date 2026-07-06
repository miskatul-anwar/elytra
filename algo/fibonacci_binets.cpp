#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#define FAST_IO                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)
using ll = long long;
using vi = std::vector<int>;
using pi = std::pair<int, int>;
using namespace std;

ll fibonacci(ll n) {
  double sqrt_5 = sqrt(5);
  ll fib =
      (pow(1.00 + sqrt_5, n) - pow(1.00 - sqrt_5, n)) / ((1 << n) * sqrt_5);
  return fib;
}

int main() {
  FAST_IO;
  ll n;
  cin >> n;
  cout << fibonacci(n) << "\n";

  return 0;
}