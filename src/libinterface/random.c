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
    randomWord(stream, wordLen);
    fprintf(stream, i != words-1 ? " " : "");
  }
}

void randomPrintBook(int texts, int minWords, int maxWords, int maxWordLen, FILE *stream) {
  int i;
  for(i=0; i<texts; i++) {
    randomText(stream, minWords, maxWords, maxWordLen);
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
  
  for(i=0; i<words; i++) {
    wordLen = rand() % maxWordLen + 1;
    randomReadVectorWord(wordLen, &(text->words[i]));
  }
}

void randomReadVectorBook(int texts, int minWords, int maxWords, int maxWordLen, VectorBook *book) {
  int i;
  for(i=0; i<texts; i++) {
    randomReadVectorText(minWords, maxWords, maxWordLen, &(book->texts[i]));
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
  
  for(i=0; i<words; i++) {
    wordLen = rand() % maxWordLen + 1;
    randomReadLinkedWord(wordLen, &(linkedTextGet(text, i)->lw));
  }
}

void randomPrintLinkedBook(int texts, int minWords, int maxWords, int maxWordLen, LinkedBook *book) {
  int i;
  for(i=0; i<texts; i++) {
    randomReadLinkedText(minWords, maxWords, maxWordLen, &(linkedBookGet(book, i)->lt));
  }
}

