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


#include "./includes/selectionSort.h"

void vectorBookSelectionSort(Book *arr, int length);
void vectorTextSelectionSort(Text *arr, int length);
void linkedTextSelectionSort(LinkedText linkedText, int length);
void linkedBookSelectionSort(LinkedBook linkedBook, int length);

#endif