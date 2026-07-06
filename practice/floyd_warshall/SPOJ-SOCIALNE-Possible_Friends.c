/* https://www.spoj.com/problems/SOCIALNE

Josué, one of the undergraduate students in PUCMM, is developing a Social
Network, but he is having difficulties in identifying the person that has more
possible friends. Two persons are possible friends if they are not friends and
they have at least one common friend, for example if person A is friend only to
person B, and person B is friend of C, then, A and C are possible friends. You
are about to help him in this task. Given the network table, you have to write a
program that finds the person that has more possible friends, if more than one
person matches this criteria, then select the one that comes first ( the one
that has the lower ID).

Input
The first line is T (1 ≤ T ≤ 1,000), the number of test cases, then T test cases
follow.

Each test case consists in a 'Y' or 'N' square matrix (M x M) representing the
friendship of the network, where M is the number of persons.

Constraints
M (1 ≤ M ≤ 50)

The square matrix has M lines, each line has M characters.

The first line of the matrix corresponds to person 0, the next line to person 1,
and so on.

On each line the leftmost character corresponds to person 0, the next character
to person 1, and so on.

So if character j of the line i is 'Y', it means that person 'i' is a friend of
'j'.

For each person i, character i of line i will be 'N'.

For each i,j character j of line i will be the same as character i of line j.

Output
For each test case, you have to output one line containing the ID of the
person(0-based) that has more possible friends and the number of possible
friends this person has, separated by a blank space.

*/

#include <stdio.h>
#include <string.h>

const int INF = 1000000000;
int dist[50][50];

void input(int row, char line[], int m);
void floyd_warshall(int v);
static inline int min(int a, int b);

int main(void) {
  int t;
  scanf("%d", &t);

  while (t--) {
    char line[55];
    scanf("%s", line);

    int m = strlen(line);
    input(0, line, m);

    for (int i = 1; i < m; ++i) {
      scanf("%s", line);
      input(i, line, m);
    }

    floyd_warshall(m);

    int max_possiblefriend = 0, min_id = 0;

    for (int i = 0; i < m; ++i) {
      int cnt = 0;
      for (int j = 0; j < m; ++j) {
        if (i != j && dist[i][j] == 2) {
          cnt++;
        }
      }
      if (cnt > max_possiblefriend) {
        max_possiblefriend = cnt;
        min_id = i;
      }
    }

    printf("%d %d\n", min_id, max_possiblefriend);
  }
  return 0;
}

static inline int min(int a, int b) { return (a < b) ? a : b; }

void input(int row, char line[], int m) {
  for (int col = 0; col < m; ++col) {
    if (row == col) {
      dist[row][col] = 0;
    } else if (line[col] == 'N') {
      dist[row][col] = INF;
    } else {
      dist[row][col] = 1;
    }
  }
}

void floyd_warshall(int v) {
  for (int k = 0; k < v; ++k) {
    for (int i = 0; i < v; ++i) {
      for (int j = 0; j < v; ++j) {
        if (dist[i][k] < INF && dist[k][j] < INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}
