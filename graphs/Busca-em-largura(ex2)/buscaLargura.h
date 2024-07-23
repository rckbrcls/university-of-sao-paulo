#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define branco 0
#define cinza 1
#define preto 2

typedef struct fila {
    int ini, fim, total;
    int vet[TAM];
} Fila;

typedef struct no {
    int vertice;
    struct no* prox;
}No;

typedef struct lista{
    int numVert;
    No** listaAdj;
    int *cor;
}Lista;

Fila * criaFila();
int estaVazia(Fila *f); 
int estaCheia(Fila *f); 
void avanca(int *valor); 
void entra(Fila *f, int valor);
int sai(Fila *f);
No *criarNo(int vert); 
Lista *criarGrafo(FILE *arquivo); 
void criarAresta(Lista* graph, int vert1, int vert2); 
void apagar(Lista* graph);
void bfs(Lista* graph, int vert, int distancia[graph->numVert][graph->numVert]);
void criarMatrizDistancia(FILE *arquivo, Lista *graph, int distancia[graph->numVert][graph->numVert]);
void imprimirMatriz(Lista *graph, int distancia[graph->numVert][graph->numVert]);
void pegarDadosArquivo(FILE *arquivo, Lista *graph);
FILE *abrirArquivoLeitura(char *nomeArq);