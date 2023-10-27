#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int cost;
    int h1, h2, h5, th1, th5;
    cin >> cost;
    th5 = cost / 5000;
    th1 = (cost - th5 * 5000) / 1000;
    h5 = (cost - th5 * 5000 - th1 * 1000) / 500;
    h2 = (cost - th5 * 5000 - th1 * 1000 - h5 * 500) / 200;
    h1 = (cost - th5 * 5000 - th1 * 1000 - h5 * 500 - h2 * 200) / 100;
    cout << h1 << " " << h2 << " " << h5 << " " << th1 << " " << th5 << "\n";
  }
}
