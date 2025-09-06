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

static inline void solve() {
  Vector v;
  vec_init(&v, 4);
  vec_push(&v, 1);
  vec_push(&v, 2);
  vec_push(&v, 3);
  vec_push(&v, 4);
  vec_push(&v, 5);

  for (int i = 0; i < v.size; i++) {
    printf("%d\n", v.data[i]);
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