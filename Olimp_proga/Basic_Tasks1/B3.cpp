#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(m, vector<ll>(n));
  vector<vector<ll>> aT(n, vector<ll>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; i < m; ++i) {
      cin >> a[j][i];
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++i) {
      cout << a[i][j] << "\n";
    }
  }
}
