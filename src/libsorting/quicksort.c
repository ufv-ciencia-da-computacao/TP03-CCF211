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

static void _partitionLinkedBook(LinkedBook *linkedBook, BookNode *head, BookNode *tail, Metric *metric) {

  BookNode pivo = linkedBook->head;

  do {
    while (pivo->lt.size > (*head)->lt.size) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
      *head = (*head)->next;
    } 
    
    while (pivo->lt.size < (*tail)->lt.size) {
      *tail = (*tail)->prev;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
    }

    if ((*head)->index <= (*tail)->index) {
      // linkedBookSwap(linkedBook, *head, *tail);

      *head = (*head)->next;
      *tail = (*tail)->prev;
      
      metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
    }
    
    metricSetComparisons(metric, metricGetComparisons(metric) + 4); //break conditions + comparison inside while

  } while ((*head)->index <= (*tail)->index); 
}

static void _partitionLinkedText(LinkedText *linkedText, TextNode *head, TextNode *tail, Metric *metric) {

  TextNode pivo = linkedText->head;

  do {
    while (tolower(pivo->lw.head->c) > tolower((*head)->lw.head->c)) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
      *head = (*head)->next;
    } 
    
    while (tolower(pivo->lw.head->c) < tolower((*tail)->lw.head->c)) {
      *tail = (*tail)->prev;
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
    }

    if ((*head)->index <= (*tail)->index) {
      linkedTextSwap(linkedText, *head, *tail);

      *head = (*head)->next;
      *tail = (*tail)->prev;
      
      metricSetMoves(metric, metricGetMoves(metric) + 1); // swap move
    }
    
    metricSetComparisons(metric, metricGetComparisons(metric) + 4); //break conditions + comparison inside while

  } while ((*head)->index <= (*tail)->index);  
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

void quickSortLinkedBook(LinkedBook *lb, Metric *metric) {
  LinkedBook interval;
  _partitionLinkedBook(lb, &(interval.head), &(interval.tail), metric);
  
  metricSetComparisons(metric, metricGetComparisons(metric) + 2);

  if (lb->head->index < interval.tail->index) 
    quickSortLinkedBook(&interval, metric);
  
  if (interval.head->index < lb->tail->index) 
    quickSortLinkedBook(&interval, metric);
}

void quickSortLinkedText(LinkedText *lt, Metric *metric) {
  LinkedText interval;
  _partitionLinkedText(lt, &(interval.head), &(interval.tail), metric);
  
  metricSetComparisons(metric, metricGetComparisons(metric) + 2);

  if (lt->head->index < interval.tail->index) 
    quickSortLinkedText(&interval, metric);
  
  if (interval.head->index < lt->tail->index) 
    quickSortLinkedText(&interval, metric);
}
