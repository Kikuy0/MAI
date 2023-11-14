#include <stdio.h>
#include <stdlib.h>

// Function to make a binary file
void makeBinFile() {
  FILE *fp;
  char fileName[50] = "f";
  int c;
  int count = 0;

  // printf("Enter the name of the binary file you want to create: ");
  // scanf("%s", fileName);

  fp = fopen(fileName, "wb");

  if (fp == NULL) {
    printf("Error! Unable to create the binary file.");
    exit(1);
  }

  printf("Enter the binary data. Type '0' to finish.\n");

  while (1) {
    scanf("%d", &c);
    if (c == 0) {
      break;
    }
    fwrite(&c, sizeof(int), 1, fp);
    count++;
  }

  fclose(fp);
  printf("The binary file has been created successfully. Total binary digits: "
         "%d\n",
         count);
}

// Function to read binary file and count odd numbers
int countOddNumbersInBinFile(char *filename) {
  FILE *file;
  unsigned char c;
  int count = 0;

  file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error! Unable to open the file %s\n", filename);
    exit(1);
  }

  while (fread(&c, sizeof(char), 1, file) == 1) {
    if (c % 2 != 0) {
      count++;
    }
  }

  fclose(file);
  return count;
}
// Function to read binary file and count odd numbers
int CountNums(char *filename) {
  FILE *file;
  unsigned counter;
  int count = 0, num;
  file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error! Unable to open the file %s\n", filename);
    exit(1);
  }
  while (fread(&num, sizeof(int), 2, file) != EOF) {
    fread(&num, sizeof(int), 1, file);
    if (num % 2 == 0) {
      count++;
      printf("%d ", num);
    }
  }

  fclose(file);
  return count;
}

int main() {
  makeBinFile();
  printf("\n%d\n", CountNums("f"));
  return 0;
}
