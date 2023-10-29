#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main() {
  string lib = "0123456789abcdefghijklmnopqrstuvwxyz", n, N = "", r_n;
  int a, b;
  cin >> a >> b >> n;
  ll num = 0;
  r_n = n;
  reverse(all(r_n));
  // cout << r_n << "\n";
  for (int i = 0; i < r_n.size(); ++i) {
    num += (lib.find(r_n[i])) * (pow(a, i));
  }
  // cout << num << "\n";
  while (num) {
    N += lib[(num % b)];
    num /= b;
  }
  if (N == "") {
    N = "0";
  } else {
    reverse(all(N));
  }
  cout << N << "\n";
}
