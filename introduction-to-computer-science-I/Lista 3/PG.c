#include <stdio.h>
#include <math.h>

int main(void){
    int num_1 = 0, num = 0, razao = 0;
    
    scanf("%d %d", &num_1, &razao);
    
    for(int i = 1; i <= 8; i++){    
        num = (num_1 * pow(razao, i - 1));
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}