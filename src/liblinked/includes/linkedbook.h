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

void LinkedBookInit(LinkedBook *lb);
void LinkedBookInsert(LinkedBook *lb, LinkedText lt);
void LinkedBookRemove(LinkedBook *lb, int index);
LinkedBook LinkedBookGet(LinkedBook lb, int index);
int  LinkedBookSize(LinkedBook lb);
void LinkedBookSwap(LinkedBook *lb, int i, int j);
void LinkedBookPrint(FILE *stream, LinkedBook lb);

#endif
