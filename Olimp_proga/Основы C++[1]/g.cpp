#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2, r1, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  if ((r1 + r2) <= float(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)))) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
