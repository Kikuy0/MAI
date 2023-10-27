#include <algorithm>
#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    int n, count = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        if (p[j] > p[j + 1]) {
          count++;
          swap(p[j], p[j + 1]);
        }
      }
    }
    cout << count << "\n";
  }
}
