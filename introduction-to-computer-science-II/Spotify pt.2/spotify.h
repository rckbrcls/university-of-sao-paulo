#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
// estrutura artista
typedef struct artista{
    char *nome, *id;
    int nAlbum, nTracks;
    double popularidade, media;
    struct artista *prox;
}Artista;
//estrutura albúm
typedef struct album{
    char *nome;
    char *id;
    int nTracks;
    struct album *prox;
    Artista *art;// ponteiro para o artista
}Album;
// estrutura música
typedef struct musica{
    char *nome, *id, *data;
    double instrumentalness, acoustcness, tempo, speechiness, popularity, loudness,
          liveness, energy,danceability, length, timeSignature;
    struct musica *prox, *ant;
    Artista *art;//ponteiro para o artista
    Album *alb;// ponteiro para o albúm
}Musica;
// estrutura lista
typedef struct lista{
    int nArtistas, nTracks;
    //listas 
    Artista *iniArt, *fimArt;
    Musica *iniM, *fimM;
    Album *iniAlb, *fimAlb;
}Lista;
// auxiliar
typedef struct auxiliar{
    char nomeMusica[200], idMusica[200], data[200];
    double instrumentalness, acoustcness, tempo, speechiness, popularity, loudness,
          liveness, energy,danceability, length, timeSignature, distancia;
    char nomeAlb[200], idAlb[200];
    char nomeArt[200], idArt[200];
}Aux;
// matriz com a distancia e o ponteiro para a música
typedef struct matriz{
    double distancia;
    Musica *mus;
}Mat;

Musica *criaMusica();
Album *criaAlbum();
Artista *criaArtista();
Lista *criaLista();
void destroiMusica(Lista *m);
void destroiAlbum(Lista *alb);
void destroiArtista(Lista *art);
void destroiLista(Lista *l);
Artista *existeArtista(Artista *p, char *id);
Album *existeAlbum(Album *p, char *id);
void insereMusica(Lista *l, Artista *art, Album *alb, Aux aux);
void insereAlbum(Lista *l, Artista *art, Aux aux);
void insereArtista(Lista *l, Aux aux);
void atribuiAux(Aux *aux, char *token, int x);
void print(Lista *l);
void abrirArquivo(FILE *arquivo, Lista *l);
void troca(Musica *a, Musica *b);
Musica* particao(Musica *base, Musica *topo);
void quicksort(Musica* base, Musica *topo);
double distancia(Musica *m2, Musica *m1);
Mat **gerarMatriz(Lista *l);
int busca(Mat *arr, int l, int r, char *string);
Mat *radixSort(Mat **vet, int n, int index);
void imprimir(int index, Mat *m, Mat *aux, int n);