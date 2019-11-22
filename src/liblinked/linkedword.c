#include "includes/linkedword.h"

static int isEmpty(LinkedWord lw) {
  return lw == NULL;
}

static LinkedWord create(char c) {
  LinkedWord new = (LinkedWord) malloc(sizeof(struct word_t));
  new->next = NULL;
  new->c = c;
}

static void nodeFree(LinkedWord lw) {
  free(lw);
}

void LinkedWordInit(LinkedWord *lw) {
  *lw = NULL;
}

void LinkedWordInsert(LinkedWord *lw, char c) {
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

void LinkedWordRemove(LinkedWord *lw, int index) {
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
    nodeFree(iterator);
  }
}

int  LinkedWordSize(LinkedWord lw) {
  if(isEmpty(lw)) return 0;
  LinkedWord iterator = lw;
  int size = 0;
  while(iterator != NULL) {
    size++;
    iterator = iterator->next;
  }
  return size;
}

int LinkedWordEquals(LinkedWord lw1, LinkedWord lw2) {
  if(!LinkedWordSize(lw1) || !LinkedWordSize(lw2)) return 0;
  LinkedWord iterator1 = lw1, iterator2 = lw2;
  while(1) {
    if(iterator1 == NULL && iterator2 == NULL) return 1;
    if(iterator1 != NULL && iterator2 != NULL && iterator1->c == iterator2->c) {
      iterator1 = iterator1->next;
      iterator2 = iterator2->next;
    } else {
      return 0;
    }
  }
  return 1;
}

void LinkedWordToString(LinkedWord lw, char *str) {
  
}
