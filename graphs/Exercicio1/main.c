#include "erdosrenyi.h"

int main(int argc, char *argv[]){

    srand(time(NULL));

    int num = 0, sel = 0;

    printf("ESCREVA O NUMERO DE NOS:\n");
    scanf("%d", &num);

    int **matrizGrafo = alocarMatriz(num);
    criarMatriz(num, matrizGrafo);

    // menu de açoes 
    do{
        printf("\n\n----MENU DE AÇOES----\n0 - SAIR\n1 - IMPRIMIR MATRIZ\n2 - GRAU E ADJACENTES DE UM VERTICE\n3 - EXISTENCIA DE UMA ARESTA\n");
        printf("-------------------------------------------\n\n");
        scanf("%d", &sel);
        
        if(sel == 1)
            imprimirMatriz(num, matrizGrafo);
        else if(sel == 2)
            grauVertice (num, matrizGrafo);
        else if(sel == 3)
            arestaExiste(num, matrizGrafo);
            
    }while(sel != 0);
    
    liberarMatriz(num, matrizGrafo);

    printf("FIM!\n");
    return 0;
}