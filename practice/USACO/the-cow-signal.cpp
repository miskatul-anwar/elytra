#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char mat[10][10];
char matk[100][100];

int main(void) {
  int m, n, k;
  cin >> m >> n >> k;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  // Loop through top left corner of each "pixel"
  for (int i = 0; i < m * k; i += k) {
    for (int j = 0; j < n * k; j += k) {

      // Copy the single character from original into each of these.
      for (int a = 0; a < k; a++)
        for (int b = 0; b < k; b++)
          matk[i + a][j + b] = mat[i / k][j / k];
    }
  }

  for (int i = 0; i < m * k; ++i) {
    for (int j = 0; j < n * k; ++j) {
      cout << matk[i][j];
    }
    cout << endl;
  }

  return 0;
}