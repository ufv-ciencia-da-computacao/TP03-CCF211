#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"
#include "../../libvector/includes/vectorword.h"

#include "../../liblinked/includes/linkedword.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedbook.h"

void fileReadVectorBook(FILE *stream, Book *book);
void fileReadLinkedBook(FILE *stream, LinkedBook *book);

void filePrintVectorWord(FILE *stream, Word word);
void filePrintVectorText(FILE *stream, Text text);
void filePrintVectorBook(FILE *stream, Book book);

void filePrintLinkedWord(FILE *stream, LinkedWord lw);
void filePrintLinkedText(FILE *stream, LinkedText lt);
void filePrintLinkedBook(FILE *stream, LinkedBook lb);

#endif
