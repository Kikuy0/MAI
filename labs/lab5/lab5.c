// ВАРИАНТ - 9
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_file() {
  FILE *file;
  char input[100];

  file = fopen("f.txt", "w"); // открытие файла

  if (file == NULL) {
    printf("Не получилось открыть файл %s\n", "f.txt");
    exit(0);
  }

  printf(
      "Введите строки для заполнения файла. Введите 'stop.' для остановки.\n");

  while (1) {
    fgets(input, 100, stdin); // получение строки.

    if (strcmp(input, "stop.\n") == 0) { // сравнение строки
      break;
    }

    fputs(input, file); // записывает содержимое input в файл
  }

  printf("Файл %s создан успешно.\n", "g.txt");

  fclose(file); // закрыть файл
}

int Task() { // функция выполнения задания
  FILE *f, *g;
  char ch, save;
  f = fopen("f.txt", "r");
  g = fopen("g.txt", "w");

  if (f == NULL || g == NULL) {
    printf("Ошибка: Не получилось открыть файл.\n");
    return 1;
  }

  while ((ch = fgetc(f)) != EOF) {
    if (isdigit(ch)) { // проверка что символ является числом
      fputc(save, g); // запись символа
    }
    save = ch;
  }

  fclose(f);
  fclose(g);
  return 0;
}

int main() {
  make_file();
  Task();
  return 0;
}
