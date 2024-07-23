#include "spotify.h"
//Função que cria música
Musica *criaMusica(){
    Musica *music = (Musica*)malloc(sizeof(Musica));
    music->nome = malloc(200*sizeof(char));
    music->id = malloc(200*sizeof(char));
    music->instrumentalness = malloc(200*sizeof(char));
    music->data = malloc(200*sizeof(char));
    music->prox = NULL;
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
    album->ini = NULL;
    album->fim = NULL;
    album->prox = NULL;
    album->nTracks = 0;
    return album;
}
//Função que cria artista
Artista *criaArtista(){
    Artista *art = (Artista*)malloc(sizeof(Artista));
    art->nome = malloc(200*sizeof(char));
    art->id = malloc(200*sizeof(char));
    art->ini = NULL;
    art->fim = NULL;
    art->prox = NULL;
    art->ant = NULL;
    art->nTracks = 0;
    art->nAlbum = 0;
    art->popularidade = 0;
    art->media = 0;
    return art;
}
//Função que cria lista
Lista *criaLista(){
    Lista *l = malloc(sizeof(Lista));
    l->ini = NULL;
    l->fim = NULL;
    l->nTracks = 0;
    l->nArtistas = 0;
    return l;
}
// Função que destroi álbum
void destroiAlbum(Album *l){
    if(l != NULL){
        Musica *p = l->ini;
        while (p != NULL) {
            l->ini = l->ini->prox;
            free(p);
            p = l->ini;
        }
        free(l);
    } 
}
// Função que destroi artista
void destroiArtista(Artista *l){
    if(l != NULL){
        Album *p = l->ini;
        while (p != NULL) {
            l->ini = l->ini->prox;
            destroiAlbum(p);
            p = l->ini;
        }
        free(l);
    } 
}
// Função que destroi lista
void destroiLista(Lista *l){
    if(l != NULL){
        Artista *p = l->ini;
        while (p != NULL) {
            l->ini = l->ini->prox;
            destroiArtista(p);
            p = l->ini;
        }
        free(l);
    } 
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
void insereMusica(Album *alb, Aux aux){
    assert(alb != NULL);
    
    Musica *music = criaMusica();// cria nó
    
    strcpy(music->nome, aux.nomeMusica);
    strcpy(music->id ,aux.idMusica); 
    strcpy(music->instrumentalness ,aux.instrumentalness);
    strcpy(music->data ,aux.data);
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

    if (alb->fim != NULL) alb->fim->prox = music;
    alb->fim = music;

    if (alb->ini == NULL) alb->ini = music;

    alb->nTracks++;//incrementa o número de músicas no álbum
}
//Função que insere álbum
void insereAlbum(Artista *art, Aux aux){
    assert(art != NULL);
    
    Album *alb = existeAlbum(art->ini, aux.idAlb);//verifica se o álbum já existe

    if(alb->ini == NULL){ //se não existir, insere novo nó
        strcpy(alb->id, aux.idAlb);
        strcpy(alb->nome, aux.nomeAlb);
        art->nAlbum++; //incrementa número de álbuns do artista

        if (art->fim != NULL) art->fim->prox = alb;
        art->fim = alb;

        if (art->ini == NULL) art->ini = alb;
    } 

    insereMusica(alb, aux);// insere música
}
//Função que insere artista
void insereArtista(Lista *l, Aux aux){
    assert(l != NULL);

    Artista *art = existeArtista(l->ini, aux.idArt); //verifica se o artista já existe

    if(art->ini == NULL){ // se não existir, insere o novo nó
        strcpy(art->id, aux.idArt);
        strcpy(art->nome, aux.nomeArt);
        l->nArtistas++;//incrementa número de artistas na lista
        
        art->ant = l->fim;
        if (l->fim != NULL) l->fim->prox = art;
        l->fim = art;

        if (l->ini == NULL) l->ini = art;
    }

    art->nTracks++; // incrementa número de músicas do artista
    art->popularidade += aux.popularity; // soma as popularidades
    art->media = (art->popularidade/art->nTracks); // tira a média
    insereAlbum(art, aux); // insere álbum
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
            strcpy(aux->instrumentalness, token);
            if (aux->instrumentalness[0] == ' ') // tira o espaço do início da string
                memmove(aux->instrumentalness, aux->instrumentalness+1, strlen(aux->instrumentalness));
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
// Imprime a lista 
void ImprimeLista(Lista *l){

    Artista *aux = l->ini;
    int i = 1;

    printf("O Dataset contem %d Artistas e %d Musicas\n", l->nArtistas, l->nTracks);
    printf("Os artistas mais populares sao:\n");

    while (aux != NULL) {
        printf("(%d) Artista: %s, Musicas: %d musicas, Popularidade: %.2lf, Link: https://open.spotify.com/artist/%s\n", i, aux->nome, aux->nTracks, aux->media, aux->id);
        aux = aux->prox;// próximo artista
        i++;
    }
}
// Função de teste, que imprime os artistas, seus álbuns e as músicas de cada álbum
void print(Lista *l){ // caso queira testar se os ponteiros estão apontando corretamente

    Artista *aux = l->ini;
    int i = 1;

    while (aux != NULL) {
        printf("(%d) ARTISTA:%s || POPULARIDADE: %.2f\n\n", i, aux->nome, aux->media);
        Album *alb = aux->ini;
        
        while (alb != NULL) {
            printf("ALBUM:%s\n\n", alb->nome);
            Musica *mus = alb->ini;
            int j = 1;
            
            while (mus != NULL) {
                printf("%d - %s\n",j ,mus->nome);
                mus = mus->prox;
                j++;
            }

            alb = alb->prox;
            printf("\n");
        }

        aux = aux->prox;
        i++;
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
// Função que troca os artistas
void troca(Artista *a, Artista *b){   
    //auxiliar
    char *tempID = a->id, *tempNome = a->nome;
    double tempPop = a->popularidade;
    double tempMedia = a->media;
    int tempTracks = a->nTracks;
    Album *tempIni = a->ini, *tempFim = a->fim;

    a->id = b->id;
    a->nome = b->nome;
    a->popularidade = b->popularidade;
    a->media = b->media;
    a->nTracks = b->nTracks;
    a->ini = b->ini;
    a->fim = b->fim;

    b->id = tempID;
    b->nome = tempNome;
    b->popularidade = tempPop;
    b->media = tempMedia;
    b->nTracks = tempTracks;
    b->ini = tempIni;
    b->fim = tempFim;
} 
// Partição do quicksort
Artista* particao(Artista *base, Artista *topo){
    
    float pivo = topo->media;

    Artista *i = base->ant;

    for (Artista *j = base; j != topo; j = j->prox){ 
        if (j->media >= pivo){ // se for maior que o pivô
            
            i = (i == NULL) ? base : i->prox; 
            
            troca(i, j); 
        } 
    } 

    i = (i == NULL)? base: i->prox; 

    troca(i, topo);

    return i; 
} 

void quicksort(Artista* base, Artista *topo){ 
    if (topo != NULL && base != topo && base != topo->prox) { 
        
        Artista *p = particao(base, topo); 

        quicksort(base, p->ant);
        quicksort(p->prox, topo);
    } 
}