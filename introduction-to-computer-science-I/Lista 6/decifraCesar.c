#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Estrutura da palavra
typedef struct palavras{
    char palavra[25];
}word;
// Copia o vetor de struct para o arquivo
void copia(int num, FILE *dest, word *string){
    for(int i = 0; i < num; i++){
       fprintf(dest, "%s", string[i].palavra);
       if(i != num-1){
           fprintf(dest, "%s", " ");
       }
    }
}
// Decifra uma palavra de cada vez
char *cifra(char string[25], int chave){
    char *aux = malloc(sizeof(char)*25);
    int i = 0;
    while(string[i] != '\0'){
        aux[i] = string[i] - chave;
        if((string[i] - chave) > 122){
            aux[i] -= 26;
        }
        if((string[i] - chave) < 97){
            aux[i] += 26;
        }
        i++;
    }
    aux[i] = '\0';
    return aux; // Retorna a palavra decifrada
}
// Conta quantas palavras tem no arquivo
int count(FILE *arq, word *string){
    int i = 0;
    while (fscanf(arq, "%s", string[i].palavra)!=EOF){ 
        i++;
    }
    return i;
}

int main(int argc, char *argv[]){
    FILE *src = NULL;
    FILE *dest = NULL;
    word *string = malloc(sizeof(word)*500);

    src = fopen(argv[1],"r");
    dest = fopen(argv[2], "w");
    if (src==NULL || dest==NULL){
        printf("ERRO!\n");
        return -1;
    }

    int num = count(src, string);
    
    int chave = 0; 
    printf("Escreva a chave da cifra:\n");
    scanf("%d", &chave);
    for(int i = 0; i < num; i++){ // Copia cada palavra decifrada para o vetor
        strcpy(string[i].palavra, cifra(string[i].palavra, chave));  
    }

    copia(num, dest, string);
    printf("Arquivo decifrado com sucesso!\n");
    fclose(src);
    fclose(dest);
    return 0;
}