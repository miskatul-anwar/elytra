#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

vector<int> dp(10e5, -1);

int fib(int n) {
  if (n == 1 || n == 0) {
    return n;
  }

  if (dp[n] != -1) {
    return dp[n];
  }

  return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  fast_io();
  int n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}