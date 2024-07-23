#include "exercicio3a.h"

int main (int argc,  char *argv[]){
    char nomeArq[50];

    scanf(" %s",  nomeArq);

    FILE *arquivo = abrirArquivoLeitura(nomeArq);
    Lista *graph = criarGrafo(arquivo);  

    pegarDadosArquivo(arquivo, graph);
    numeroDeComponentes(graph);

    apagar(graph);
    fclose(arquivo);

    return 0;
}