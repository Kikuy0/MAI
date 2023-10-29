#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, count_min = 0, count_max = 0;
  cin >> n;
  vector<int> arr(n);
  vector<int> min_pos;
  vector<int> max_pos;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<int> s_arr = arr;
  sort(all(s_arr));
  if (n == 1) {
    cout << "1 1\n1 1\n1 1\n";
  } else {
    if (arr[0] > arr[1]) {
      count_max++;
      max_pos.push_back(1);
    }
    if (arr[0] < arr[1]) {
      count_min++;
      min_pos.push_back(1);
    }
    for (int j = 1; j < n - 1; ++j) {
      if ((arr[j - 1] > arr[j]) && (arr[j] < arr[j + 1])) {
        count_min++;
        min_pos.push_back(j + 1);
      }
      if ((arr[j - 1] < arr[j]) && (arr[j] > arr[j + 1])) {
        count_max++;
        max_pos.push_back(j + 1);
      }
    }
    if (arr[n - 1] > arr[n - 2]) {
      count_max++;
      max_pos.push_back(n);
    }
    if (arr[n - 1] < arr[n - 2]) {
      count_min++;
      min_pos.push_back(n);
    }
    cout << count_min << " ";
    for (int elem : min_pos) {
      cout << elem << " ";
    }
    cout << "\n" << count_max << " ";
    for (int elem : max_pos) {
      cout << elem << " ";
    }
    cout << "\n";
    for (int k = 0; k < n; ++k) {
      if (arr[k] == s_arr[0]) {
        cout << k + 1 << " ";
        break;
      }
    }
    for (int k = 0; k < n; ++k) {
      if (arr[k] == s_arr[n - 1]) {
        cout << k + 1 << "\n";
        break;
      }
    }
  }
}
