#include "spotify.h"

//Função que cria música
Musica *criaMusica(){
    Musica *music = (Musica*)malloc(sizeof(Musica));
    music->nome = malloc(200*sizeof(char));
    music->id = malloc(200*sizeof(char));
    music->data = malloc(200*sizeof(char));
    music->prox = NULL;
    music->ant = NULL;
    music->art = NULL;
    music->alb = NULL;
    music->instrumentalness = 0;
    music->acoustcness = 0;
    music->tempo = 0;
    music->speechiness = 0;
    music->popularity = 0;
    music->loudness = 0;
    music->liveness = 0;
    music->energy = 0;
    music->danceability = 0;
    music->length = 0;
    music->timeSignature = 0;
    return music;
}
//Função que cria álbum
Album *criaAlbum(){
    Album *album = (Album*)malloc(sizeof(Album));
    album->nome = malloc(200*sizeof(char));
    album->id = malloc(200*sizeof(char));
    album->prox = NULL;
    album->art = NULL;
    album->nTracks = 0;
    return album;
}
//Função que cria artista
Artista *criaArtista(){
    Artista *art = (Artista*)malloc(sizeof(Artista));
    art->nome = malloc(200*sizeof(char));
    art->id = malloc(200*sizeof(char));
    art->prox = NULL;
    art->nTracks = 0;
    art->nAlbum = 0;
    art->popularidade = 0;
    art->media = 0;
    return art;
}
//Função que cria lista
Lista *criaLista(){
    Lista *l = malloc(sizeof(Lista));
    l->iniM = NULL;
    l->fimM = NULL;
    l->iniAlb = NULL;
    l->fimAlb = NULL;
    l->iniArt = NULL;
    l->fimArt = NULL;
    l->nTracks = 0;
    l->nArtistas = 0;
    return l;
}
//destrói lista de músicas
void destroiMusica(Lista *m){
    if(m != NULL){
        Musica *p = m->iniM;
        while (p != NULL) {
            m->iniM = m->iniM->prox;
            free(p->id);
            free(p->nome);
            free(p->data);
            free(p);
            p = m->iniM;
        }
    } 
}
// Função que destroi álbum
void destroiAlbum(Lista *alb){
    if(alb != NULL){
        Album *p = alb->iniAlb;
        while (p != NULL) {
            alb->iniAlb = alb->iniAlb->prox;
            free(p->id);
            free(p->nome);
            free(p);
            p = alb->iniAlb;
        }
    } 
}
// Função que destroi artista
void destroiArtista(Lista *art){
    if(art != NULL){
        Artista *p = art->iniArt;
        while (p != NULL) {
            art->iniArt = art->iniArt->prox;
            free(p->id);
            free(p->nome);
            free(p);
            p = art->iniArt;
        }
    } 
}
// Função que destroi lista
void destroiLista(Lista *l){
    destroiArtista(l);
    destroiAlbum(l);
    destroiMusica(l);
    free(l);
}

