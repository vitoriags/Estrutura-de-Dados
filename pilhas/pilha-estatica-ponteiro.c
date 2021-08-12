// pilha estática com ponteiro que pergunta quantas informações deseja em sua pilha e apaga as duas últimas

#include <stdio.h>
#include <string.h>

#define tamanho_max 10

typedef struct {  
  char titulo[50];
  int valor;
  float peso;
} DOCUMENTO;

// pilha estatica
typedef struct{
  DOCUMENTO elementos[tamanho_max];
  DOCUMENTO* topo;
} PILHA;

// declarando as minhas funções
void push(PILHA* pilha, DOCUMENTO valor, int indice);
void pop(PILHA* pilha);
int length(PILHA* pilha);
void iniciarPilha(PILHA* pilha);
void limparPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
DOCUMENTO criarDocumento(char *titulo, int valor, float peso);


int main(void){

  PILHA duracell;
  int i = 0;
  char titulo[50];
  int valor;
  float peso;

  iniciarPilha(&duracell);
  int tamanho;

  printf("Quantos elementos serão adicionados na pilha?: ");
  scanf("%d", &tamanho);

  while(i < tamanho){
    printf("Titulo: ");
    scanf("%s", titulo);
    printf("Valor: ");
    scanf("%d", &valor);
    printf("Peso: ");
    scanf("%f", &peso);
    printf("\n");
    push(&duracell, criarDocumento(titulo, valor, peso), i);
    i++;
  }

  // eliminando as duas últimas informações
  pop(&duracell);
  pop(&duracell);
  imprimirPilha(&duracell);

  return 0;
}

DOCUMENTO criarDocumento(char *titulo, int valor, float peso){
  DOCUMENTO documento;
  strcpy(documento.titulo, titulo);
  documento.valor = valor;
  documento.peso = peso;
  return documento;
}

void iniciarPilha(PILHA* pilha){
  pilha->topo = NULL;
  pilha->elementos[0].valor = -1;
}
void limparPilha(PILHA* pilha){
  pilha->topo = NULL;
  pilha->elementos[0].valor = -1;
}

int length(PILHA* pilha){
  int i = 0;
    while(pilha->elementos[i].valor != -1)
      i++;
  return i;
}

void push(PILHA* pilha, DOCUMENTO valor, int indice){

  if(length(pilha) < tamanho_max){
    pilha->elementos[indice] = valor;
    pilha->topo = &pilha->elementos[indice];
    pilha->elementos[indice+1].valor = -1;  // o valor acima do topo valer -1 para ter um ponto de parada na função leigth;
  }else
    printf("PILHA CHEIA\n");
}

void pop(PILHA* pilha){
  if(length(pilha) > 0){
    pilha->topo = &pilha->elementos[length(pilha) - 2];
    pilha->elementos[length(pilha)-1].valor = -1;
  }

  else
    printf("Pilha Vazia");
}

void imprimirPilha(PILHA* pilha){
  int k = length(pilha) - 1;
  while(k >= 0){
    printf("%s ", pilha->elementos[k].titulo);
    printf("%d ", pilha->elementos[k].valor);
    printf("%.2f\n", pilha->elementos[k].peso);
    k--;
  }
}