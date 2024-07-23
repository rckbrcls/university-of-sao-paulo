#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// estrutura do aluno
typedef struct itens{
    char *aluno;
}Item;
// tabela hash
typedef struct hash{
    int qtd, tamanho;
    struct itens **itm; // ponteiro duplo 
}Hash;
// cria tabela
Hash *criar(int lug){
    Hash *h = (Hash*)malloc(sizeof(Hash));

    h->qtd = 0;
    h->tamanho = lug;

    h->itm = (Item**)malloc(sizeof(Item*)*lug);
    for(int i = 0; i < lug; i++) // todas as posições da tabela com null
        h->itm[i] = NULL;

    return h;
}
//destrói tabela
void destroi(Hash *h){
    if(h == NULL)
        return;

    for(int i = 0; i < h->tamanho; i++) // percorre tabela
        if(h->itm[i] != NULL) // se tiver algo
            free(h->itm[i]); //libera

    free(h->itm);
    free(h);
}
//função de hashing
int hash(char *nome, int lug){
    int total = 0;

    for(int i = 0; i < strlen(nome); i++)
        total += (int)nome[i];// soma das letras

    return total%lug; // mod do número de lugares
}

int sondagemLinear(int pos, int i, int lug){
    return ((pos + i) & 0x7FFFFFFF) % lug; // sondagem linear
}
// cria novo item para a tabela
Item* criarItem(char *aluno){
    Item* itm = (Item*)malloc(sizeof(Item));
    itm->aluno = (char*)malloc(strlen(aluno)+1);
     
    strcpy(itm->aluno, aluno);
 
    return itm;
}

void insercao(Hash *h, char *aluno){
    if(h == NULL && h->qtd == h->tamanho)
        return;

    int pos, newPos;

    pos = hash(aluno, h->tamanho); // hash

    for(int i = 0; i < h->tamanho; i++){
        newPos = sondagemLinear(pos, i, h->tamanho); // sondagem caso esteja ocupado
        
        if(h->itm[newPos] == NULL){ //vazio
            Item *novo = criarItem(aluno);
            h->itm[newPos] = novo;// insere novo item
            h->qtd++;
            return; // sai
        }
    }
}

void busca(Hash *h, char *aluno){
    if(h == NULL)
        return;

    int pos, newPos;

    pos = hash(aluno, h->tamanho); //hash

    for(int i = 0; i < h->tamanho; i++){
        newPos = sondagemLinear(pos, i, h->tamanho);
        
        if(h->itm[newPos] != NULL) // se não for vazio
            if(strcmp(h->itm[newPos]->aluno, aluno)==0){ // se for o aluno procurado
                printf("%s esta presente no lugar %d\n", aluno, newPos);
                return;
            }
    }
    // não achou
    printf("%s nao esta presente\n", aluno);
}

void remover(Hash *h, char *aluno){
    if(h == NULL)
        return;
    int pos, newPos;

    pos = hash(aluno, h->tamanho);

    for(int i = 0; i < h->tamanho; i++){
        newPos = sondagemLinear(pos, i, h->tamanho);
        
        if(h->itm[newPos] != NULL)// se não for vazio
            if(strcmp(h->itm[newPos]->aluno, aluno)==0){ // se for o aluno procurado
                free(h->itm[newPos]);//libera
                h->itm[newPos] = NULL;
                h->qtd--;// diminui quantidade
                return;
            }
    }        
}

void operacao(int lug, int alun, Hash *h){
    int remov = 0, busc = 0;
    char *aluno = (char*)malloc(sizeof(char)*50);

    for (int i = 0; i < alun; i++){ // insere alun vezes
        scanf(" %[^\n]s", aluno);
        insercao(h, aluno);
    }

    for(int i = 0; i < h->tamanho; i++) // imprime 
        if(h->itm[i] != NULL)
            printf("%d: %s\n", i, h->itm[i]->aluno);
        else
            printf("%d: XXXX\n", i);
    printf("\n");
    
    scanf("%d", &remov);

    for(int i = 0; i < remov; i++){ // remove remov vezes
        scanf(" %[^\n]s", aluno);
        remover(h, aluno);
    }
    
    scanf("%d", &busc);

    for(int i = 0; i < busc; i++){ // busca busc vezes
        scanf(" %[^\n]s", aluno);
        busca(h, aluno);
    }

    free(aluno);
}

int main (void){
    int lug = 0, alun = 0; 
    
    scanf("%d%d", &lug, &alun); // número de lugares e alunos

    Hash *h = criar(lug); // cria tabela hash

    operacao(lug, alun, h); // operações

    destroi(h); // destrói tabela 

    return 0;
}