#include <stdio.h>

int main (){
    float A, B, resultado;
    int C;

    scanf("%f %f %d", &A, &B, &C);

    if(C==1){
        resultado =  A+B; 
    }else if(C==2){
        resultado =  A-B; 
    }else if(C==3){
        resultado =  A*B;
    }else if(C==4){
        resultado =  A/B;
    }else{
        printf("-1\n");
        return 1;
    }
    
    printf("%.1f\n", resultado);

    return 0;
}