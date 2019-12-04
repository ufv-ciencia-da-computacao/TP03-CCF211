#include <stdio.h>
#include "../../src/liblinked/includes/linkedword.h"
#include "../../src/liblinked/includes/linkedtext.h"
#include "../../src/liblinked/includes/linkedbook.h"

void filePrintLinkedWord(FILE *stream, LinkedWord lw) {
  WordNode iterator = lw.head;
  while (iterator != NULL) {
    fprintf(stream, "%c", iterator->c);
    iterator = iterator->next;
  }
}

void filePrintLinkedText(FILE *stream, LinkedText lt) {
  TextNode iterator = lt.head;
  while(iterator != NULL) {
    filePrintLinkedWord(stream, iterator->lw);
    fprintf(stream, iterator->next != NULL ? " " : "");
    iterator = iterator->next;
  }
}

void filePrintLinkedBook(FILE *stream, LinkedBook lb) {
  BookNode iterator = lb.head;
  while(iterator != NULL) {
    filePrintLinkedText(stream, iterator->lt);
    fprintf(stream, "\n");
    iterator = iterator->next;
  }
}

int main() {

  LinkedWord lw;
  LinkedText lt;
  LinkedBook lb;

  linkedBookInit(&lb);

  int i, j, k;
  for(i=0; i<100000; i++) {
    linkedTextInit(&lt);
    for(j=0; j<50000; j++) {
      linkedWordInit(&lw);
      for(k=0; k<7; k++) {
        linkedWordInsert(&lw, (char) 'a' + (i + j + k)%26 );
      }
      linkedTextInsert(&lt, lw);
    }
    linkedBookInsert(&lb, lt);
  }
  printf("..");

  // filePrintLinkedBook(stdout, lb);
  linkedBookFree(&lb);
  return 0;
}
