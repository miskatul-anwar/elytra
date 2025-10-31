#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

unsigned int hamming_dist(string s1, string s2, size_t n) {
  unsigned int dist = 0;

  for (size_t i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
      dist++;
    }
  }

  return dist;
}

unsigned int hamming_dist_opt(int s1, int s2) {
  unsigned int dist = __builtin_popcount(s1 ^ s2);
  return dist;
}

int main(void) {
  string s1 = "0110", s2 = "1001";
  int s1n = 0b0110, s2n = 0b1001;
  size_t n = 4;
  cout << hamming_dist(s1, s2, n) << '\n';
  cout << hamming_dist_opt(s1n, s2n) << '\n';
  return 0;
}