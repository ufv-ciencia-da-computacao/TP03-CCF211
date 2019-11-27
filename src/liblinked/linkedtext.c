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

void LinkedTextRemove(LinkedText *lt, int index) {
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
    nodeFree(iterator);
  }
}

LinkedWord LinkedTextGetWord(LinkedText *lt, int index) {
  LinkedText iterator = *lt;
  int count = 0;
  
  while (iterator != NULL) {
    if (count == index) {
      return iterator->lw;
    }
    count++;
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

int LinkedTextBytes(LinkedText lt) {
  int size = 0;
  LinkedText iterator = lt;
  while(iterator != NULL) {
    size += LinkedWordBytes(iterator->lw);
    iterator = iterator->next;
  }
  return size;
}

void LinkedTextPrint(LinkedText lt, FILE *stream) {
  LinkedText iterator = lt;
  while(iterator != NULL) {
    LinkedWordPrint(iterator->lw, stream);
    fprintf(stream, iterator->next != NULL ? " " : "");
    iterator = iterator->next;
  }
}

