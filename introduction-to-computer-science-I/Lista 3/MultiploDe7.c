#include <stdio.h>

int main(void){
    int aux = 0;
    for(int i = 10; i < 99999; i++){
        if(i%7 == 0) aux++;
    }
    printf("%d\n", aux);
    return 0;
}