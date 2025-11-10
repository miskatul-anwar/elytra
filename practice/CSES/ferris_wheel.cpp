#include <algorithm>
#include <iostream>
#include <vector>
int main(void) {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> w(n);
  for (int &i : w)
    std::cin >> i;
  std::sort(w.begin(), w.end());

  int i = 0, j = n - 1, cnt = 0;

  while (i <= j) {
    if (w[i] + w[j] <= x) {
      i++, j--; /* pair of lightest + heaviest child */
    } else {
      j--; /* Haviest Child Goes Alone */
    }
    cnt++;
  }

  std::cout << cnt << '\n';

  return 0;
}