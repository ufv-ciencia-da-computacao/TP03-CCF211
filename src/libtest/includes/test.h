#ifndef __TEST_H__
#define __TEST_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomInit();
void randomWord(char **str, int length);
void randomText(char **str, int words, int maxWordLen);
void randomBook(char **str, int texts, int words, int maxWordLen);

#endif
