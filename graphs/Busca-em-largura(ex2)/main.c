#include "buscaLargura.h"

int main (int argc,  char *argv[]){
    char nomeArq[50];

    scanf(" %s",  nomeArq);

    FILE *arquivo = abrirArquivoLeitura(nomeArq);
    Lista *graph = criarGrafo(arquivo);    

    int distancia[graph->numVert][graph->numVert];

    pegarDadosArquivo(arquivo, graph);
    criarMatrizDistancia(arquivo, graph, distancia);
    imprimirMatriz(graph, distancia);
    apagar(graph);

    return 0;
}