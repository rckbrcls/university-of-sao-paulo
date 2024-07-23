#include <stdio.h>

int main(){
    int n, fat = 1;

    scanf("%d", &n);

    while(n>0){
        fat *= n--;
    }

    printf("%d\n", fat);

    return 0;
}