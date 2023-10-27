#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

struct item {
  string name;
  int s;
  int p;
};

bool Comp(item rhs, item lhs) {
  if (rhs.p != lhs.p) {
    return rhs.p > lhs.p;
  }
  if (rhs.s != lhs.s) {
    return rhs.s < lhs.s;
  } else {
    return rhs.name < lhs.name;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  cin >> N;
  vector<item> a(N);
  for (ll i = 0; i < N; ++i) {
    cin >> a[i].name >> a[i].p >> a[i].s;
  }
  sort(all(a), Comp);

  for (item elem : a) {
    cout << elem.name << endl;
  }
}
