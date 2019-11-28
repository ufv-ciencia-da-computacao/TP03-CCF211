#include "./includes/quicksort.h"

static void _partitionBookVector(Book *arr, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  Text pivo = arr->texts[ (*i + *j)/2 ];

  do {
    while (pivo.size > arr->texts[*i].size) (*i)++;
    while (pivo.size < arr->texts[*j].size) (*j)--;
    
    if (*i <= *j) {
      Text aux = arr->texts[*i];
      arr->texts[*i] = arr->texts[*j];
      arr->texts[*j] = aux;

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);

}

static void _partitionTextVector(Text *arr, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  Word pivo = arr->words[ (*i + *j)/2 ];

  do {
    while (tolower(pivo.character[0]) > tolower(arr->words[*i].character[0])) (*i)++;
    while (tolower(pivo.character[0]) > tolower(arr->words[*j].character[0])) (*j)--;
    
    if (*i <= *j) {
      Word aux = arr->words[*i];
      arr->words[*i] = arr->words[*j];
      arr->words[*j] = aux;

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);
}

static void _partitionLinkedBook(LinkedBook *linkedBook, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  LinkedText pivo = LinkedBookGet(*linkedBook, ((*i + *j)/2))->lt;

  do {
    while (LinkedTextSize(pivo) > LinkedTextSize(LinkedBookGet(*linkedBook, *i)->lt)) (*i)++;
    while (LinkedTextSize(pivo) < LinkedTextSize(LinkedBookGet(*linkedBook, *j)->lt)) (*j)--;
    
    if (*i <= *j) {
      LinkedBookSwap(linkedBook, *i, *j);

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);
}

static void _partitionLinkedText(LinkedText *linkedText, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  LinkedWord pivo = LinkedTextGet(*linkedText, ((*i + *j)/2))->lw;

  do {
    while (tolower(pivo->c) > tolower(LinkedTextGet(*linkedText, *i)->lw->c)) (*i)++;
    while (tolower(pivo->c) < tolower(LinkedTextGet(*linkedText, *j)->lw->c)) (*j)--;
    
    if (*i <= *j) {
      LinkedTextSwap(linkedText, *i, *j);

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);
}

void quickSortVectorBook(Book *book, int l, int r) {
  int i, j;
  _partitionBookVector(book, l, r, &i, &j);
  if (l < j) quickSortVectorBook(book, l, j);
  if (i < r) quickSortVectorBook(book, i, r);
}

void quickSortVectorText(Text *text, int l, int r) {
  int i, j;
  _partitionTextVector(text, l, r, &i, &j);
  if (l < j) quickSortVectorText(text, l, j);
  if (i < r) quickSortVectorText(text, i, r);
}

void quickSortLinkedBook(LinkedBook *lb, int l, int r) {
  int i, j;
  _partitionLinkedBook(lb, l, r, &i, &j);
  if (l < j) quickSortLinkedBook(lb, l, j);
  if (i < r) quickSortLinkedBook(lb, i, r);
}

void quickSortLinkedText(LinkedText *lt, int l, int r) {
  int i, j;
  _partitionLinkedText(lt, l, r, &i, &j);
  if (l < j) quickSortLinkedText(lt, l, j);
  if (i < r) quickSortLinkedText(lt, i, r);
}
