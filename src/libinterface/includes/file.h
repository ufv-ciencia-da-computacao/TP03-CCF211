#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"
#include "../../libvector/includes/vectorword.h"

#include "../../liblinked/includes/linkedword.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedbook.h"

#include "../../libmetric/includes/metric.h"

FILE *fileOpen(char *filename, char *mode);

void fileReadVectorBook(FILE *stream, VectorBook *book);
void fileReadLinkedBook(FILE *stream, LinkedBook *book);

void filePrintVectorWord(FILE *stream, VectorWord word);
void filePrintVectorText(FILE *stream, VectorText text);
void filePrintVectorBook(FILE *stream, VectorBook book);

void filePrintLinkedWord(FILE *stream, LinkedWord lw);
void filePrintLinkedText(FILE *stream, LinkedText lt);
void filePrintLinkedBook(FILE *stream, LinkedBook lb);

void filePrintMetric(Metric metric);

#endif
