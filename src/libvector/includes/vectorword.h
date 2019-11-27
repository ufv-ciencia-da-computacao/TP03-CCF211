#ifndef __VECTOR_WORD_H__
#define __VECTOR_WORD_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100000
#include <stdbool.h>
#include <string.h>

typedef struct vectorword_t {
  char character[MAXTAM];
  int size;
} Word;

void wordInit(Word *word);
int wordInsertChar(Word *word, char c);
int wordDeleteChar(Word *word, int searched, char *deleted);
bool isEmpty(Word *word);
void wordToString(Word *word, char *str);

#endif