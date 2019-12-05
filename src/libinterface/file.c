#include "./includes/file.h"

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
  WordNode iterator = lw.head;
  while (iterator != NULL) {
    fprintf(stream, "%c", iterator->c);
    iterator = iterator->next;
  }
}

void filePrintLinkedText(FILE *stream, LinkedText lt) {
  TextNode iterator = lt.head;
  while(iterator != NULL) {
    filePrintLinkedWord(stream, iterator->lw);
    fprintf(stream, iterator->next != NULL ? " " : "");
    iterator = iterator->next;
  }
}

void filePrintLinkedBook(FILE *stream, LinkedBook lb) {
  BookNode iterator = lb.head;
  while(iterator != NULL) {
    filePrintLinkedText(stream, iterator->lt);
    fprintf(stream, "\n");
    iterator = iterator->next;
  }
}

void filePrintMetric(Metric metric) {
  printf("O algoritmo gastou %lf segundos para executar\n", metricGetSeconds(metric));
  printf("Foram feitas %ld movimentacoes\n", metricGetMoves(&metric));
  printf("Foram feitas %ld comparacoes\n", metricGetComparisons(&metric));
}
