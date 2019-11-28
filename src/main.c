#include <stdio.h>
#include "libvector/includes/vectorbook.h"

int main() {

  Word w;
  wordInit(&w);

  wordInsertChar(&w, 'a');
  wordInsertChar(&w, 'b');
  wordInsertChar(&w, 'd');
  wordInsertChar(&w, 'c');

  Text t;
  textInit(&t);

  textInsertWord(&t, w);
  textInsertWord(&t, w);
  textInsertWord(&t, w);

  Book b;
  bookInit(&b);

  bookInsertWord(&b, t);
  bookInsertWord(&b, t);
  bookInsertWord(&b, t);
  bookInsertWord(&b, t);
  bookInsertWord(&b, t);



  bookPrint(stdout, b);


  return 0;
}
