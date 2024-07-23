#include "parte2.h"

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

    for (int i = 0; i < vertices; i++)
        graph->listaAdj[i] = NULL;
         
    free(linha);

    return graph;
}
// cria aresta
void criarAresta(Graph* graph, int vert1, int vert2) {
    No* novoNo = criarNo(vert2);
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

// Conta o numero de vertices sorvedouros
void contarSorvedouros(Graph* graph){
    int numSorvedouros = 0;

    for(int i = 0; i < graph->numVert; i++){ // percorre todos os vertices
        if(graph->listaAdj[i] == NULL) // se um vertice nao aponta para outro
            numSorvedouros++; //  ele eh sorvedouro
    }

    printf("%d\n",  numSorvedouros);
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