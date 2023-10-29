#include <iostream>

using namespace std;

int main() {
  double num = 0, a;
  while (cin >> a) {
    num += a;
  }
  cout.precision(16);
  cout << num << "\n";
}
