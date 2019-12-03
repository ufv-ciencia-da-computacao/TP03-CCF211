#include "./includes/vectorbook.h"

void bookInit(VectorBook *book, int cap) {
  book->texts = (VectorText*) malloc (cap*sizeof(VectorText));
  book->size = 0;
  book->capacity = cap;
}

int bookInsertText(VectorBook *book, VectorText text) {
  if (book->size == book->capacity) {
    return -1;
  } else {
    book->texts[book->size++] = text;
  }  

  return 0;
}

int bookDeleteText(VectorBook *book, int searched, VectorText *deleted) {
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

void vectorBookToLinkedBook(LinkedBook* lb, VectorBook vb) {
  int i, j;
  LinkedText lt;
  for (i = 0; i < vb.size; i++) {
    vectorTextToLinkedText(&lt, vb.texts[i]);
    linkedBookInsert(lb, lt);
  }
}

int  bookSize(VectorBook book) {
  return book.size;
}

void bookFree(VectorBook *book) {
  int i;
  for(i=0; i<book->size; i++) {
    textFree(&(book->texts[i]));
  }
  free(book->texts);
}
