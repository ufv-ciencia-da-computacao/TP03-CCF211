#ifndef __VECTOR_TEXT_H__
#define __VECTOR_TEXT_H__

#include "vectorword.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct vectortext_t {
  vectorword_t words[MAXTAM];
  int tail, head;
} Text;

void textInit(Text *text);
void textInsertWord(Text *text, Word word);
void textDeleteWord(Text *text, Word searched, Word *deleted);
void textToString(Text *text);
void textFree(Text *text);

#endif