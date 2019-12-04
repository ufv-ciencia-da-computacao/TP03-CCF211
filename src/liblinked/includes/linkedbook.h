#ifndef __LINKED_BOOK_H__
#define __LINKED_BOOK_H__

#include <stdlib.h>
#include "linkedtext.h"

typedef struct book_t * BookNode;
struct book_t {
  LinkedText lt;
  BookNode next;
  BookNode prev;
};

typedef struct {
  BookNode head;
  BookNode tail;
  int size;
} LinkedBook;

void linkedBookInit(LinkedBook *lb);
void linkedBookInsert(LinkedBook *lb, LinkedText lt);
void linkedBookRemove(LinkedBook *lb, BookNode index);
BookNode linkedBookPrev(BookNode bn);
BookNode linkedBookNext(BookNode bn);
int  linkedBookSize(LinkedBook lb);
void linkedBookSwap(LinkedBook *lb, BookNode a, BookNode b);
void linkedBookFree(LinkedBook *lb);

#endif
