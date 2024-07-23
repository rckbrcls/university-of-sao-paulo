#include<stdio.h>

int main(void){
    float vetor[5];
    int maiorIndice = 0;
    for(int i = 0; i < 5; i++){
        scanf("%f", &vetor[i]);
    }

    float maior = vetor[0];

    for(int i = 0; i < 5; i++){
        if(maior < vetor[i]){
            maior = vetor[i];
            maiorIndice = i;
        }
    }

    printf("%.1f\n%d\n", maior, maiorIndice);

    return 0;
}