#include <stdio.h>

int main(void){
    int lin, col;
    scanf("%d %d", &lin, &col);
    //Cria e escreve na matriz
    int matriz[lin][col];
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matriz[i][j]);
        }    
    }
    // Faz a transposta
    int transposta[col][lin];
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            transposta[j][i] = matriz[i][j];
        }    
    }
    // Imprime a transposta
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j++){
            printf("%d ", transposta[i][j]);
        }    
        printf("\n");
    }

    return 0;
}