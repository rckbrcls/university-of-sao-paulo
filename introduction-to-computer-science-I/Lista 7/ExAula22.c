#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Estrutura que vai guardar as strings do arquivo 
typedef struct string{
    char *string;
    int freq; // Frequência da string no arquivo
}Str;

Str *cria(int tam){ // Cria vetor de struct
    Str *p = (Str*)calloc(tam, sizeof(Str));
    
    for(int i = 0; i < tam; i++){
        p[i].string = (char*)calloc(100, sizeof(char)); // Aloca todas as strings
        p[i].freq = 0; // Inicializa com 0
    }

    return p;
}
// Função que abre o arquivo e retorna seu ponteiro
FILE *lerArquivo(char *arqname){
    FILE *aux = fopen(arqname, "r"); // Abre pra ler
    
    if (aux == NULL){ // Caso esteja vazio
        printf("ERRO!\n");
        exit(-1);
    }
        
    return aux; // Retorna ponteiro
}

int contarChar(char *arqname){ // Conta número de chars
    FILE *arquivo = lerArquivo(arqname); // Abre pra leitura 
    
    char ch;
    int count = 0;
    
    while((ch = fgetc(arquivo)) != EOF) // Pega char por char até o fim do arquivo 
        count++; // incrementa

    fclose(arquivo); //Fecha

    return count; // Retorna número de chars
}

int contarString(char *arqname){
    FILE *arquivo = lerArquivo(arqname); // Abre pra leitura 
    
    char ch;
    int count = 0;
    
    while((ch = fgetc(arquivo)) != EOF){ // Pega char por char até o fim do arquivo 
        if(ch == ' '||ch == '\n') // Se acha um char que é espaço ou tab, incrementa número de palavras
            count++;// incrementa
    }

    fclose(arquivo); //Fecha

    return count+1;  // Retorna número de strings
}

int contarLinhas(char *arqname){
    FILE *arquivo = lerArquivo(arqname); // Abre pra leitura 
    
    char ch;
    int count = 0;
    
    while((ch = fgetc(arquivo)) != EOF){ // Pega char por char até o fim do arquivo 
        if(ch == '\n') // Caso ache tab, incrementa linha
            count++; // incrementa
    }

    fclose(arquivo); //Fecha

    return count+1;  // Retorna número de linhas
}

//Função auxiliar que retorna quantas vezes uma string aparece em um vetor de struct
int recorrencia(char *string, Str *p, int tam){ 
    int count = 0;

    for(int i = 0; i < tam; i++){ // percorre vetor de struct
        if(strcmp(p[i].string, string) == 0) // Se achar, incrementa
            count++;
    }
    
    return count;
}

//Função auxiliar que checa se já existe uma string em um vetor de struct
int repetido(char *string, Str *p, int tam){
    
    for(int i = 0; i < tam; i++){ // percorre vetor de struct
        if(strcmp(p[i].string, string) == 0) // Se achar, retorna verdadeiro
            return 1;
    }

    return 0; // Não achou
}
// Função que verifica a frequência das strings do arquivo
void frenquenciaString(char *arqname){
    FILE *arquivo = lerArquivo(arqname); // Abre pra leitura 

    int k = 0;
    char ch;

    Str *p = cria(1000); // Cria auxiliar com tamanho de 1000

    while(!feof(arquivo)){ // Até o fim do arquivo

        //Pega a linha do arquivo
        char *linha = calloc(1024, sizeof(char)); 
        fgets(linha, 1024, arquivo);

        // Divide a primeira palavra, com o delimitador de ' '            
        char *token = strtok(linha, " ");
        
        strcpy(p[k++].string, token);// copia para a primeira posição do vetor de string

        while(token != NULL){ // até final da linha
            token = strtok(NULL, " \n"); 
            
            if(token != NULL){
                strcpy(p[k++].string, token);
            }
        }
    }

    int tam = contarString(arqname); // Quantas palavras

    Str *s = cria(tam); //Cria o vetor que vai imprimir as strings sem repetição

    s[0] = p[0]; // Atribui primeira posição

    for(int i = 0; i < tam; i++)// Pega a frequência de cada string
        p[i].freq = recorrencia(p[i].string, p, tam);
    
    int count = 0;

    for(int i = 0; i < tam; i++)
        if(!repetido(p[i].string, s, tam)) // Se não for repetido, atribui
            s[count++] = p[i];
    
    for(int i = 0; i < tam; i++)
        if(s[i].freq != 0) // Só imprime se essa palavra existir
            printf("(%s) - %d vezes\n\n", s[i].string, s[i].freq);

    //libera 
    free(p);
    free(s);

    fclose(arquivo); // fecha arquivo
}

int main(int argc, char *argv[]){

    int ch = contarChar(argv[1]);
    printf("Numero de char's - %d\n", ch);

    int line = contarLinhas(argv[1]);
    printf("Numero de linhas - %d\n", line);

    int string = contarString(argv[1]);
    printf("Numero de strings - %d\n", string);
    
    frenquenciaString(argv[1]);

    return 0;
}