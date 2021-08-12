#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct doc{  
  char nome[55];
  struct doc *prox;
} DOCUMENTO;

typedef struct{
  DOCUMENTO *topo;
} PILHA;

// declarando as funções
void push(PILHA* pilha, DOCUMENTO *documento);
void pop(PILHA* pilha);
int length(PILHA* pilha);
void iniciarPilha(PILHA* pilha);
void limparPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
DOCUMENTO *input(char *nome);

int main(void) {

  PILHA duracell;

  iniciarPilha(&duracell);
  push(&duracell, input("vitoria"));
  push(&duracell, input("isabela"));
  push(&duracell, input("larissa"));
  pop(&duracell);

  imprimirPilha(&duracell);

  return 0;
}

DOCUMENTO *input(char *nome){

  DOCUMENTO *documento = (DOCUMENTO*) malloc(sizeof(DOCUMENTO));
  strcpy(documento->nome, nome);
  return documento;
}

void iniciarPilha(PILHA* pilha){
  pilha->topo = NULL;
}

void limparPilha(PILHA* pilha){
  DOCUMENTO *posicao = pilha->topo;
  DOCUMENTO* apagar;

  while (posicao != NULL){
    apagar = posicao;
    posicao = pilha->topo;
    free(apagar);
  }
  iniciarPilha(pilha);
}

int length(PILHA* pilha){
  DOCUMENTO *posicao = pilha->topo;
  int tamanho = 0;

  while (posicao != NULL){
    tamanho++;
    posicao = posicao->prox;
  }
  return tamanho;
}

void push(PILHA* pilha, DOCUMENTO *documento){
  documento->prox = pilha->topo;
  pilha->topo = documento;
}

void pop(PILHA* pilha){
  if (pilha->topo == NULL)
    printf("Pilha Vazia");
  
  else{
    DOCUMENTO *apagar = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(apagar);
  }
}

void imprimirPilha(PILHA* pilha){
  DOCUMENTO *posicao = pilha->topo;

  while (posicao != NULL){
    printf("%s\n", posicao->nome);
    posicao = posicao->prox;
  }
}