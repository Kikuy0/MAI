#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2, r1, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  float ds = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
  if ((ds < max(r1, r2))) {
    if ((ds + min(r1, r2)) >= max(r1, r2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (ds <= (r1 + r2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
