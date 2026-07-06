#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int> &arr, int n, int q) {
  int left = 0, right = n - 1, res = n + 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] >= q) {
      res = mid + 1;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return res;
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);

  for (int &i : arr) {
    cin >> i;
  }

  while (k--) {
    int q;
    cin >> q;

    cout << bin_search(arr, n, q) << '\n';
  }

  return 0;
}