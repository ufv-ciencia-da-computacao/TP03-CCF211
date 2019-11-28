#include "./includes/quicksort.h"

void _partitionBookVector(Book *arr, int l, int r, int *i, int *j) {
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

void _partitionTextVector(Text *arr, int l, int r, int *i, int *j) {
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

void _partitionLinkedBook(LinkedBook *linkedBook, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  LinkedText pivo = LinkedBookGetText(*linkedBook, ((*i + *j)/2));

  do {
    while (LinkedTextSize(pivo) > LinkedTextSize(LinkedBookGetText(*linkedBook, *i))) (*i)++;
    while (LinkedTextSize(pivo) < LinkedTextSize(LinkedBookGetText(*linkedBook, *j))) (*j)--;
    
    if (*i <= *j) {
      LinkedText aux = LinkedBookGetText(*linkedBook, *i);

      LinkedText textI = LinkedBookGetText(*linkedBook, *i);
      LinkedText textJ = LinkedBookGetText(*linkedBook, *j);

      textI = textJ;
      textJ = aux;

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);
}

void _partitionLinkedText(LinkedText *linkedText, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  LinkedWord pivo = LinkedTextGetWord(*linkedText, ((*i + *j)/2));

  do {
    while (tolower(pivo->c) > tolower(LinkedTextGetWord(*linkedText, *i)->c)) (*i)++;
    while (tolower(pivo->c) < tolower(LinkedTextGetWord(*linkedText, *j)->c)) (*j)--;
    
    if (*i <= *j) {
      LinkedWord aux = LinkedTextGetWord(*linkedText, *i);

      LinkedWord wordI = LinkedTextGetWord(*linkedText, *i);
      LinkedWord wordJ = LinkedTextGetWord(*linkedText, *j);

      wordI = wordJ;
      wordJ = aux;

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);
}

void quickSort(void **arr, int l, int r, void (*partition)(void**, int, int, int*, int*)) {
  int i, j;
  partition(arr, l, r, &i, &j);
  if (l < j) quickSort(arr, l, j, partition);
  if (i < r) quickSort(arr, i, r, partition);   
}
