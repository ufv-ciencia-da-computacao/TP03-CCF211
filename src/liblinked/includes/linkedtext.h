#ifndef __LINKED_TEXT_H__
#define __LINKED_TEXT_H__

#include <stdlib.h>
#include "linkedword.h"

typedef struct text_t * LinkedText;
struct text_t {
  LinkedWord lw;
  LinkedText next;
};

void LinkedTextInit(LinkedText *lt);
void LinkedTextInsert(LinkedText *lt, LinkedWord lw);
void LinkedTextRemove(LinkedText *lt, int index);
LinkedWord LinkedTextGetWord(LinkedText *lt, int index);
int  LinkedTextSize(LinkedText lt);
void LinkedTextToString(LinkedText lt, char *str);

#endif
