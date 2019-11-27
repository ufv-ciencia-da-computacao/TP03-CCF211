#include "./includes/selectionSort.h"

void vectorBookSelectionSort(Book *arr, int length) {
  int min;
  int i, j;

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

void vectorTextSelectionSort(Text *arr, int length) {
  int min;
  int i, j;

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(arr->words[j].character[0]) < arr->words[min].character[0]) {
        min = j;
      }
    }
    Word aux = arr->words[min];
    arr->words[min] = arr->words[i];
    arr->words[i] = aux;
  } 
}

void linkedTextSelectionSort(LinkedText linkedText, int length) {
  int min;
  int i, j;

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(LinkedTextGetWord(linkedText, j)->c) < tolower(LinkedTextGetWord(linkedText, min)->c)) {
        min = j;
      }
    }

    LinkedWord wordI = LinkedTextGetWord(linkedText, i);
    LinkedWord min = LinkedTextGetWord(linkedText, j);
    LinkedWord aux = min;
    min = wordI;
    wordI = aux;
  } 
}

void linkedBookSelectionSort(LinkedBook linkedBook, int length) {
  int min;
  int i, j;

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (LinkedTextSize(LinkedBookGetText(linkedBook, j)) < LinkedTextSize(LinkedBookGetText(linkedBook, min))) {
        min = j;
      }
    }

    LinkedText bookI = LinkedBookGetText(linkedBook, i);
    LinkedText min = LinkedBookGetText(linkedBook, j);
    LinkedText aux = min;
    min = bookI;
    bookI = aux;
  } 
}