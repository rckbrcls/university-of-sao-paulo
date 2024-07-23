#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define TAM 1000
#define branco 0
#define cinza 1
#define preto 2

typedef struct elem { 
    int valor;
    int prioridade;
}Elem;

typedef struct heap {
    int total;
    Elem *vet;
} Heap;

typedef struct no {
    int vertice;
    int peso;
    struct no* prox;
}No;

typedef struct graph{
    int numVert;
    No** listaAdj;
    int *cor;
}Graph;

Heap criaHeap(int n);
void swap(Heap *h, int i, int j);
int pai(int i);
int filhoEsquerdo(int i);
int filhoDireito(int i);
void paraCima(Heap *h, int i);
int eFolha(Heap h, int pos);
void paraBaixo(Heap *h, int i);
void inserirFila(Heap *h, int x, int p);
Elem removerPrioridade(Heap *h);
void mudarPrioridade(Heap *h, int i, int p);
No *criarNo(int vert, int peso);
Graph *criarGrafo(FILE *arquivo);
void criarAresta(Graph* graph, int vert1, int vert2, int peso);
void apagar(Graph* graph); 
int buscar(Heap *h, int v);
void atribuirpai(int i, int *pai, int x);
void prim(Graph* graph, int vert); 
void pegarDadosArquivo(FILE *arquivo, Graph *graph);
FILE *abrirArquivoLeitura(char *nomeArq);
void printGraph(Graph* graph);