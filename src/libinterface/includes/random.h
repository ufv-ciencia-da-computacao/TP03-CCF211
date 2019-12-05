#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"
#include "../../libvector/includes/vectorword.h"

#include "../../liblinked/includes/linkedbook.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedword.h"

void randomInit();

void randomPrintWord(int length, FILE *stream);
void randomPrintText(int minWords, int maxWords, int maxWordLen, FILE *stream);
void randomPrintBook(int texts, int minWords, int maxWords, int maxWordLen, FILE *stream);

void randomReadVectorWord(int length, VectorWord *word);
void randomReadVectorText(int words, int maxWordLen, VectorText *text);
void randomReadVectorBook(int texts, int minWords, int maxWords, int maxWordLen, VectorBook *book);
void randomReadLinkedWord(int length, LinkedWord *word);
void randomReadLinkedText(int words, int maxWordLen, LinkedText *text);
void randomReadLinkedBook(int texts, int minWords, int maxWords, int maxWordLen, LinkedBook *book);

int randomInterval(int min, int max);

#endif
