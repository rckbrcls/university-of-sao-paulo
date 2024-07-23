#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define branco 0
#define cinza 1
#define preto 2
#define TAM 100

typedef struct fila {
    int ini, fim, total;
    int vet[TAM];
} Fila;

typedef struct no {
    int vertice;
    struct no* prox;
}No;

typedef struct graph{
    int numVert;
    No** listaAdj;
    int *cor;
    int *peso;
    int **pais;
}Graph;

Fila * criaFila();
int estaVazia(Fila *f);
int estaCheia(Fila *f);
void avanca(int *valor);
void entra(Fila *f, int valor);
int sai(Fila *f);

No *criarNo(int vert);
Graph *criarGrafo(FILE *arquivo); 
void criarAresta(Graph* graph, int vert1, int vert2); 
void apagar(Graph* graph);
void pegarDadosArquivo(FILE *arquivo, Graph *graph);
FILE *abrirArquivoLeitura(char *nomeArq);
void buscarMenorDistancia(Graph* graph);
void bfs(Graph* graph, int vert, int *descendentes, int *distancia);