#include <stdio.h>
#include <string.h>

// Conta as ocorrências da palavra
int ocorrencia(FILE *arquivo, char palavra[50]){
    int count = 0;
    char aux[50];
    while (fscanf(arquivo, "%s", aux)!=EOF){ // Enquanto não for o final do arquivo
        if(strcmp(palavra, aux) == 0){ // Se achar a palavra, incrementa
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]){
    char palavra[50];
    FILE *arquivo = NULL;
    
    arquivo = fopen(argv[1], "r");
    if (arquivo==NULL){
        printf("ERRO!\n");
        return -1;
    }
    
    printf("Escreva a palavra que deseja ver a ocorrência no arquivo:\n");
    scanf("%s", palavra);
    
    int count = ocorrencia(arquivo, palavra);
    if(count == 0){
        printf("Não há ocorrências dessa palavra no arquivo\n");
    }else{
        printf("A palavra %s apareceu %d vezes no arquivo\n", palavra, count);
    }
    
    fclose(arquivo);
    return 0;
}