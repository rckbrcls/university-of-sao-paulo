#include <stdio.h>
#include <stdlib.h>

int soma(int *vetor, int tam){ 
    if (tam <= 0) 
        return 0;
    return (soma(vetor, tam-1) + vetor[tam-1]); 
} 

int main(void){ 

    int tam = 0; 

    printf("Escreva o tamanho do vetor: ");
    scanf("%d", &tam);
    printf("\n");

    int *vetor = malloc(sizeof(int)*tam); 

    for(int i = 0; i < tam; i++){
        printf("%d - ", i);
        scanf("%d", &vetor[i]);
        printf("\n");
    }

    printf("%d\n", soma(vetor, tam));

    free(vetor);

    return 0; 
} 