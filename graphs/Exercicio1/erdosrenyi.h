// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funçoes
int **alocarMatriz(int n);
void liberarMatriz(int n, int **matriz);
void criarMatriz(int num, int **matrizGrafo);
void imprimirMatriz(int num, int **matrizGrafo);
void grauVertice (int num, int **matrizGrafo);
void arestaExiste(int num, int **matrizGrafo);