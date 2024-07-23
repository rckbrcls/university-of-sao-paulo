#include "parte2.h"

int main (int argc,  char *argv[]){
    char nomeArq[2000];
    
    scanf(" %s",  nomeArq);

    FILE *arquivo = abrirArquivoLeitura(nomeArq);
    Graph *graph = criarGrafo(arquivo);  

    pegarDadosArquivo(arquivo, graph);
    contarSorvedouros(graph);
    apagar(graph);

    return 0;
}