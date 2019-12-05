#include "./includes/menu.h"

void menuInit(Menu *menu) {
  menu->texts = 1000;
  menu->minWords = 10;
  menu->maxWords = 100;
  menu->maxWordLen = 1;
  menu->vector_linked = 1;
  menu->quick_selection = 0;
  menu->text_book = 0;
}

int menuShow(Menu menu) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
  printf("-------------------- MENU --------------------\n");
  printf("1- Padroes de Criacao (");
  if(menu.text_book) printf("%d textos, ", menu.texts);
  printf("%d a %d palavras, ate %d letras)\n", menu.minWords, menu.maxWords, menu.maxWordLen);
  printf("2- Trocar Estrutura (%s ativo)\n", menu.text_book ? "Biblioteca" : "Texto");
  printf("3- Trocar Implementacao (lista %s ativo)\n", menu.vector_linked ? "Encadeada" : "Vetor");
  printf("4- Trocar Odenacao (%s sort ativo)\n", menu.quick_selection ? "Selection" : "Quick");
  printf("5- Criar %s\n", menu.text_book ? "Biblioteca" : "Texto");
  printf("6- Mostrar %s\n", menu.text_book ? "Biblioteca" : "Texto");
  printf("7- Ordenar %s\n", menu.text_book ? "Biblioteca" : "Texto");
  printf("0- Sair\n");
  printf(":> ");
  int opt;
  scanf("%d", &opt);
  return opt;
}

void menuToggleSort(Menu *menu) {
  menu->quick_selection = !menu->quick_selection;
}

void menuToggleImplementation(Menu *menu) {
  menu->vector_linked = !menu->vector_linked;
}

void menuToggleStructure(Menu *menu) {
  menu->text_book = !menu->text_book;
}

void menuSetParameters(Menu *menu) {
  if(menu->text_book) {
    printf("Numero de textos: ");
    scanf("%d", &menu->texts);
  }
  printf("Minimo de palavras: ");
  scanf("%d", &menu->minWords);
  printf("Maximo de palavras: ");
  scanf("%d", &menu->maxWords);
  printf("Tamanho maximo de palavra: ");
  scanf("%d", &menu->maxWordLen);
}

void menuContinue() {
  printf("\npressione ENTER para continuar...");
  #ifdef _WIN32
    fflush(stdin);
  #else
    __fpurge(stdin);
  #endif
  getchar();
}
