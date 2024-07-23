#include "spotify.h"

int main(int argc, char *argv[]){
    Lista *l = criaLista();
    
    char *arqName = malloc(sizeof(char)*200);

    scanf("%s", arqName);

    FILE *arquivo = fopen(arqName,"r");
    if (arquivo == NULL){
        printf("ERRO!\n");
        exit(-1);
    }

    abrirArquivo(arquivo, l);

    quicksort(l->ini, l->fim);

    //print(l); //testar albuns, artistas e músicas

    ImprimeLista(l);
    
    fclose(arquivo);
    free(arqName);

    destroiLista(l);

    return 0;
}