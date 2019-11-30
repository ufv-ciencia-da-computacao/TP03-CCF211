#include "./includes/vectortext.h"

void textInit(VectorText *text) {
  text->size = 0;
}

int textInsertWord(VectorText *text, VectorWord word) {
  if (text->size == MAXTAM_TEXT) {
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

int textSize(VectorText text) {
  return text.size;
}
