#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Estrutura pessoa
typedef struct {
    char nome[100];
    char cidade[100];
} Pessoa;

// Função de troca para a direita
void SwapDireita(Pessoa *swp, int i){
    Pessoa aux;
    aux = swp[i];
    swp[i] = swp[i+1];
    swp[i+1] = aux;
}
// Função de troca para a esquerda
void SwapEsquerda(Pessoa *swp, int i){
    Pessoa aux;
    aux = swp[i];
    swp[i] = swp[i-1];
    swp[i-1] = aux;
}

// Função de ordenação por cocktail-sort 
void CocktailSort(int n, Pessoa* pe) {
    int inicio = 0, final = n-1 , trocou = 0, i, tam = 0;
    // Vetor de struct auxiliar que vai comparar os nomes como se todos os chars fossem minúsculos
    Pessoa *minuscula = (Pessoa*) malloc(n*sizeof(Pessoa));

    //Copia os nomes para a auxiliar
    for(int k = 0; k < n; k++){
        strcpy(minuscula[k].nome, pe[k].nome);
    }
    // Converte os chars para minúsculo
    for(int j = 0; j < n; j++){
        tam = strlen(minuscula[j].nome);
        for(int k = 0; k < tam; k++){// Pecorre a string
            minuscula[j].nome[k] = tolower(minuscula[j].nome[k]);//Diminui caractere por caractere
        }
    }
    /* Se não houver troca de posições ou o ponteiro que
       sobe ultrapassar o que desce, o vetor esta ordenado*/
    while(trocou == 0 && inicio < final){
        trocou = 1;
        // For que anda para direita
        for(i = inicio; i < final; i++){
            if(strcmp(minuscula[i].nome, minuscula[i+1].nome) > 0){
                //Troca os dois vetores de struct
                SwapDireita(minuscula, i);
                SwapDireita(pe, i);
                trocou = 0;
            }
        }
        /* Diminui o "final" porque o maior na ordem alfabética 
           já está na direita (atual posição final) */
        final = final - 1; 
        //For que anda para esquerda
        for(i = final; i > inicio; i = i - 1){  
            if(strcmp(minuscula[i].nome, minuscula[i - 1].nome) < 0){
                //Troca os dois vetores de struct
                SwapEsquerda(minuscula, i);
                SwapEsquerda(pe, i);
                trocou = 0;
            }
        }
        /* Aumenta o "inicio" porque o menor valor já está
           na posição inicial (inicio)*/ 
        inicio = inicio + 1;  
    }
    free(minuscula); 
}

// Função que entra nomes e que quebra string total e a atribui para o vetor de struct
void EntrarNomes(int n, Pessoa* pe){
    char *total = malloc(100*sizeof(char));

    for(int i = 0; i < n; i++){
        scanf("%[^\n]s", total);
        getchar();

        char* token;    
        token = strtok(total, "."); //Função para separar strings
        strcpy(pe[i].nome, token); //Atribui nome
        strcat(pe[i].nome, "."); // Concatena "." 
        token = strtok(NULL, "."); // Separa no segundo "." delimitador
        strcpy(pe[i].cidade, token); //Atribui cidade
        strcat(pe[i].cidade, "."); // Concatena "."
    }

    free(total);
}

//Função que imprime os nomes ordenados
void print(int n, Pessoa *pe){
    for(int i = 0; i < n; i++){
        printf("%s\n", pe[i].nome);
    }
}

// Checa se os nomes moram em São Carlos
void ChecarMoradia(char busca[70], Pessoa *pe, int k, int n){
    for(int i = 0; i < n; i++){
        if(strcmp(busca, pe[i].nome) == 0){//Acha a pessoa
            if(strcmp(pe[i].cidade, " Sao Carlos.") == 0){ //Verifica se mora São Carlos
                printf("1\n"); // Mora
            }else{
                printf("0\n"); // Não mora
            }
            return;
        }
    }
}

// Main
int main (void){
    int n = 0, k = 0;
    Pessoa* pe;
    char busca[70];

    scanf("%d ", &n);
    pe = malloc(sizeof(Pessoa)*n); // Aloca vetor de struct

    EntrarNomes(n, pe);
    CocktailSort(n, pe);
    print(n, pe);

    scanf("%d ", &k);
    
    for(int i = 0; i < k; i++){
        scanf("%[^\r]s", busca);// Nome que vai verificar se mora em São Carlos
        getchar();
        getchar();
        ChecarMoradia(busca, pe, k, n); // Checa
    }
    return 0;
}