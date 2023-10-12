#include <iostream>

using namespace std;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int p = 1;
  if (n % x != 0) {
    p *= (n / x) + 1;
  } else {
    p *= n / x;
  }
  if (m % y != 0) {
    p *= (m / y) + 1;
  } else {
    p *= (m / y);
  }
  cout << p << "\n";
}
