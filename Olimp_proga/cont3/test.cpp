#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> permutation(N);
  std::vector<bool> remembered(N, false);

  for (int i = 0; i < N; ++i) {
    std::cin >> permutation[i];
    if (permutation[i] > 0) {
      remembered[permutation[i] - 1] = true;
    }
  }

  int next_value = 1;
  for (int i = 0; i < N; ++i) {
    if (permutation[i] == 0) {
      while (remembered[next_value - 1]) {
        next_value++;
      }
      permutation[i] = next_value;
      remembered[next_value - 1] = true;
    }
  }

  // Проверка на точную ошибку
  for (int i = 0; i < N; ++i) {
    if (permutation[i] == i + 1) {
      std::cout << "1\n";
      return 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    std::cout << permutation[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
