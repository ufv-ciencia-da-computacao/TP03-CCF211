#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"

#include "../../liblinked/includes/linkedbook.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedword.h"

void selectionSortVectorBook(Book *arr);
void selectionSortVectorText(Text *arr);
void selectionSortLinkedText(LinkedText linkedText);
void selectionSortLinkedBook(LinkedBook linkedBook);

#endif
