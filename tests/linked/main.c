#include <stdio.h>
#include "../../liblinked/includes/linkedtext.h"

int main() {

  LinkedWord lw;
  LinkedText lt;
  linkedTextInit(&lt);
  
  linkedWordInit(&lw);
  linkedWordInsert(&lw, 'a');
  linkedWordInsert(&lw, 'b');
  linkedWordInsert(&lw, 'c');
  linkedTextInsert(&lt, lw);

  linkedWordInit(&lw);
  linkedWordInsert(&lw, 'c');
  linkedWordInsert(&lw, 'b');
  linkedWordInsert(&lw, 'a');
  linkedTextInsert(&lt, lw);

  linkedWordInit(&lw);
  linkedWordInsert(&lw, 'c');
  linkedWordInsert(&lw, 'a');
  linkedWordInsert(&lw, 'b');
  linkedTextInsert(&lt, lw);
  
  linkedTextSwap(&lt, 2, 1);


  linkedTextPrint(stdout, lt);

  return 0;
}
