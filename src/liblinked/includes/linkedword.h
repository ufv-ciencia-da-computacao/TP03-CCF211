#ifndef __LINKED_WORD_H__
#define __LINKED_WORD_H__

#include <stdlib.h>

typedef struct word_t * WordNode;
struct word_t {
  char c;
  WordNode next;
  WordNode prev;
  int index;
};

typedef struct {
  WordNode head;
  WordNode tail;
  int size;
} LinkedWord;

void linkedWordInit(LinkedWord *lw);
void linkedWordInsert(LinkedWord *lw, char c);
void linkedWordRemove(LinkedWord *lw, WordNode index);
WordNode linkedWordPrev(WordNode wn);
WordNode linkedWordNext(WordNode wn);
int  linkedWordSize(LinkedWord lw);
void linkedWordSwap(LinkedWord *lw, WordNode a, WordNode b);
void linkedWordFree(LinkedWord *lw);

#endif
