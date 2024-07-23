#include <stdio.h>

int main(){
    int n, fat = 1;

    scanf("%d", &n);

    do{
        fat *= n--;
    }while(n>0);

    printf("%d\n", fat);

    return 0;
}