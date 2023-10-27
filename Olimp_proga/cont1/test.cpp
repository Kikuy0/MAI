#include <iostream>
using namespace std;

int main() {
  int x1, x2;
  cin >> x1 >> x2;
  if (x1 > x2) {
    swap(x1, x2);
  }
  cout << x1 << x2 << "\n";
}
