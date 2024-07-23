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

typedef struct lista{
    int numVert;
    No** listaAdj;
    int *cor;
}Lista;

No *criarNo(int vert);
Lista *criarGrafo(FILE *arquivo); 
void criarAresta(Lista* graph, int vert1, int vert2); 
void apagar(Lista* graph); 
void dfs(Lista* graph, int vert, int *ciclo); 
void verificaCiclo(Lista* graph);
void pegarDadosArquivo(FILE *arquivo, Lista *graph);
FILE *abrirArquivoLeitura(char *nomeArq);
FILE *abrirArquivoEscrita(char *nomeArq);