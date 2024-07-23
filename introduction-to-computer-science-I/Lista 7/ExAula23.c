#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LMTRAND 500 //Limite dos números aleatórios

// Três funções de abertura de arquivos
FILE *abrir1(char *arqname){
    FILE *aux = fopen(arqname, "wb"); // Abre pra escrever
    
    if (aux == NULL){ // Caso esteja vazio
        printf("ERRO!\n");
        exit(-1);
    }
        
    return aux; // Retorna ponteiro
}
FILE *abrir2(char *arqname){
    FILE *aux = fopen(arqname, "rb+"); // Abre pra ler e escrever
    
    if (aux == NULL){ // Caso esteja vazio
        printf("ERRO!\n");
        exit(-1);
    }
        
    return aux; // Retorna ponteiro
}
FILE *abrir3(char *arqname){
    FILE *aux = fopen(arqname, "ab"); // Abre pra escrever ao final
    
    if (aux == NULL){ // Caso esteja vazio
        printf("ERRO!\n");
        exit(-1);
    }
        
    return aux; // Retorna ponteiro
}
// Troca na ordenação
void troca(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
// Partiçao do quicksort
int particao (int vet[], int base, int topo){ 
    int pivo = vet[topo]; 
    int i = (base - 1); 
  
    for (int j = base; j <= topo- 1; j++) { 
        if (vet[j] < pivo) { 
            i++;   
            troca(&vet[i], &vet[j]); 
        } 
    } 

    troca(&vet[i + 1], &vet[topo]); 
    return (i + 1); 
} 
// Quicksort
void quickSort(int vet[], int base, int topo) { 
    if (base < topo){ 
        // divide a partição
        int pi = particao(vet, base, topo); 
  
        //chamadas recursivas
        quickSort(vet, base, pi - 1); 
        quickSort(vet, pi + 1, topo); 
    }
} 
// Cria arquivo binário
void criarBin(int n, char *arqname){
    FILE *arq = abrir1(arqname);
    
    int *p = calloc(n, sizeof(int));
    // Preenche com números aleatórios
    for(int i = 0; i < n; i++){
        p[i] = rand() % LMTRAND;
    }
    // ordena
    quickSort(p, 0, n-1);

    //Passa o vetor pro arquivo
    fwrite(p, sizeof(int), n, arq);

    // Fecha e libera
    fclose(arq);
    free(p);
}

void imprimirArq(char *name) {

    FILE *fp;
    // Se existir o arquivo
    if ((fp = fopen(name, "rb"))!=NULL) {

        int item;
        //Lê o primeiro int
        fread(&item, 1, sizeof(int), fp);
        
        while (!feof(fp)) {// Até o fim do arquivo
            
            printf("%d ", item); //printa

            fread(&item,1,sizeof(int), fp);//lê o próximo int

        }
        
        printf("\n");
        fclose(fp);

    }

}
//Ordena o arquivo com bubblesort sem memória primária
void ordena(int n, char *arqname){
    FILE *bin = abrir2(arqname); // abre arquivo para leitura e escrita
    
    int num1, num2;
    size_t numSize = sizeof(int); // Tamanho de int

    fseek(bin, 0, SEEK_END); //Fim do arquivo

    int fileSize = ftell(bin); // Tira o tamanho do arquivo

    rewind(bin); // Volta pro começo
    

    for (int i = 0; i < fileSize; i += numSize){
        for (int j = 0; j < fileSize - numSize; j += numSize){
            //Pega o número da posição no arquivo para ser comparado
            fread(&num1, numSize, 1, bin);
            fread(&num2, numSize, 1, bin);
            //Compara
            if (num1 > num2){
                //faz a troca usando fseek
                fseek(bin, -(numSize * 2), SEEK_CUR);
                fwrite(&num2, numSize, 1, bin);
                fwrite(&num1, numSize, 1, bin);
                fseek(bin, -numSize, SEEK_CUR);

            }else{
                fseek(bin, -numSize, SEEK_CUR);

            }
        }
        rewind(bin); // volta pro começo do arquivo
    }

    fclose(bin); //fecha arquivo

}
//Carregar arquivo 1 no arquivo final
void carregar1(int n, int *vet, char *final){
    FILE *p = abrir1(final);
    fwrite(vet, sizeof(int), n, p);
    fclose(p);    
}
//Carregar arquivo 2 no arquivo final
void carregar2(int n, int *vet, char *final){
    FILE *p = abrir3(final);
    fwrite(vet, sizeof(int), n, p);
    fclose(p);    
}
//Carregar os dois arquivos no arquivo final
void carregarArq(int n, char *arq1, char *arq2, char *final){
    //Abre os dois para ler e escrever
    FILE *bin1 = abrir2(arq1);
    FILE *bin2 = abrir2(arq2);

    //Cria vetores auxiliares para escrever no arquivo final
    int *vet1 = malloc(n*sizeof(int));
    int *vet2 = malloc(n*sizeof(int));

    //Lê os vetores do arquivo e passa pros auxiliares
    fread(vet1, sizeof(int), n, bin1);
    fread(vet2, sizeof(int), n, bin2);

    //Carrega os vetores para o arquivo
    carregar1(n, vet1, final);
    carregar2(n, vet2, final);

    fclose(bin1);
    fclose(bin2);
    free(vet1);
    free(vet2);
}

int main(int argc, char *argv[]){
    //Semente rand
    srand(time(0));
    
    int n = 0;

    scanf("%d", &n);

    criarBin(n, argv[1]);
    criarBin(n, argv[2]);
    
    printf("Primeiro arquivo:\n");
    imprimirArq(argv[1]);
    printf("\nSegundo arquivo:\n");
    imprimirArq(argv[2]);

    carregarArq(n, argv[1], argv[2], argv[3]);
    
    printf("\nArquivo final antes da ordenação:\n");
    imprimirArq(argv[3]);

    ordena(n, argv[3]);

    printf("\nArquivo final depois da ordenação:\n");
    imprimirArq(argv[3]);

    return 0;
}