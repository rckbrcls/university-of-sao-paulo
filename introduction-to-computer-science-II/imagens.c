#include <stdio.h>
#include <stdlib.h>
// Função que aloca a matriz dinamicamente
int **alocar(int **mat, int n){
    mat = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
    }
    return mat;
}
// Função que libera a matriz
void liberaMat(int **mat, int n){ 
    for (int i=0; i < n; i++)
        free (mat[i]);
    free (mat);
}
// Função que imprime a matriz
void imprimir(int **mat, int n){
    for (int i = 0; i <  n; i++) { // Imprimindo a matriz do labirinto
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
// Função que calcula o intervalo 'm'
int intervalo(int **mat, int x, int y, int p, int t){
    int m = 0, calc = 0;
    
    calc = p - mat[x][y];
    m = abs(calc); // Módulo
    
    if(m <= t){ // Se condiz com o intervalo, retorna verdadeiro
        return 1;
    }else{ // Se não, retorna falso
        return 0;
    }
}

int pixel(int x, int y, int **mat, int t, int n, int p, int flag){
    
    if(x < 0 || x >= n || y < 0 || y >= n){ // Verifica se não ultrapassa os limites da matriz
        return 0;
    }else if(mat[x][y] == p && flag == 1){ // Verifica se 'v' é igual a 'p', e se não é a posição de 'p'
        return 0;
    }else if(intervalo(mat, x, y, p, t)){ // Verifica se condiz com o intervalo
        mat[x][y] = p;
        if (pixel(x - 1, y, mat, t, n, p, 1)) return 1;// Tenta ir para cima.
        if (pixel(x , y + 1, mat, t, n, p, 1)) return 1;// Tenta ir para a direita.
        if (pixel(x + 1, y , mat, t, n, p, 1)) return 1;// Tenta ir para baixo.
        if (pixel(x, y- 1, mat, t, n, p, 1)) return 1;// Tenta ir para a esquerda.
    }
    
    return 0;// Não conseguiu, então volta.
}

int main (void){
    int n = 0, x = 0, y = 0, t = 0, **mat = NULL;
    
    scanf("%d %d %d %d", &n, &x, &y, &t);
    mat = alocar(mat, n);
    
    srand(t); //Gera semente aleatória
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            mat[i][j] = rand() % 256; // Atribui até o número 255
        }
    }
    imprimir(mat, n);
    pixel(x, y, mat, t, n, mat[x][y], 0);
    printf("\n");
    imprimir(mat, n);
    liberaMat(mat, n);// Libera matriz
    return 0;
}