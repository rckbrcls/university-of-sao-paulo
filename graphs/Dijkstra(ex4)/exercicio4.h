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

typedef struct fila {
    int total;
    Elem vet[TAM];
} Fila;

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

Fila * criaFila();
int estaVazia(Fila *f); 
int estaCheia(Fila *f); 
void avanca(int *valor); 
void entra(Fila *f, int valor, int prio);
int sai(Fila *f);
No *criarNo(int vert, int peso);
Graph *criarGrafo(FILE *arquivo); 
void criarAresta(Graph* graph, int vert1, int vert2, int dist); 
void apagar(Graph* graph); 
void dijkstra(Graph* graph, int vert, int distancia[graph->numVert][graph->numVert]); 
void pegarDadosArquivo(FILE *arquivo, Graph *graph);
FILE *abrirArquivoLeitura(char *nomeArq);
void criarMatrizDistancia(Graph* graph, int distancia[graph->numVert][graph->numVert]);
void imprimirMatriz(Graph *graph, int distancia[graph->numVert][graph->numVert]);
int tamNum(int n);