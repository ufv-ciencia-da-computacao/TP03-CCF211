#ifndef __VECTOR_WORD_H__
#define __VECTOR_WORD_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM_WORD 10
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../../liblinked/includes/linkedword.h"

typedef struct vectorword_t {
  char character[MAXTAM_WORD];
  int size;
} VectorWord;

void wordInit(VectorWord *word);
int wordInsertChar(VectorWord *word, char c);
int wordDeleteChar(VectorWord *word, int searched, char *deleted);
void vectorWordToLinkedWord(LinkedWord* lw, VectorWord vw);
int wordSize(VectorWord word);

#endif
