#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m));
  vector<vector<ll>> aT(m, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  cout << m << " " << n << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      aT[j][i] = a[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << aT[i][j] << " ";
    }
    cout << endl;
  }
}
