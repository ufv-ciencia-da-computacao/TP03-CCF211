#include <stdio.h>
#include "../../liblinked/includes/linkedtext.h"

int main() {

  LinkedWord lw;
  LinkedText lt;
  LinkedTextInit(&lt);

  LinkedWordInit(&lw);
  LinkedWordInsert(&lw, 'a');
  LinkedWordInsert(&lw, 'b');
  LinkedWordInsert(&lw, 'c');
  LinkedTextInsert(&lt, lw);

  LinkedWordInit(&lw);
  LinkedWordInsert(&lw, 'c');
  LinkedWordInsert(&lw, 'b');
  LinkedWordInsert(&lw, 'a');
  LinkedTextInsert(&lt, lw);

  LinkedWordInit(&lw);
  LinkedWordInsert(&lw, 'c');
  LinkedWordInsert(&lw, 'a');
  LinkedWordInsert(&lw, 'b');
  LinkedTextInsert(&lt, lw);

  LinkedTextSwap(&lt, 2, 1);


  LinkedTextPrint(stdout, lt);

  return 0;
}
