#include "../../libsorting/includes/quicksort.h"
#include "../../libsorting/includes/selectionSort.h"
#include <stdlib.h>
#include <time.h>

int main() {

  Word w;
  wordInit(&w);

  Text t;
  textInit(&t);

  Book b;
  bookInit(&b);

  srand(time(0));

  int i, j, k;

  for(i=rand()%10; i>=0; i--) {
    textInit(&t);
    for(j=rand()%10; j>=0; j--) {
      wordInit(&w);
      for(k=rand()%10; k>=0; k--) {
        wordInsertChar(&w, (char)(rand() % 26 + 'A'));
      }
      textInsertWord(&t, w);
    }
    vectorTextSelectionSort(&t);
    bookInsertText(&b, t);
  }

  vectorBookSelectionSort(&b);
  bookPrint(stdout, b);

  return 0;
}
