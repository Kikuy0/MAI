#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, ans = -1;
  cin >> n;
  int i = 1;
  vector<ll> a(2);
  a[1] = 1;
  if (n == 0) {
    cout << "0" << endl;
  } else if (n == 1) {
    cout << "1" << endl;
  } else {
    while (a[i] < n) {
      ++i;
      a.push_back(a[i - 2] + a[i - 1]);
    }
    if (a[i] == n) {
      cout << i << "\n";
    } else {
      cout << "-1"
           << "\n";
    }
  }
}
