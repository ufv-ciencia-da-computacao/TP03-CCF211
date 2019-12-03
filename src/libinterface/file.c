#include "./includes/file.h"

/*FILE *fileOpen(char *filename, char *mode) {
  char fdir[32] = "./inputs/";
  strcat(fdir, filename);
  return fopen(fdir, mode);
}

void fileReadVectorBook(FILE *stream, VectorBook *book) {
  VectorWord word;
  wordInit(&word);
  VectorText text;
  textInit(&text);
  char c; //// / / / / // / / / pera ai
  while(1) {
    c = fgetc(stream);
    if(feof(stream)) break;
    if(c == ' ') {
      textInsertWord(&text, word);
      wordInit(&word);
      continue;
    }
    if(c == '\n') {
      textInsertWord(&text, word);
      bookInsertText(book, text);
      wordInit(&word);
      textInit(&text);
      continue;
    }
    wordInsertChar(&word, c);
  }
}

void fileReadLinkedBook(FILE *stream, LinkedBook *book) {
  LinkedWord word;
  linkedWordInit(&word);
  LinkedText text;
  linkedTextInit(&text);
  char c;
  while(1) {
    c = fgetc(stream);
    if(feof(stream)) break;
    if(c == ' ') {
      linkedTextInsert(&text, word);
      linkedWordInit(&word);
      continue;
    }
    if(c == '\n') {
      linkedTextInsert(&text, word);
      linkedBookInsert(book, text);
      linkedWordInit(&word);
      linkedTextInit(&text);
      continue;
    }
    linkedWordInsert(&word, c);
  }
} */

void filePrintVectorWord(FILE *stream, VectorWord word) {
  int i;
  for(i=0; i<word.size; i++) {
    fprintf(stream, "%c", word.character[i]);
  }
}

void filePrintVectorText(FILE *stream, VectorText text) {
  int i;
  for (i = 0; i < text.size; i++) {
    filePrintVectorWord(stream, text.words[i]);
    fprintf(stream, i != text.size-1 ? " " : "");
  }
}

void filePrintVectorBook(FILE *stream, VectorBook book) {
  int i;
  for (i = 0; i < book.size; i++) {
    filePrintVectorText(stream, book.texts[i]);
    fprintf(stream, "\n");
  }
}

void filePrintLinkedWord(FILE *stream, LinkedWord lw) {
  LinkedWord iterator = lw;
  while (iterator != NULL) {
    fprintf(stream, "%c", iterator->c);
    iterator = iterator->next;
  }
}

void filePrintLinkedText(FILE *stream, LinkedText lt) {
  LinkedText iterator = lt;
  while(iterator != NULL) {
    filePrintLinkedWord(stream, iterator->lw);
    fprintf(stream, iterator->next != NULL ? " " : "");
    iterator = iterator->next;
  }
}

void filePrintLinkedBook(FILE *stream, LinkedBook lb) {
  LinkedBook iterator = lb;
  while(iterator != NULL) {
    filePrintLinkedText(stream, iterator->lt);
    fprintf(stream, "\n");
    iterator = iterator->next;
  }
}

void filePrintMetric(Metric metric) {
  printf("O algoritmo gastou %lf segundos para executar\n", metricGetSeconds(metric));
  printf("Foram feitas %d movimentacoes\n", metricGetMoves(&metric));
  printf("Foram feitas %d comparacoes\n", metricGetComparisons(&metric));
}
