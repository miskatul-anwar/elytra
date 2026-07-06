/* https://cses.fi/problemset/task/1672

There are n cities and m roads between them. Your task is to process q queries
where you have to determine the length of the shortest route between two given
cities.


Input
The first input line has three integers n, m and q: the number of cities, roads,
and queries. Then, there are m lines describing the roads. Each line has three
integers a, b and c: there is a road between cities a and b whose length is c.
All roads are two-way roads. Finally, there are q lines describing the queries.
Each line has two integers a and b: determine the length of the shortest route
between cities a and b.

Output
Print the length of the shortest route for each query. If there is no route,
print -1 instead.


Example
Input:

4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
Output:

5
5
8
-1
3

*/

#include <stdio.h>

#define INF 1000000000000LL // Long long constant
#define MAX 500

long long graph[MAX][MAX];
long long dist[MAX][MAX];

void floyd_warshall(int n) {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);

  // Initialize the graph and distance matrix
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i == j)
        graph[i][j] = 0;
      else
        graph[i][j] = INF;

  // Input roads
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    scanf("%d %d %lld", &a, &b, &c);
    a--;
    b--; // Convert to 0-based index

    if (graph[a][b] > c) {
      graph[a][b] = c;
      graph[b][a] = c;
    }
  }

  // Copy graph to dist
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      dist[i][j] = graph[i][j];

  floyd_warshall(n);

  // Handle queries
  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--; // Convert to 0-based index
    if (dist[a][b] < INF)
      printf("%lld\n", dist[a][b]);
    else
      printf("-1\n");
  }

  return 0;
}
