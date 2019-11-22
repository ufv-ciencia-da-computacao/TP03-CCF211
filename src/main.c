#include <stdio.h>
#include "liblinked/includes/linkedword.h"
#include "liblinked/includes/linkedtext.h"

int main() {

  LinkedWord lw, lw1;
  LinkedWordInit(&lw);
  LinkedWordInit(&lw1);

  LinkedText lt;
  LinkedTextInit(&lt);

  int i;

  for(i=0; i<26; i++) {
    LinkedWordInsert(&lw, 'a' + i);
    LinkedWordInsert(&lw1, 'z'- i);
  }

  LinkedTextInsert(&lt, lw);
  LinkedTextInsert(&lt, lw1);

  LinkedTextRemove(&lt, lw);

  printf("%d\n", LinkedTextSize(lt));

  return 0;
}
