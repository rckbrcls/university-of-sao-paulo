#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
//Struct do livro
typedef struct book{
    float preco;
    char nome[100];
}Book;
//Função de entrada dos livros
void EntrarLivro(Book *livro, int n){
    char *total = malloc(100*sizeof(char)); // String que pega o nome e o preço do livro

    for(int i = 0; i < n; i++){
        scanf("%[^\n]s", total);
        getchar();
        
        char *token;    
        token = strtok(total, ","); //Função para separar strings
        strcpy(livro[i].nome, token); //Atribui nome
        token = strtok(NULL, " ");
        livro[i].preco = atof(token); //Atribui preco
    }
    
    free(total); // Libera
}
//Função que ordena as gamas do merge
void Merge(Book *livro, int meio, int tam){
    if (tam < 2)
        return;

    int i = 0, j = meio, k = 0;
    Book aux[tam];

    while (i < meio && j < tam)
        aux[k++] = (livro[i].preco < livro[j].preco) ? livro[i++] : livro[j++];

    memcpy(aux+k, livro+i, (meio-i) * sizeof *livro);
    memcpy(livro, aux, (k + (meio-i)) * sizeof *livro);
}
//Função que imprime cada etapa 
void PrintEtapa(Book *livro, int n){
    for(int i = 0; i < n; i++){
        printf("%.2f ", livro[i].preco);
    }
}
//Função merge que divide em duas gamas
void MergeSort(Book *livro, int tam){
    PrintEtapa(livro, tam);
    printf("\n");
    if (tam < 2) // Caso todas as gamas tenham só 1 elemento, volta
        return;

    int meio = tam/2; // Meio em dois
    MergeSort(livro, meio);
    MergeSort(livro+meio, tam-meio);
    Merge(livro, meio, tam);
}
//Função merge que divide em três gamas
void MergeSort3Vias(Book *livro, int tam){
    if (tam < 3){ //              Caso tenha uma gama com menos de 3 elementos,
        MergeSort(livro, tam); // chama a função merge que divide em duas gamas
        return;
    }
    PrintEtapa(livro, tam);
    printf("\n");

    int meio1 = ceil(tam/3.0);// Primeira metade
    int meio2 = ceil((2 * tam)/3.0); // Segunda metade
    
    MergeSort3Vias(livro, meio1);
    MergeSort3Vias(livro+meio1, meio2-meio1);
    MergeSort3Vias(livro+meio2, tam-meio2);
    Merge(livro, meio1, meio2);
    Merge(livro, meio2, tam);
}
//Imprime os livros e seus preços
void Print(Book *livro, int n){
    printf("\n");
    for (int i = 0; i < n; i++){ 
        printf("%s, R$%.2f\n", livro[i].nome, livro[i].preco); 
    } 
}
//Main
int main(void){
    int n = 0;
    Book *livro = NULL;
    scanf("%d ", &n);

    livro = malloc(sizeof(Book)*n); // Aloca vetor de struct

    EntrarLivro(livro, n);
    MergeSort3Vias(livro, n);
    Print(livro, n);

    return 0;
}