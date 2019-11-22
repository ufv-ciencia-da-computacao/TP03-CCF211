#include "includes/linkedtext.h"

static int isEmpty(LinkedText lt) {
  return lt == NULL;
}

static LinkedText create(LinkedWord lw) {
  LinkedText new = (LinkedText) malloc(sizeof(struct text_t));
  new->next = NULL;
  new->lw = lw;
}

static void nodeFree(LinkedText lt) {
  /* free word */
  free(lt);
}

void LinkedTextInit(LinkedText *lt) {
  *lt = NULL;
}

void LinkedTextInsert(LinkedText *lt, LinkedWord lw) {
  LinkedText iterator = *lt;
  if(isEmpty(*lt)) {
    *lt = create(lw);
  } else {
    while (iterator->next != NULL) {
      iterator = iterator->next;
    }
    iterator->next = create(lw);
  }
}

void LinkedTextRemove(LinkedText *lt, LinkedWord lw) {
  if(isEmpty(*lt)) return; 
  LinkedText iterator = *lt, prev = NULL, remove;
  while(iterator != NULL) {
    if(LinkedWordEquals(iterator->lw, lw)) {
      if(prev == NULL) {
        *lt = iterator->next;
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

int  LinkedTextSize(LinkedText lt) {
  if(isEmpty(lt)) return 0;
  LinkedText iterator = lt;
  int size = 0;
  while(iterator != NULL) {
    size++;
    iterator = iterator->next;
  }
  return size;
}

void LinkedTextToString(LinkedText lt, char *str) {
  
}

