#include <stdio.h>
#include <string.h>
void substitui(char string1[25], char string2[25], char string3[25]){
    int k, j, flag;

    for(int i = 0; string1[i]!= '\0'; i++){
        if(string1[i] == string2[0]){
            flag = 1;
            k = i;
            for(j = 0; string2[j] != '\0'; j++){
                if(string2[j] != string1[i]){
                    flag = 0;
                }
                i++;
            }  
            i--;
            if(flag){
                for(j = 0; string3[j] != '\0'; j++){
                    string1[k] = string3[j];    
                    k++;         
                }  
            }    
        }
    }
}    
int main(void){
    char string1[25], string2[25], string3[25];

    scanf("%s %s %s", string1, string2, string3);

    substitui(string1, string2, string3);

    printf("%s", string1);

    return 0;
}