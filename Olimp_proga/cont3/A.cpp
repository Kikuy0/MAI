#include <algorithm>
#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
  int n, count = 1;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != a[i + 1]) {
      count++;
    }
  }
  cout << count << "\n";
}
