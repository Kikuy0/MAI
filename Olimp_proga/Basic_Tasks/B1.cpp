#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long summ = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    summ += x;
  }
  cout << summ << "\n";
}
