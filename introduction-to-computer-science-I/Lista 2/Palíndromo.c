#include <stdio.h>

int main(){
    int num, aux, reverse;

    scanf("%d", &num);

    if(num<100||num>999){
        printf("INVALIDO\n");
        return 1;
    }

    aux = num;
    reverse = 0;

    while (aux != 0) {
        reverse = reverse * 10 + aux % 10;  
        aux = aux / 10;               
    }

    if (reverse == num){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

    return 0;
}