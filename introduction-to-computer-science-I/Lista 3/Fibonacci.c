#include <stdio.h>

int main(void){
    int num = 0, num2 = 1, fib;
    printf("%d %d ", num, num2);
    for(int i = 0; i < 14; i++){
        fib = num + num2;
        num = num2;
        num2 = fib;
        printf("%d ", fib);
    }
    return 0;
}