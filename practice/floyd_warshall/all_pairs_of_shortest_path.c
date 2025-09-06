/* https : // open.kattis.com/problems/allpairspath */
#include <stdio.h>
const int INF = 1 << 28;

int graph[500][500];

void floyd_warshall(int n);

int main(void) {
  while (1) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    if (n == 0 && m == 0 && q == 0)
      break;

    // Initialize graph
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        graph[i][j] = (i == j) ? 0 : INF;

    // Read edges
    while (m--) {
      int a, b, e;
      scanf("%d %d %d", &a, &b, &e);
      if (graph[a][b] > e)
        graph[a][b] = e;
    }

    // Run Floyd-Warshall and negative cycle detection
    floyd_warshall(n);

    // Process queries
    while (q--) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (graph[a][b] == -INF)
        printf("-Infinity\n");
      else if (graph[a][b] == INF)
        printf("Impossible\n");
      else
        printf("%d\n", graph[a][b]);
    }

    printf("\n");
  }

  return 0;
}

void floyd_warshall(int n) {
  // Floyd-Warshall main loop
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (graph[i][k] < INF && graph[k][j] < INF &&
            graph[i][j] > graph[i][k] + graph[k][j])
          graph[i][j] = graph[i][k] + graph[k][j];

  // Detect negative cycles that affect reachable paths
  for (int k = 0; k < n; ++k) {
    if (graph[k][k] < 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (graph[i][k] < INF && graph[k][j] < INF)
            graph[i][j] = -INF;
        }
      }
    }
  }
}
