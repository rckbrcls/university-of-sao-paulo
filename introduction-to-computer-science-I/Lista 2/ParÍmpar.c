#include <stdio.h>

int main(){
    int num;

    scanf("%d", &num);

    if(num<=0){
        printf("INVALIDO\n");
        return 1;
    }

    if(num%2==0){
        printf("PAR\n");
    }else{
        printf("IMPAR\n");
    }

    return 0;
}