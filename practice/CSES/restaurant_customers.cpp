#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int n;
  cin >> n;
  vi arr(n), dep(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i] >> dep[i];
  }

  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());

  int i = 0, j = 0, currc = 0, maxc = 0;

  while (i < n and j < n) {
    if (arr[i] < dep[j]) {
      currc++;
      maxc = max(maxc, currc);
      i++;
    } else {
      currc--;
      j++;
    }
  }

  cout << maxc << '\n';
  return 0;
}