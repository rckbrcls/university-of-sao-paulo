#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, aux, potA, potB, potC;

    scanf("%f %f %f", &a, &b, &c);

    if(a > b){ //a b
        if(b < c){// a c b
            aux = b;
            b = c;
            c = aux; // a b c
        }
    }else if(b > c){ // b a?c
        if(a > c){// b a c
            aux = a;
            a = b;
            b = aux;
        }else{ // b c a
            aux = a;
            a = b;
            b = c;
            c = aux;
        }
    }else{ //c b a 
        aux = c;
        c = a;
        a = aux;
    } 

    potA = pow(a, 2);
    potB = pow(b, 2);
    potC = pow(c, 2);
    
    if(a>=(b+c)){
        printf("NAO FORMA TRIANGULO\n");
        return 1;
    }
    if((potA)==((potB)+(potC)))
        printf("TRIANGULO RETANGULO\n");
    if((potA)>((potB)+(potC)))
        printf("TRIANGULO OBTUSANGULO\n");
    if((potA)<((potB)+(potC)))
        printf("TRIANGULO ACUTANGULO\n");
    if(a==b && b==c && c==a)
        printf("TRIANGULO EQUILATERO\n");
    if(a!=b && b==c && a!=c)
        printf("TRIANGULO ISOSCELES\n");
    else if(a==b && b!=c && a!=c)
        printf("TRIANGULO ISOSCELES\n");
    else if(a!=b && b!=c && a==c)
        printf("TRIANGULO ISOSCELES\n");

    return 0;
}