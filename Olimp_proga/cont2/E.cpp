#include <iostream>

using namespace std;
#define ll long long

int main() {
  string s;
  cin >> s;

  ll ans = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    char k = s[i];
    if (k == '4' || k == '6' || k == '9' || k == '0')

      ans += 1;
    else if (k == '8')
      ans += 2;
  }

  cout << ans << '\n';
}
