#include "./includes/selectionSort.h"
#include <stdio.h>

void selectionSortVectorBook(VectorBook *arr, Metric *metric) {
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
    VectorText aux = arr->texts[min];
    arr->texts[min] = arr->texts[i];
    arr->texts[i] = aux;
    
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}

void selectionSortVectorText(VectorText *arr, Metric *metric) {
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
    VectorWord aux = arr->words[min];
    arr->words[min] = arr->words[i];
    arr->words[i] = aux;
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}

void selectionSortLinkedText(LinkedText *linkedText, Metric *metric) {
  TextNode itI, itJ;
  TextNode min;

  for (itI = linkedText->head; itI->next != NULL; itI = min->next) {
    min = itI;
    for (itJ = itI->next; itJ != NULL; itJ = itJ->next) {
      if (tolower(itJ->lw.head->c) < tolower(min->lw.head->c)) {
        min = itJ;
      }
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    if (min != linkedText->head) {
      linkedTextSwap(linkedText, itI, min);
    }
    
    metricSetMoves(metric, metricGetMoves(metric) + 1);
  } 
}

void selectionSortLinkedBook(LinkedBook *linkedBook, Metric *metric) {
  BookNode min;
  BookNode itI, itJ;

  for (itI = linkedBook->head; itI->next != NULL; itI = min->next) {
    min = itI;
    for (itJ = itI->next; itJ != NULL; itJ = itJ->next) {
      if (itJ->lt.size < min->lt.size) {
        min = itJ;
      }
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    linkedBookSwap(linkedBook, itI, min);
    metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
  } 
}
