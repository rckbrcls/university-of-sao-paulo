#include<stdio.h>

int main(){
    int dist;
    double combust, media;

    scanf("%d %lf", &dist, &combust);

    media = dist/combust;

    printf("%.3lf\n", media);

    return 0;
}