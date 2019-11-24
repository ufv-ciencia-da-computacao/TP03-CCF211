#include "./includes/vectortext.h"

void textInit(Text *text) {
  text->size = 0;
}

int textInsertWord(Text *text, Word word) {
  if (text->size == MAXTAM) {
    return -1;
  } else {
    text->words[text->size++] = word;
  }  

  return 0;
}

int textDeleteWord(Text *text, int searched, Word *deleted) {
  int indexSearched = -1;
  for (int i = 0; i < text->size; i++) {
    if (i == searched) {
      *deleted = text->words[i];
      indexSearched = i;
      break;
    }
  }

  if (indexSearched == -1) {
    return -1;
  } else {
    for (int i = indexSearched+1; i < text->size; i++) {
      text->words[i-1] = text->words[i];
    }
  }
  
  return 1;
}

bool textIsEmpty(Text *text) {
  if (text->size == 0) {
    return true;
  }
  return false;
}

void textToString(Text *text, char *str) {
  for (int i = 0; i < text->size; i++) {
    wordToString(&(text->words[i]), str);
    strcat(str, " ");
  }
}