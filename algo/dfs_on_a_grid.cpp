#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int n, m;
  vector<vector<bool>> vis;

  bool isValid(int x, int y, vector<vector<char>> &grid) {
    // Check if out of bounds
    if (x < 0 || x >= n || y < 0 || y >= m)
      return false;

    // Check if already visited or water
    if (vis[x][y] || grid[x][y] == '0')
      return false;

    return true;
  }

  void dfs(int x, int y, vector<vector<char>> &grid) {
    vis[x][y] = true;

    // Explore 4 directions
    if (isValid(x - 1, y, grid))
      dfs(x - 1, y, grid); // up
    if (isValid(x, y + 1, grid))
      dfs(x, y + 1, grid); // right
    if (isValid(x + 1, y, grid))
      dfs(x + 1, y, grid); // down
    if (isValid(x, y - 1, grid))
      dfs(x, y - 1, grid); // left
  }

  int numIslands(vector<vector<char>> &grid) {
    n = grid.size();
    if (n == 0)
      return 0;
    m = grid[0].size();

    vis.assign(n, vector<bool>(m, false));

    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1' && !vis[i][j]) {
          dfs(i, j, grid);
          count++;
        }
      }
    }

    return count;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};

  cout << "Number of islands: " << sol.numIslands(grid) << endl;
  return 0;
}
