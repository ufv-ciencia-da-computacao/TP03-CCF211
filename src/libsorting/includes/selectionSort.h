#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"

#include "../../liblinked/includes/linkedbook.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedword.h"

#include "../../libinterface/includes/file.h"

#include "../../libmetric/includes/metric.h"

void selectionSortVectorBook(VectorBook *arr, Metric *metric);
void selectionSortVectorText(VectorText *arr, Metric *metric);
void selectionSortLinkedText(LinkedText *linkedText, Metric *metric);
void selectionSortLinkedBook(LinkedBook *linkedBook, Metric *metric);

#endif
