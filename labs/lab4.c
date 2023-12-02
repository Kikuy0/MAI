#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int main() {
  char str[330];
  scanf("%s", str);
  char *words[30];
  int i = 0, j = 0;

  // Break string into words
  words[i] = strtok(str, ",.");
  while (words[i] != NULL) {
    i++;
    words[i] = strtok(NULL, ",.");
  }

  // Sort the words
  qsort(words, i, sizeof(char *), cmpfunc);

  printf("Sorted words are:\n");
  for (j = 0; j < i; j++) {
    printf("%d. %s\n", j + 1, words[j]);
  }

  return 0;
}
