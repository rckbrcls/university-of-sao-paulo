#include <stdio.h>

int main(void){
    int num, impar = 0, par = 0;

    while(1){
        scanf("%d", &num);
        if((num<=0)) break;
        if(num%2==0){
            par++;
        }else if(num%2==1){
            impar++;
        }
    }
    printf("%d\n%d\n", impar, par);
    return 0;
}