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

void LinkedWordRemove(LinkedWord *lw, char c) {
  if(isEmpty(*lw)) return; 
  LinkedWord iterator = *lw, prev = NULL, remove;
  while(iterator != NULL) {
    if(iterator->c == c) {
      if(prev == NULL) {
        *lw = iterator->next;
      } else {
        prev->next = iterator->next;
      }
      remove = iterator;
      iterator = iterator->next;
      nodeFree(remove);
      continue;
    }
    prev = iterator;
    iterator = iterator->next;
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

void LinkedWordToString(LinkedWord lw, char *str) {
  
}

