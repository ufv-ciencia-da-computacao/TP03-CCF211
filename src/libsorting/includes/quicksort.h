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

void quickSortVectorBook(VectorBook *book, int l, int r, Metric *metric);
void quickSortVectorText(VectorText *text, int l, int r, Metric *metric);
void quickSortLinkedBook(LinkedBook *lb, BookNode l, BookNode r, Metric *metric);
void quickSortLinkedText(LinkedText *lt, TextNode l, TextNode r, Metric *metric);
// void quickSort(LinkedText lt, TextNode low, TextNode high);

#endif
