#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  string s;
  cin >> s;

  map<char, int> freq;
  for (char c : s) {
    freq[c]++;
  }

  string o;

  for (pair<char, int> k1 : freq) {
    for (pair<char, int> k2 : freq) {
      if (k1.second > 0) {
        o += k2.first;
        k2.second--;
      }
    }
  }

  return 0;
}