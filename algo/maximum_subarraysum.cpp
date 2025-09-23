#include <algorithm>
#include <iostream>
using namespace std;
int main(void) {
  int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};
  int best = 0, sum = 0;

  for (int e : arr) {
    sum = max(e, sum + e);
    best = max(best, sum);
  }

  cout << best << '\n';
}