//Função que verifica se artista já existe
Artista *existeArtista(Artista *p, char *id){
    if (p == NULL) // se não existir, cria nó
        return criaArtista();
    if (strcmp(id, p->id) == 0) // se existir, retorna o ponteiro para ele
        return p; // achou
    return existeArtista(p->prox, id);// procura recursivamente
}
//Função que verifica se álbum já existe
Album *existeAlbum(Album *p, char *id){
    if(p == NULL)// se não existir, cria nó
        return criaAlbum(); 
    if(strcmp(id, p->id) == 0)// se existir, retorna o ponteiro para ele
        return p; // achou
    return existeAlbum(p->prox, id);// procura recursivamente
}
//Função que insere música
void insereMusica(Lista *l, Artista *art, Album *alb, Aux aux){
    assert(alb != NULL);
    
    Musica *music = criaMusica();// cria nó
    
    strcpy(music->nome, aux.nomeMusica);
    strcpy(music->id ,aux.idMusica); 
    strcpy(music->data ,aux.data);
    music->instrumentalness = aux.instrumentalness;
    music->acoustcness = aux.acoustcness;
    music->tempo = aux.tempo;
    music->speechiness = aux.speechiness;
    music->popularity = aux.popularity;
    music->loudness = aux.loudness;
    music->liveness = aux.liveness;
    music->energy = aux.energy;
    music->danceability = aux.danceability;
    music->length = aux.length;
    music->timeSignature = aux.timeSignature;
    
    //aponta ponteiros alb e art da música para os artistas e as músicas
    music->alb = alb;
    music->art = art;

    music->ant = l->fimM;
    if (l->fimM != NULL) l->fimM->prox = music;
    l->fimM = music;

    if (l->iniM == NULL) l->iniM = music;

    alb->nTracks++;//incrementa o número de músicas no álbum
}
//Função que insere álbum
void insereAlbum(Lista *l, Artista *art, Aux aux){
    assert(art != NULL);
    
    Album *alb = existeAlbum(l->iniAlb, aux.idAlb);//verifica se o álbum já existe

    if(alb->nTracks == 0){ //se não existir, insere novo nó
        strcpy(alb->id, aux.idAlb);
        strcpy(alb->nome, aux.nomeAlb);
        art->nAlbum++; //incrementa número de álbuns do artista
        
        //aponta o ponteiro art para o artista
        alb->art = art;


        if (l->fimAlb != NULL) l->fimAlb->prox = alb;
        l->fimAlb = alb;

        if (l->iniAlb == NULL) l->iniAlb = alb;
    } 

    insereMusica(l, art, alb, aux);// insere música
}
//Função que insere artista
void insereArtista(Lista *l, Aux aux){
    assert(l != NULL);

    Artista *art = existeArtista(l->iniArt, aux.idArt); //verifica se o artista já existe

    if(art->nTracks == 0){ // se não existir, insere o novo nó
        strcpy(art->id, aux.idArt);
        strcpy(art->nome, aux.nomeArt);
        l->nArtistas++;//incrementa número de artistas na lista
        
        if (l->fimArt != NULL) l->fimArt->prox = art;
        l->fimArt = art;

        if (l->iniArt == NULL) l->iniArt = art;
    }

    art->nTracks++; // incrementa número de músicas do artista
    art->popularidade += aux.popularity; // soma as popularidades
    art->media = (art->popularidade/art->nTracks); // tira a média
    insereAlbum(l, art, aux); // insere álbum
}
// Atribui dados para a estrutura auxiliar
void atribuiAux(Aux *aux, char *token, int x){
    switch (x){ // qual dado da linha deve ser pego
        case 1:
            strcpy(aux->nomeMusica, token);
            if (aux->nomeMusica[0] == ' ') // tira o espaço do início da string
                memmove(aux->nomeMusica, aux->nomeMusica+1, strlen(aux->nomeMusica));
            break;
        case 2:
            strcpy(aux->idMusica, token);
            if (aux->idMusica[0] == ' ') // tira o espaço do início da string
                memmove(aux->idMusica, aux->idMusica+1, strlen(aux->idMusica));
            break;
        case 3:
            strcpy(aux->nomeAlb, token);
            if (aux->nomeAlb[0] == ' ') // tira o espaço do início da string
                memmove(aux->nomeAlb, aux->nomeAlb+1, strlen(aux->nomeAlb));
            break;
        case 4:
            strcpy(aux->idAlb, token);
            if (aux->idAlb[0] == ' ') // tira o espaço do início da string
                memmove(aux->idAlb, aux->idAlb+1, strlen(aux->idAlb));
            break;
        case 5:
            strcpy(aux->nomeArt, token);
            if (aux->nomeArt[0] == ' ') // tira o espaço do início da string
                memmove(aux->nomeArt, aux->nomeArt+1, strlen(aux->nomeArt));
            break;
        case 6:
            strcpy(aux->idArt, token);
            if (aux->idArt[0] == ' ') // tira o espaço do início da string
                memmove(aux->idArt, aux->idArt+1, strlen(aux->idArt));
            break;
        case 7:
            strcpy(aux->data, token);
            if (aux->data[0] == ' ') // tira o espaço do início da string
                memmove(aux->data, aux->data+1, strlen(aux->data));
            break;
        case 8:
            aux->length = atof(token);
            break;
        case 9:
            aux->popularity = atof(token);
            break;
        case 10:
            aux->acoustcness = atof(token);
            break;
        case 11:
            aux->danceability = atof(token);
            break;
        case 12:
            aux->energy = atof(token);
            break;
        case 13:
            aux->instrumentalness = atof(token);
            break;
        case 14:
            aux->liveness = atof(token);
            break;
        case 15:
            aux->loudness = atof(token);
            break;
        case 16:
            aux->speechiness = atof(token);
            break;
        case 17:
            aux->tempo = atof(token);
            break;
        case 18:
            aux->timeSignature = atof(token);
            break;
    }
}
// Função de teste, que imprime os artistas, seus álbuns e as músicas de cada álbum
void print(Lista *l){ // caso queira testar se os ponteiros estão apontando corretamente
    
    Musica *mus = l->iniM;

    printf("MUSICAS\n");
    while (mus != NULL){
        printf("ID - %s\n", mus->id);
        printf("MUSICA - %s\n", mus->nome);
        printf("ALBUM - %s\n", mus->alb->nome);
        printf("ARTISTA - %s\n", mus->art->nome);
        printf("\n");
        mus = mus->prox;
    }
    printf("---ALBUNS---\n");
    Album *alb = l->iniAlb;
    while (alb != NULL){
        printf("ID - %s\n", alb->id);
        printf("ALBUM - %s\n", alb->nome);
        printf("ARTISTA - %s\n", alb->art->nome);
        printf("\n");
        alb = alb->prox;
    }
    printf("---ARTISTAS---\n");
    Artista *art = l->iniArt;
    while (art != NULL){
        printf("ID - %s\n", art->id);
        printf("ARTISTA - %s\n", art->nome);
        printf("\n");
        art = art->prox;
    }
}
// Função que abre o arquivo CSV
void abrirArquivo(FILE *arquivo, Lista *l){
    int flag = 0, x = 1; 
    char *linha = malloc(1024*sizeof(char)); // pega cada linha do arquivo
    
    while (fgets(linha, 1024, arquivo)){// pega linha até o final do arquivo
        if(flag){ // caso já tenha que pegar os dados
            Aux aux;
        
            char *token = strtok(linha, ";"); // quebra no ";"
            
            if(token[0] == ' '){// caso não tenha a primeira música, vai pra lista "(null)"
                atribuiAux(&aux, "(null)", x++);
                atribuiAux(&aux, token, x++); 
            }else // caso tenha a primeira música
                atribuiAux(&aux, token, x++);
            
            while(token != NULL){ // até o fim da linha
                token = strtok(NULL, ";\n");
                
                if(token != NULL){
                    atribuiAux(&aux, token, x++);
                }
            }

            insereArtista(l, aux); //Insere os dados da estrutura na lista
            l->nTracks++;// incrementa número de músicas

            x = 1; // inícia de novo
        }
        flag++;
    }

    free(linha);

}
// Função que troca as músicas
void troca(Musica *a, Musica *b){   
    //auxiliar
    char *tmpid = a->id, *tmpnome = a->nome, *tmpdata = a->data;
    
    double tmpdanceability = a->danceability, tmppopularity = a->popularity, tmplength = a->length, tmptimeSignature = a->timeSignature, tmpinstrumentalness = a->instrumentalness,
    tmpliveness = a->liveness, tmploudness = a->loudness, tmpspeechiness = a->speechiness, tmptempo = a->tempo, tmpacoustcness = a->acoustcness,
    tmpenergy = a->energy; 

    Artista *tmpart = a->art;
    Album *tmpalb = a->alb;

    a->id = b->id;
    a->nome = b->nome;
    a->data = b->data;
    a->popularity = b->popularity;
    a->length = b->length;
    a->timeSignature = b->timeSignature;
    a->instrumentalness = b->instrumentalness;
    a->liveness = b->liveness;
    a->loudness = b->loudness;
    a->speechiness = b->speechiness;
    a->tempo = b->tempo;
    a->acoustcness = b->acoustcness;
    a->energy = b->energy;
    a->danceability = b->danceability;
    a->art = b->art;
    a->alb = b->alb;


    b->id = tmpid;
    b->nome = tmpnome;
    b->data = tmpdata;
    b->popularity = tmppopularity;
    b->length = tmplength;
    b->timeSignature = tmptimeSignature;
    b->instrumentalness = tmpinstrumentalness;
    b->liveness = tmpliveness;
    b->loudness = tmploudness;
    b->speechiness = tmpspeechiness;
    b->tempo = tmptempo;
    b->acoustcness = tmpacoustcness;
    b->energy = tmpenergy;
    b->danceability = tmpdanceability;
    b->art = tmpart;
    b->alb = tmpalb;
} 
// Partição do quicksort
Musica* particao(Musica *base, Musica *topo){
    
    char *pivo = topo->id;

    Musica *i = base->ant;

    for (Musica *j = base; j != topo; j = j->prox){ 
        if (strcmp(j->id, pivo) <= 0){ // se for maior que o pivô
            
            i = (i == NULL) ? base : i->prox; 
            
            troca(i, j); 
        } 
    } 

    i = (i == NULL)? base: i->prox; 

    troca(i, topo);

    return i; 
} 
//quicksort 
void quicksort(Musica* base, Musica *topo){ 
    if (topo != NULL && base != topo && base != topo->prox) { 
        
        Musica *p = particao(base, topo); 

        quicksort(base, p->ant);
        quicksort(p->prox, topo);
    } 
}
// calcula distância de duas músicas
double distancia(Musica *m2, Musica *m1){
    double distancia = 0, total;
    
    distancia += pow((m1->timeSignature - m2->timeSignature), 2);
    distancia += pow((m1->instrumentalness - m2->instrumentalness), 2);
    distancia += pow((m1->liveness - m2->liveness), 2);
    distancia += pow((m1->loudness - m2->loudness), 2);
    distancia += pow((m1->speechiness - m2->speechiness), 2);
    distancia += pow((m1->tempo - m2->tempo), 2);
    distancia += pow((m1->acoustcness - m2->acoustcness), 2);
    distancia += pow((m1->energy - m2->energy), 2);
    distancia += pow((m1->danceability - m2->danceability), 2);

    total = sqrt(distancia);

    return total;
}
// gera a matriz dissimilaridade
Mat **gerarMatriz(Lista *l){
    // cria matriz
    Mat **matriz = (Mat**)malloc(sizeof(Mat*)*l->nTracks+1);
    for(int i = 0; i < l->nTracks; i++)
        matriz[i] = (Mat*)malloc(sizeof(Mat)*l->nTracks+1);
    
    //aux1 que percorre a lista de músicas
    Musica *aux1 = l->iniM;
    int i = 0, j = 0;

    while (aux1 != NULL){// linhas da matriz
        //aux2 que percorre a lista de músicas
        Musica *aux2 = l->iniM;

        while (aux2 != NULL){//colunas da matriz

            matriz[i][j].distancia = distancia(aux1, aux2); //calcula a distância

            matriz[i][j].mus = aux2; // pega o ponteiro mus e aponta para a posição da música na lista de músicas
    
            aux2 = aux2->prox; // próxima música
            j++;//incrementa coluna
        }

        matriz[i]->mus = aux1; //pega o ponteiro mus das linhas e aponta para a música na lista 

        aux1 = aux1->prox;//próxima música
        j = 0;//zera colunas
        i++;// incrementa linhas
    }

    return matriz;// retorna matriz
}
// busca binária nas linhas da matriz
int busca(Mat *arr, int l, int r, char *string) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        
        if (strcmp(arr[mid].mus->id, string) == 0) //se achar retorna
            return mid; 
  
        if (strcmp(arr[mid].mus->id, string) > 0) 
            return busca(arr, l, mid - 1, string); 
  
        return busca(arr, mid + 1, r, string); 
    } 

    return -1; // não achou
} 
// radix sort
Mat *radixSort(Mat **vet, int n, int index){
    int c[256] = {0};
    int pos[256];

    Mat *aux = malloc(sizeof(Mat)*n); // vetor auxiliar que vai ser ordenado
    Mat *vcop = malloc(sizeof(Mat)*n);
    
    for(int i = 0; i < n; i++) // copia valores da linha da matrizs
        aux[i] = vet[index][i];

    for (int shift = 0; shift <= 24; shift += 8){
        
        for(int j = 0; j < n; j++){
            short k = ((int)(aux[j].distancia*1000000) >> shift) & 255;
            c[k]++;
            vcop[j] = aux[j];
        }

        pos[0] = 0;

        for(int i = 1; i < 256; i++){
            pos[i] = pos[i-1] + c[i-1];
            c[i-1] = 0;
        }

        for (int j = 0; j < n; j++){
            short k = ((int)(vcop[j].distancia*1000000) >> shift) & 255;
            aux[pos[k]] = vcop[j];
            pos[k]++;
        }

    }

    free(vcop);

    return aux;// retorna auxiliar
}

void imprimir(int index, Mat *m, Mat *aux, int n){
    
    printf("----As %d musicas mais parecidas com %s sao:\n", n, m[index].mus->nome);
    for (int i = 0; i < n; i++){
        printf("\t(%d)Artista: %s\n", i, aux[i].mus->art->nome);
        printf("\t\tMusica: %s\n", aux[i].mus->nome);
        printf("\t\tDissimilaridade: %lf\n", aux[i].distancia);
        printf("\t\tLink: https://open.spotify.com/track/%s\n", aux[i].mus->id);
    }
    printf("\n");
}
