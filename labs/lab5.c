#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
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

  printf("Successfully wrote numbers from file f to file g.\n");
  return 0;
}
