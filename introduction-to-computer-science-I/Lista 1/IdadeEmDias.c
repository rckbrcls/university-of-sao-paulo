#include<stdio.h>

int main(){
    int info, anos, meses, dias;

    scanf("%d", &info);

    anos = info/365; 
    meses =(info%365)/30;
    dias =(info%365)%30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);

    return 0;
}