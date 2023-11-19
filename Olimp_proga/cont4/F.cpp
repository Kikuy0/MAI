#include <iostream>
#include <vector>

using namespace std;

int kost(int st, int k) {
  int sum = st;
  for (int i = 1; i < k; ++i) {
    sum += (st + i);
  }
  return sum;
}

int main() {
  int n, a, m, k, mod, summ = 0;
  cin >> n >> a >> m >> k >> mod;
  vector<int> cnt(mod);
  for (int i = 0; i < n; ++i) {
    cnt[a]++;
    a = (a * m + k) % mod;
  }
  int j = 0, i = 0;
  for (int i = 0; i < mod; ++i) {
    int a = cnt[i] * (kost(j + 1, cnt[i])) * i;
    summ += (a % 1000000007);
    if (cnt[i] != 0) {
      j += cnt[i];
    };
  }
  cout << summ << "\n";
  // cout << kost(3, 2) << "\n";
  return 0;
}
