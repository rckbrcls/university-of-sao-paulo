#include <stdio.h>
#include <string.h>
// Copia char por char para o outro arquivo
void copia(FILE *src, FILE *dest){
    char aux;
    for(int i = 1; i < 500; i++){
        if(!feof(src)){
            aux = fgetc(src); 
            fprintf(dest, "%c", aux);
        }
    }
}

int main(int argc, char *argv[]){
    FILE *src = NULL;
    FILE *dest = NULL;

    src = fopen(argv[1],"r");
    dest = fopen(argv[2], "w");
    if (src==NULL || dest==NULL){
        printf("ERRO!\n");
        return -1;
    }
    
    copia(src, dest);

    printf("Arquivos copiados com sucesso!\n");

    fclose(src);
    fclose(dest);
    return 0;
}