// ВАРИАНТ - 9
#include <stdio.h>

float Task1(float arr[], int k, float y) {
  float ans = -1;
  for (int i = 0; i < k; ++i) {
    if ((ans < arr[i]) && (arr[i] < y)) {
      ans = arr[i];
    }
  }
  return ans;
}

int MaxValuePos(float arr[], int k) {
  float ans = -1;
  int pos;
  for (int i = 0; i < k; ++i) {
    if (ans < arr[i]) {
      ans = arr[i];
      pos = i;
    }
  }
  return pos;
}

int MinValuePos(float arr[], int k) {
  float ans = 10000000000;
  for (int i = 0; i < k; ++i) {
    if (ans > arr[i]) {
      ans = arr[i];
    }
  }
  return ans;
}

float Task2(float arr[], int st, int end) {
  float ans, sum = 0;
  int count = 0;
  for (int i = st; i < end; ++i) {
    sum += arr[i];
    count++;
    // printf("%f %d \n", sum, count); - debug
  }
  return sum / count;
}

int main() {
  int k;
  float x, y;
  scanf("%d%f", &k, &y);
  float arr[k];
  for (int i = 0; i < k; ++i) {
    scanf("%f", &arr[i]);
  }
  // for (int i = 0; i < k; ++i) {
  //   printf("%f\n", arr[i]); -- debug
  // }
  int st, end;
  if (MaxValuePos(arr, k) < MinValuePos(arr, k)) {
    st = MaxValuePos(arr, k);
    end = MinValuePos(arr, k);
  } else {
    st = MinValuePos(arr, k);
    end = MaxValuePos(arr, k);
  }
  printf("Task 1 answer - %f\n", Task1(arr, k, y));
  printf("Task 2 answer - %f\n", Task2(arr, st, end));
  return 0;
}
