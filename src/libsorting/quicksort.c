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

static void _partitionLinkedBook(LinkedBook *linkedBook, BookNode *l, BookNode *r, BookNode *head, BookNode *tail, Metric *metric) {

  *head = *l;
  *tail = *r;

  BookNode pivo = (*l);

  do {

    if(*head == NULL || *tail == NULL) break;

    while (pivo->lt.size > (*head)->lt.size && (*head)->index <= (*r)->index) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
      *head = (*head)->next;
    }

    while (pivo->lt.size < (*tail)->lt.size && (*tail)->index >= (*l)->index) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
      *tail = (*tail)->prev;
    }

    if ((*head)->index <= (*tail)->index) {
      BookNode auxHead = (*head)->next;
      BookNode auxTail = (*tail)->prev;

      if(*head == *l) *l = *tail;
      if(*tail == *r) *r = *head;

      linkedBookSwap(linkedBook, *head, *tail);
      
      if(auxHead == *tail || auxTail == *head) break;

      *head = auxHead;
      *tail = auxTail;

      metricSetMoves(metric, metricGetMoves(metric) + 1);
    }
    
    metricSetComparisons(metric, metricGetComparisons(metric) + 4);

  } while ((*head)->index <= (*tail)->index); 
}

static void _partitionLinkedText(LinkedText *linkedText, TextNode *l, TextNode *r, TextNode *head, TextNode *tail, Metric *metric) {
  *head = *l;
  *tail = *r;

  TextNode pivo = (*l);

  do {

    if(*head == NULL || *tail == NULL) break;

    while (tolower(pivo->lw.head->c) > tolower((*head)->lw.head->c) && (*head)->index <= (*r)->index) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1); 
      *head = (*head)->next;
    }

    while (tolower(pivo->lw.head->c) < tolower((*tail)->lw.head->c) && (*tail)->index >= (*l)->index) {
      metricSetComparisons(metric, metricGetComparisons(metric) + 1);
      *tail = (*tail)->prev;
    }

    if ((*head)->index <= (*tail)->index) {
      TextNode auxHead = (*head)->next;
      TextNode auxTail = (*tail)->prev;

      if(*head == *l) *l = *tail;
      if(*tail == *r) *r = *head;

      linkedTextSwap(linkedText, *head, *tail);
      
      if(auxHead == *tail || auxTail == *head) break;

      *head = auxHead;
      *tail = auxTail;

      metricSetMoves(metric, metricGetMoves(metric) + 1);
    }
    
    metricSetComparisons(metric, metricGetComparisons(metric) + 4);

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

void quickSortLinkedBook(LinkedBook *lb, BookNode l, BookNode r, Metric *metric) {
  if(l == r) return;
  BookNode i = l, j = r;
  _partitionLinkedBook(lb, &l, &r, &i, &j, metric);
    
  metricSetComparisons(metric, metricGetComparisons(metric) + 2);  

  if (j != NULL && l->index < j->index) 
    quickSortLinkedBook(lb, l, j, metric);

  if (i != NULL && i->index < r->index) 
    quickSortLinkedBook(lb, i, r, metric);
}

void quickSortLinkedText(LinkedText *lt, TextNode l, TextNode r, Metric *metric) {
  if(l == r) return;
  TextNode i = l, j = r;
  _partitionLinkedText(lt, &l, &r, &i, &j, metric);
    
  metricSetComparisons(metric, metricGetComparisons(metric) + 2);  

  if (j != NULL && l->index < j->index) 
    quickSortLinkedText(lt, l, j, metric);

  if (i != NULL && i->index < r->index) 
    quickSortLinkedText(lt, i, r, metric);
}
