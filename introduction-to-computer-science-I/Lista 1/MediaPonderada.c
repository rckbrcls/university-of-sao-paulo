#include<stdio.h>
#include<math.h>

int main(){
    float nota1, nota2, media;

    scanf("%f %f", &nota1, &nota2);

    media = (3.5*nota1)+(7.5*nota2);
    media = media/11;

    printf("%.5lf", media);

    return 0;
}