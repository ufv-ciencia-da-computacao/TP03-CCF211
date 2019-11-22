#ifndef __LINKED_BOOK_H__
#define __LINKED_BOOK_H__

#include <stdlib.h>
#include "linkedtext.h"

typedef struct book_t * LinkedBook;
struct book_t {
  LinkedText lt;
  LinkedBook next;
};

void LinkedBookInit(LinkedBook *lb);
void LinkedBookInsert(LinkedBook *lb, LinkedText lw);
void LinkedBookRemove(LinkedBook *lt, int index);
int  LinkedBookSize(LinkedBook lt);
void LinkedBookToString(LinkedBook lt, char *str);

#endif
