#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, g;
  cin >> n >> g;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(all(a));
  bool fl = true;
  for (int i = 0; i < n; ++i) {
    if (g > a[i].first) {
      g += a[i].first;
    } else {
      fl = false;
      break;
    }
  }
  if (fl) {
    cout << "YES"
         << "\n";
    for (int i = 0; i < n; ++i) {
      cout << a[i].second << " ";
    }
  } else {
    cout << "NO";
  }
  cout << endl;
}
