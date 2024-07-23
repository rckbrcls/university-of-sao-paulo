#include <stdio.h>
#include <string.h>

int vogal(char verif){
    if(verif=='a'||verif=='e'||verif=='i'||verif=='o'||verif=='u')
        return 0;
    else
        return 1;
}
void remover(char string[25]){
    int i = 0, j = 0;
    while(string[i]!='\0'){
        if(vogal(string[i]) == 0){
            for(j = i; string[j] != '\0'; j++)
                string[j] = string[j+1];   
        }else{
            i++;
        }
    }
}

int main(void){
    char string[25];
    scanf("%s", string);

    remover(string);

    printf("%s\n", string);

    return 0;
}