#include<stdio.h>
#include<math.h>

int main(){
    double raio, area, pi = 3.14159;

    scanf("%lf", &raio);

    area = pi*raio*raio;

    printf("%.4lf", area);

    return 0;
}