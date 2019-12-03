#ifndef __MENU_H__
#define __MENU_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#ifdef linux
  #include <stdio_ext.h>
#endif

typedef struct {
  int texts;
  int minWords;
  int maxWords;
  int maxWordLen;
  int vector_linked;
  int quick_selection;
  char filename[FILENAME_MAX];
} Menu;

void menuInit(Menu *menu);
int  menuShow(Menu menu);
void menuToggleSort(Menu *menu);
void menuToggleStruct(Menu *menu);
void menuSetParameters(Menu *menu);
void menuContinue();

#endif
