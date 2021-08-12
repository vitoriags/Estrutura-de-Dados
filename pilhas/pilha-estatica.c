#include <stdio.h>

#define tamanho_max 10

// pilha estatica

typedef struct{
  int elementos[tamanho_max];
  int topo;
} PILHA;

// declarando as minhas funções

void push(PILHA* pilha, int valor);
void pop(PILHA* pilha);
int length(PILHA* pilha);
void iniciarPilha(PILHA* pilha);
void limparPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);


int main(void) {

  PILHA duracell;

  iniciarPilha(&duracell);
  push(&duracell, 2);
  push(&duracell, 4);
  push(&duracell, 6);
  push(&duracell, 8);
  push(&duracell, 9);
  push(&duracell, 0);
  push(&duracell, 10);
  push(&duracell, 10);
  push(&duracell, 10);
  push(&duracell, 10);
  push(&duracell, 10);


  imprimirPilha(&duracell);

  return 0;
}



void iniciarPilha(PILHA* pilha){
  pilha->topo = -1;
}
void limparPilha(PILHA* pilha){
  pilha->topo = -1;
}

int length(PILHA* pilha){
  return pilha->topo + 1;
}

void push(PILHA* pilha, int valor){
  if(length(pilha) < tamanho_max){
    pilha->topo = pilha->topo + 1;
    pilha->elementos[pilha->topo] = valor;
  }else
    printf("PILHA CHEIA\n");
}

void pop(PILHA* pilha){
  if(length(pilha) > 0)
    pilha->topo = pilha->topo - 1;
}

void imprimirPilha(PILHA* pilha){
  for(int i = pilha->topo; i >=0; i--){
    if(i == pilha->topo)
      printf("[%d] %d -> TOPO\n", i, pilha->elementos[i]);
    else
      printf("[%d] %d\n", i, pilha->elementos[i]);
  }
}