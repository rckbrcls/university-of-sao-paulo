#include<stdio.h>

int main(void){
    int count = 0, vetor1[5], vetor2[3];
    
    for(int i = 0; i < 5; i++)
        scanf("%d", &vetor1[i]);
    for(int i = 0; i < 3; i++)
        scanf("%d", &vetor2[i]);

    for(int i = 0; i < 5; i++){
        if(vetor1[i]==vetor2[0]){
            for(int j = 0; j < 3; j++){
                if(vetor1[i+j]==vetor2[j]){
                    count++;
                }
            }    
        } 
    }

    if(count==3){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

    return 0;
}