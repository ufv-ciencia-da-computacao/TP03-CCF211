#include <stdio.h>
#include "./libinterface/includes/menu.h"
#include "./liblinked/includes/linkedbook.h"
#include "./libvector/includes/vectorbook.h"
#include "./libsorting/includes/quicksort.h"
#include "./libsorting/includes/selectionSort.h"
#include "./libinterface/includes/file.h"
#include "./libinterface/includes/random.h"

int main() {

  Menu menu;
  menuInit(&menu);

  LinkedBook lb;
  linkedBookInit(&lb);

  VectorBook vb;
  bookInit(&vb);

  Metric metric;
  metricInit(&metric);

  randomInit();

  int opt;
  int exit = 0;
  int length;
  int i;

  while(!exit) {
    opt = menuShow(menu);
    switch (opt) {
    case 1: 
      if(menu.vector_linked) {
        /* free previous alocated */
        linkedBookInit(&lb);
        randomReadLinkedBook(menu.texts, menu.minWords, menu.maxWords, menu.maxWordLen, &lb);
      } else {
        bookInit(&vb);
        randomReadVectorBook(menu.texts, menu.minWords, menu.maxWords, menu.maxWordLen, &vb);
      }
      break;
    
    case 2:
      menuSetParameters(&menu);
      break;
    
    case 3: 
      printf("\n");
      if(menu.vector_linked) {
        filePrintLinkedBook(stdout, lb);
      } else {
        filePrintVectorBook(stdout, vb);
      }
      menuContinue();
      break;
    
    case 4:
      if(menu.vector_linked) {
        length = linkedBookSize(lb);
        if(menu.quick_selection) {
          selectionSortLinkedBook(lb, &metric);
        } else {
          quickSortLinkedBook(&lb, 0, linkedBookSize(lb)-1, &metric);
        }
      } else {
        if(menu.quick_selection) {
          selectionSortVectorBook(&vb, &metric);
        } else {
          quickSortVectorBook(&vb, 0, bookSize(vb)-1, &metric);
        }
      }
      break;

    case 5:
      if(menu.vector_linked) {
        length = linkedBookSize(lb);
        if(menu.quick_selection) {
          for(i=0; i<length; i++) {
            selectionSortLinkedText(linkedBookGet(lb, i)->lt, &metric);
          }
        } else {
          for(i=0; i<length; i++) {
            quickSortLinkedText(&(linkedBookGet(lb, i)->lt), 0, linkedTextSize(linkedBookGet(lb, i)->lt)-1, &metric);
          }
        }
      } else {
        length = bookSize(vb);
        if(menu.quick_selection) {
          for(i=0; i<length; i++) {
            selectionSortVectorText(&(vb.texts[i]), &metric);
          }
        } else {
          for(i=0; i<length; i++) {
            quickSortVectorText(&(vb.texts[i]), 0, textSize(vb.texts[i])-1, &metric);
          }
        }
      }
      break; 
    
    case 6: 
      menuToggleSort(&menu);
      break;

    case 7:
      menuToggleStruct(&menu);
      break;
    
    default: exit = 1;
      break;
    }
  }

  return 0;
}
