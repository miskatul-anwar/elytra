#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

const int INF = 1e9;
const long long LINF = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-9;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define el '\n'

int main() {
  FASTIO;
  int n;
  cin >> n;
  n *= 2;
  vector<int> people(n);

  for (int &i : people)
    cin >> i;

  sort(all(people));
  int min_stability = INF;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      vector<int> new_people;
      for (int p = 0; p < n; ++p)
        if (p != i && p != j)
          new_people.pb(people[p]);
      int total_instability = 0;
      for (int p = 0; p < n - 2; p += 2)
        total_instability += new_people[p + 1] - new_people[p];

      min_stability = min(min_stability, total_instability);
    }
  }

  cout << min_stability << el;
  return 0;
}