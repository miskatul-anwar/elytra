#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays a[l..m] and a[m+1..r]
void merge(vector<int> &a, int l, int m, int r) {
  vector<int> left(a.begin() + l, a.begin() + m + 1);
  vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

  int i = 0, j = 0, k = l;
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j])
      a[k++] = left[i++];
    else
      a[k++] = right[j++];
  }
  while (i < left.size())
    a[k++] = left[i++];
  while (j < right.size())
    a[k++] = right[j++];
}

void merge_sort(vector<int> &a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  vector<int> a = {5, 4, 3, 2, 1};
  merge_sort(a, 0, a.size() - 1);
  for (int x : a)
    cout << x << " ";
  cout << endl;
  return 0;
}