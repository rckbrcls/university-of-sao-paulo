#include "exercicio5.h"
// Criar heap
Heap criaHeap(int n){
    Heap h;

    h.total = n;
    h.vet = calloc(n, sizeof(Elem));
    
    h.vet[0].valor = 0;
    h.vet[0].prioridade = 0;

    for(int i = 1; i < n; i++){
        h.vet[i].valor = i;
        h.vet[i].prioridade = INT_MAX;
    }

    return h;
}
// trocar valores dos nós
void swap(Heap *h, int i, int j){
    int temp1 = h->vet[i].valor;
    int temp2 = h->vet[i].prioridade;

    h->vet[i].valor = h->vet[j].valor;
    h->vet[i].prioridade = h->vet[j].prioridade;

    h->vet[j].valor = temp1;
    h->vet[j].prioridade = temp2;
}
// ver qual o pai
int pai(int i){
    return (i - 1) / 2;
}
// ver qual eh o filho esquerdo
int filhoEsquerdo(int i){
    return ((2 * i) + 1);
}
// ver qual eh o filho direito
int filhoDireito(int i){
    return ((2 * i) + 2);
}
// transferir valor para cima
void paraCima(Heap *h, int i){
    while (h->vet[i].prioridade < h->vet[pai(i)].prioridade){
        //printf("FILHO %d E PAI %d\n", h->vet[i].valor, h->vet[pai(i)].valor);
        swap(h, pai(i), i);
        i = pai(i);
    }
}
// verificar se eh folha
int eFolha(Heap h, int pos){
    if (pos >= (h.total/2) && pos <= h.total) 
        return 1;
    
    return 0;
}
//transferir valor para baixo
void paraBaixo(Heap *h, int i){
    if (!eFolha(*h, i)) {
            if (h->vet[i].prioridade > h->vet[filhoEsquerdo(i)].prioridade
                || h->vet[i].prioridade > h->vet[filhoDireito(i)].prioridade) {
 
                if (h->vet[filhoEsquerdo(i)].prioridade < h->vet[filhoDireito(i)].prioridade) {
                    swap(h, i, filhoEsquerdo(i));
                    paraBaixo(h, filhoEsquerdo(i));
                }
 
                else {
                    swap(h, i, filhoDireito(i));
                    paraBaixo(h, filhoDireito(i));
                }
            }
        }
}
// inserir na heap
void inserirHeap(Heap *h, int x, int p){
    h->vet[++h->total].valor = x;
    h->vet[h->total].prioridade = p;
    
    paraCima(h, h->total);
}
// remover da heap
Elem removerHeap(Heap *h){
    Elem result;

    result.valor = h->vet[0].valor;
    result.prioridade = h->vet[0].prioridade;

    int pos = --h->total;

    h->vet[0].valor = h->vet[pos].valor;
    h->vet[0].prioridade = h->vet[pos].prioridade;

    paraBaixo(h, 0);

    return result; // retorna valores removidos
}
// mudar prioridade de um nó
void mudarPrioridade(Heap *h, int i, int p){
    int oldp = h->vet[i].prioridade;
    h->vet[i].prioridade = p;
 
    if (p < oldp)
        paraCima(h, i);
    else
        paraBaixo(h ,i);
}

 // cria no
No *criarNo(int vert, int peso) {
    No* novoNo = malloc(sizeof(No));
    novoNo->vertice = vert;
    novoNo->prox = NULL;
    novoNo->peso = peso;
    return novoNo;
}

// cria grafo
Graph *criarGrafo(FILE *arquivo) {
    char  *token, *linha = calloc(2000, sizeof(char));

    fgets(linha, 2000, arquivo); // pega a primeira linha

    char* tmp = strdup(linha);

    token = strsep(&tmp, " ");
    token = strsep(&tmp, "\n"); // pega o numero de vertices do arquivo pajek
    
    int vertices = atoi(token); 

    Graph* graph = malloc(sizeof(Graph));

    graph->numVert = vertices;
    graph->listaAdj = calloc(vertices, sizeof(No*));
    graph->cor = calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++)
        graph->listaAdj[i] = NULL;
         
    free(linha);

    return graph;
}
// cria aresta
void criarAresta(Graph* graph, int vert1, int vert2, int peso) {
    No* novoNo = criarNo(vert2, peso);
    novoNo->prox = graph->listaAdj[vert1];
    graph->listaAdj[vert1] = novoNo;

    novoNo = criarNo(vert1, peso);
    novoNo->prox = graph->listaAdj[vert2];
    graph->listaAdj[vert2] = novoNo;
}

// apagar o grafo
void apagar(Graph* graph) {
  
    for (int v = 0; v < graph->numVert; v++) {
        No* current = graph->listaAdj[v];
        No* prox;
    
        while (current) {
            prox = current->prox;
            free(current);
            current = prox;
        }
        graph->listaAdj[v] = NULL;
    }
    free(graph);
}

int buscar(Heap *h, int v){
    for(int i = 0; i < h->total; i++){
        if(h->vet[i].valor == v)
            return i;
    }

    return -1;
}

void atribuirpai(int i, int *pai, int x){
    pai[i] = x;
}

// algoritmo de prim
void prim(Graph* graph, int vert) {

    Heap h = criaHeap(graph->numVert);// cria heap do tamanho do numero de vertices
    int pai[graph->numVert]; // array que na vai ser usado mas que representa os antecessores
    int pesoTotal = 0;

    atribuirpai(0, pai, vert); // atribui o vertice inicial

    int i = 0;

    while(h.total > 0){ // enquanto a heap nao estiver vazia
        
        Elem atual = removerHeap(&h); 
        pesoTotal += atual.prioridade; // incrementa o peso total
        
        atribuirpai(i++, pai, atual.valor); // atribui para o array
    
        No* temp = graph->listaAdj[atual.valor]; // primeira posicao da lista adjacencia
        
        while (temp) { // percorre toda a lista adjacente
            
            int adjvertice = temp->vertice;
            int peso = temp->peso;

            int index = buscar(&h, adjvertice);
            
            if(index > -1){ // verifica se esta na lista 
                if(peso < h.vet[index].prioridade)
                    mudarPrioridade(&h, index, peso); // muda o peso se necessario
            }
            
            temp = temp->prox; 
        }
        
    }

    printf("%d\n", pesoTotal);
}
// pega os dados do arquivo pajek
void pegarDadosArquivo(FILE *arquivo, Graph *graph){
     
    int flag = 0;
    char *linha = malloc(2000*sizeof(char)); // pega cada linha do arquivo

    while (fgets(linha, 2000, arquivo) && strlen(linha)>2) {// pega linha até o final do arquivo
        if(flag > 0 && strcmp(linha, "\n")){
            char* tmp = strdup(linha); // copia da linha
            char *token;

            token = strsep(&tmp, " "); // divide a linha no espaço
            int vert1 = atoi(token);
            
            token = strsep(&tmp, " "); // pega o que vem antes do \n
            int vert2 = atoi(token);
            
            token = strsep(&tmp, "\n");
            int peso = atoi(token);
            
            criarAresta(graph, vert1-1, vert2-1, peso); // atribui aresta
        }
        flag++;
    }
    free(linha);
    
}   

// abre o arquivo para leitura 
FILE *abrirArquivoLeitura(char *nomeArq){
    FILE *arquivo = fopen(nomeArq,"r");
    
    if (arquivo == NULL)
        exit(0);

    return arquivo;
}
