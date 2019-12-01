#include "includes/linkedtext.h"

static int isEmpty(LinkedText lt) {
  return lt == NULL;
}

static LinkedText create(LinkedWord lw) {
  LinkedText new = (LinkedText) malloc(sizeof(struct text_t));
  new->next = NULL;
  new->lw = lw;
  return new;
}

void linkedTextInit(LinkedText *lt) {
  *lt = NULL;
}

void linkedTextInsert(LinkedText *lt, LinkedWord lw) {
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

void linkedTextRemove(LinkedText *lt, int index) {
  if(isEmpty(*lt)) return; 
  LinkedText iterator = *lt, prev = NULL;
  int i;
  for(i=0; i<index; i++) {
    if(iterator == NULL) break;
    prev = iterator;
    iterator = iterator->next;
  }
  if(i == index) {
    if(prev == NULL) {
      *lt = iterator->next;
    } else {
      prev->next = iterator->next;
    }
    linkedWordFree(&(iterator->lw));
    free(iterator);
  }
}

LinkedText linkedTextGet(LinkedText lt, int index) {
  LinkedText iterator = lt;
  int count = 0;
  
  while (iterator != NULL) {
    if (count == index) {
      return iterator;
    }
    count++;
    iterator = iterator->next;
  }

  return NULL;
}

int linkedTextSize(LinkedText lt) {
  if(isEmpty(lt)) return 0;
  LinkedText iterator = lt;
  int size = 0;
  while(iterator != NULL) {
    size++;
    iterator = iterator->next;
  }
  return size;
}

void linkedTextSwap(LinkedText *lt, int i, int j) {
  LinkedText aux1 = linkedTextGet(*lt, i);
  LinkedText aux2 = linkedTextGet(*lt, j);
  LinkedWord swap = aux1->lw;
  aux1->lw = aux2->lw;
  aux2->lw = swap;
}

void linkedTextFree(LinkedText *lt) {
  while(!isEmpty(*lt)) {
    linkedTextRemove(lt, 0);
  }
}

