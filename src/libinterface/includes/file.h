#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include "../../libvector/includes/vectorbook.h"
#include "../../libvector/includes/vectortext.h"
#include "../../libvector/includes/vectorword.h"

#include "../../liblinked/includes/linkedword.h"
#include "../../liblinked/includes/linkedtext.h"
#include "../../liblinked/includes/linkedbook.h"

#include "./includes/file.h"

void fileReadVectorWord(char *file, Word *word, int length, int *position);
void fileReadVectorText(char *file, Text *text, int wordLength, int textLength, int *position);
void fileReadVectorBook(char *file, Book *book, int wordLength, int textLength, int bookLength, int *position);

void fileReadLinkedWord(char *file, LinkedWord *word, int length, int *position);
void fileReadLinkedText(char *file, LinkedText *text, int wordLength, int textLength, int *position);
void fileReadLinkedBook(char *file, LinkedBook *book, int wordLength, int textLength, int bookLength, int *position);

#endif