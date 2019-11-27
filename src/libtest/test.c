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

void randomText(FILE *stream, int length, int maxWordLen) {
  int i, total = 0, wordLen;
  while(total < length) {
    wordLen = rand() % maxWordLen + 1;
    randomWord(stream, wordLen);
    total += wordLen;
    fprintf(stream, i != total < length ? " " : "");
    total++;
  }
}

void randomBook(FILE *stream, int texts, int length, int maxWordLen) {
  int i;
  for(i=0; i<texts; i++) {
    randomText(stream, length, maxWordLen);
    fprintf(stream, "\n");
  }
}
