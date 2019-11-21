#include <stdio.h>
#include "src/liblinked/linkedword.h"

int main() {

  LinkedWord lw;
  LinkedWordInit(&lw);
  LinkedWordInsert(&lw, 'd');
  LinkedWordInsert(&lw, 'e');
  LinkedWordInsert(&lw, 'n');
  LinkedWordInsert(&lw, 'e');
  LinkedWordInsert(&lw, 'r');
  LinkedWordRemove(&lw, 'd');
  LinkedWordRemove(&lw, 'e');

  LinkedWord iterator = lw;
  while(iterator != NULL) {
    printf("%c\n", iterator->c);
    iterator = iterator->next;
  }


  return 0;
}
