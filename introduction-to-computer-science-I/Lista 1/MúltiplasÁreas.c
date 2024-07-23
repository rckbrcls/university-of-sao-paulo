#include<stdio.h>

int main(){
    double a, b, c, areat, areac, areatr, areaq, arearet;

    scanf("%lf %lf %lf", &a, &b, &c);

    areat = (a*c)/2;
    areac = (c*c)*3.14159;
    areatr = (a+b)*c;
    areatr =  areatr/2;
    areaq = b*b;
    arearet = a*b;

    printf("%.3lf\n%.3lf\n%.3lf\n%.3lf\n%.3lf\n", areat, areac, areatr, areaq, arearet);

    return 0;
}