/* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
 */

/**
 * @author: miskatul-anwar
 * @date: 2025-08-27 06:41:04 UTC
 * @problem: A. Binary Search
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define ull unsigned long long
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f

bool binary_search(int arr[], int size, int target) {
  int left = 0, right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
      return true;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return false;
}

static inline void solve(int n, int k) {
  int arr[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  while (k--) {
    int q;
    scanf("%d", &q);

    printf("%s\n", (binary_search(arr, n, q) ? "YES" : "NO"));
  }
}

int main() {
  int n, k;

  scanf("%d %d", &n, &k);

  solve(n, k);

  return 0;
}
