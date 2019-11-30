#ifndef __VECTOR_book_H__
#define __VECTOR_book_H__

#include <stdio.h>
#include <stdlib.h>
#include "vectortext.h"

#define MAXTAM_BOOK 100

typedef struct vectorbook_t {
  VectorText texts[MAXTAM_BOOK];
  int size;
} VectorBook;

void bookInit(VectorBook *book);
int  bookInsertText(VectorBook *book, VectorText text);
int  bookDeleteText(VectorBook *book, int searched, VectorText *deleted);
int  bookSize(VectorBook book);

#endif
