#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char string[25];
    scanf("%s", string);
    
    int tam = strlen(string);
    
    for(int i = 0; i < tam; i++ ){
        if((string[i] >= 65) && (string[i] <= 90))
            string[i] += 32;
    }

    printf("%s\n", string);
    return 0;
}