#include "./includes/vectortext.h"

void textInit(Text *text) {
  text->size = 0;
}

int textInsertWord(Text *text, Word word) {
  if (text->size == MAXTAM_TEXT) {
    return -1;
  } else {
    text->words[text->size++] = word;
  }  

  return 0;
}

int textDeleteWord(Text *text, int searched, Word *deleted) {
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

int textSize(Text text) {
  return text.size;
}

void textPrint(FILE *stream, Text text) {
  int i;
  for (i = 0; i < text.size; i++) {
    wordPrint(stream, text.words[i]);
    fprintf(stream, i != text.size-1 ? " " : "");
  }
}
