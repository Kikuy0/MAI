#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l, r;
  while (true) {
    cin >> l >> r;
    if (l == r == 0) {
      break;
    }
    reverse(a.begin() + l - 1, a.end() + r - 1);
  }
  for (ll elem : a) {
    cout << elem << " ";
  }
  cout << endl;
  return 0;
}
