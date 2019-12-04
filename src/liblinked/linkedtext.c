#include "includes/linkedtext.h"

static int isEmpty(LinkedText lt) {
  return lt.size == 0;
}

static TextNode create(LinkedWord linkedword) {
  TextNode new = (TextNode) malloc(sizeof(struct text_t));
  new->next = NULL;
  new->prev = NULL;
  new->lw = linkedword;
  return new;
}

void linkedTextInit(LinkedText *lt) {
  lt->head = NULL;
  lt->tail = NULL;
  lt->size = 0;
}

void linkedTextInsert(LinkedText *lt, LinkedWord tn) {
  TextNode new = create(tn);
  TextNode last = lt->tail;
  if (isEmpty(*lt)) {
    lt->head = new;
  } else {
    new->prev = last;
    last->next = new;
  }
  lt->tail = new;
  lt->size++;
}

TextNode linkedTextNext(TextNode tn) {
  return tn->next;
}

TextNode linkedTextPrev(TextNode tn) {
  return tn->prev;
}

void linkedTextRemove(LinkedText *lt, TextNode index) {
  TextNode indexPrev = index->prev;
  TextNode indexNext = index->next;

  if (indexPrev != NULL) indexPrev->next = indexNext;
  else lt->head = indexNext;

  if (indexNext != NULL) indexNext->prev = indexPrev;
  else lt->tail = indexPrev;
     
  linkedWordFree(&(index->lw));
  free(index);

  lt->size--;
}

int  linkedTextSize(LinkedText lt) {
  return lt.size;
}

void linkedTextSwap(LinkedText *lt, TextNode a, TextNode b) {
  if (a == b) return;

  TextNode temp;
  TextNode pa = a->prev;
  TextNode na = a->next;
  TextNode pb = b->prev;
  TextNode nb = b->next;
  
  if(pa != NULL) pa->next = b;
  else lt->head = b;

  if(na != NULL) na->prev = b;
  else lt->tail = b;
  
  if(pb != NULL) pb->next = a;
  else lt->head = a;
  
  if(nb != NULL) pb->prev = a;
  else lt->tail = a;


  temp = a->next;
  a->next = b->next;
  b->next = temp;
  
  temp = a->prev;
  a->prev = b->prev;
  b->prev = temp;
}

void linkedTextFree(LinkedText *lt) {
  while (!isEmpty(*lt)) {
    linkedTextRemove(lt, lt->head);
  }
}
