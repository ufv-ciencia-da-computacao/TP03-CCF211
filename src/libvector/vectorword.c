#include "./includes/vectorword.h"

void wordInit(Word *word) {
  word->size = 0;
}

int wordInsertChar(Word *word, char c) {
  if (word->size == MAXTAM_WORD) {
    return -1;
  } else {
    word->character[word->size++] = c;
  }

  return 0;
}

int wordDeleteChar(Word *word, int searched, char *deleted) {
  int indexSearched = -1;
  int i;
  for (i = 0; i < word->size; i++) {
    if (i == searched) {
      *deleted = word->character[i];
      indexSearched = i;
      break;
    }
  }

  if (indexSearched == -1) {
    return -1;
  } else {
    for (i = indexSearched+1; i < word->size; i++) {
      word->character[i-1] = word->character[i];
    }
  }
  word->size--;
  
  return 1;
}

int wordSize(Word word) {
  return word.size;
}

void wordPrint(FILE *stream, Word word) {
  int i;
  for(i=0; i<word.size; i++) {
    fprintf(stream, "%c", word.character[i]);
  }
}