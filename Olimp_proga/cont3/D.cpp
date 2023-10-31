#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll n;
  int a, b;
  cin >> n >> a >> b;          // 3 1 1
  ll l = 0, r = (n * (a + b)); // l = 0 r = 6
  while (l < r) {
    ll t = (l + r) / 2; // t = 1
    // cout << l << r << t; -- debug
    if (((t / a) + (t / b)) >= (n - 1)) { //
      r = t;                              //  r = 1
    } else {
      l = t + 1; // = 0
    }
  }
  cout << l + min(a, b) << endl;
}
