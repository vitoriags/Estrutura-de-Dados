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

void push(FILA* fila, int valor) {
  struct elemento* novo = (struct elemento*) malloc(sizeof(struct elemento));

  novo->valor = valor;
  novo->prox = NULL;

  if (fila->head == NULL)
    fila->head = novo;
  else
    fila->tail->prox = novo;

  fila->tail = novo;
}

void pop(FILA* fila) {
  if (fila->head != NULL) {
    struct elemento* apagar = fila->head;
    fila->head = fila->head->prox;
    free(apagar);
    
    if (fila->head == NULL)
      fila->tail = NULL;
  }
}

void imprimeFila(FILA* fila) {
  struct elemento* i = fila->head;

  while(i != NULL) {
    printf(" %d |", i->valor);
    i = i->prox;
  }
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

int main(void) {
  
  FILA fila;

  iniciaFila(&fila);

  push(&fila, 1);
  push(&fila, 2);
  push(&fila, 3);
  push(&fila, 4);
  push(&fila, 5);

  pop(&fila);

  imprimeFila(&fila);

  return 0;
}