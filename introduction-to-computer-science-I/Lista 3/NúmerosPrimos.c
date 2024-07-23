#include <stdio.h>

int main(void){
    int aux = 0;
    for(int i = 10; i < 100; i++){
        for(int j = 1; j < 100; j++){
            if(i%j == 0 ){
                aux++;
            }
        }
        if(aux == 2){
            printf("%d ", i);
        }
        aux = 0;
    }
    return 0;
}