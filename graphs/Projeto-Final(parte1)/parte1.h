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
}Graph;

No *criarNo(int vert);
Graph *criarGrafo(FILE *arquivo); 
void criarAresta(Graph* graph, int vert1, int vert2); 
void apagar(Graph* graph); 
void buscarFonte(Graph* graph, int vert);
void contarFontes(Graph* graph);
void pegarDadosArquivo(FILE *arquivo, Graph *graph);
FILE *abrirArquivoLeitura(char *nomeArq);
FILE *abrirArquivoEscrita(char *nomeArq);