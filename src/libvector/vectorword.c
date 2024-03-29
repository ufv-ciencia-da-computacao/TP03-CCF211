#include "./includes/vectorword.h"

void wordInit(VectorWord *word, int cap) {
  word->character = (char*) malloc (cap*sizeof(char));
  word->size = 0;
  word->capacity = cap;
}

int wordInsertChar(VectorWord *word, char c) {
  if (word->size == word->capacity) {
    return -1;
  } else {
    word->character[word->size++] = c;
  }

  return 0;
}

int wordDeleteChar(VectorWord *word, int searched, char *deleted) {
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



void vectorWordToLinkedWord(LinkedWord* lw, VectorWord vw) {
  int i;
  for (i = 0; i < vw.size; i++) {
    linkedWordInsert(lw, vw.character[i]);
  }
}

int wordSize(VectorWord word) {
  return word.size;
}

void wordFree(VectorWord* word) {
  free(word->character);
}
