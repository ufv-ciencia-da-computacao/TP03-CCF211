#include "includes/linkedbook.h"

static int isEmpty(LinkedBook lb) {
  return lb.size == 0;
}

static BookNode create(LinkedText linkedText) {
  BookNode new = (BookNode) malloc(sizeof(struct book_t));
  new->next = NULL;
  new->prev = NULL;
  new->lt = linkedText;
  return new;
}

void linkedBookInit(LinkedBook *lb) {
  lb->head = NULL;
  lb->tail = NULL;
  lb->size = 0;
}

void linkedBookInsert(LinkedBook *lb, LinkedText lt) {
  BookNode new = create(lt);
  BookNode last = lb->tail;
  if (isEmpty(*lb)) {
    lb->head = new;
  } else {
    new->prev = last;
    last->next = new;
  }
  lb->tail = new;
  lb->size++;
}

BookNode linkedBookNext(BookNode bn) {
  return bn->next;
}

BookNode linkedBookPrev(BookNode bn) {
  return bn->prev;
}

void linkedBookRemove(LinkedBook *lb, BookNode index) {
  BookNode indexPrev = index->prev;
  BookNode indexNext = index->next;

  if (indexPrev != NULL) indexPrev->next = indexNext;
  else lb->head = indexNext;

  if (indexNext != NULL) indexNext->prev = indexPrev;
  else lb->tail = indexPrev;
     
  linkedTextFree(&(index->lt));
  free(index);

  lb->size--;
}

int  linkedBookSize(LinkedBook lb) {
  return lb.size;
}

void linkedBookSwap(LinkedBook *lb, BookNode a, BookNode b) {
  if (a == b) return;

  BookNode temp;
  BookNode pa = a->prev;
  BookNode na = a->next;
  BookNode pb = b->prev;
  BookNode nb = b->next;
  
  if(pa != NULL) pa->next = b;
  else lb->head = b;

  if(na != NULL) na->prev = b;
  else lb->tail = b;
  
  if(pb != NULL) pb->next = a;
  else lb->head = a;
  
  if(nb != NULL) pb->prev = a;
  else lb->tail = a;


  temp = a->next;
  a->next = b->next;
  b->next = temp;
  
  temp = a->prev;
  a->prev = b->prev;
  b->prev = temp;
}

void linkedBookFree(LinkedBook *lb) {
  while (!isEmpty(*lb)) {
    linkedBookRemove(lb, lb->head);
  }
}
