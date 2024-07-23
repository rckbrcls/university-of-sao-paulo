#include "erdosrenyi.h"

// Aloca dinamicamente a matriz do grafo, inicializando com 0
int **alocarMatriz(int n){
    int **temp = (int**)calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++)
        temp[i] = (int*)calloc(n, sizeof(int));

    return temp;
}
// Libera a matriz do grafo
void liberarMatriz(int n, int **matriz){
    
    for(int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);

}
// Cria grafo no modelo ernos renyi
void criarMatriz(int num, int **matrizGrafo){
    double p = 0;

    printf("ESCREVA O P ENTRE 0 E 1:\n");
    // Enquanto a p nao for entre 0 e 1, repete o laço
    while(1){ 
        scanf("%lf", &p);
        if(p > 1 || p < 0)
            printf("DIGITE UM NUMERO CORRETO:\n");
        else
            break;
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(i!=j) // Diagonal principal
                if(((double)rand() / (double)(RAND_MAX)) >= p){ // Se o numero aleatorio entre 0 e 1 for maior ou igual a p, cria a aresta
                    matrizGrafo[i][j]++;
                    matrizGrafo[j][i]++;
                }    
        }
    }
}
// Imprime a matriz
void imprimirMatriz(int num, int **matrizGrafo){
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            printf("%d      ", matrizGrafo[i][j]);
        }
        printf("\n");       
    }
}
// Acha o grau e os vertices adjacentes de um determinado vertice
void grauVertice (int num, int **matrizGrafo){
    
    int vert = 0, grau = 0;

    imprimirMatriz(num, matrizGrafo);

    printf("ESCOLHA UM VERTICE ENTRE 1 E %d:\n", num);
    scanf("%d", &vert);

    vert--;

    printf("OS VERTICES ADJACENTES SAO:\n");
    for(int i = 0; i < num; i++){
        if(matrizGrafo[vert][i] > 0){ // Se for maior que um eh adjacente
            printf("%d   |   ", i+1);
            if(matrizGrafo[vert][i] == 2) // Duas arestas
                grau += 2;
            else if(matrizGrafo[vert][i] == 1) // Uma aresta
                grau += 1;
        } 
    }
    printf("\nO GRAU DO VERTICE E: %d\n", grau);
}
// Verifica se uma aresta existe
void arestaExiste(int num, int **matrizGrafo){
    int  aresta1 = 0, aresta2 = 0;

    imprimirMatriz(num, matrizGrafo);

    printf("ESCOLHA A ARESTA (Vi, Vj):\n");
    scanf("%d%d", &aresta1, &aresta2);

    aresta1--;
    aresta2--;

    if(matrizGrafo[aresta1][aresta2] > 0)
        printf("EXISTE!\n");
    else
        printf("NAO EXISTE!\n");
}
