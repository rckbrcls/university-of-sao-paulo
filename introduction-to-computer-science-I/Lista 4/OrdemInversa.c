#include<stdio.h>

int main(void){
    int vetor[100], aux, i = 0;
    
    while(1){
        scanf("%d", &aux);
        if(aux<=0){
            break;
        }else{
            vetor[i] = aux;
            i++;
        }
    }

    for(int k = i-1; k >= 0; k--){
        printf("%d\n", vetor[k]);
    }

    return 0;
}