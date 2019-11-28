#ifndef __VECTOR_WORD_H__
#define __VECTOR_WORD_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM_WORD 15
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct vectorword_t {
  char character[MAXTAM_WORD];
  int size;
} Word;

void wordInit(Word *word);
int wordInsertChar(Word *word, char c);
int wordDeleteChar(Word *word, int searched, char *deleted);
int wordSize(Word word);
void wordPrint(FILE *stream, Word word);

#endif
