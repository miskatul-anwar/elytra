#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  size_t n = 5;
  vector<vector<int>> grid = {{3, 7, 9, 2, 7},
                              {9, 8, 3, 5, 5},
                              {1, 7, 9, 8, 5},
                              {3, 8, 6, 4, 10},
                              {6, 3, 9, 7, 8}};

  vector<vector<int>> sum = vector(n, vector(n, 0));

  // Initialize the first cell
  sum[0][0] = grid[0][0];
  //  Initialize the first row
  for (int j = 1; j < n; j++) {
    sum[0][j] = sum[0][j - 1] + grid[0][j];
  }
  //  Initialize the first column
  for (int i = 1; i < n; i++) {
    sum[i][0] = sum[i - 1][0] + grid[i][0];
  }
  //  Fill the rest

  for (int i = 1; i < 5; ++i) {
    for (int j = 1; j < 5; ++j) {
      sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
    }
  }

  cout << sum[4][4] << endl;
}