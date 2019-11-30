#include "./includes/selectionsort.h"

void selectionSortVectorBook(Book *arr) {
  int min;
  int i, j;
  int length = bookSize(*arr);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (arr->texts[j].size < arr->texts[min].size) {
        min = j;
      }
    }
    Text aux = arr->texts[min];
    arr->texts[min] = arr->texts[i];
    arr->texts[i] = aux;
  } 
}

void selectionSortVectorText(Text *arr) {
  int min;
  int i, j;
  int length = textSize(*arr);
  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(arr->words[j].character[0]) < tolower(arr->words[min].character[0])) {
        min = j;
      }
    }
    Word aux = arr->words[min];
    arr->words[min] = arr->words[i];
    arr->words[i] = aux;
  } 
}

void selectionSortLinkedText(LinkedText linkedText) {
  int min;
  int i, j;
  int length = linkedTextSize(linkedText);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(linkedTextGet(linkedText, j)->lw->c) < tolower(linkedTextGet(linkedText, min)->lw->c)) {
        min = j;
      }
    }

    linkedTextSwap(&linkedText, i, min);
  } 
}

void selectionSortLinkedBook(LinkedBook linkedBook) {
  int min;
  int i, j;
  int length = linkedBookSize(linkedBook);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (linkedTextSize(linkedBookGet(linkedBook, j)->lt) < linkedTextSize(linkedBookGet(linkedBook, min)->lt)) {
        min = j;
      }
    }

    linkedBookSwap(&linkedBook, i, min);
  } 
}
