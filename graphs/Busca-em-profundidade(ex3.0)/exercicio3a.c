#include "exercicio3a.h"
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
// bubble sort comum
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {   
        for (int j = 0; j < n - i - 1; j++) { 
            if (a[j] < a[j + 1]) { 
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// busca em profundidade recursiva
int dfs(Lista* graph, int vert, int *num) {

    graph->cor[vert] = cinza;// posicao atual com cinza
    
    No* temp = graph->listaAdj[vert]; // primeira posicao da lista adjacencia

    while (temp) { // enquanto a lista adjacente da posicao existir 
        int adjvertice = temp->vertice;
        
        if (graph->cor[adjvertice] == branco)// se nao tiver sido visitado
            dfs(graph, adjvertice, num);
        
        temp = temp->prox; 
    }

    graph->cor[vert] = preto; // terminou de usar o vertice atual  
    *num += 1; // incrementa numero de vertices
}

void numeroDeComponentes(Lista* graph){
    int nComp = 0; // numero de componentes
    int *nVertComp = calloc(graph->numVert, sizeof(int)); // vetor que contem quantos vertices tem no componente

    for(int i = 0; i < graph->numVert; i++){ // para ir em todos os vertices
        if(graph->cor[i] == branco){// verifica se ja nao passou
            int num = 0; // auxiliar com o numero de vertices do componente
            dfs(graph, i, &num);
            nVertComp[nComp] = num; 
            nComp++; // incrementa componente
        }
    }

    bubble_sort(nVertComp, nComp); // ordena vetor
    
    FILE *arquivoSaida = abrirArquivoEscrita("arquivo3A.txt"); // arquivo txt de saida

    printf("%d\n", nComp);
    fprintf(arquivoSaida, "%d\n", nComp);//escreve no arquivo

    for(int i = 0; i < nComp; i++){
        printf("%d\n", nVertComp[i]);
        fprintf(arquivoSaida, "%d\n", nVertComp[i]);//escreve no arquivo
    }
        
    fclose(arquivoSaida);
    free(nVertComp);
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