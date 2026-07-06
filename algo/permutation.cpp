#include "bits/stdc++.h"
using namespace std;

vector<int> permutation;
vector<bool> chosen;
vector<int> v;
int n;

void search() {
  if ((int)permutation.size() == n) {
    for (int x : permutation)
      cout << x << " ";
    cout << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      if (chosen[i])
        continue;
      chosen[i] = true;
      permutation.push_back(v[i]);
      search();
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

int main() {
  v = {1, 2, 3};
  n = v.size();
  chosen.assign(n, false);

  search();
  return 0;
}
