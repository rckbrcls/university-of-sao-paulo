#include<stdio.h>

int main(){
    int a, b, c, aux;
    
    scanf("%d %d %d", &a, &b, &c);
        
    if(a < b){ //a b
        if(b > c){// a c b
            aux = b;
            b = c;
            c = aux; // a b c
        }
    }else if(b < c){ // b a?c
        if(a < c){// b a c
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
    printf("%d %d %d\n", a, b, c);

    return 0;
}