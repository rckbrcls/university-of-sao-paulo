#include <stdio.h>

int main(void){
    int num, maior, menor;
    scanf("%d", &num);
    maior = num;
    menor = num;
    while(!(num<=0)){
        if(num>maior)maior=num;
        if(num<menor)menor=num;
        scanf("%d", &num);
    }
    printf("%d\n", maior);
    printf("%d\n", menor);
    return 0;
}