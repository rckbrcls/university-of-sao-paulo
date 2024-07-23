#include "buscaLargura.h"

// cria fila 
Fila * criaFila() {
    Fila *f = malloc(sizeof(Fila));
    
    f->ini = 0;
    f->fim = 0;
    f->total = 0;

    return f;
}
// verifica se esta vazia
int estaVazia(Fila *f) {
    return (f->total == 0);
}
// verifica se esta cheia
int estaCheia(Fila *f) {
    return (f->total == TAM);
}
 // avanca posicao fila
void avanca(int *valor) {
    if (*valor == TAM - 1)
        *valor = 0; // reinicia
    else
        (*valor)++;
}
// entra na fila
void entra(Fila *f, int valor) {
   
   if (estaCheia(f))
        return; 
        
    f->vet[f->fim] = valor;
    f->total++; 

    avanca(&(f->fim)); 
}
 // sai da fila
int sai(Fila *f) {
    int valor = 0;

    if (estaVazia(f))
        return -1; 

    valor = f->vet[f->ini]; 
    f->total--; 

    avanca(&(f->ini));

    return valor;
}
 // cria no
No *criarNo(int vert) {
    No* novoNo = malloc(sizeof(No));
    novoNo->vertice = vert;
    novoNo->prox = NULL;
    return novoNo;
}

// cria grafo
Lista *criarGrafo(FILE *arquivo) {
    char  *token, *linha = calloc(50, sizeof(char));

    fgets(linha, 50, arquivo); // pega a primeira linha

    char* tmp = strdup(linha);

    token = strsep(&tmp, " ");
    token = strsep(&tmp, "\n"); // pega o numero de vertices do arquivo pajek
    
    int vertices = atoi(token); 

    Lista* graph = malloc(sizeof(Lista));

    graph->numVert = vertices;
    graph->listaAdj = calloc(vertices, sizeof(No*));
    graph->cor = calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++)
         graph->listaAdj[i] = NULL;
    
    free(linha);

    return graph;
}
// cria aresta
void criarAresta(Lista* graph, int vert1, int vert2) {
  
    No* novoNo = criarNo(vert2);
    novoNo->prox = graph->listaAdj[vert1];
    graph->listaAdj[vert1] = novoNo;

    novoNo = criarNo(vert1);
    novoNo->prox = graph->listaAdj[vert2];
    graph->listaAdj[vert2] = novoNo;
}

// apagar o grafo
void apagar(Lista* graph) {
  
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

// busca em largura 
void bfs(Lista* graph, int vert, int distancia[graph->numVert][graph->numVert]) {
    Fila *q = criaFila(); // cria fila auxiliar

    graph->cor[vert-1] = cinza;// inicia a primeira posicao com cinza
    distancia[vert-1][vert-1] = 0; // distancia 0
    entra(q, vert);

    // enquanto a fila nao estiver vazia
    while (!estaVazia(q)) {

        int atual = sai(q); 
        No* temp = graph->listaAdj[atual-1];
    
        while (temp) { // enquanto a lista adjacente da posicao existir 
            int adjvertice = temp->vertice;

            if (graph->cor[adjvertice] == branco) { // se nao tiver sido visitado
                distancia[vert-1][adjvertice] = distancia[vert-1][atual-1] + 1; // incrementa a distancia do atual
                graph->cor[adjvertice] = cinza; // atribui cinza
                entra(q, adjvertice + 1); // entra na fila
            }
            temp = temp->prox; 
        }

        graph->cor[atual] == preto; // terminou de usar o vertice atual
    }

    for(int k = 0; k < graph->numVert; k++)// reatribui para branco 
        graph->cor[k] = branco;

}
// cria a matriz com distancia
void criarMatrizDistancia(FILE *arquivo, Lista *graph, int distancia[graph->numVert][graph->numVert]){
    for(int i = 0; i < graph->numVert; i++)
        bfs(graph, i+1, distancia);
}
// imprime a matriz
void imprimirMatriz(Lista *graph, int distancia[graph->numVert][graph->numVert]) {
    for(int i = 0; i < graph->numVert; i++){
        for(int j = 0; j < graph->numVert; j++){
            printf("%d ", distancia[i][j]);
        }
        printf("\n");
    }
}

// pega os dados do arquivo pajek
void pegarDadosArquivo(FILE *arquivo, Lista *graph){
     
    int flag = 0;
    char *linha = malloc(50*sizeof(char)); // pega cada linha do arquivo

    while (fgets(linha, 50, arquivo)){// pega linha até o final do arquivo
        if(flag > 0){
            char* tmp = strdup(linha); // copia da linha
            char *token;
            
            token = strsep(&tmp, " "); // divide a linha no espaço
            int vert1 = atoi(token);

            token = strsep(&tmp, "\n"); // pega o que vem antes do \n
            int vert2 = atoi(token);

            criarAresta(graph, vert1-1, vert2-1); // atribui aresta
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