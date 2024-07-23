#include <stdio.h>
#include <string.h>
int substring(char string1[25], char string2[25]){
    int j = 0, flag = 0;

    for(int i = 0; string1[i]!= '\0'; i++){
        if(string1[i] == string2[0]){
            flag = 1;
            for(j = 0; string2[j] != '\0'; j++){
                if(string2[j] != string1[i]){
                    flag = 0;
                }
                i++;
            } 
        }
    }

    if(flag){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char string1[25], string2[25];

    scanf("%s %s", string1, string2);

    if(substring(string1, string2)){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

    return 0;
}