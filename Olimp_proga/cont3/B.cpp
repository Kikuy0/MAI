#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main() {
  ll n, g;
  cin >> n >> g;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  bool fl = true;
  for (int i = 0; i < n; ++i) {
    if (g > a[i]) {
      g += a[i];
    } else {
      fl = false;
      break;
    }
  }
  if (fl) {
    cout << "YES"
         << "\n";
    for (ll elem : a) {
      cout << elem << " ";
    }
  } else {
    cout << "NO"
         << "\n";
  }
  cout << endl;
}
