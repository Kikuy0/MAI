#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

using ll = long long;

int main() {

  double a, h, ans, pi = 3.14159265359;
  cin >> a >> h;
  ans = (4 * pi * (h * h)) + (6 * pi * h * a) + (6 * (a * a));
  cout << setprecision(16);
  cout << ans << "\n";
}
