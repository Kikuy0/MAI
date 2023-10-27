#include <iostream>
using namespace std;

int main() {
  long long R, C;
  cin >> R >> C;
  if (R < C) {
    cout << "2\n";
  }
  if (R >= C) {
    cout << "1\n";
  }
}
