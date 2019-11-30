#include "./includes/quicksort.h"

static void _partitionBookVector(VectorBook *arr, int l, int r, int *i, int *j, Metric *metric) {
  *i = l;
  *j = r;

  VectorText pivo = arr->texts[ (*i + *j)/2 ];

  do {
    while (pivo.size > arr->texts[*i].size) {
      (*i)++;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }

    while (pivo.size < arr->texts[*j].size) { 
      (*j)--;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    
    if (*i <= *j) {
      VectorText aux = arr->texts[*i];
      arr->texts[*i] = arr->texts[*j];
      arr->texts[*j] = aux;

      (*i)++;
      (*j)--;

      metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move

    }
    
    metricSetComparisons(metric, metricGetComparisons(metric) + 4);
    
  } while (*i <= *j);

}

static void _partitionTextVector(VectorText *arr, int l, int r, int *i, int *j, Metric *metric) {
  *i = l;
  *j = r;

  VectorWord pivo = arr->words[ (*i + *j)/2 ];

  do {
    while (tolower(pivo.character[0]) > tolower(arr->words[*i].character[0])) { 
      (*i)++;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }

    while (tolower(pivo.character[0]) < tolower(arr->words[*j].character[0])) {
      (*j)--;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    
    if (*i <= *j) {
      VectorWord aux = arr->words[*i];
      arr->words[*i] = arr->words[*j];
      arr->words[*j] = aux;

      (*i)++;
      (*j)--;

      metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move

    }

    metricSetComparisons(metric, metricGetComparisons(metric) + 4);
    
  } while (*i <= *j);
}

static void _partitionLinkedBook(LinkedBook *linkedBook, int l, int r, int *i, int *j, Metric *metric) {
  *i = l;
  *j = r;

  LinkedText pivo = linkedBookGet(*linkedBook, ((*i + *j)/2))->lt;

  do {
    while (linkedTextSize(pivo) > linkedTextSize(linkedBookGet(*linkedBook, *i)->lt)) {
      (*i)++;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }

    while (linkedTextSize(pivo) < linkedTextSize(linkedBookGet(*linkedBook, *j)->lt)) { 
      (*j)--;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
    }
    
    if (*i <= *j) {
      linkedBookSwap(linkedBook, *i, *j);

      (*i)++;
      (*j)--;
      metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
    }

    metricSetComparisons(metric, metricGetComparisons(metric) + 4); //break conditions + comparison inside while
    
  } while (*i <= *j);
}

static void _partitionLinkedText(LinkedText *linkedText, int l, int r, int *i, int *j, Metric *metric) {
  *i = l;
  *j = r;

  LinkedWord pivo = linkedTextGet(*linkedText, ((*i + *j)/2))->lw;

  do {
    while (tolower(pivo->c) > tolower(linkedTextGet(*linkedText, *i)->lw->c)) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
      (*i)++;
    } 
    
    while (tolower(pivo->c) < tolower(linkedTextGet(*linkedText, *j)->lw->c)) {
      (*j)--;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
    }

    if (*i <= *j) {
      linkedTextSwap(linkedText, *i, *j);

      (*i)++;
      (*j)--;
      
      metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
    }
    
    metricSetComparisons(metric, metricGetComparisons(metric) + 4); //break conditions + comparison inside while

  } while (*i <= *j);  
}

void quickSortVectorBook(VectorBook *book, int l, int r, Metric *metric) {
  int i, j;
  _partitionBookVector(book, l, r, &i, &j, metric);
  if (l < j) quickSortVectorBook(book, l, j, metric);
  if (i < r) quickSortVectorBook(book, i, r, metric);
}

void quickSortVectorText(VectorText *text, int l, int r, Metric *metric) {
  int i, j;
  _partitionTextVector(text, l, r, &i, &j, metric);
  if (l < j) quickSortVectorText(text, l, j, metric);
  if (i < r) quickSortVectorText(text, i, r, metric);
}

void quickSortLinkedBook(LinkedBook *lb, int l, int r, Metric *metric) {
  int i, j;
  _partitionLinkedBook(lb, l, r, &i, &j, metric);
  if (l < j) quickSortLinkedBook(lb, l, j, metric);
  if (i < r) quickSortLinkedBook(lb, i, r, metric);
}

void quickSortLinkedText(LinkedText *lt, int l, int r, Metric *metric) {
  int i, j;
  _partitionLinkedText(lt, l, r, &i, &j, metric);
  if (l < j) quickSortLinkedText(lt, l, j, metric);
  if (i < r) quickSortLinkedText(lt, i, r, metric);
}
