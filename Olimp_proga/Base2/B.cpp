#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll n, fac = 1;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    fac *= i;
  }
  cout << ((fac) % (1000000007)) << endl;
}
