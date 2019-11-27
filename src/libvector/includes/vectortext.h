#ifndef __VECTOR_TEXT_H__
#define __VECTOR_TEXT_H__

#include "vectorword.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct vectortext_t {
  Word words[MAXTAM];
  int size;
} Text;

void textInit(Text *text);
int textInsertWord(Text *text, Word word);
int textDeleteWord(Text *text, int searched, Word *deleted);
bool textIsEmpty(Text *text);
void textToString(Text *text, char *str);

#endif