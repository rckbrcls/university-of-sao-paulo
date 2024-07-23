#include "parte4.h"

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
    graph->peso = calloc(vertices, sizeof(int));
    graph->pais = (int **)calloc(vertices, sizeof(int*));
    
    for (int i = 0; i < vertices; i++){
        graph->pais[i] = (int*)calloc(2, sizeof(int));
        graph->listaAdj[i] = NULL;
    }

    free(linha);

    return graph;
}
// cria aresta
void criarAresta(Graph* graph, int vert1, int vert2) {
    No* novoNo = criarNo(vert2);
    novoNo->prox = graph->listaAdj[vert1];
    graph->listaAdj[vert1] = novoNo;
    
    if(graph->peso[vert2] == 0){
        graph->pais[vert2][0] = vert1;
    }else if(graph->peso[vert2] == 1){
        graph->pais[vert2][1] = vert1;
    }

    graph->peso[vert2]++;
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

// busca em profundidade recursiva
void bfs(Graph* graph, int vert, int *descendentes, int *distancia) {
    Fila *q = criaFila();
    
    entra(q, vert);
    
    graph->cor[vert] = cinza;
    distancia[vert] = 0; // seta a distancia do vertice
    descendentes[vert] = 1;  // seta o vetores que sao percorridos pelo dfs como Descendentes

    while (!estaVazia(q)) {
        
        int atual = sai(q);
    
        No* temp = graph->listaAdj[atual]; // primeira posicao da lista adjacencia

        while (temp) { // enquanto a lista adjacente da posicao existir
            int adjvertice = temp->vertice;

            if (graph->cor[adjvertice] == branco){// se nao tiver sido visitado
                entra(q, adjvertice);
                distancia[adjvertice] = distancia[atual] + 1; // seta a distancia do vertice
                descendentes[adjvertice] = 1;  // seta o vetores que sao percorridos pelo dfs como Descendentes
                graph->cor[adjvertice] = cinza;
            }
            
            temp = temp->prox;
        }
    
        graph->cor[vert] = preto;
    }
}

void buscarMenorDistancia(Graph* graph){
    int *descendentes = calloc(graph->numVert, sizeof(int)); // vetor para verificar se eh descendente de 1
    int *distancia = calloc(graph->numVert, sizeof(int)); // vetor distancia dos descendentes de 1
    int menorDistancia = INT_MAX; // pega a menor distancia dos sorvedouros

    bfs(graph,  0, descendentes, distancia);

    // procura a menor distancia de dois pais
    for(int i = 0; i < graph->numVert; i++){        

        if(graph->peso[i] == 2 && graph->listaAdj[i] == NULL && descendentes[graph->pais[i][0]] == 1 && descendentes[graph->pais[i][1]] == 1){
            int auxDist = distancia[graph->pais[i][0]] + distancia[graph->pais[i][1]];

            if(menorDistancia > auxDist) // se achar uma distancia menor, seta
                menorDistancia = auxDist;
        }

    }
    // imprime os vertices com menor distancia dos pais
    for(int i = 0; i < graph->numVert; i++){
        int auxDist = distancia[graph->pais[i][0]] + distancia[graph->pais[i][1]];
        
        if(graph->peso[i] == 2 && graph->listaAdj[i] == NULL && descendentes[graph->pais[i][0]] == 1 && descendentes[graph->pais[i][1]] == 1 && auxDist == menorDistancia)
            printf("%d\n", i+1);
    }

    free(descendentes);
    free(distancia);
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

            int vert2 = 0;

            while(token != NULL){ // até o fim da linha

                token = strsep(&tmp, " ");

                if(token != NULL && strcmp(token, " ") && strcmp(token, "\n") && strlen(token) > 0)
                    vert2 = atoi(token);

            }

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
void printGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->numVert; v++) {
    No* temp = graph->listaAdj[v];
    printf("\n Vertex %d\n: ", v+1);
    while (temp) {
      printf("%d -> ", temp->vertice+1);
      temp = temp->prox;
    }
    printf("\n");
  }
}