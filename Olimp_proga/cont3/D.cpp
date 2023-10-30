#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll left = 0, right = n / (min(a, b));
  while (left < right) {
    ll mid = (left + right) / 2;
    if (((mid / a) + (mid / b) + 1) >= n) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << left + min(a, b) << "\n";
}
// 1 2 3 4 5 6 7
