// ВАРИАНТ - 9
#include <ctype.h>
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
  int pos;
  for (int i = 0; i < k; ++i) {
    if (ans > arr[i]) {
      ans = arr[i];
      pos = i;
    }
  }
  return pos;
}

float Task2(float arr[], int st, int end) {
  float ans, sum = 0;
  int count = 0;
  for (int i = st + 1; i < end; ++i) {
    sum += arr[i];
    count++;
    // printf("%f %d \n", sum, count); //- debug
  }
  return sum / count;
}

int main() {
  int k;
  double y;
  printf("Введите k(>1) и Y:");
  scanf("%i%lf", &k, &y);
  // if ((k < 2) || !isdigit(y)) {
  //   printf("Неверный ввод\n");
  //   return 0;
  // }
  printf("Введите %i чисел через пробел:\n", k);
  float arr[k];
  for (int i = 0; i < k; ++i) {
    if (scanf("%f", &arr[i]) != 1) {
      printf("Неверный ввод\n");
      return 0;
    }
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
  printf("Ответ на 1 задание - %f\n", Task1(arr, k, y));
  if (end - st != 1) {
    printf("Ответ на 2 задание - %f\n", Task2(arr, st, end));
  } else {
    printf("Ответ на 2 задание - такого элемента нет!\n");
  }
  return 0;
}
