#ifndef __LINKED_WORD_H__
#define __LINKED_WORD_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct word_t * LinkedWord;
struct word_t {
  char c;
  LinkedWord next;
};

void linkedWordInit(LinkedWord *lw);
void linkedWordInsert(LinkedWord *lw, char c);
LinkedWord linkedWordGet(LinkedWord lw, int index);
void linkedWordRemove(LinkedWord *lw, int index);
int  linkedWordSize(LinkedWord lw);
void linkedWordSwap(LinkedWord *lw, int i, int j);

#endif
