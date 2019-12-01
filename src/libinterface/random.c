#include "./includes/random.h"

void randomInit() {
  srand(time(0));
}

void randomPrintWord(int length, FILE *stream) {
  int i;
  for(i=0; i<length; i++) {
    fprintf(stream, "%c", (char) ((rand() % 26) + (rand() % 2 ? 'A' : 'a')));
  }
}

void randomPrintText(int minWords, int maxWords, int maxWordLen, FILE *stream) {
  int i, wordLen, 
      words = minWords + (rand() % (maxWords - minWords + 1));
  
  for(i=0; i<words; i++) {
    wordLen = rand() % maxWordLen + 1;
    randomPrintWord(wordLen, stream);
    fprintf(stream, i != words-1 ? " " : "");
  }
}

void randomPrintBook(int texts, int minWords, int maxWords, int maxWordLen, FILE *stream) {
  int i;
  for(i=0; i<texts; i++) {
    randomPrintText(minWords, maxWords, maxWordLen, stream);
    fprintf(stream, "\n");
  }
}

void randomReadVectorWord(int length, VectorWord *word) {
  int i;
  for(i=0; i<length; i++) {
    wordInsertChar(word, (char) ((rand() % 26) + (rand() % 2 ? 'A' : 'a')));
  }
}

void randomReadVectorText(int minWords, int maxWords, int maxWordLen, VectorText *text) {
  int i, wordLen, 
      words = minWords + (rand() % (maxWords - minWords + 1));
  VectorWord vw;
  for(i=0; i<words; i++) {
    wordInit(&vw);
    wordLen = rand() % maxWordLen + 1;
    randomReadVectorWord(wordLen, &vw);
    textInsertWord(text, vw);
  }
}

void randomReadVectorBook(int texts, int minWords, int maxWords, int maxWordLen, VectorBook *book) {
  int i;
  VectorText vt;
  for(i=0; i<texts; i++) {
    textInit(&vt);
    randomReadVectorText(minWords, maxWords, maxWordLen, &vt);
    bookInsertText(book, vt);
  }
}

void randomReadLinkedWord(int length, LinkedWord *word) {
  int i;
  for(i=0; i<length; i++) {
    linkedWordInsert(word, (char) ((rand() % 26) + (rand() % 2 ? 'A' : 'a')));
  }
}

void randomReadLinkedText(int minWords, int maxWords, int maxWordLen, LinkedText *text) {
  int i, wordLen, 
      words = minWords + (rand() % (maxWords - minWords + 1));
  LinkedWord lw;
  for(i=0; i<words; i++) {
    linkedWordInit(&lw);
    wordLen = rand() % maxWordLen + 1;
    randomReadLinkedWord(wordLen, &lw);
    linkedTextInsert(text, lw);
  }
}

void randomReadLinkedBook(int texts, int minWords, int maxWords, int maxWordLen, LinkedBook *book) {
  int i;
  LinkedText lt;
  for(i=0; i<texts; i++) {
    linkedTextInit(&lt);
    randomReadLinkedText(minWords, maxWords, maxWordLen, &lt);
    linkedBookInsert(book, lt);
  }
}

