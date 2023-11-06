#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;

  vector<ll> sticks(N);
  for (int i = 0; i < N; ++i) {
    cin >> sticks[i];
  }

  sort(sticks.begin(), sticks.end());

  ll count = 0;

  for (int i = 0; i < N - 2; ++i) {
    for (int j = i + 1; j < N - 1; ++j) {
      ll sum = sticks[i] + sticks[j];
      int idx = lower_bound(sticks.begin() + j + 1, sticks.end(), sum) -
                sticks.begin();
      count += (idx - j - 1);
    }
  }

  cout << count << endl;

  return 0;
}
