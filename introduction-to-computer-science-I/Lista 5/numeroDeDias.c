#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dias(char data[15]){
    int dias = 0, meses = 0, anos = 0, total = 0;

    char *token;    
    token = strtok(data, "/");
    dias = atoi(token);
    token = strtok(NULL, "/");
    meses = atoi(token);
    token = strtok(NULL, " ");
    anos = atoi(token); 

    total = (meses*31) + (anos*365) + dias;

    return total;
}

int main(void){
    char data[15];
    
    scanf("%s", data);

    printf("%d\n", dias(data));
    
    return 0;
}