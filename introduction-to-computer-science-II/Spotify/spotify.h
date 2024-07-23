#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct musica{
    char *nome, *id, *instrumentalness, *data;
    float acoustcness, tempo, speechiness, popularity, loudness,
          liveness, energy,danceability, length, timeSignature;
    struct musica *prox;
}Musica;

typedef struct album{
    char *nome;
    char *id;
    int nTracks;
    Musica *ini, *fim;
    struct album *prox;
}Album;

typedef struct artista{
    char *nome, *id;
    int nAlbum, nTracks;
    float popularidade, media;
    Album *ini, *fim;
    struct artista *prox, *ant;
}Artista;

typedef struct lista{
    int nArtistas, nTracks;
    Artista *ini, *fim;
}Lista;

typedef struct auxiliar{
    char nomeMusica[200], idMusica[200], instrumentalness[200], data[200];
    float acoustcness, tempo, speechiness, popularity, loudness,
          liveness, energy,danceability, length, timeSignature;
    char nomeAlb[200], idAlb[200];
    char nomeArt[200], idArt[200];
}Aux;

Musica *criaMusica();
Album *criaAlbum();
Artista *criaArtista();
Lista *criaLista();
void destroiAlbum(Album *l);
void destroiArtista(Artista *l);
void destroiLista(Lista *l);
Artista *existeArtista(Artista *p, char *id);
Album *existeAlbum(Album *p, char *id);
void insereMusica(Album *alb, Aux aux);
void insereAlbum(Artista *art, Aux aux);
void insereArtista(Lista *l, Aux aux);
void atribuiAux(Aux *aux, char *token, int x);
void ImprimeLista(Lista *l);
void print(Lista *l);
void abrirArquivo(FILE *arquivo, Lista *l);
void troca(Artista *a, Artista *b);
Artista* particao(Artista *base, Artista *topo);
void quicksort(Artista* base, Artista *topo);