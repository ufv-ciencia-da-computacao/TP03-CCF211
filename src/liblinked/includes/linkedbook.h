#ifndef __LINKED_BOOK_H__
#define __LINKED_BOOK_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedtext.h"

typedef struct book_t * LinkedBook;
struct book_t {
  LinkedText lt;
  LinkedBook next;
};

void linkedBookInit(LinkedBook *lb);
void linkedBookInsert(LinkedBook *lb, LinkedText lt);
void linkedBookRemove(LinkedBook *lb, int index);
LinkedBook linkedBookGet(LinkedBook lb, int index);
int  linkedBookSize(LinkedBook lb);
void linkedBookSwap(LinkedBook *lb, int i, int j);
void linkedBookFree(LinkedBook *lb);

#endif
