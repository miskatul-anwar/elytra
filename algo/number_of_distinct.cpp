#include <bits/stdc++.h>
#include <unordered_set>
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
using usi = std::unordered_set<int>;
using namespace std;

int main() {
  FAST_IO;
  vi v = {1, 2, 3, 2, 1, 4, 5};
  usi distinct_elements(v.begin(), v.end());
  cout << "Number of distinct elements: " << distinct_elements.size() << endl;
  return 0;
}