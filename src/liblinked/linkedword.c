#include "includes/linkedword.h"

static int isEmpty(LinkedWord lw) {
  return lw.size == 0;
}

static WordNode create(char c) {
  WordNode new = (WordNode ) malloc(sizeof(struct word_t));
  new->next = NULL;
  new->prev = NULL;
  new->c = c;

  return new;
}

void linkedWordInit(LinkedWord *lw) {
  lw->head = NULL;
  lw->tail = NULL;
  lw->size = 0;
}

void linkedWordInsert(LinkedWord *lw, char c) {
  WordNode new = create(c);
  WordNode last = lw->tail;
  if (isEmpty(*lw)) {
    lw->head = new;
  } else {
    new->prev = last;
    last->next = new;
  }
  new->index = lw->size;
  lw->tail = new;
  lw->size++;
}

WordNode linkedWordNext(WordNode wn) {
  return wn->next;
}

WordNode linkedWordPrev(WordNode wn) {
  return wn->prev;
}

void linkedWordRemove(LinkedWord *lw, WordNode index) {
  WordNode indexPrev = index->prev;
  WordNode indexNext = index->next;

  if (indexPrev != NULL) indexPrev->next = indexNext;
  else lw->head = indexNext;

  if (indexNext != NULL) indexNext->prev = indexPrev;
  else lw->tail = indexPrev;
     
  free(index);

  lw->size--;
}

int  linkedWordSize(LinkedWord lw) {
  return lw.size;
}

void linkedWordSwap(LinkedWord *lw, WordNode a, WordNode b) {
  if (a == b) return;

  WordNode temp;
  WordNode pa = a->prev;
  WordNode na = a->next;
  WordNode pb = b->prev;
  WordNode nb = b->next;
  
  if(pa != NULL) pa->next = b;
  else lw->head = b;

  if(na != NULL) na->prev = b;
  else lw->tail = b;
  
  if(pb != NULL) pb->next = a;
  else lw->head = a;
  
  if(nb != NULL) nb->prev = a;
  else lw->tail = a;

  temp = a->next;
  a->next = b->next;
  b->next = temp;
  
  temp = a->prev;
  a->prev = b->prev;
  b->prev = temp;
}

void linkedWordFree(LinkedWord *lw) {
  while (!isEmpty(*lw)) {
    linkedWordRemove(lw, lw->head);
  }
}
