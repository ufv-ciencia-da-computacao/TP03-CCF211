#ifndef __VECTOR_TEXT_H__
#define __VECTOR_TEXT_H__

#include "vectorword.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXTAM_TEXT 100

typedef struct vectortext_t {
  VectorWord words[MAXTAM_TEXT];
  int size;
} VectorText;

void textInit(VectorText *text);
int textInsertWord(VectorText *text, VectorWord word);
int textDeleteWord(VectorText *text, int searched, VectorWord *deleted);
int textSize(VectorText text);

#endif
