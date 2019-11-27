#include "includes/test.h"

void randomInit() {
  srand(time(0));
}

void randomWord(char **str, int length) {
  *str = (char *) calloc(length + 1, sizeof(char));
  int i;
  for(i=0; i<length; i++) {
    (*str)[i] = (char) ((rand() % 26) + (rand() % 2 ? 'A' : 'a'));
  }
}

void randomText(char **str, int words, int maxWordLen) {
  int i;
  char *word;
  *str = (char *) calloc(words * maxWordLen + 1, sizeof(char));
  for(i=0; i<words; i++) {
    randomWord(&word, rand() % maxWordLen + 1);
    strcat(*str, word);
    strcat(*str, " ");
    free(word);
  }
}

void randomBook(char **str, int texts, int words, int maxWordLen) {
  int i;
  *str = (char *) calloc((texts * words + 1) * maxWordLen + 1, sizeof(char));
  char *text;
  for(i=0; i<texts; i++) {
    randomText(&text, words, maxWordLen);
    strcat(*str, text);
    strcat(*str, "\n");
    free(text);
  }
}
