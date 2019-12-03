#ifndef __VECTOR_TEXT_H__
#define __VECTOR_TEXT_H__

#include "vectorword.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../liblinked/includes/linkedtext.h"

typedef struct vectortext_t {
  VectorWord *words;
  int size;
  int capacity;
} VectorText;

void textInit(VectorText *text, int cap);
int textInsertWord(VectorText *text, VectorWord word);
int textDeleteWord(VectorText *text, int searched, VectorWord *deleted);
void vectorTextToLinkedText(LinkedText* lt, VectorText vt);
int textSize(VectorText text);
void textFree(VectorText *text);

#endif
