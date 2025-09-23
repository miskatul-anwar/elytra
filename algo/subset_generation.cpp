#include <cstddef>
#include <iostream>
#include <vector>
using vi = std::vector<int>;
using namespace std;

int main(void) {
  vi v = {1, 2, 3};
  size_t n = v.size();

  vector<vector<int>> subsets;

  for (int i = 0; i < (1 << n); i++) {
    vi subset;

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        subset.push_back(v[j]);
      }
    }

    subsets.push_back(subset);
  }

  for (const auto &subset : subsets) {
    cout << "{ ";
    for (const auto &elem : subset) {
      cout << elem << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}