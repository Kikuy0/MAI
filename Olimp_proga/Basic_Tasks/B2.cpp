#include <iostream>
#include <string>

using namespace std;

int main() {
  long long n, m, count = 0;
  string st1, st2;
  cin >> n >> m >> st1 >> st2;
  for (int i = 0; i <= n - m; ++i) {
    if (st1.substr(i, m) == st2) {
      count += 1;
    }
  }
  cout << count << "\n";
}
