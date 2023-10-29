#include <algorithm>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, summ = 0;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(all(arr), greater());
  for (int i = 0; i < n; ++i) {
    if (((i + 1) % k) != 0) {
      summ += arr[i];
    } else {
      continue;
    }
  }
  cout << summ << "\n";

  // for (int elem : arr) {
  //   cout << elem << " "; // debug
  // }
}
