#ifndef __VECTOR_book_H__
#define __VECTOR_book_H__

#include <stdio.h>
#include <stdlib.h>
#include "vectortext.h"

#define MAXTAM_BOOK 100

typedef struct vectorbook_t {
  Text texts[MAXTAM_BOOK];
  int size;
} Book;

void bookInit(Book *book);
int  bookInsertText(Book *book, Text text);
int  bookDeleteText(Book *book, int searched, Text *deleted);
int  bookSize(Book book);

#endif
