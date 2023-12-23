#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b); // посимвольное сравнение строк
}

int main() {
  char str[330];
  printf("Введите слова разделенные запятым и с точкой в конце");
  fgets(str, 330, stdin);
  char *words[30];
  int i = 0, j = 0;

  // разбиение строк на слова
  words[i] = strtok(str, " ,.\n");
  while (words[i] != NULL) {
    i++;
    words[i] = strtok(NULL, " ,.\n");
  }

  // Сортировка по алфавиту
  qsort(words, i, sizeof(char *), cmpfunc);

  printf("Отсортированные слова:\n");
  for (j = 0; j < i; j++) {
    printf("%d. %s\n", j + 1, words[j]);
  }

  return 0;
}
