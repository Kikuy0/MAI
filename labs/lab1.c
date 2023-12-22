// ВАРИАНТ - 9
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define pi 3.141592653589793

int fac(int x) {
  unsigned long long ans = 1;
  for (int i = 1; i <= x; ++i) {
    ans *= i;
  }
  return ans;
}

static double byAccuracy(float x, float acc) {
  double ans = 0;
  double xn = 1000;
  for (int i = 0; xn >= acc; ++i) {
    xn = pow((-1), i) * ((pow(x, 2 * i)) / fac(2 * i));
    ans += xn;
    if (xn < 0)
      xn = xn * (-1);
  }
  return ans;
}

static double byQuantity(float x, int n) {
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += pow((-1), i) * ((pow(x, 2 * i)) / fac(2 * i));
  }
  return ans;
}

int main(void) {
  int k, n, unit, err;
  double x, acc;
  printf("---Cos(X)---\n");
  printf("Choose:\n1.По числу членов\n2.С заданной точностью\n");
  if ((scanf("%d", &k) != 1) || (k > 2) || (k < 1)) {
    printf("Неверный ввод.\n");
    return 0;
  }
  switch (k) {
  case 1:
    printf("Введите X и число членов через пробел:");
    err = scanf("%lf%d", &x, &n);
    // printf("x - %lf  n - %d\n", x, n); // debug
    // fflush(stdin);
    if (!isdigit(n)) {
      printf("Неверный ввод\n");
      return 0;
    }
    printf("Ответ: ");
    if (x < 0)
      x *= (-1);
    unit = x / (2 * pi);
    x -= unit * (2 * pi);
    // printf("x before %f \n",x);
    if (x <= pi / 2) {
      // printf("%f \n", x);
      printf("%f\n", byQuantity(x, n));
    }
    if (x > pi / 2 && x < pi) {
      // printf("%f \n", x);
      printf("%f\n", (-1) * byQuantity(pi - x, n));
    }
    if (x > pi && x < 3 * pi / 2) {
      double offset = x - pi;
      x = pi - offset;
      // printf("%f \n", x);
      printf("%f\n", (-1) * byQuantity(pi - x, n));
    }
    if (x > 3 * pi / 2) {
      double offset = 2 * pi - x;
      x = offset;
      // printf("%f \n", x);
      printf("%f\n", byQuantity(x, n));
    }
    break;
  case 2:
    printf("Введите X и точность(чем ниже указанная точность,тем дальше ответ "
           "от истинны) через пробел:");
    err = scanf("%lf%lf", &x, &acc);
    // fflush(stdin);
    // if (err != 1) {
    //   printf("Неверный ввод\n");
    //   return 0;
    // }
    if (x < 0)
      x *= (-1);
    unit = x / (2 * pi);
    x -= unit * (2 * pi);
    // printf("x before %f \n",x);
    if (x <= pi / 2) {
      // printf("%f \n", x);
      printf("%f\n", byAccuracy(x, acc));
    }
    if (x > pi / 2 && x < pi) {
      // printf("%f \n", x);
      printf("%f\n", (-1) * byAccuracy(pi - x, acc));
    }
    if (x > pi && x < 3 * pi / 2) {
      double offset = x - pi;
      x = pi - offset;
      // printf("%f \n", x);
      printf("%f\n", byAccuracy(x, acc));
    }
    if (x > 3 * pi / 2) {
      double offset = 2 * pi - x;
      x = offset;
      // printf("%f \n", x);
      printf("%f\n", byAccuracy(x, acc));
    }
    break;
  }
}
