#include "exercicio4.h"

int main (int argc,  char *argv[]){
    char nomeArq[2000];
  
    scanf(" %s",  nomeArq);

    FILE *arquivo = abrirArquivoLeitura(nomeArq);
    Graph *graph = criarGrafo(arquivo);  
    int distancia[graph->numVert][graph->numVert];

    pegarDadosArquivo(arquivo, graph);
    criarMatrizDistancia(graph, distancia);
    imprimirMatriz(graph, distancia);
    apagar(graph);

    return 0;
}