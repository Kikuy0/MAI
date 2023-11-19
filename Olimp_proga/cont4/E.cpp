#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

int main(void) {
  int n;
  ll a0, ai, m = (pow(10, 9) + 7), m1, m2;
  cin >> n >> a0;
  ai = a0 * 5 % m;
  m1 = ai;
  m2 = 0;
  for (int i = 2; i <= n; ++i) {
    ll save;
    save = ai;
    // cout << save << "\n"; // debug
    ai = save * 5 % m;
    if (ai > m1) {
      m2 = m1;
      m1 = ai;
    }
    if (m1 > ai > m2) {
      m2 = ai;
    }
  }
  cout << m2 << " " << m1 << "\n";
}
