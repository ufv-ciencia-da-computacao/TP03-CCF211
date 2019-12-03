#include "./includes/vectortext.h"

void textInit(VectorText *text, int cap) {
  text->capacity = cap;
  text->words = (VectorWord *) malloc(cap * sizeof(VectorWord));
  text->size = 0;
}

int textInsertWord(VectorText *text, VectorWord word) {
  if (text->size == text->capacity) {
    return -1;
  } else {
    text->words[text->size++] = word;
  }  

  return 0;
}

int textDeleteWord(VectorText *text, int searched, VectorWord *deleted) {
  int indexSearched = -1;
  int i;
  for (i = 0; i < text->size; i++) {
    if (i == searched) {
      *deleted = text->words[i];
      indexSearched = i;
      break;
    }
  }

  if (indexSearched == -1) {
    return -1;
  } else {
    for (i = indexSearched+1; i < text->size; i++) {
      text->words[i-1] = text->words[i];
    }
  }

  text->size--;
  
  return 1;
}

void vectorTextToLinkedText(LinkedText* lt, VectorText vt) {
  int i, j;
  LinkedWord lw;
  for (i = 0; i < vt.size; i++) {
    vectorWordToLinkedWord(&lw, vt.words[i]);
    linkedTextInsert(lt, lw);
  }
}

int textSize(VectorText text) {
  return text.size;
}

void textFree(VectorText *text) {
  int i;
  for(i=0; i<text->size; i++) {
    wordFree(&(text->words[i]));
  }
  free(text->words);
}
