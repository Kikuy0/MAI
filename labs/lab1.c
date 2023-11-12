#include <math.h>
#include <stdio.h>

int fac(int x) {
  long long ans = 1;
  for (int i = 1; i <= x; ++i) {
    ans *= i;
  }
  return ans;
}

float byAccuracy(float x, float acc) {
  float ans = 0;
  int i = 1;
  while (ans < acc) {
    ans += pow((-1), i) * ((pow(x, 2 * i)) / fac(2 * i));
    ++i;
  }
  return ans;
}

float byQuantity(float x, int n) {
  float ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += pow((-1), i) * ((pow(x, 2 * i)) / fac(2 * i));
  }
  return ans;
}

int main(void) {
  float x;
  int n, k;
  scanf("%f%d", &x, &n);
  printf("%f\n", byQuantity(x, n));
  // printf("%d\n", fac(k)); debug func(fac)
}
