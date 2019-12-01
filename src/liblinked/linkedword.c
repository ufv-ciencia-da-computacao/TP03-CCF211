#include "includes/linkedword.h"

static int isEmpty(LinkedWord lw) {
  return lw == NULL;
}

static LinkedWord create(char c) {
  LinkedWord new = (LinkedWord) malloc(sizeof(struct word_t));
  new->next = NULL;
  new->c = c;
  return new;
}

void linkedWordInit(LinkedWord *lw) {
  *lw = NULL;
}

void linkedWordInsert(LinkedWord *lw, char c) {
  LinkedWord iterator = *lw;
  if(isEmpty(*lw)) {
    *lw = create(c);
  } else {
    while (iterator->next != NULL) {
      iterator = iterator->next;
    }
    iterator->next = create(c);
  }
}

LinkedWord linkedWordGet(LinkedWord lw, int index) {
  LinkedWord iterator = lw;
  int i;
  for(i=0; i<index; i++) {
    if(isEmpty(iterator)) return NULL;
    iterator = iterator->next;
  }
  return iterator;
}

void linkedWordRemove(LinkedWord *lw, int index) {
  if(isEmpty(*lw)) return; 
  LinkedWord iterator = *lw, prev = NULL;
  int i;
  for(i=0; i<index; i++) {
    if(iterator == NULL) break;
    prev = iterator;
    iterator = iterator->next;
  }
  if(i == index) {
    if(prev == NULL) {
      *lw = iterator->next;
    } else {
      prev->next = iterator->next;
    }
    free(iterator);
  }
}

int  linkedWordSize(LinkedWord lw) {
  if(isEmpty(lw)) return 0;
  LinkedWord iterator = lw;
  int size = 0;
  while(iterator != NULL) {
    size++;
    iterator = iterator->next;
  }
  return size;
}

void linkedWordSwap(LinkedWord *lw, int i, int j) {
  LinkedWord aux1 = linkedWordGet(*lw, i);
  LinkedWord aux2 = linkedWordGet(*lw, j);
  char swap = aux1->c;
  aux1->c = aux2->c;
  aux2->c = swap;
}

void linkedWordFree(LinkedWord *lw) {
  while(!isEmpty(*lw)) {
    linkedWordRemove(lw, 0);
  }
}
