#include <stdio.h>
#include "./libinterface/includes/menu.h"
#include "./liblinked/includes/linkedbook.h"
#include "./libvector/includes/vectorbook.h"
#include "./libsorting/includes/quicksort.h"
#include "./libsorting/includes/selectionSort.h"
#include "./libinterface/includes/file.h"
#include "./libinterface/includes/random.h"

int main() {

  LinkedWord lw;
  Metric metric;
  metricInit(&metric);

  LinkedText lt;
  linkedTextInit(&lt);

  int i, j, k;
  //for(i=0; i<10; i++) {
    // linkedTextInit(&lt);
    randomReadLinkedText(10, 10, &lt);
    // linkedBookInsert(&lb, lt);
  // }

  // // linkedTextSwap(&lt, lt.head, lt.tail);

  // TextNode t1 = lt.head, t2 = lt.tail;
  // while(t1 != NULL && t2 != NULL) {
  //   linkedTextSwap(&lt, t1, t2);
  //   t1 = t1->next;
  //   t2 = t2->prev;
  //   printf(",");
  // }
  // printf("t1=%d, t2=%d\n", t1, t2);

  filePrintLinkedText(stdout, lt);
  // selectionSortLinkedText(&lt, &metric);
  // filePrintLinkedText(stdout, lt);

  // filePrintMetric(metric);

  // linkedTextFree(&lt);

  return 0;
}