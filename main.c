#include <stdio.h>
#include "src/liblinked/includes/linkedword.h"

int main() {

  LinkedWord lw, lw1;
  LinkedWordInit(&lw);
  LinkedWordInit(&lw1);
  int i;

  for(i=0; i<26; i++) {
    LinkedWordInsert(&lw, 'a' + i/4);
    LinkedWordInsert(&lw1, 'a' + i/3);
  }

  printf("%d\n", LinkedWordEquals(lw1, lw));

  return 0;
}
