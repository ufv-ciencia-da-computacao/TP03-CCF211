#include "includes/linkedbook.h"

static int isEmpty(LinkedBook lb) {
  return lb == NULL;
}

static LinkedBook create(LinkedText lt) {
  LinkedBook new = (LinkedBook) malloc(sizeof(struct book_t));
  new->next = NULL;
  new->lt = lt;
  return new;
}

void linkedBookInit(LinkedBook *lb) {
  *lb = NULL;
}

void linkedBookInsert(LinkedBook *lb, LinkedText lt) {
  LinkedBook iterator = *lb;
  if(isEmpty(*lb)) {
    *lb = create(lt);
  } else {
    while (iterator->next != NULL) {
      iterator = iterator->next;
    }
    iterator->next = create(lt);
  }
}

void linkedBookRemove(LinkedBook *lb, int index) {
  if(isEmpty(*lb)) return; 
  LinkedBook iterator = *lb, prev = NULL;
  int i;
  for(i=0; i<index; i++) {
    if(iterator == NULL) break;
    prev = iterator;
    iterator = iterator->next;
  }
  if(i == index) {
    if(prev == NULL) {
      *lb = iterator->next;
    } else {
      prev->next = iterator->next;
    }
    linkedTextFree(&(iterator->lt));
    free(iterator);
  }
}

int  linkedBookSize(LinkedBook lb) {
  if(isEmpty(lb)) return 0;
  LinkedBook iterator = lb;
  int size = 0;
  while(iterator != NULL) {
    size++;
    iterator = iterator->next;
  }
  return size;
}

void linkedBookSwap(LinkedBook *lb, int i, int j) {
  LinkedBook aux1 = linkedBookGet(*lb, i);
  LinkedBook aux2 = linkedBookGet(*lb, j);
  LinkedText swap = aux1->lt;
  aux1->lt = aux2->lt;
  aux2->lt = swap;
}

LinkedBook linkedBookGet(LinkedBook lb, int index) {
  LinkedBook iterator = lb;
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


void linkedBookFree(LinkedBook *lb) {
  while(!isEmpty(*lb)) {
    linkedBookRemove(lb, 0);
  }
}
