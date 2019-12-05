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
  linkedTextInit(&lt);

  int i, j, k;
  //for(i=0; i<10; i++) {
    // linkedTextInit(&lt);
    for(j=0; j<10; j++) {
      linkedWordInit(&lw);
      for(k=0; k<9; k++) {
        
        linkedWordInsert(&lw, (char) 'z' - (i + j + k)%26 );
      }
      
      linkedTextInsert(&lt, lw);
    }
    // linkedBookInsert(&lb, lt);
  // }

  // // linkedTextSwap(&lt, lt.head, lt.tail);

  TextNode t1 = lt.head, t2;

  // F  1 2 3 4 5 6 0
  // t2 
  
  while(t1 != NULL) {
    t2 = lt.tail;
    linkedTextSwap(&lt, t1, lt.tail);
    t1 = t2->next;
    printf(",");
  }

  // filePrintLinkedText(stdout, lt);
  // selectionSortLinkedText(&lt, &metric);
  // filePrintLinkedText(stdout, lt);

  // filePrintMetric(metric);

  // linkedTextFree(&lt);

  return 0;
}