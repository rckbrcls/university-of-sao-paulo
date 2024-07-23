#include <stdio.h>

int main(void){
    int num_1 = 0, num = 0, razao = 0;
    
    scanf("%d %d", &num_1, &razao);
    
    for(int i = 1; i <= 6; i++){    
        num = (num_1 + (i - 1) * razao);
        printf("%d ", num);
    }
    return 0;
}