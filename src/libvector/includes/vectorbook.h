#ifndef __VECTOR_book_H__
#define __VECTOR_book_H__

#include "vectortext.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorbook_t {
  vectortext_t texts[MAXTAM];
  int tail, head;
} Book;

void bookInit(Book *books);
void bookInsertWord(Book *books, Text text);
void bookDeleteWord(Book *books, Word searched, Word *deleted);
void bookToString(Book *books);
void bookFree(Book *books);

#endif