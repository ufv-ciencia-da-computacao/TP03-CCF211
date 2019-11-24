#ifndef __VECTOR_book_H__
#define __VECTOR_book_H__

#include "vectortext.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorbook_t {
  Text texts[MAXTAM];
  int size;
} Book;

void bookInit(Book *book);
void bookInsertWord(Book *book, Text text);
void bookDeleteWord(Book *book, int searched, Word *deleted);
void bookToString(Book *book, char *str);
void bookFree(Book *book);

#endif