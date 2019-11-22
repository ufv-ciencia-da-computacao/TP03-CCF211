#include "includes/LinkedBook.h"

static int isEmpty(LinkedBook lb) {
  return lb == NULL;
}

static LinkedBook create(LinkedText lt) {
  LinkedBook new = (LinkedBook) malloc(sizeof(struct book_t));
  new->next = NULL;
  new->lt = lt;
}

static void nodeFree(LinkedBook lb) {
  /* free text */
  free(lb);
}

void LinkedBookInit(LinkedBook *lb) {
  *lb = NULL;
}

void LinkedBookInsert(LinkedBook *lb, LinkedText lt) {
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

void LinkedBookRemove(LinkedBook *lb, int index) {
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
    nodeFree(iterator);
  }
}

int  LinkedBookSize(LinkedBook lb) {
  if(isEmpty(lb)) return 0;
  LinkedBook iterator = lb;
  int size = 0;
  while(iterator != NULL) {
    size++;
    iterator = iterator->next;
  }
  return size;
}

void LinkedBookToString(LinkedBook lb, char *str) {
  
}

