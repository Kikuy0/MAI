#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll m = 0;
  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      m = max(a[i][j], m);
    }
    sort(all(a[i]));
  }
  sort(all(a));
  /*
  for (vector elem : a) {
    for (ll elem1 : elem) {
      cout << elem1 << " ";
    }
    cout << "\n";
  }
  */
  ll c = min(a[0][1], a[1][0]) - a[0][0];
  ll d = (m - a[0][0] - ((n - 1) * c)) / (n - 1);
  cout << c << " " << d << "\n";
}
