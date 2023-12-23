// ВАРИАНТ - 9
#include <stdio.h>

// Функция формирования файла
void createFile(const char *filename) {
  FILE *file = fopen(filename, "wb");
  int k, size, err;
  if (file == NULL) {
    printf("Ошибка при создании файла\n");
    return;
  }
  printf("Введите количество чисел:");
  err = scanf("%i", &k);
  if (err != 1) {
    printf("Ошибка ввода.\n");
    return;
  }
  int data[k];
  printf("Введите %i чисел через пробел:", k);
  for (int i = 0; i < k; ++i) {
    err = scanf("%i", &data[i]);
    if (err != 1) {
      printf("Ошибка ввода\n");
      return;
    }
  }
  size = (sizeof(data) / sizeof(int));
  fwrite(data, sizeof(int), size, file);

  fclose(file);
}

// Функция вывода результата
void printResult(const char *filename, int evenCount, int oddCount) {
  printf("Результат:\n");
  printf("Количество четных чисел: %d\n", evenCount);
  printf("Количество нечетных чисел: %d\n", oddCount);

  FILE *file = fopen(filename, "ab");
  if (file == NULL) {
    perror("Ошибка при открытии файла для добавления результатов");
    return;
  }

  fwrite(&evenCount, sizeof(int), 1,
         file); // Записывает четные числа в конец файла
  fwrite(&oddCount, sizeof(int), 1,
         file); // Записывает нечетные числа в конец файла

  fclose(file);
  printf("Результаты успешно записаны в файл.\n");
}

// Функция вычислительной части алгоритма
void Task(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Ошибка при открытии файла");
    return;
  }

  int number;
  int evenCount = 0, oddCount = 0;

  while (fread(&number, sizeof(int), 1, file) == 1) {
    if (number % 2 == 0) {
      evenCount++;
    } else {
      oddCount++;
    }
  }

  fclose(file);

  printResult(filename, evenCount, oddCount);
}

// Функция для чтения целых чисел из бинарного файла
void readIntegersFromFile(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Ошибка при открытии файла");
    return;
  }

  int number;

  printf("Содержимое файла %s:\n", filename);

  while (fread(&number, sizeof(int), 1, file) == 1) {
    printf("%d ", number);
  }

  printf("\n");

  fclose(file);
}

int main() {
  const char *filename = "f.bin";
  createFile(filename);           // функция создания
  Task(filename);                 // выполнение задания
  readIntegersFromFile(filename); // читает целые числа из файла

  return 0;
}
