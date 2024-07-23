#include <stdio.h>

int main (){
    int num, verif;

    scanf("%d", &num);

    verif = num%11;

    if(verif==0){
        printf("FELIZ");
    }else{
        printf("TRISTE");
    }

    return 0;
}