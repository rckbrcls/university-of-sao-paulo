#include<stdio.h>

int main(void){
    int matriz[3][3], det = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

   for(int i = 0; i < 3; i++)
      det = det + (matriz[0][i]*(matriz[1][(i+1)%3]*matriz[2][(i+2)%3] - matriz[1][(i+2)%3]*matriz[2][(i+1)%3]));

    printf("%d\n", det);
    
    return 0;
}