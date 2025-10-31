#include <cstddef>
using namespace std;

int main(void) {
  const unsigned int n = 5;
  int matrix[5][5] = {{0, 1, 0, 0, 1},
                      {0, 0, 1, 0, 0},
                      {1, 0, 0, 0, 0},
                      {0, 1, 1, 0, 1},
                      {0, 0, 0, 0, 0}};

  int total_subgrids = 0;
  for (size_t a = 0; a < n; a++) {
    for (size_t b = a + 1; b < n; b++) {
      int count = 0;

      for (int i = 0; i < n; i++) {
        if (matrix[a][i] == 1 && matrix[b][i] == 1)
          count++;
      }
      total_subgrids += count * (count - 1) / 2;
    }
  }
}