#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_file() {
  FILE *file;
  char input[100];

  file = fopen("f.txt", "w");

  if (file == NULL) {
    printf("Could not create file %s\n", "f.txt");
    exit(0);
  }

  printf("Enter strings to add to the file. Enter 'stop' to stop.\n");

  while (1) {
    fgets(input, 100, stdin);

    if (strcmp(input, "stop\n") == 0) {
      break;
    }

    fputs(input, file);
  }

  printf("File %s has been created successfully.\n", "f.txt");

  fclose(file);
}

int Task() {
  FILE *f, *g;
  char ch, save;
  f = fopen("f.txt", "r");
  g = fopen("g.txt", "w");

  if (f == NULL || g == NULL) {
    printf("Error: Could not open the files.\n");
    return 1;
  }

  while ((ch = fgetc(f)) != EOF) {
    if (isdigit(ch)) {
      fputc(save, g);
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
