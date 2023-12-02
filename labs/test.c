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
    ans+=xn;
    if(xn<0)xn=xn*(-1);
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
  int k, n , unit;
  double x, acc;
  printf("Chose:\n1.По числу членов;\n2.С заданной точностью\n");
  scanf("%d", &k);
  switch (k) {
  case 1:
    scanf("%lf%d", &x, &n);
    if(x<0)x*=(-1);
    unit = x / (2*pi);
    x-=unit*(2*pi);
    printf("x before %f \n",x);
    if(x<=pi/2){
        printf("%f \n",x);
        printf("%f\n", byQuantity(x, n));
    }
    if(x>pi/2 && x < pi){
        printf("%f \n",x);
        printf("%f\n", (-1)*byQuantity(pi-x, n));
    }
    if(x>pi && x < 3*pi/2){
        double offset = x - pi;
        x = pi - offset;
        printf("%f \n",x);
        printf("%f\n", (-1)*byQuantity(pi-x, n));
    }
    if(x > 3*pi/2){
        double offset = 2*pi-x;
        x = offset;
        printf("%f \n",x);
        printf("%f\n", byQuantity(x, n));
    }
    break;
  case 2:
    scanf("%lf%lf", &x, &acc);
    if(x<0)x*=(-1);
    unit = x / (2*pi);
    x-=unit*(2*pi);
    printf("x before %f \n",x);
    if(x<=pi/2){
        printf("%f \n",x);
        printf("%f\n", byAccuracy(x, acc));
    }
    if(x>pi/2 && x < pi){
        printf("%f \n",x);
        printf("%f\n", (-1)*byAccuracy(pi-x, acc));
    }
    if(x>pi && x < 3*pi/2){
        double offset = x - pi;
        x = pi - offset;
        printf("%f \n",x);
        printf("%f\n", byAccuracy(x, acc));
    }
    if(x > 3*pi/2){
        double offset = 2*pi-x;
        x = offset;
        printf("%f \n",x);
        printf("%f\n", byAccuracy(x, acc));
    }
    break;
  }

}