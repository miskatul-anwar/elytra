#include <bits/stdc++.h>
#include <vector>
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

ll concat(int a, int b) {
  long long t = 10;
  while (t <= b)
    t *= 10;
  return a * t + b;
}

int main() {
  FAST_IO;
  int t;
  cin >> t;

  while (t--) {
    ll x;
    cin >> x;

    ll y = 1;

    while (concat(x, y) % (x + y) != 0) {
      y++;
    }

    cout << y << "\n";
  }
}