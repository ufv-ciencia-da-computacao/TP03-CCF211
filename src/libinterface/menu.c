#include "./includes/menu.h"

void menuInit(Menu *menu) {
  menu->texts = 5;
  menu->minWords = 1;
  menu->maxWords = 10;
  menu->maxWordLen = 5;
  menu->vector_linked = 0;
  menu->quick_selection = 0;
}

int menuShow(Menu menu) {
  system("cls");
  printf("-------------- MENU --------------\n");
  printf("1- Criar Biblioteca (%d textos, %d a %d palavras, ate %d letras)\n", menu.texts, menu.minWords, menu.maxWords, menu.maxWordLen);
  printf("2- Alterar Padrao de Criacao\n");
  printf("3- Mostrar Biblioteca\n");
  printf("4- Ordenar Biblioteca\n");
  printf("5- Ordenar Textos\n");
  printf("6- Trocar Odenacao (%s sort ativo)\n", menu.quick_selection ? "selection" : "quick");
  printf("7- Trocar Estrutura (lista %s ativa)\n", menu.vector_linked ? "encadeada" : "vetor");
  printf("0- Sair\n");
  printf(": ");
  int opt;
  scanf("%d", &opt);
  return opt;
}

void menuToggleSort(Menu *menu) {
  menu->quick_selection = !menu->quick_selection;
}

void menuToggleStruct(Menu *menu) {
  menu->vector_linked = !menu->vector_linked;
}

void menuSetParameters(Menu *menu) {
  printf("Numero de textos: ");
  scanf("%d", &menu->texts);
  printf("Minimo de palavras: ");
  scanf("%d", &menu->minWords);
  printf("Maximo de palavras: ");
  scanf("%d", &menu->maxWords);
  printf("Tamanho maximo de palavra (max 20): ");
  scanf("%d", &menu->maxWordLen);
}

void menuContinue() {
  printf("\npressione ENTER para continuar...\n");
  fflush(stdin);
  getchar();
}
