#include "./includes/vectorbook.h"

void bookInit(Book *book) {
  book->size = 0;
}

int bookInsertText(Book *book, Text t) {
  if (book->size == MAXTAM) {
    return -1;
  } else {
    book->texts[book->size++] = t;
  }  

  return 0;
}

int bookDeleteText(Book *book, int searched, Text *deleted) {
  int indexSearched = -1;
  for (int i = 0; i < book->size; i++) {
    if (i == searched) {
      *deleted = book->texts[i];
      indexSearched = i;
    }
  }

  if (indexSearched == -1) {
    return -1;
  } else {
    for (int i = indexSearched+1; i < book->size; i++) {
      book->texts[i-1] = book->texts[i];
    }
  }
  
  return 1;
}

bool bookIsEmpty(Book *book) {
  if (book->size == 0) {
    return true;
  }
  return false;
}

void bookToString(Book *book, char *str) {
  for (int i = 0; i < book->size; i++) {
    textToString(&(book->texts[i]), str);
    strcat(str, " ");
  }
}