#include <algorithm>
#include <iostream>
#include <set>
#include <string>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> lib;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    sort(all(s));
    lib.insert(s);
  }
  cout << lib.size() << "\n";
}
