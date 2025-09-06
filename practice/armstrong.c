#include <math.h>
#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int sum = 0, originaln = n;

  while (n > 0) {
    int last_digit = n % 10;
    sum += pow(last_digit, 3);
    n /= 10;
  }

  for (int i = n; i > 0; i /= 10) {
    int last_digit = i % 10;
    sum += pow(last_digit, 3);
  }
}
