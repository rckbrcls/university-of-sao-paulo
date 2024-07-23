#include <stdio.h>

int main(void){
    int n, maior = 0;
    scanf("%d", &n);
    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
        if(maior<vetor[i]){
            maior = vetor[i];
        }
    }
    printf("%d\n", maior);
    return 0;
}