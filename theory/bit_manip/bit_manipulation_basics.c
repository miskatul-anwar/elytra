#include <stdio.h>

int get(int num, int pos) {
  return (num >> pos) & 1;
}

int set(int num, int pos) {
  return num | (1 << pos);
}

int clear(int num, int pos) {
  return num & ~(1 << pos);
}

int toggle(int num, int pos) {
  return num ^ (1 << pos);
}

int update(int num, int pos, int val) {
  return (num & ~(1 << pos)) | (val << pos);
}

int clear_last_n_bits(int num, int n) {
    return num & (-1 << n);
}

int clear_range_bits(int num, int i, int j) {
  int a = (~0) << j + 1;
  int b = (1 << i) - 1;
  int mask = a | b
  n = n & mask;
  return n;
}

int count_set_bits(int num) {
  int count = 0;
  while (num) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

int is_power_of_two(int num) {
  return num && !(num & (num - 1));
}

int main() {
  int num, pos;
  scanf("%d %d", &num, &pos);
  return 0;
}
