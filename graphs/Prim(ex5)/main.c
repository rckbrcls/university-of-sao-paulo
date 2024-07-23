#include "exercicio5.h"

int main (int argc,  char *argv[]){
    char nomeArq[2000];
    scanf(" %s",  nomeArq);

    FILE *arquivo = abrirArquivoLeitura(nomeArq);
    Graph *graph = criarGrafo(arquivo);  

    pegarDadosArquivo(arquivo, graph);
    prim(graph, 0);
    apagar(graph);

    return 0;
}