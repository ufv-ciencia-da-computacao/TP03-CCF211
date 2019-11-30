#include "./includes/vectorbook.h"

void bookInit(Book *book) {
  book->size = 0;
}

int bookInsertText(Book *book, Text text) {
  if (book->size == MAXTAM_BOOK) {
    return -1;
  } else {
    book->texts[book->size++] = text;
  }  

  return 0;
}

int bookDeleteText(Book *book, int searched, Text *deleted) {
  int indexSearched = -1;
  int i;
  for (i = 0; i < book->size; i++) {
    if (i == searched) {
      *deleted = book->texts[i];
      indexSearched = i;
    }
  }

  if (indexSearched == -1) {
    return -1;
  } else {
    for (i = indexSearched+1; i < book->size; i++) {
      book->texts[i-1] = book->texts[i];
    }
  }

  book->size--;
  
  return 1;
}

int  bookSize(Book book) {
  return book.size;
}
