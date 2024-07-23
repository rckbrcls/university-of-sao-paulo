#include <stdio.h>

int main (){
    float salario, novoSalario, reajuste;
    int percentual;
    scanf("%f", &salario);

    if(salario>0 && salario<=400){
        percentual = 15;
        reajuste = (percentual*salario)/100;
        novoSalario = salario+reajuste;
    }else if(salario>400 && salario<=800){
        percentual = 12;
        reajuste = (percentual*salario)/100;
        novoSalario = salario+reajuste;
    }else if(salario>800 && salario<=1200){
        percentual = 10;
        reajuste = (percentual*salario)/100;
        novoSalario = salario+reajuste;
    }else if(salario>1200 && salario<=2000){
        percentual = 7;
        reajuste = (percentual*salario)/100;
        novoSalario = salario+reajuste;
    }else if(salario>2000){
        percentual = 4;
        reajuste = (percentual*salario)/100;
        novoSalario = salario+reajuste;
    }
    
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %%\n", novoSalario, reajuste, percentual);

    return 0;
}