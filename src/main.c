#include <stdio.h>
#include "libinterface/includes/file.h"
#include "libsorting/includes/selectionsort.h"

int main() {

  FILE *ptr = fopen("inputs/test.txt", "r");

  LinkedBook b;
  linkedBookInit(&b);
  fileReadLinkedBook(ptr, &b);
  selectionSortLinkedBook(b);
  filePrintLinkedBook(stdout, b);

  fclose(ptr);

  return 0;
}
