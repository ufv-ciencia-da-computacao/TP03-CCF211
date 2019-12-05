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
  bookInit(&vb, 1);

  LinkedText lt;
  linkedTextInit(&lt);

  VectorText vt;
  textInit(&vt, 1);

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
      menuSetParameters(&menu);
      break;
    
    case 2: 
      menuToggleStructure(&menu);
      break;

    case 3:
      menuToggleImplementation(&menu);
      break;

    case 4:
      menuToggleSort(&menu);
      break;    

    case 5:
      if(menu.text_book) {
        if(menu.vector_linked) {
          linkedBookFree(&lb);
          linkedBookInit(&lb);
          randomReadLinkedBook(menu.texts, menu.minWords, menu.maxWords, menu.maxWordLen, &lb);
        } else {
          bookFree(&vb);
          bookInit(&vb, menu.texts);
          randomReadVectorBook(menu.texts, menu.minWords, menu.maxWords, menu.maxWordLen, &vb);
        }
      } else {
        if(menu.vector_linked) {
          linkedTextFree(&lt);
          linkedTextInit(&lt);
          randomReadLinkedText(randomInterval(menu.minWords, menu.maxWords), menu.maxWordLen, &lt);
        } else {
          textFree(&vt);
          textInit(&vt, menu.maxWords);
          randomReadVectorText(randomInterval(menu.minWords, menu.maxWords), menu.maxWordLen, &vt);
        }
      }
      break; 
    
    case 6: 
      if(menu.text_book) {
        if(menu.vector_linked) {
          filePrintLinkedBook(stdout, lb);
        } else {
          filePrintVectorBook(stdout, vb);
        }
      } else {
        if(menu.vector_linked) {
          filePrintLinkedText(stdout, lt);
        } else {
          filePrintVectorText(stdout, vt);
        }
      }
      menuContinue();
      break;

    case 7:
      metricInit(&metric);
      if(menu.text_book) {
          if(menu.vector_linked) {
            if(menu.quick_selection) {
              selectionSortLinkedBook(&lb, &metric);
            } else {
              quickSortLinkedBook(&lb, lb.head, lb.tail, &metric);
            }
          } else {
            if(menu.quick_selection) {
              selectionSortVectorBook(&vb, &metric);
            } else {
              quickSortVectorBook(&vb, 0, bookSize(vb)-1, &metric);
            }
          }
      } else {
        if(menu.vector_linked) {
          if(menu.quick_selection) {
            selectionSortLinkedText(&lt, &metric);
          } else {
            quickSortLinkedText(&lt, lt.head, lt.tail, &metric);
            // quickSort(lt, lt.head, lt.tail);
          }
        } else {
          if(menu.quick_selection) {
            selectionSortVectorText(&vt, &metric);
          } else {
            quickSortVectorText(&vt, 0, textSize(vt)-1, &metric);
          }
        }
      }
      metricFinish(&metric);
      filePrintMetric(metric);
      menuContinue();
      break;
    
    default: exit = 1;
      break;
    }
  }

  linkedBookFree(&lb);
  linkedTextFree(&lt);
  textFree(&vt);
  bookFree(&vb);

  return 0;
}
