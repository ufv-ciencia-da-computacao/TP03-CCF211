#include "./includes/file.h"

void fileReadVectorWord(char *file, Word *word, int length, int *position) {
  FILE *ptr;

  ptr = fopen(file, "r+");

  int counter = length;

  fseek (ptr, position, SEEK_SET);

  while (!feof(ptr) && --counter) {
    char c;
    fread(&c, 1, 1, ptr);
    wordInsertChar(word, c);
  }

  position = ftell(ptr);
}

void fileReadVectorText(char *file, Text *text, int wordLength, int textLength, int *position) {
  int i;
  for (i = 0; i < textLength; i++) {
    Word word;
    fileReadVectorWord(file, &word, wordLength, position);
    textInsertWord(text, word);
  }
}
void fileReadVectorBook(char *file, Book *book, int wordLength, int textLength, int bookLength, int *position) {
  int i;
  for (i = 0; i < bookLength; i++) {
    Text text;
    fileReadVectorText(file, &text, wordLength, textLength, position);
    bookInsertText(book, text);
  }
}

void fileReadLinkedWord(char *file, LinkedWord *word, int length, int *position) {
  FILE *ptr;

  ptr = fopen(file, "r+");

  int counter = length;

  fseek (ptr, position, SEEK_SET);

  while (!feof(ptr) && --counter) {
    char c;
    fread(&c, 1, 1, ptr);
    LinkedWordInsert(word, c);
  }

  position = ftell(ptr);
}
void fileReadLinkedText(char *file, LinkedText *text, int wordLength, int textLength, int *position) {
  int i;
  for (i = 0; i < textLength; i++) {
    LinkedWord word;
    fileReadLinkedWord(file, &word, wordLength, position);
    LinkedTextInsert(text, word);
  }
}
void fileReadLinkedBook(char *file, LinkedBook *book, int wordLength, int textLength, int bookLength, int *position) {
  int i;
  for (i = 0; i < bookLength; i++) {
    LinkedText text;
    fileReadLinkedText(file, &text, wordLength, textLength, position);
    LinkedBookInsert(book, text);
  }
}