#include <stdio.h>

int main (){
    float altura, peso, imc;

    scanf("%f %f", &altura, &peso);
    imc = peso/(altura*altura);

    if(imc<20){
        printf("Abaixo do peso\n");
    }else if(imc>=20 && imc<25){
        printf("Peso Normal\n");
    }else if(imc>=25 && imc<30){
        printf("Sobre Peso\n");
    }else if(imc>=30 && imc<40){
        printf("Obeso\n");
    }else if(imc>=40){
        printf("Obeso Morbido\n");
    }

    return 0;
}