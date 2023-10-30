#include <iostream>

int main() {
  long long N, a, b;
  std::cin >> N >> a >> b;

  long long left = 1;
  long long right = N / (a + b) + 1;

  while (left < right) {
    long long mid = (left + right) / 2;
    if (mid * a + mid * b >= N) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  std::cout << left << std::endl;

  return 0;
}
