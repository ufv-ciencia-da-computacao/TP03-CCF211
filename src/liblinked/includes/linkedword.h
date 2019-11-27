#ifndef __LINKED_WORD_H__
#define __LINKED_WORD_H__

#include <stdlib.h>

typedef struct word_t * LinkedWord;
struct word_t {
  char c;
  LinkedWord next;
};

void LinkedWordInit(LinkedWord *lw);
void LinkedWordInsert(LinkedWord *lw, char c);
void LinkedWordRemove(LinkedWord *lw, int index);
int  LinkedWordSize(LinkedWord lw);
int  LinkedWordBytes(LinkedWord lw);
int  LinkedWordEquals(LinkedWord lw1, LinkedWord lw2);
void LinkedWordToString(LinkedWord lw, char **str);

#endif
