#include <iostream>

using namespace std;

int main() {
  int x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  int count = 0;
  for (int x0 = -100; x0 <= 100; ++x0) {
    for (int y0 = -100; y0 <= 100; ++y0) {
      if (((min(x1, x2) < x0) && (x0 <= max(x1, x2))) ||
          ((min(x3, x4) < x0) && (x0 <= max(x3, x4)))) {
        if (((min(y1, y2) < y0) && (y0 <= max(y1, y2))) ||
            ((min(y3, y4) < y0) && (y0 <= max(y3, y4)))) {
          count++;
        }
      }
    }
  }
  cout << count << "\n";
}
