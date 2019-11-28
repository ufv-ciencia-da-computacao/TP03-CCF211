#include "./includes/selectionSort.h"

void vectorBookSelectionSort(Book *arr) {
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

void vectorTextSelectionSort(Text *arr) {
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

void linkedTextSelectionSort(LinkedText linkedText) {
  int min;
  int i, j;
  int length = LinkedTextSize(linkedText);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(LinkedTextGet(linkedText, j)->lw->c) < tolower(LinkedTextGet(linkedText, min)->lw->c)) {
        min = j;
      }
    }

    LinkedTextSwap(&linkedText, i, min);
  } 
}

void linkedBookSelectionSort(LinkedBook linkedBook) {
  int min;
  int i, j;
  int length = LinkedBookSize(linkedBook);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (LinkedTextSize(LinkedBookGet(linkedBook, j)->lt) < LinkedTextSize(LinkedBookGet(linkedBook, min)->lt)) {
        min = j;
      }
    }

    LinkedBookSwap(&linkedBook, i, min);
  } 
}
