#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    q.push(m);
  }
  ll l1, l2;
  l1 = q.top();
  q.pop();
  while (!q.empty()) {
    l2 = q.top();
    q.pop();
    cout << l1 << " " << l2 << "\n";
    if ((l1 + l2) <= q.top()) {
      l1 += l2;
    } else {
      q.push(l1 + l2);
      l1 = q.top();
      q.pop();
    }
  }
}
