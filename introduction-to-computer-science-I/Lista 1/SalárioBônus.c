#include<stdio.h>
#include<math.h>

int main(){
    double salario, vendas, total;

    scanf("%lf %lf", &salario, &vendas);
    
    vendas = (vendas*15)/100;
    total = salario+vendas;

    printf("%.2lf\n", total);

    return 0;
}