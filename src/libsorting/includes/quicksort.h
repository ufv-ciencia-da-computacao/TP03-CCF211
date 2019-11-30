#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"

#include "../../liblinked/includes/linkedbook.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedword.h"

#include "../../libmetric/includes/metric.h"

/* void _partitionBookVector(Book *arr, int l, int r, int *i, int *j);
void _partitionTextVector(Text *arr, int l, int r, int *i, int *j);
void _partitionLinkedBook(LinkedBook *linkedBook, int l, int r, int *i, int *j);
void _partitionLinkedText(LinkedText *linkedText, int l, int r, int *i, int *j);
*/
void quickSortVectorBook(Book *book, int l, int r, Metric *metric);
void quickSortVectorText(Text *text, int l, int r, Metric *metric);
void quickSortLinkedBook(LinkedBook *lb, int l, int r, Metric *metric);
void quickSortLinkedText(LinkedText *lt, int l, int r, Metric *metric);

#endif
