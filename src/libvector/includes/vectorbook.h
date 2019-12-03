#ifndef __VECTOR_book_H__
#define __VECTOR_book_H__

#include <stdio.h>
#include <stdlib.h>
#include "vectortext.h"
#include "../../liblinked/includes/linkedbook.h"

typedef struct vectorbook_t {
  VectorText *texts;
  int size;
  int capacity;
} VectorBook;

void bookInit(VectorBook *book, int cap);
int  bookInsertText(VectorBook *book, VectorText text);
int  bookDeleteText(VectorBook *book, int searched, VectorText *deleted);
void vectorBookToLinkedBook(LinkedBook* lb, VectorBook vb);
int  bookSize(VectorBook book);
void bookFree(VectorBook *book);

#endif
