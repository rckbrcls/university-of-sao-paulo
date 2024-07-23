#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

#define P 0.5 // Porcentagem de chance da execução do laço -> 50%
#define MAXLVL 24 // Número máximo de níveis

typedef struct tweet{
    char *palavra; // Palavra
    struct tweet* prox; 
}Twt;

typedef struct lista{
    Twt *ini, *fim;
}List;

// Nó
typedef struct node {
    char *palavra; // Palavra
    int level; // Nível do nó
    struct node** forward; //Arranjo de ponteiros para o próximo nó
}No;

// Skip list
typedef struct skiplist{
    No* header; // Cabeçalho da skip list
    int level; // Nível do cabeçalho
}Skip;

List *criaLista(){
    List *twt = malloc(sizeof(List)); // instancia lista
    twt->ini = NULL;
    twt->fim = NULL;
    return twt;
}

void freeSkip(Skip *list){

    while(list->header != NULL){
        No *aux = list->header;
        list->header = list->header->forward[0];
       
        free(aux);
    }

    free(list);
}

void insereLista(List *twt, char *palavra) {
    
    Twt *aux = (Twt*)malloc(sizeof(Twt));
    aux->palavra = (char*)malloc(sizeof(char)*50);
    
    strcpy(aux->palavra, palavra);

    aux->prox = NULL;

    // atualiza ponteiros
    if (twt->fim != NULL)
        twt->fim->prox = aux;
    twt->fim = aux;

    if (twt->ini == NULL)
        twt->ini = aux;

}

// Função que gera números aleatórios entre 0-1
float randomize(){
    float result = 0.0;

    result = ((float)rand())/(float)(RAND_MAX);

    return result;
}
// Cria nível de tamanho aleatório, até TAMLVL
int randomLvl(){
    int result = 1;

    while(randomize() < P && result < MAXLVL)
        result++;
    
    return result;
}
// Cria nó
No* criarNo(int level, char *palavra){
    No* p = malloc(sizeof(No)); //Ponteiro do nó

    p->level = level; //Nível do nó

    p->forward = malloc((level+1)*sizeof(No*)); // Alocando o arranjo, com tamanho do nível
    p->palavra = malloc(sizeof(char)*100);

    //Inicializando o arranjo com null
    for(int i = 0; i < (p->level+1); i++)
        p->forward[i] = NULL;
    
    //Atribuindo os dados para o nó
    strcpy(p->palavra, palavra);

    return p;
}
// Cria skip list
Skip* criarSkip(){
    Skip* p = malloc(sizeof(Skip));// Ponteiro da lista

    p->header = criarNo(MAXLVL, "null"); //Criando o cabeçalho da lista, com nível máximo

    p->level = 0; //Nível da skip list sendo 0

    return p;
}

void sai(List *twt, char **palavra) {
    
    if(twt->ini == NULL)
        return;

    Twt *aux;
    strcpy(*palavra, twt->ini->palavra); // copia info
    
    aux = twt->ini; // guarda ponteiro a apagar
    twt->ini = twt->ini->prox; // atualiza encadeamento
    free(aux); // apaga caixa

}

No* procurar(Skip* sl, char *busca){

    No* x = sl->header; // Aponta para o cabeçalho
    
    //Do nível mais alto para o mais baixo
    for(int i = x->level; i >= 0; i--){
        
        //Enquanto não achou o palavra e forward[i] não é null
        while(x->forward[i] != NULL && strcmp(x->forward[i]->palavra, busca) < 0)
            x = x->forward[i];
    
    }

    x = x->forward[0];

    //Retorna ponteiro, que pode ou não estar apontando para o palavra procurado

    return (No*)x;
}

//Funçao que busca palavra desejado
int existe(Skip* sl, List *twt, int flag){
    while (twt->ini != NULL){
        char *busca = malloc(sizeof(char)*50); // palavra original
        char *comp = malloc(sizeof(char)*50); // palavra auxiliar para comparação
        
        sai(twt, &busca); // sai uma palavra da lista e atribui para a string busca
        strcpy(comp, busca); 

        for(int i = 0; comp[i]; i++) // minuscula para comparar com as do dicionario
            comp[i] = tolower(comp[i]);

        No* p = procurar(sl, comp); //Ponteiro que pode ou não estar apontando para a palavra

        if(p != NULL){//Verifica se é diferente de null
            if(strcmp(p->palavra, comp) != 0){ // Se o palavra do ponteiro condiz com o procurado
                printf("%s ", busca); // imprime palavra errada
                flag = 1;// existe uma palavra errada
            }
        }

        if(twt->ini == NULL) // fim da lista = \n
            printf("\n");

        free(busca);
        free(comp);
    }
    return flag;
}

