#include "./includes/vectorword.h"

void wordInit(Word *word) {
  word->size = 0;
}

int wordInsertChar(Word *word, char c) {
  if (word->size == MAXTAM) {
    return -1;
  } else {
    word->character[word->size++] = c;
  }  

  return 0;
}

int wordDeleteChar(Word *word, int searched, char *deleted) {
  int indexSearched = -1;
  for (int i = 0; i < word->size; i++) {
    if (i == searched) {
      deleted = word->character[i];
      indexSearched = i;
      break;
    }
  }

  if (indexSearched == -1) {
    return -1;
  } else {
    for (int i = indexSearched+1; i < word->size; i++) {
      word->character[i-1] = word->character[i];
    }
  }
  
  return 1;
}

bool wordIsEmpty(Word *word) {
  if (word->size == 0) {
    return true;
  }
  return false;
}

void wordToString(Word *word, char *str) {
  for (int i = 0; i < word->size; i++) {
    strcat(str, word->character[i]);
  }
}