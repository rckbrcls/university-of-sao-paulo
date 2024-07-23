#include<stdio.h>
#include<math.h>

int main(){
    int a, b, c, d, diferen;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    diferen = (a*b)-(c*d);

    printf("%d\n", diferen);

    return 0;
}