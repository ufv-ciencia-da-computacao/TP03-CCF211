#include <stdio.h>
#include "libinterface/includes/file.h"

int main() {

  FILE *ptr = fopen("inputs/test.txt", "r");

  LinkedBook b;
  linkedBookInit(&b);
  fileReadLinkedBook(ptr, &b);
  linkedBookPrint(stdout, b);

  printf("\n%d\n", linkedBookSize(b));

  fclose(ptr);

  return 0;
}
