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
} VectorWord;

void wordInit(VectorWord *word);
int wordInsertChar(VectorWord *word, char c);
int wordDeleteChar(VectorWord *word, int searched, char *deleted);
int wordSize(VectorWord word);

#endif
