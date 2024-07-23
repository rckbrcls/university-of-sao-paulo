#include<stdio.h>

int main(void){
    int n, somaP = 0, somaI = 0;
    scanf("%d", &n);
    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i]%2 == 0){
            somaP += vetor[i];
        }
        if(vetor[i]%2 == 1){
            somaI += vetor[i];
        }
    }

    printf("%d\n%d\n", somaP, somaI);
    
    return 0;
}