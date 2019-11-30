#ifndef __LINKED_TEXT_H__
#define __LINKED_TEXT_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedword.h"

typedef struct text_t * LinkedText;
struct text_t {
  LinkedWord lw;
  LinkedText next;
};

void linkedTextInit(LinkedText *lt);
void linkedTextInsert(LinkedText *lt, LinkedWord lw);
void linkedTextRemove(LinkedText *lt, int index);
LinkedText linkedTextGet(LinkedText lt, int index);
int  linkedTextSize(LinkedText lt);
void linkedTextSwap(LinkedText *lt, int i, int j);

#endif
