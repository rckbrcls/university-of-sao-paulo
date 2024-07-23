#include <stdio.h>
#include <string.h>

int palindromo(char string[25]){
    char inversa[25];
    int verif;

    strcpy(inversa, string);
    size_t size = strlen(inversa);
    
    for(int i = 0; i < size/2; i++) {
       char tmp = inversa[i]; 
       inversa[i] = inversa[size - i - 1]; 
       inversa[size - i - 1] = tmp; 
    }

    verif = strcmp(string, inversa);

    if(verif == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char string[25];
    scanf("%s", string);
    
    if(palindromo(string)){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

    return 0;
}