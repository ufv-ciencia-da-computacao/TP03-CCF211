#include <stdio.h>
#include "liblinked/includes/linkedbook.h"

int main() {

  LinkedWord lw, lw1;
  LinkedWordInit(&lw);
  LinkedWordInit(&lw1);

  LinkedText lt;
  LinkedTextInit(&lt);

  LinkedBook lb;
  LinkedBookInit(&lb);

  int i;

  for(i=0; i<26; i++) {
    LinkedWordInsert(&lw, 'a' + i);
    LinkedWordInsert(&lw1, 'z' - i);
  }

  LinkedTextInsert(&lt, lw);
  LinkedTextInsert(&lt, lw1);


  LinkedBookInsert(&lb, lt);
  
  LinkedTextInsert(&lt, lw);
  
  LinkedBookInsert(&lb, lt);

  char *str;
  LinkedBookToString(lb, &str);

  printf("%s.\n", str);

  free(str);

  return 0;
}
