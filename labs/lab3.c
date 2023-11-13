// ВАРИАНТ - 9
#include <stdio.h>
#include <stdlib.h>

static int **createMatrix(int rows, int cols) {
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }
  return matrix;
}

void fillMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void ViewMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

static int MatrixAverage(int **matrix, int rows, int cols) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sum += matrix[i][j];
    }
  }
  return (sum / (rows * cols));
}

static float Task(int **matrix, int rows, int cols, int average) {
  int sum = 0, count = 0, saveCount = 0, saveSum = 0, k = 1;
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      sum += matrix[j][i];
      if ((matrix[j][i] % 2 != 0) && (matrix[j][i] > average)) {
        count++;
      }
    }
    // printf("%d %d\n", sum, count); - debug
    if (count > saveCount) {
      saveSum = sum;
      saveCount = count;
      k = 1;
    } else if (count == saveCount) {
      saveSum += sum;
      k++;
    }
    sum = 0;
    count = 0;
  }
  return (saveSum / (cols * k));
}

int main() {
  int rows, cols, MAverage;
  printf("Enter number of rows: ");
  scanf("%d", &rows);
  printf("Enter number of columns: ");
  scanf("%d", &cols);
  int **matrix = createMatrix(rows, cols);
  fillMatrix(matrix, rows, cols);
  ViewMatrix(matrix, rows, cols);
  MAverage = MatrixAverage(matrix, rows, cols);
  // printf("%d\n", MAverage); - debug
  printf("Task answer - %f\n", Task(matrix, rows, cols, MAverage));
  return 0;
}
