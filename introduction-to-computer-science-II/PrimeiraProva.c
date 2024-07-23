#include<stdio.h>
#include<stdlib.h>
// Função de alocar matriz
double **AlocarMatriz(int m){
    double **mat;
    mat = (double **)malloc(sizeof(double*)*m);
    if(mat == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for(int i = 0; i < m; i++){
        mat[i] = (double*)malloc(sizeof(double)*m);
        if(mat[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    return mat;
}
// Função de solução
void Solucao(int m, double **mat, int i){
    if(i >= m) return; // base

    for (int j = 0; j < m; j++) {
        if (i > j) {
            mat[i][j]= (i+j)/2.0;
        } else if (i < j) {
            mat[i][j]= (i+j)/4.0; 
        } else if (i-1 >= 0){ 
            double soma = 0.0;
            for (int a = 0; a < m; a++) {
               soma+= mat[i-1][a];
            }
        mat[i][j]= soma;
        }else{
            mat[i][j]=0.0;
        }
    }
    Solucao(m, mat, i+1);
}

// Função de imprimir ultima linha
void ImprimirLinha(int m, double **mat){
    for (int i = 0; i < m; i++) {
        printf("%.2lf ", mat[m-1][i]);
    }
    printf("\n");
}
// Main
int main (void){
    int m, i = 0;
    scanf("%d", &m);

    double **mat = AlocarMatriz(m);
    Solucao(m, mat, i);
    ImprimirLinha(m, mat);

    return 0;
}