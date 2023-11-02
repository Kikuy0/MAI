#include <algorithm>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, count = 0;
  cin >> n;
  vector<int> arr(n);
  vector<int> nums(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    if (m > n) {
      cout << "-1"
           << "\n";
      return 0;
    } else if ((nums[m] > 0) && (m != 0)) {
      cout << "-1"
           << "\n";
      return 0;
    }
    arr[i] = m;
    nums[m]++;
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 0) {
      for (int j = 1; j < n + 1; ++j) {
        if (nums[j] == 0) {
          nums[j]++;
          arr[i] = j;
          break;
        }
      }
    }
  }
  for (int elem : arr) {
    cout << elem << " ";
  }
  cout << "\n";
}
