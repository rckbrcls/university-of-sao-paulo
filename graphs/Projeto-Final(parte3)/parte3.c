#include "parte3.h"

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
void dfs(Graph* graph, int vert, int *descendentes) {
    descendentes[vert] = 1; // seta o vetores que sao percorridos pelo dfs como descendentes

    No* temp = graph->listaAdj[vert]; // primeira posicao da lista adjacencia

    while (temp) { // enquanto a lista adjacente da posicao existir
        int adjvertice = temp->vertice;

        if (graph->cor[adjvertice] == branco) { // se nao tiver sido visitado
            dfs(graph, adjvertice, descendentes);
            graph->cor[adjvertice] = cinza;
        }

        temp = temp->prox;
    }

    graph->cor[vert] = preto;

}
// busca descendentes sorvedouros do vertice 1
void buscarSorvedouros(Graph* graph){
    int *descendentes = calloc(graph->numVert, sizeof(int)); // vetor para verificar se eh descendente de 1

    dfs(graph, 0, descendentes); // inicia dfs

    for(int i = 0; i < graph->numVert; i++){
        //caso seja sorvedouro e os pais sejam descendentes do vertice 1
        if(graph->peso[i] == 2 && graph->listaAdj[i] == NULL && descendentes[graph->pais[i][0]] == 1 && descendentes[graph->pais[i][1]] == 1)
            printf("%d\n", i+1); // imprime vertice
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