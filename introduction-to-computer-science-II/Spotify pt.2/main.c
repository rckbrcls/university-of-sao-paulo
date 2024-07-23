#include "spotify.h"

int main(int argc, char *argv[]){
    Lista *l = criaLista();
    char *string = malloc(sizeof(char)*100);
    char *arqName = malloc(sizeof(char)*200);
    int num = 0, qnt = 0;

    scanf("%s", arqName);

    FILE *arquivo = fopen(arqName,"r");
    
    if (arquivo == NULL){
        printf("ERRO!\n");
        exit(-1);
    }

    abrirArquivo(arquivo, l);

    quicksort(l->iniM, l->fimM);

    Mat **matriz = gerarMatriz(l);

    //print(l); //testar albuns, artistas e músicas

    scanf("%d %d",&num, &qnt);

    for(int i = 0; i < num; i++){
        scanf("%s", string);
        getchar();

        int index = busca(*matriz, 0, l->nTracks-1, string); 
        
        if(index != -1){ // se achar
            
            Mat *aux = radixSort(matriz, l->nTracks, index);

            imprimir(index, *matriz, aux, qnt);
        
            free(aux);
        }
    }

    fclose(arquivo);
    free(arqName);
    free(string);

    for (int i = 0; i < l->nTracks; i++)
        free(matriz[i]);
    free(matriz);
    
    destroiLista(l);

    return 0;
}