#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

void randomInit();
void randomWord(int length, FILE *stream);
void randomText(int minWords, int maxWords, int maxWordLen, FILE *stream);
void randomBook(int texts, int minWords, int maxWords, int maxWordLen, FILE *stream);

#endif
