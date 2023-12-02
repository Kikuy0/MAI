// ВАРИАНТ - 9
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// static void fillFile(FILE* file); // заполняет файл 10 случайными числами
static void makeFile(FILE *file);
static void printFile(FILE *file); // выводит содержимое файла
static void solve(FILE *file);     // решение задачи
int main(int argc, char *argv[]) {
  FILE *f = fopen("f.bin", "w+b");

  makeFile(f);
  // fillFile(f);
  printFile(f);
  solve(f);
  printFile(f);
  fclose(f);
  return 0;
}

/*
static void fillFile(FILE* file)
{
    srand(time(NULL));
    uint8_t n = 0;
    for (int i = 0; i < 10; i++) {
        n = rand() % 20;
        fwrite(&n, sizeof(uint8_t), 1, file);
    }
    fseek(file, 0, SEEK_SET);
}
*/

// Function to make a binary file
static void makeFile(FILE *file) {
  char fileName[50] = "f.bin";
  int c;
  int count = 0;

  // printf("Enter the name of the binary file you want to create: ");
  // scanf("%s", fileName);

  file = fopen(fileName, "w+b");

  if (file == NULL) {
    printf("Error! Unable to create the binary file.");
    exit(1);
  }

  printf("Enter the binary data. Type '0' to finish.\n");

  while (1) {
    scanf("%d", &c);
    if (c == 0) {
      break;
    }
    count++;
    uint8_t y = c;
    fwrite(&y, sizeof(uint8_t), 1, file);
  }
  fseek(file, 0, SEEK_SET);
}

static void printFile(FILE *file) {
  uint8_t n = 0;
  for (int i = 0; i < 10; i++) {
    fread(&n, sizeof(uint8_t), 1, file);
    printf("%3i ", n);
  }
  putc('\n', stdout);
  fseek(file, 0, SEEK_SET);
}

static void solve(FILE *file) {
  uint8_t buf[10];
  uint8_t countOdd = 0;
  uint8_t countEven = 0;
  fread(buf, sizeof(uint8_t), 10, file);
  for (int i = 0; i < 10; i++) {
    if (buf[i] % 2 == 0) {
      countOdd++;
    } else {
      countEven++;
    }
  }
  // fwrite(&countOdd, sizeof(uint8_t), 1, file);
  // fwrite(&countEven, sizeof(uint8_t), 1, file);
}
