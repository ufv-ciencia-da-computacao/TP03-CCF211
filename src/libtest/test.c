#include "includes/test.h"

void randomInit() {
  srand(time(0));
}

void randomWord(FILE *stream, int length) {
  int i;
  for(i=0; i<length; i++) {
    fprintf(stream, "%c", (char) ((rand() % 26) + (rand() % 2 ? 'A' : 'a')));
  }
}

void randomText(FILE *stream, int words, int maxWordLen) {
  int i;
  for(i=0; i<words; i++) {
    randomWord(stream, rand() % maxWordLen + 1);
    fprintf(stream, i != words-1 ? " " : "");
  }
}

void randomBook(FILE *stream, int texts, int words, int maxWordLen) {
  int i;
  for(i=0; i<texts; i++) {
    randomText(stream, words, maxWordLen);
    fprintf(stream, "\n");
  }
}
