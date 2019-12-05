#ifndef __LINKED_TEXT_H__
#define __LINKED_TEXT_H__

#include <stdlib.h>
#include "linkedword.h"

typedef struct text_t * TextNode;
struct text_t {
  LinkedWord lw;
  TextNode next;
  TextNode prev;
  int index;
};

typedef struct {
  TextNode head;
  TextNode tail;
  int size;
} LinkedText;

void linkedTextInit(LinkedText *lt);
void linkedTextInsert(LinkedText *lt, LinkedWord lw);
void linkedTextRemove(LinkedText *lt, TextNode index);
TextNode linkedTextPrev(TextNode tn);
TextNode linkedTextNext(TextNode tn);
int  linkedTextSize(LinkedText lt);
void linkedTextSwap(LinkedText *lt, TextNode a, TextNode b);
void linkedTextFree(LinkedText *lt);

#endif
