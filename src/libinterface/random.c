#include "./includes/random.h"

void randomInit() {
  srand(time(0));
}

void randomWord(int length, FILE *stream) {
  int i;
  for(i=0; i<length; i++) {
    fprintf(stream, "%c", (char) ((rand() % 26) + (rand() % 2 ? 'A' : 'a')));
  }
}

void randomText(int minWords, int maxWords, int maxWordLen, FILE *stream) {
  int i, wordLen, 
      words = minWords + (rand() % (maxWords - minWords + 1));
  
  for(i=0; i<words; i++) {
    wordLen = rand() % maxWordLen + 1;
    randomWord(stream, wordLen);
    fprintf(stream, i != words-1 ? " " : "");
  }
}

void randomBook(int texts, int minWords, int maxWords, int maxWordLen, FILE *stream) {
  int i;
  for(i=0; i<texts; i++) {
    randomText(stream, minWords, maxWords, maxWordLen);
    fprintf(stream, "\n");
  }
}
