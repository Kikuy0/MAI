#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int l = 1, r = n + 1;
  while (l + 1 < r) {
    int mid = (r + l) / 2;
    cout << mid << "\n";
    fflush(stdout);
    string s;
    cin >> s;
    if (s == ">=") {
      l = mid;
    } else if (s == "<") {
      r = mid;
    }
  }
  cout << "! " << l;
  fflush(stdout);
}
