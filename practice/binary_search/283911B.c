#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const bool TEST_CASES = false;

typedef struct {
  int *data;
  int size;
  int capacity;
} Vector;

void vec_init(Vector *v, int capacity) {
  v->data = (int *)malloc(sizeof(int) * capacity);
  v->size = 0;
  v->capacity = capacity;
}

void vec_push(Vector *v, int val) {
  if (v->size == v->capacity) {
    v->capacity *= 2;
    v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);
  }
  v->data[v->size++] = val;
}

void vec_free(Vector *v) { free(v->data); }

int closest_left(int *arr, int n, int key) {
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (arr[m] <= key) {
      ans = m;   // candidate index
      l = m + 1; // search right
    } else {
      r = m - 1;
    }
  }
  return ans; // -1 if none
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);

  Vector v;
  vec_init(&v, n);

  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);

    vec_push(&v, val);
  }

  for (int i = 0; i < k; i++) {
    int q, idx = -1;
    scanf("%d", &q);

    idx = closest_left(v.data, n, q);

    printf("%d\n", idx == -1 ? 0 : idx + 1); // 1-based index, 0 if none
  }

  vec_free(&v);
}

int main() {
  if (TEST_CASES) {
    int t;
    if (scanf("%d", &t) != 1)
      return 1;
    while (t--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
