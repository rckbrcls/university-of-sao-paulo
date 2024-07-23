#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Estrutura da palavra
typedef struct palavras{
    char palavra[50];
}word;
//Função que aloca e inicializa as strings
word *aloca(){
    word *aux = malloc(sizeof(word)*100);
    for(int i = 0; i < 100; i++){
        strcpy(aux[i].palavra, "NULL");
    }
    return aux;
}
// Verifica se já contou essa palavra
int existe(word *aux, int u, char palavra[50]){
    if (u == 0) return 0;
    for (int i = 0; i <= u; i++)
        if (strcmp(aux[i].palavra, palavra) == 0) return 1;
    return (0);
}
// Atribui as strings do arquivo para o vetor de struct
word *atribuir(FILE *arq){
    word *vetor = aloca();
    int i = 0;
    while (fscanf(arq, "%s", vetor[i].palavra)!=EOF){ 
        i++;
    }
    return vetor;
}
// Verifica se há uma palavra igual nos arquivos
int comum(FILE *arquivo_1, FILE *arquivo_2, word *iguais){
    int count = 0;
    word *aux1 = atribuir(arquivo_1);
    word *aux2 = atribuir(arquivo_2);

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(strcmp(aux1[i].palavra, aux2[j].palavra) == 0){ //Se achar uma palavra em comum
                if(!existe(iguais, count, aux1[i].palavra)){
                    iguais[count] = aux1[i];
                    count++;
                }
            }
        }   
    }
    return count;
}

int main(int argc, char *argv[]){
    FILE *arquivo_1 = NULL;
    FILE *arquivo_2 = NULL;
    word *iguais = aloca();

    arquivo_1 = fopen(argv[1], "r");
    arquivo_2 = fopen(argv[2], "r");
    if (arquivo_1==NULL || arquivo_2==NULL){
        printf("ERRO!\n");
        return -1;
    }
    int count = comum(arquivo_1, arquivo_2, iguais);
    
    if(strcmp(iguais[0].palavra, "NULL") == 0){ // Verifica se eles têm alguma palavra igual
        printf("Os arquivos não têm palavras iguais\n");
    }else{
        if(count == 1){
            printf("Os arquivos têm uma palavra igual\nA palavra é:\n");
        }else{
            printf("Os arquivos têm %d palavras iguais\nAs palavras são:\n", count);
        }
        for(int i = 0; i < count; i++){
            printf("%d - %s\n", i+1, iguais[i].palavra);
        }
    }
    free(iguais);
    fclose(arquivo_1);
    fclose(arquivo_2);
    return 0;
}