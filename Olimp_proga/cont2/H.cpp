#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, clmin, clmax, gmin = pow(10, 10), gmax = -1 * pow(10, 10), igmin,
                       igmax;
  cin >> n;
  vector<int> arr(n);
  vector<int> lmin;
  vector<int> lmax;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if ((i == 0) && (arr[i] > arr[i + 1])) {
      clmax++;
      lmax.push_back(i);
    }
    if ((i == 0) && (arr[i] < arr[i + 1])) {
      clmin++;
      lmin.push_back(i);
    }
    if ((i == (n - 1)) && (arr[i] > arr[i - 1])) {
      clmax++;
      lmax.push_back(i);
    }
    if ((i == (n - 1)) && (arr[i] < arr[i - 1])) {
      clmin++;
      lmin.push_back(i);
    } else {
      if ((arr[i - 1] > arr[i]) && (arr[i] < arr[i + 1])) {
        clmin++;
        lmin.push_back(i);
      }
      if ((arr[i - 1] < arr[i]) && (arr[i] > arr[i + 1])) {
        clmax++;
        lmax.push_back(i);
      }
    }
    if (arr[i] > gmax)
      igmax = i;
    if (arr[i] < gmin)
      igmin = i;
  }
}
