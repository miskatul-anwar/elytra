#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> b(n);
    unordered_map<int, vector<int>> freq_map;

    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      freq_map[b[i]].push_back(i);
    }

    vector<int> a(n, 0);
    int current_value = 1;
    bool possible = true;

    for (auto &[f, indices] : freq_map) {
      if (indices.size() % f != 0) {
        possible = false;
        break;
      }

      for (size_t i = 0; i < indices.size(); i += f) {
        for (int j = 0; j < f; ++j) {
          a[indices[i + j]] = current_value;
        }
        ++current_value;
      }
    }

    if (!possible) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}
