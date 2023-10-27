#include <iostream>

using namespace std;

int main() {
  int x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  int x0, y0;
  if (x1 > x2) {
    swap(x1, x2);
  }
  if (x3 > x4) {
    swap(x3, x4);
  }
  if (y1 > y2) {
    swap(y1, y2);
  }
  if (y3 > y4) {
    swap(y3, y4);
  }
  if (x2 <= x3) {
    x0 = 0;
  } else if (x3 <= x2 && x2 <= x4) {
    x0 = x2 - max(x1, x3);
  } else if (x4 < x2) {
    x0 = x4 - max(x1, x3);
  }
  if (y4 <= y1) {
    y0 = 0;
  } else if (y3 <= y2 && y2 <= y4) {
    y0 = y2 - max(y1, y3);
  } else if (y4 < y2) {
    y0 = y4 - max(y1, y3);
  }
  if (x0 < 0 || y0 < 0)
    cout << "0" << endl;
  else
    cout << x0 * y0 << endl;
}
