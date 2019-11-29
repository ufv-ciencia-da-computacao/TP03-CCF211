#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

void randomInit();
void randomWord(FILE *stream, int length);
void randomText(FILE *stream, int minWords, int maxWords, int maxWordLen);
void randomBook(FILE *stream, int texts, int minWords, int maxWords, int maxWordLen);

#endif