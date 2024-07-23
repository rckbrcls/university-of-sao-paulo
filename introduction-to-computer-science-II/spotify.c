#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Estrutura do artista
typedef struct artista{
    char nome[100];
    char id[100];
    int nTracks;
    float popularidade;
}Artista;
//Função que aloca vetor de struct e incializa seus elementos
Artista *aloca(int num){
    Artista *aux = (Artista*)malloc(sizeof(Artista)*num);
    for(int i = 0; i < num; i++){
        strcpy(aux[i].nome, "NULL");
        strcpy(aux[i].id, "NULL");
        aux[i].nTracks = 0;
        aux[i].popularidade = 0;
    }
    return aux;
}
//Conta numero de músicas
int contarM(char *nomeArq){
    FILE *fp = fopen(nomeArq,"r");
    int ch = 0, linhas = 1;

    if (fp == NULL)
        return 0;

    while (!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n') // A cada linha uma música
            linhas++;
    }
    fclose(fp);
    return linhas;
}
//Verifica se o nome do artista já existe no vetor
int existe(Artista *aux, int u, char auxNome[50]){
    if (u == 0) return 0;
    for (int i = 0; i <= u; i++){
        if (strcmp(aux[i].nome, auxNome) == 0) return 1;
    }
    return (0);
}
//Calcular popularidade
float calcPopulariade(char nome[100], Artista *aux, int num){
    float soma = 0, media = 0;
    int divisor = 0;
    for(int i = 0; i < num; i++){
        if(strcmp(aux[i].nome, nome) == 0){
            soma += aux[i].popularidade;
            divisor++;
        }
    }
    return media = soma/divisor;
}
//Somar todas as tracks do artista
float somaTracks(char nome[100], Artista *aux, int num){
    int soma = 0;
    for(int i = 0; i < num; i++){
        if(strcmp(aux[i].nome, nome) == 0){
            soma++;
        }
    }
    return soma;
}
//Troca posições do vetor
void troca(Artista *a, Artista *b) { 
    Artista t = *a; 
    *a = *b; 
    *b = t; 
} 
//Pega o último elemento da partição como pivô, e o põe na posição correta
int particao (Artista *art, int inicio, int fim) { 
    float pivo = art[fim].popularidade;    // pivô 
    int i = (inicio - 1);  // Menor elemento
  
    for (int j = inicio; j <= fim- 1; j++){
        if (art[j].popularidade > pivo) { 
            i++;    // Incrementa o menor elemento 
            troca(&art[i], &art[j]);  
        } 
    } 
    troca(&art[i + 1], &art[fim]); 
    return (i + 1); 
}
//Função de ordenação
void quickSort(Artista *art, int inicio, int fim){ 
    if (inicio < fim) {
        int pi = particao(art, inicio, fim);

        quickSort(art, inicio, pi - 1); 
        quickSort(art, pi + 1, fim); 
    } 
}
//Função que imprime
void print(Artista *art, int numeroTracks, int numeroArts){ 
    printf("O Dataset contem %d Artistas e %d Musicas\nOs artistas mais populares sao:\n", numeroArts, numeroTracks);
    for(int i  = 0; i < numeroArts; i++){
        printf("(%d) Artista: %s, Musicas: %d musicas, Popularidade: %.2lf, Link: https://open.spotify.com/artist/%s\n", i+1,
        art[i].nome, art[i].nTracks, art[i].popularidade, art[i].id);
    }
}
//Pega o "n" dado na linha do arquivo
char* pegaLinha(char* linha, int n){
    char* tok;
    for (tok = strtok(linha, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--n)
            return tok;
    }
    return NULL;
}
//Verifica se existe alguma linha está faltando um dado
int vazio(char linha[1025]){
    int count = 0;
    char *token = strtok(linha, ";");

    while (token != NULL) {// Conta quantos elementos tem na linha
        token = strtok(NULL, ";\n");
        count++;
    }
    if(count < 19)// Se estiver faltando
        return 1;
    return 0;
}
//Atribui os dados do arquivo
char *arqToVet(char linha[1025], int x){
    //Verifica se está faltando dados
    int v = 0;
    char auxlinha[1025];
    strcpy(auxlinha, linha);
    if(vazio(auxlinha))//Se sim, diminui até onde procurar
        v = 1;
    
    char* tmp = strdup(linha);

    if(x == 0)
        return pegaLinha(tmp, 5-v);
    else if(x == 1)
        return pegaLinha(tmp, 6-v);
    
    return pegaLinha(tmp, 9-v);
}
//Função que faz todas as atribuições
void atribuir(FILE *arquivo, int num){
    Artista *aux = aloca(num);
    int flag = 0, numeroArts = 0, numeroTracks = 0;
    char linha[1025], nome[50];
    
    while (fgets(linha, 1024, arquivo)){
        if(flag > 0){//Se já tiver passado pela primeira linha
            //Pega os nomes que estão no arquivo e atribuem para o vetor
            strcpy(nome, arqToVet(linha, 0));
            if (nome[0] == ' ') 
                memmove(nome, nome+1, strlen(nome));
            if(!existe(aux, numeroTracks, nome))
                numeroArts++;
            strcpy(aux[numeroTracks].nome, nome);
            //Pega os id's que estão no arquivo e atribuem para o vetor
            strcpy(aux[numeroTracks].id, arqToVet(linha, 1));
            if (aux[numeroTracks].id[0] == ' ') 
                memmove(aux[numeroTracks].id, aux[numeroTracks].id+1, strlen(aux[numeroTracks].id));
            //Pega as popularidades que estão no arquivo e atribuem para o vetor
            aux[numeroTracks].popularidade = atof(arqToVet(linha, 2));
            
            numeroTracks++;//Icrementa o número de tracks
        }
        flag++;
    }
    // Pega os dados do auxiliar e atribui para um vetor mais comprimido
    Artista *art = aloca(numeroArts); //Aloca com o tamanho certo de artistas
    int j = 0;
    for(int i = 0; i < num; i++){ // Pecorre o auxiliar até achar um artista diferente
        if(!existe(art, numeroArts, aux[i].nome)){ // Se o acha, atribui os dados para o art
            strcpy(art[j].nome, aux[i].nome);
            strcpy(art[j].id, aux[i].id);
            art[j].popularidade = calcPopulariade(aux[i].nome, aux, num);
            art[j].nTracks = somaTracks(aux[i].nome, aux, num);
            j++;// Próxima posição do art
        }
    }
    quickSort(art, 0, numeroArts-1); //Ordena
    print(art, numeroTracks, numeroArts);//Imprime o vetor de struct
    free(aux);
    free(art);
}

int main(int argc, char *argv[]){
    char nomeArq[50];
    scanf("%s", nomeArq);
    int num = contarM(nomeArq);
    
    FILE *arquivo = fopen(nomeArq,"r");
    if (arquivo == NULL)
    {
        printf("ERRO!\n");
        exit(-1);
    }

    atribuir(arquivo, num);
    fclose(arquivo);
    return 0;
}