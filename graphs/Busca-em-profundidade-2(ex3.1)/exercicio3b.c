#include "exercicio3b.h"

 // cria no
No *criarNo(int vert) {
    No* novoNo = malloc(sizeof(No));
    novoNo->vertice = vert;
    novoNo->prox = NULL;
    return novoNo;
}

// cria grafo
Lista *criarGrafo(FILE *arquivo) {
    char  *token, *linha = calloc(2000, sizeof(char));

    fgets(linha, 2000, arquivo); // pega a primeira linha

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

// busca em profundidade recursiva
void dfs(Lista* graph, int vert, int *ciclo) {

    graph->cor[vert] = cinza;// posicao atual com cinza
    
    No* temp = graph->listaAdj[vert]; // primeira posicao da lista adjacencia

    while (temp) { // enquanto a lista adjacente da posicao existir 
        int adjvertice = temp->vertice;
        
        if (graph->cor[adjvertice] == branco) { // se nao tiver sido visitado
            dfs(graph, adjvertice, ciclo);
        }else if(graph->cor[adjvertice] == cinza){ // se ja tiver visitado, tem ciclo
            *ciclo = 1;
            return;
        }

        temp = temp->prox; 
    }

    graph->cor[vert] = preto; // terminou de usar o vertice atual  
}
// Verifica ciclo
void verificaCiclo(Lista* graph){
    int ciclo = 0; // verifica se possui ciclo
    
    for(int i = 0; i < graph->numVert; i++){ // para ir em todos os vertices
        if(graph->cor[i] == branco) // verifica se ja nao passou
            dfs(graph, i, &ciclo);
    }

    FILE *arquivoSaida = abrirArquivoEscrita("arquivo3B.txt"); // arquivo txt de saida

    if(ciclo){
        printf("S\n");
        fputc('S', arquivoSaida);//escreve no arquivo
    }else{
        printf("N\n"); 
        fputc('N', arquivoSaida);//escreve no arquivo
    }
}

// pega os dados do arquivo pajek
void pegarDadosArquivo(FILE *arquivo, Lista *graph){
     
    int flag = 0;
    char *linha = malloc(2000*sizeof(char)); // pega cada linha do arquivo

    while (fgets(linha, 2000, arquivo) && strlen(linha)>2) {// pega linha até o final do arquivo
        if(flag > 0 && strcmp(linha, "\n")){
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

// abre o arquivo para escrita
FILE *abrirArquivoEscrita(char *nomeArq){
    FILE *arquivo = fopen(nomeArq,"w");
    
    if (arquivo == NULL)
        exit(0);

    return arquivo;
}