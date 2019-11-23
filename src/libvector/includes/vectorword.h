#ifndef __VECTOR_WORD_H__
#define __VECTOR_WORD_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100000

typedef struct vectorword_t {
  char character[MAXTAM];
  int tail, head;
} Word;

void wordInit(Word *word);
void wordInsertChar(Word *word, char c);
void wordDeleteChar(Word *word, char searched, char *deleted);
void wordToString(Word *word);
void wordFree(Word *word);

#endif