// Função de inserção
void inserir(Skip* sl, char *palavra){
    
    //Arranjo que atualiza os nós de forward
    No *update[MAXLVL+1];
    
    for(int i = 0; i < MAXLVL+1; i++)
        update[i] = NULL;

    //Aponta para o cabeçalho
    No* x = sl->header;

    int level = x->level; // Nível do cabeçalho

    //Do nível mais alto para o mais baixo
    for(int i = level; i >= 0; i--){

        //Enquanto não achou o palavra e forward[i] não é null
        while(x->forward[i] != NULL && strcmp(x->forward[i]->palavra, palavra) < 0)
            x = x->forward[i];
        
        // Guarda o nó que vai ser atualizado
        update[i] = x;
    }

    x = x->forward[0];

    // Caso ponteiro seja null ou x->palavra não seja igual ao palavra a ser inserido
    if(x == NULL || strcmp(x->palavra, palavra) != 0){

        int novoLvl = randomLvl(); //Nível do novo nó

        //Caso o novo nível seja maior que o nível da skip list  
        if(novoLvl > level){

            // Atualiza o update para que aponte para o cabeçalho da lista
            // entre a seu nível e o nível do novo nó
            for(int i = level + 1; i <= novoLvl; i++){
                update[i] = sl->header;
            }

            //Atualiza o nível do skip list
            sl->level = novoLvl;
        }

        // Cria o novo nó
        x = criarNo(novoLvl, palavra);

        // Inserindo o novo nó na skip list
        for(int i = 0; i <= novoLvl; i++){
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}

void abrirArquivo(Skip *dicionario, FILE *arq){
    char *linha = malloc(1024*sizeof(char));
    
    while (fgets(linha, 1024, arq)){ // linha por linha
        
        char *token = strtok(linha, " ’“”_][\r\t1234567890…\"\'\n\\$*%():/.,!?&;@-,#"); // delimitadores 
        
        char *str = malloc(sizeof(char)*50); // string auxiliar que vai passar pro dicionario em minusculo

        if(token != NULL){
            strcpy(str, token);
            
            for(int i = 0; str[i]; i++)// para minusculo
                str[i] = tolower(str[i]);
            
            inserir(dicionario, str);
        }

        while(token != NULL){
            token = strtok(NULL, " ’“”_][\r\t1234567890…\"\'\n\\$*%():/.,!?&;@-,#");
            
            if(token != NULL){
                strcpy(str, token);
            
                for(int i = 0; str[i]; i++)
                    str[i] = tolower(str[i]);

                inserir(dicionario, str);
            }  
        }

        free(str);
    }

    free(linha);

}

void abrirTweet(Skip* sl, FILE *arq){
    char *linha = malloc(1024*sizeof(char));
    int flag = 0;

    while (fgets(linha, 1024, arq)){
        List *twt = criaLista(); // lista das palavras do tweet

        char *token = strtok(linha, ": ");

        if(strcmp(token, "\"text\"") == 0){ // se achar a chave text
            while(token != NULL){
                
                token = strtok(NULL, " ’“”_][…1234567890\"\'\n\\$*%():/.,!?&;@-,#");
                
                if(token != NULL)
                    insereLista(twt, token);
                
            }   
        }

        flag = existe(sl, twt, flag); // se existe alguma palavra errada, flag = 1

    }

    if(flag == 0)
        printf("No tweets to check\n");
    
    free(linha);
}

int main(int argc, char *argv[]){
    char *arqname = malloc(sizeof(char)*50);
    char *tweetname = malloc(sizeof(char)*50);

    scanf("%s", arqname);
    getchar();
    scanf("%s", tweetname);
    getchar();

    FILE *arq = fopen(arqname, "r");
    if(arq == NULL)
        exit(-1);
    
    FILE *tweet = fopen(tweetname, "r");
    if(arq == NULL)
        exit(-1);

    Skip *dicionario = criarSkip(); //Skip list para o dicionario

    abrirArquivo(dicionario, arq);
    abrirTweet(dicionario, tweet);

    freeSkip(dicionario);
    free(arqname);
    free(tweetname);
    fclose(arq);
    fclose(tweet);

    return 0;
}