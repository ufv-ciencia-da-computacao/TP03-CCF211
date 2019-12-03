#ifndef __VECTOR_book_H__
#define __VECTOR_book_H__

#include <stdio.h>
#include <stdlib.h>
#include "vectortext.h"
#include "../../liblinked/includes/linkedbook.h"

#define MAXTAM_BOOK 1000

typedef struct vectorbook_t {
  VectorText texts[MAXTAM_BOOK];
  int size;
} VectorBook;

void bookInit(VectorBook *book);
int  bookInsertText(VectorBook *book, VectorText text);
int  bookDeleteText(VectorBook *book, int searched, VectorText *deleted);
void vectorBookToLinkedBook(LinkedBook* lb, VectorBook vb);
int  bookSize(VectorBook book);

#endif
