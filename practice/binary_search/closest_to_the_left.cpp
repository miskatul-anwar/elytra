#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int> &arr, int n, int q) {
  int left = 0, right = n - 1, ans = 0;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] <= q) {
      ans = mid + 1;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return ans;
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
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