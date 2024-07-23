#include "exercicio4.h"

Heap criaHeap(int n){
    Heap h;

    h.total = 0;
    h.vet = calloc(n, sizeof(Elem));

    for(int i = 0; i < n; i++)
        h.vet[i].valor = -1, h.vet[i].prioridade = -1; 

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
        if(h->vet[i].valor == -1 || h->vet[pai(i)].valor == -1)
            break;
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
    if (h->total == TAM)
        return;
    
    h->vet[h->total].valor = x;
    h->vet[h->total].prioridade = p;
    
    paraCima(h, h->total);
    
    h->total++;
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

// algoritmo de dijkstra
void dijkstra(Graph* graph, int vert, int distancia[graph->numVert][graph->numVert]) {

    Heap q = criaHeap(TAM);
    
    for(int i = 0; i < graph->numVert; i++)
        distancia[vert][i] = INT_MAX; // pior caso
    
    distancia[vert][vert] = 0; // inicia a posicao com zero
    inserirHeap(&q, vert, INT_MAX);
    
    while(q.total != 0){ // enquanto a fila nao estiver vazia
        Elem atual = removerHeap(&q);
        No* temp = graph->listaAdj[atual.valor]; // primeira posicao da lista adjacencia
        
        if(graph->cor[atual.valor] == branco){
            while (temp) { // enquanto existir vertice adjacente 
                
                int adjvertice = temp->vertice;
                int peso = temp->peso;

                if((graph->cor[adjvertice] == branco) && (distancia[vert][adjvertice] > (distancia[vert][atual.valor]+peso))){ // verifica se pode fazer o relaxamento
                    distancia[vert][adjvertice] = distancia[vert][atual.valor] + peso;
                    inserirHeap(&q, adjvertice, distancia[vert][adjvertice]); // inserir na heap
                }
                temp = temp->prox; 
            }
            
        }
        graph->cor[atual.valor] == cinza; 
    } 
    for(int k = 0; k < graph->numVert; k++)// reatribui para branco 
        graph->cor[k] = branco;

    free(q.vet);
}
// cria a matriz de distancia
void criarMatrizDistancia(Graph* graph, int distancia[graph->numVert][graph->numVert]){
    for(int i = 0; i < graph->numVert; i++)
        dijkstra(graph, i, distancia);
}
//pega o tamanho do numero
int tamNum(int n){
    int count = 0;

    do{
        count++;
        n /= 10;
    }while (n != 0);
    
    return count;
}
//procura o maior numero da matriz e retorna seu numero de digitos
int procurarDigitMaiorNumero(int n, int distancia[n][n]){
    int maiorNum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(maiorNum < distancia[i][j])
                maiorNum = distancia[i][j];
        }
    } 

    return (tamNum(maiorNum));
}

// imprime a matriz
void imprimirMatriz(Graph *graph, int distancia[graph->numVert][graph->numVert]) {
    
    int nDigitosMaior = procurarDigitMaiorNumero(graph->numVert, distancia);

    for(int i = 0; i < graph->numVert; i++){
        for(int j = 0; j < graph->numVert; j++){
            if(j > 0)
                printf(" ");
            if(nDigitosMaior == 4)
                printf("%4d", distancia[i][j]);
            else if(nDigitosMaior == 3)
                printf("%3d", distancia[i][j]);
            else if(nDigitosMaior == 2)
                printf("%2d", distancia[i][j]);
            else if(nDigitosMaior == 1)
                printf("%1d", distancia[i][j]);
        }
        printf("\n");
    }
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