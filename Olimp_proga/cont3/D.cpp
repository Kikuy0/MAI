#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll left = 0, right = (n * (max(a, b)));
  while (left < right) {
    ll t = ((left + right) / 2);
    if (((t / a) + (t / b) + 1) >= n) {
      right = t + 1;
    } else {
      left = t;
    }
  }
  cout << left + min(a, b) << "\n";
}
// 1 2 3 4 5 6 7
