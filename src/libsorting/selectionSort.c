#include "./includes/selectionSort.h"

void selectionSortVectorBook(Book *arr, Metric *metric) {
  int min;
  int i, j;
  int length = bookSize(*arr);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (arr->texts[j].size < arr->texts[min].size) {
        min = j;
      }
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    Text aux = arr->texts[min];
    arr->texts[min] = arr->texts[i];
    arr->texts[i] = aux;
    
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}

void selectionSortVectorText(Text *arr, Metric *metric) {
  int min;
  int i, j;
  int length = textSize(*arr);
  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(arr->words[j].character[0]) < tolower(arr->words[min].character[0])) {
        min = j;
      }
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    Word aux = arr->words[min];
    arr->words[min] = arr->words[i];
    arr->words[i] = aux;
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}

void selectionSortLinkedText(LinkedText linkedText, Metric *metric) {
  int min;
  int i, j;
  int length = linkedTextSize(linkedText);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (tolower(linkedTextGet(linkedText, j)->lw->c) < tolower(linkedTextGet(linkedText, min)->lw->c)) {
        min = j;
      }
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }

    linkedTextSwap(&linkedText, i, min);
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}

void selectionSortLinkedBook(LinkedBook linkedBook, Metric *metric) {
  int min;
  int i, j;
  int length = linkedBookSize(linkedBook);

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if (linkedTextSize(linkedBookGet(linkedBook, j)->lt) < linkedTextSize(linkedBookGet(linkedBook, min)->lt)) {
        min = j;
      }
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }

    linkedBookSwap(&linkedBook, i, min);
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}
