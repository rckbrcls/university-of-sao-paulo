#include<stdio.h>

int main(void){
    int n = 0, aux = 0, k, j;
    scanf("%d", &n);
    int vetor[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for (k = 1; k < n; k++){
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}