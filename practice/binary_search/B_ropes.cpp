#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  double left = 0, right = 1e7;

  for (int iter = 0; iter < 100; ++iter) {
    double mid = (left + right) / 2;
    int pieces = 0;
    for (int i = 0; i < n; ++i) {
      pieces += int(a[i] / mid);
    }
    if (pieces >= k)
      left = mid;
    else
      right = mid;
  }
  cout << fixed << setprecision(10) << left << "\n";
  return 0;
}