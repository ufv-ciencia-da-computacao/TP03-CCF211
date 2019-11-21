#include <stdio.h>
#include "src/liblinked/linkedword.h"

int main() {

  LinkedWord lw;
  LinkedWordInit(&lw);
  int i;

  for(i=0; i<26; i++) {
    LinkedWordInsert(&lw, 'a' + i/4);
  }
  
  printf("size: %d\n", LinkedWordSize(lw));
  
  LinkedWordRemove(&lw, 'a');
  LinkedWordRemove(&lw, 'a');

  printf("size: %d\n", LinkedWordSize(lw));

  LinkedWord iterator = lw;
  while(iterator != NULL) {
    printf("%c ", iterator->c);
    iterator = iterator->next;
  }

  printf("\n");

  return 0;
}
