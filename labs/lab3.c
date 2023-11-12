#include <stdio.h>

int GetMatrix(int m, int n) {
  int matrix[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      scanf("%d", &a);
      matrix[i][j] = a;
    }
  }
  return **matrix;
}
void ViewMatrix(int **matrix, int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  int **matrix;
  **matrix = GetMatrix(m, n);
  ViewMatrix(matrix, m, n);
}
