#include <stdio.h>
#include <malloc.h>

struct elemento {
  int valor;
  struct elemento* prox;
};

typedef struct {
	struct elemento* head;
  struct elemento* tail;
} FILA;

void iniciaFila(FILA* fila) {
  fila->head = NULL;
  fila->tail = NULL;
}

void adicionar(FILA* fila, int valor) {
  struct elemento* novo = (struct elemento*) malloc(sizeof(struct elemento));

  novo->valor = valor;
  novo->prox = NULL;

  if (fila->head == NULL)
    fila->head = novo; // FILA ESTA VAZIA
  
  else
    fila->tail->prox = novo;

  // ADICIONANDO NO FIM
  fila->tail = novo;
}

void remover(FILA* fila) {
  if (fila->head != NULL) {
    // REMOVENDO DO COMEÇO
    struct elemento* apagar = fila->head;
    fila->head = fila->head->prox;

    free(apagar);
    
    if (fila->head == NULL) fila->tail = NULL;
  }
}

void imprimeFila(FILA* fila) {
  struct elemento* i = fila->head;
  while(i != NULL) {
    printf("|_%d_|", i->valor);
    i = i->prox;
  }

  printf("\n\n");
}

int length(FILA* fila) {
  struct elemento* i = fila->head;
  int tamanho = 0;

  while(i != NULL) {
    tamanho++;
    i = i->prox;
  }

  return tamanho;
}

void copiaInverso(FILA* fila, FILA* fila2) {
  
  struct elemento* f1 = fila->head;
  struct elemento* anterior = NULL;

  while (f1 != NULL){
    struct elemento* conteudo = (struct elemento*) malloc(sizeof(struct elemento));

    conteudo->valor = f1->valor;
    conteudo->prox = anterior;
    fila2->head = conteudo;

    anterior = conteudo;
    f1 = f1->prox;

    if (conteudo->valor == fila->head->valor)
      fila2->tail = conteudo;
  }
}

int main(void) {
  
  FILA minhaFila;
  FILA minhaFila2;

  iniciaFila(&minhaFila);
  iniciaFila(&minhaFila2);

  adicionar(&minhaFila, 1);
  adicionar(&minhaFila, 2);
  adicionar(&minhaFila, 3);
  adicionar(&minhaFila, 4);
  adicionar(&minhaFila, 5);
  adicionar(&minhaFila, 6);
  adicionar(&minhaFila, 7);
  //remover(&minhaFila);

  copiaInverso(&minhaFila, &minhaFila2);

  imprimeFila(&minhaFila);
  imprimeFila(&minhaFila2);

  return 0;
}