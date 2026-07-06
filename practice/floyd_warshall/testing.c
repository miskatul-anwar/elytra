#include <stdbool.h>
#include <stdio.h>
bool min(int n1, int n2);

int main(void) {
  int n1 = 2, n2 = 1;
  min(n1, n2);
  printf("Done?");
}

bool min(int n1, int n2) { return n1 > n2; };
