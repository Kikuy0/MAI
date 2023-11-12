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
  float ans = 0, facc = 10;
  int i = 1;
  while (facc > acc) {
    facc = ((pow(x, 2 * i)) / fac(2 * i));
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
  int k, n;
  float x, acc;
  printf("Chose:\n1.By quantity\n2.By accuracy\n");
  scanf("%d", &k);
  switch (k) {
  case 1:
    scanf("%f%d", &x, &n);
    printf("%f\n", byQuantity(x, n));
    break;
  case 2:
    scanf("%f%f", &x, &acc);
    printf("%f", byAccuracy(x, acc));
    break;
  }

  // printf("%d\n", fac(k)); debug func(fac)
}
