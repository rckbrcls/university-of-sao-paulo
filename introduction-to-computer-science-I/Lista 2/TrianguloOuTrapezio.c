#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, area, perimetro;

    scanf("%f %f %f", &a, &b, &c);
    
    if(a>=(b+c)){
        area = ((a+b)*c)/2;
        printf("Area = %.1f\n", area);
    }else{
        perimetro = a+b+c;
        printf("Perimetro = %.1f\n", perimetro);
    }

    return 0;
}