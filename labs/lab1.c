#include <math.h>
#include <stdio.h>

int fac(int x) {
  long long ans = 1;
  for (int i = 1; i <= x; ++i) {
    ans *= i;
  }
  return ans;
}

static double byAccuracy(float x, float acc) {
  double ans = 0, facc = 10000000;
  int i = 1;
  while (facc > acc) {
    facc = ((pow(x, 2 * i)) / fac(2 * i));
    ans += pow((-1), i) * ((pow(x, 2 * i)) / fac(2 * i));
    ++i;
  }
  return ans;
}

static double byQuantity(float x, int n) {
  float ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += pow((-1), i) * ((pow(x, 2 * i)) / fac(2 * i));
  }
  return ans;
}

int main(void) {
  int k, n;
  double x, acc;
  printf("Chose:\n1.По числу членов;\n2.С заданной точностью\n");
  scanf("%d", &k);
  switch (k) {
  case 1:
    scanf("%lf%d", &x, &n);
    printf("%f\n", byQuantity(x, n));
    break;
  case 2:
    scanf("%lf%lf", &x, &acc);
    printf("%lf", byAccuracy(x, acc));
    break;
  }

  // printf("%d\n", fac(k)); debug func(fac)
}
