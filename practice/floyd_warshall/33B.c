/* https://codeforces.com/contest/33/problem/B
 *
 *
 * Problem Statement:
 * --------------------------------
 * Boy Valera likes strings. And even more he likes them, when they are
 * identical. That's why in his spare time Valera plays the following game. He
 * takes any two strings, consisting of lower case Latin letters, and tries to
 * make them identical. According to the game rules, with each move Valera can
 * change one arbitrary character Ai in one of the strings into arbitrary
 * character Bi, but he has to pay for every move a particular sum of money,
 * equal to Wi. He is allowed to make as many moves as he needs. Since Valera is
 * a very economical boy and never wastes his money, he asked you, an
 * experienced programmer, to help him answer the question: what minimum amount
 * of money should Valera have to get identical strings.
 *
 *
 * Input:
 * -------------------------------
 * The first input line contains two initial non-empty strings s and t,
 * consisting of lower case Latin letters. The length of each string doesn't
 * exceed 10^5. The following line contains integer n (0 ≤ n ≤ 500) — amount of
 * possible changings. Then follow n lines, each containing characters Ai and Bi
 * (lower case Latin letters) and integer Wi (0 ≤ Wi ≤ 100), saying that it's
 * allowed to change character Ai into character Bi in any of the strings and
 * spend sum of money Wi.
 *
 *
 * Output:
 * -------------------------------
 * If the answer exists, output the answer to the problem, and the resulting
 * string. Otherwise output -1 in the only line. If the answer is not unique,
 * output any.
 *
 * */

#include <stdio.h>
#include <string.h>
#define N 30
#define L 1000000 + 7
const int INF = 1 << 28;
int dist[N][N];
char s[L], t[L];

static inline int min(int a, int b) { return (a > b) ? b : a; }

void floyd_warshall() {
  for (int k = 0; k < 26; ++k)
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dist[i][j] = (i == j) ? 0 : INF;

  scanf("%s", s);
  scanf("%s", t);

  if (strlen(s) != strlen(t)) {
    printf("%d\n", -1);
    goto finish;
  }

  int n;
  scanf("%d", &n);

  char c1, c2, c3;
  int k;

  while (n--) {
    scanf(" %c %c %d", &c1, &c2, &k);

    int i = c1 - 'a', j = c2 - 'a';
    dist[i][j] = min(dist[i][j], k);
  }

  floyd_warshall();

  n = strlen(s);
  int cost = 0, mn;

  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      mn = INF, c3 = '#';

      for (int j = 'a'; j <= 'z'; ++j) {
        k = dist[s[i] - 'a'][j - 'a'] + dist[t[i] - 'a'][j - 'a'];
        if (k <= mn)
          mn = k, c3 = j;
      }

      cost += mn;
      s[i] = t[i] = c3;

      if (mn >= INF) {
        printf("%d\n", -1);
        goto finish;
      }
    }
  }

  printf("%d\n", cost);
  printf("%s\n", s);

finish:
  return 0;
}
