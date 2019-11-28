#ifndef __TEST_H__
#define __TEST_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

void randomInit();
void randomWord(FILE *stream, int length);
void randomText(FILE *stream, int length, int maxWordLen);
void randomBook(FILE *stream, int texts, int length, int maxWordLen);

#endif