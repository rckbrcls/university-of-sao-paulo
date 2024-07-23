#include<stdio.h>
#include<stdlib.h>

void printMaze(char **maze, int linhas, int colunas) { // Calcula as quantidades pedidas e imprime
    int pessoas = 0, valid = 0, visit = 0;
    float porcent;

    for (int x = 0; x <  linhas; x++) {//       Laço para percorrer todo o labirinto e
        for (int y = 0; y < colunas; y++) {//   contar as quantidades.
            if(maze[x][y]=='#'){// Quantidade de pessoas.
                pessoas++;
            }else if(maze[x][y]=='.'){// Quantidade de caminhos válidos.
                valid++;
            }else if(maze[x][y]=='*'){// Quantidade de caminhos visitados.
                visit++;
            }
        }
    }
    valid = valid + visit; // Total dos caminhos válidos.
    porcent = (visit*100)/valid; // Cálculo da porcentagem de exploração do labirinto.

    for (int x = 0; x <  linhas; x++) { // Imprimindo a matriz do labirinto
        for (int y = 0; y < colunas; y++) {
            printf("%c", maze[x][y]);
        }
        printf("\n");
    }

    printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\nVeja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n", pessoas);
    printf("----Numero total de caminhos validos:   %d\n", valid);
    printf("----Numero total de caminhos visitados: %d\n", visit);
    printf("----Exploracao total do labirinto: %.1f%%\n", porcent);
}

int labirinto(int lin, int col, char **maze, int linhas, int colunas) {  
    
    if (lin < 0 || lin >=linhas || col < 0 || col >= colunas){ // Verifica se não ultrapassa os limites da matriz
        return 0;
    }else if (maze[lin][col] == '#' ||maze[lin][col] == '*'){ // Verifica se há pessoas ou se já passou.
        return 0;
    }else if (lin == 0 || lin == linhas-1 || col == 0 || col == colunas-1){// Verifica se achou a saída.
        maze[lin][col] = '*';
        return 1;
    }else if (maze[lin][col]== '.'){ // Verifica se o caminho é livre.
        maze[lin][col] = '*';
        if (labirinto(lin - 1, col, maze, linhas, colunas)) return 1;// Tenta ir para cima.
        if (labirinto(lin , col + 1, maze, linhas, colunas)) return 1;// Tenta ir para a direita.
        if (labirinto(lin + 1, col , maze, linhas, colunas)) return 1;// Tenta ir para baixo.
        if (labirinto(lin, col- 1, maze, linhas, colunas)) return 1;// Tenta ir para a esquerda.
    }

    return 0;// Não conseguiu, então volta.
}

char **alocar(char **maze, int linhas, int colunas){
    maze = malloc(linhas * sizeof(char*));
    for (int x = 0; x < linhas; x++) {
        maze[x] = malloc(colunas * sizeof(char));
    }
    return maze;
}
void liberaMat(char **maze, int linhas){ 
    for (int i=0; i < linhas; i++)
        free (maze[i]);
    free (maze);
}

FILE *abrirArq(char arqname[100], FILE *arqtxt){ // Função de abrir o arquivo.
    arqtxt = fopen(arqname,"rt");
    if (arqtxt==NULL)
    {
        printf("ERRO!\n");
        exit(-1);
    }
    return arqtxt;
}

int main(){
    int linhas, colunas, lin, col;
    char arqname[100];
    char **maze = NULL;
    FILE *arqtxt = NULL;

    scanf("%[^\n]", arqname);
    
    arqtxt = abrirArq(arqname, arqtxt);

    fscanf(arqtxt, "%d%d\n", &linhas, &colunas);
    fscanf(arqtxt, "%d%d\n", &lin, &col);
    
    maze = alocar(maze, linhas, colunas); // Aloca a matriz do labirinto.
    
    for (int x = 0; x < linhas; x++){
        for (int y = 0; y < colunas; y++){
           fscanf(arqtxt, "%c\n", &(maze[x][y])); // Passa a matriz do arquivo para a do programa.
        }     
    }
      
    fclose(arqtxt);// fecha o arquivo
    labirinto(lin, col, maze, linhas, colunas); 
    printMaze(maze, linhas, colunas);
    liberaMat(maze,linhas);// Libera a matriz do labirinto.

    return 0;
}