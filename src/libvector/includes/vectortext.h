#ifndef __VECTOR_TEXT_H__
#define __VECTOR_TEXT_H__

#include "vectorword.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXTAM_TEXT 100

typedef struct vectortext_t {
  Word words[MAXTAM_TEXT];
  int size;
} Text;

void textInit(Text *text);
int textInsertWord(Text *text, Word word);
int textDeleteWord(Text *text, int searched, Word *deleted);
int textSize(Text text);
void textPrint(FILE *stream, Text text);

#endif
