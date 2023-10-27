#include <iostream>

using namespace std;

int main() {
  int x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  int count = 0;
  if (x1 > x2)
    swap(x1, x2);
  if (x3 > x4)
    swap(x3, x4);
  if (y1 > y2)
    swap(y1, y2);
  if (y3 > y4)
    swap(y3, y4);
  for (int x0 = -100; x0 <= 100; ++x0) {
    for (int y0 = -100; y0 <= 100; ++y0) {
      if (((x1 <= x0) && (x0 < x2) && (y1 <= y0) && (y0 < y2)) ||
          ((x3 <= x0) && (x0 < x4) && (y3 <= y0) && (y0 < y4))) {
        count++;
      }
    }
  }
  cout << count << "\n";
}
