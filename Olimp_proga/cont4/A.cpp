#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define all(x) x.begin(), x.end()

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  bool fl = true;
  sort(all(arr));
  for (int i = 0; i < n; ++i) {
    if ((arr[i] - arr[0]) != i) {
      fl = false;
      break;
    }
  }
  if (fl) {
    cout << "Deck looks good"
         << "\n";
  } else {
    cout << "Scammed"
         << "\n";
  }
}
