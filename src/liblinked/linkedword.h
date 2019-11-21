#ifndef __WORD_H__
#define __WORD_H__

#include <stdlib.h>

typedef struct word_t * LinkedWord;
struct word_t {
  char c;
  LinkedWord next;
};

void LinkedWordInit(LinkedWord *lw);
void LinkedWordInsert(LinkedWord *lw, char c);
void LinkedWordRemove(LinkedWord *lw, char c);
int  LinkedWordSize(LinkedWord lw);
void LinkedWordToString(LinkedWord lw, char *str);

#endif
