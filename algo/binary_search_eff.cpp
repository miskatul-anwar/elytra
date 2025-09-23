#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &arr, int target) {
  int n = arr.size();
  int k = 0;

  for (int i = n / 2; i >= 1; i /= 2) {
    while (k + i < n && arr[k + i] <= target) {
      k += i;
    }
  }

  if (k < n && arr[k] == target) {
    return k;
  } else {
    return -1;
  }
}

int main(void) {
  vector<int> array = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

  int result = binary_search(array, 15);

  if (result != -1) {
    cout << "Element found at index: " << result << endl;
  } else {
    cout << "Element not found" << endl;
  }

  cout << '\n';
}