#include <algorithm>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(n + 1);
  vector<int> arr(n);
  vector<int> tmp;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    if ((m > n) || (cnt[m] > 0 && m != 0)) {
      cout << "-1"
           << "\n";
      return 0;
    }
    arr[i] = m;
    cnt[m]++;
  }
  for (int i = 1; i < n + 1; ++i) {
    if (cnt[i] == 0) {
      tmp.push_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] != 0) {
      cout << arr[i] << " ";
    } else {
      cout << tmp.back() << " ";
      tmp.pop_back();
    }
  }
  cout << "\n";
}
