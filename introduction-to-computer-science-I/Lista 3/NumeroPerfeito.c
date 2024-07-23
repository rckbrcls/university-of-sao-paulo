#include <stdio.h>

int main(void){
    int num, i, aux = 0;
    
    scanf("%d", &num);
    
    for(i = 1; i < num; i++){
        if(num%i==0){
            aux += i;
        }
    }
    if(aux == num){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }
    return 0;
}