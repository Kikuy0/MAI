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
  vector<ll> s_a = a;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(s_a));
  bool fl = true;
  for (int i = 0; i < n; ++i) {
    if (g > s_a[i]) {
      g += s_a[i];
    } else {
      fl = false;
      break;
    }
  }
  if (fl) {
    cout << "YES"
         << "\n";
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        if (s_a[i] == a[k]) {
          cout << k + 1 << " ";
        }
      }
    }
  } else {
    cout << "NO"
         << "\n";
  }
  cout << endl;
}
