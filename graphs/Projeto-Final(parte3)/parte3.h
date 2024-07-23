#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define branco 0
#define cinza 1
#define preto 2

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

No *criarNo(int vert);
Graph *criarGrafo(FILE *arquivo); 
void criarAresta(Graph* graph, int vert1, int vert2); 
void apagar(Graph* graph);
void pegarDadosArquivo(FILE *arquivo, Graph *graph);
FILE *abrirArquivoLeitura(char *nomeArq);
FILE *abrirArquivoEscrita(char *nomeArq);
void dfs(Graph* graph, int vert, int *filhos);
void buscarSorvedouros(Graph* graph);