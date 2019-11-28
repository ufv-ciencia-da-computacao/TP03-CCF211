#ifndef __LINKED_WORD_H__
#define __LINKED_WORD_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct word_t * LinkedWord;
struct word_t {
  char c;
  LinkedWord next;
};

void LinkedWordInit(LinkedWord *lw);
void LinkedWordInsert(LinkedWord *lw, char c);
LinkedWord LinkedWordGet(LinkedWord lw, int index);
void LinkedWordRemove(LinkedWord *lw, int index);
int  LinkedWordSize(LinkedWord lw);
void LinkedWordSwap(LinkedWord *lw, int i, int j);
void LinkedWordPrint(FILE *stream, LinkedWord lw);

#endif
