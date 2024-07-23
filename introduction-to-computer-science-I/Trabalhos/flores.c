//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// estrutura dos dados da flor
typedef struct flores{
    char *especie;
    double largura;
    double altura;
    int grupo;
    struct flores *rep;
}Flor;

// cria vetor de struct
Flor *criaStruct(){
    Flor *aux = (Flor*)malloc(150*sizeof(Flor)); // 150 posições 
    
    for(int i = 0; i < 150; i++){ // inicializa as posições 
        aux[i].largura = 0;
        aux[i].altura = 0;
        aux[i].grupo = 0;
        aux[i].especie = (char*)malloc(100*sizeof(char));
        aux[i].rep = NULL;
    }

    return aux; // retorna o vetor
}
// cria matriz de struct
Flor **criaGrupos(int gp){
    Flor **grupos = (Flor**)malloc(gp*sizeof(Flor*)); // linhas = grupos
    for(int i = 0; i < gp; i++)
        grupos[i] = (Flor*)malloc(150*sizeof(Flor));// colunas = flores

    for(int i = 0; i < gp; i++){//roda os grupos
        grupos[i]->rep = (Flor*)malloc(sizeof(Flor));// aloca cada representante dos grupos
        grupos[i]->rep->especie = (char*)malloc(100*sizeof(char));
        grupos[i]->rep->altura = 0;
        grupos[i]->rep->largura = 0;
        for(int j = 0; j < 150; j++){ // inicializa cada posição do grupo
            grupos[i][j].largura = 0;
            grupos[i][j].altura = 0;
        }
    }

    return grupos; // retorna 
}
// abrir arquivo para ler
FILE *abrirArquivo(char *arqname){
    FILE *aux = fopen(arqname, "r"); // ler
    
    if(aux == NULL){ // caso esteja vazio
        printf("ERRO! arquivo vazio\n");
        exit(-1);
    }

    return aux; // retorna 
}

void lerDados(Flor *f, char *arqname){
    int flag = 0, i = 0; 
    char *linha = malloc(1024*sizeof(char)); // pega cada linha do arquivo
    
    FILE *arquivo = abrirArquivo(arqname); // abre o arquivo

    while (fgets(linha, 1024, arquivo)){// pega linha até o final do arquivo
        
        if(flag && i < 150){ // caso já tenha passado do cabeçalho e não tenha passado da última posição do vetor

            char *token = strtok(linha, ","); // quebra no ","
            f[i].altura = atof(token); 

            token = strtok(NULL, ",");
            f[i].largura = atof(token);

            token = strtok(NULL, "\n");
            strcpy(f[i].especie, token);

            i++; // incrementa 
        }

        flag++; // flag de saída do cabeçalho
    }

    free(linha); // libera linha
    fclose(arquivo);// fecha o arquivo

}
// inicializa os representantes 
void inicializar(Flor *f, Flor **grupos, int gp){
    int pos = 0; // posição do representante no vetor

    printf("Os representantes iniciais são:\n\n");

    for(int i = 0; i < gp;  i++){
        printf("Grupo %d:\n\n", i+1);

        pos = rand() % 150; // número aleatório de 0 -> 149

        // atribui para o representante do grupo
        grupos[i]->rep->altura = f[pos].altura;
        grupos[i]->rep->largura = f[pos].largura;

        printf("Altura - %.1lf\n", grupos[i]->rep->altura);
        printf("Largura - %.1lf\n", grupos[i]->rep->largura);
    }

}
// atualiza representante
void atualizarR(Flor **grupos, int gp){
    double somaAlt = 0, somaLarg = 0, mediaAlt = 0, mediaLarg = 0;
    int count = 0;

    for(int j = 0; j < gp; j++){

        printf("Representante anterior do grupo %d: %.2lf, %.2lf\n", j+1, grupos[j]->rep->altura, grupos[j]->rep->largura);
        
        for(int i = 0; i < 150; i++){
            if(grupos[j][i].altura != 0){ // até chegar numa posição que não tenha uma flor alocada
                // soma altura e largura
                somaAlt += grupos[j][i].altura;
                somaLarg += grupos[j][i].largura;

                count++; // incrementa número de flores

            }else if(grupos[j][i].altura == 0){ //se chegar na posição não alocada, para o laço
                break;
            }
        }
        
        if(count != 0){
            // tira as médias 
            mediaAlt = somaAlt/count;
            mediaLarg = somaLarg/count;

            // atualiza o representante
            grupos[j]->rep->altura = mediaAlt;
            grupos[j]->rep->largura = mediaLarg;

            printf("Representante atual: %.2lf, %.2lf\n\n", grupos[j]->rep->altura, grupos[j]->rep->largura);
        }
        // zera para atribuir de novo as flores
        for(int i = 0; i < 150; i++){
            grupos[j][i].altura = 0;
            grupos[j][i].largura = 0;
        }
    }
    
}

// aloca flor nos grupos
void alocarGP(Flor **grupos, Flor *f, int gp){
    int menorPos = 0; // posição na matriz da menor distância euclidiana
    
    for(int i = 0; i < 150; i++){

        printf("---GRUPO 1---\n\n");
        printf("ALTURA: %.2lf - %.2lf \n\n", grupos[0]->rep->altura, f[i].altura);
        printf("LARGURA: %.2lf - %.2lf \n\n", grupos[0]->rep->largura, f[i].largura);

        double dX = grupos[0]->rep->altura - f[i].altura; 
        double dY = grupos[0]->rep->largura - f[i].largura; 
        double dist = sqrt(dX*dX + dY*dY);

        double menorDist = dist; // inicializa a menor distância com a distância do primeiro grupo

        printf("DISTANCIA: %.2lf\n\n", dist);    

        for(int j = 1; j < gp; j++){ // calcula a distância dos restos dos grupos
            printf("---GRUPO %d--\n\n", j+1);
            printf("ALTURA: %.2lf - %.2lf \n\n", grupos[j]->rep->altura, f[i].altura);
            printf("LARGURA: %.2lf - %.2lf \n\n", grupos[j]->rep->largura, f[i].largura);
            
            dX = grupos[j]->rep->altura - f[i].altura; 
            dY = grupos[j]->rep->largura - f[i].largura; 
            dist = sqrt(dX*dX + dY*dY);

            printf("DISTANCIA: %.2lf\n\n", dist);

            // caso a distância de outro grupo seja menor, atualiza a menor distância e a posição do grupo na matriz
            if(dist < menorDist){
                menorDist = dist;
                menorPos = j;
            }
                
        }

        printf("Vai para o grupo: %d\n\n", menorPos+1);

        for(int j = 0; j < 150; j++){ // roda tadas as posições do grupo
            if(grupos[menorPos][j].altura == 0){ // até achar uma que não esteja alocada nenhuma flor, aí atribui os dados
                grupos[menorPos][j].altura = f[i].altura;
                grupos[menorPos][j].largura = f[i].largura;
                f[i].grupo = menorPos+1;// passa o grupo para o vetor, para a hora de passar pro arquivo os dados
                break;// sai do laço
            }
        }
    }
}
// escreve em outro arquivo
void escreverResult(char *arqname, Flor *f){
    FILE *arq = fopen(arqname, "wb"); // abrir para escrever

    fprintf(arq, "%s", "\"petal.length\",\"petal.width\",\"variety\",\"group\"\n"); // cabeçalho das colunas

    for(int i = 0; i < 150; i++){
        fprintf(arq, "%.1lf,%.1lf,%s,%d%s", f[i].altura, f[i].largura, f[i].especie, f[i].grupo, "\n"); // passa os dados para o arquivo
    }

    fclose(arq); // fecha o arquivo

}
// imprime os grupos
void imprimirGP(int gp, Flor **grupos){
    for(int i = 0; i < gp; i++){ // linhas = grupos
        printf("---GRUPO %d---\n\n", i+1); 
        for(int j = 0; j < 150; j++){ // colunas = flores dos grupos
            if(grupos[i][j].altura != 0){ // caso chegue numa posição que não foi alocada uma flor 
                printf("%d - %.2lf, %.2lf\n", j+1, grupos[i][j].altura, grupos[i][j].largura);
            }else // se sim, para o laço
                break;
        }
        printf("\n");
    }
}

void liberarMat(Flor **grupos, int gp){
    //libera a matriz

    for (int i = 0; i < gp; i++){
        free(grupos[i]->rep->especie);
        free(grupos[i]->rep);
        free(grupos[i]);
    }

    free(grupos);
}

void liberarVet(Flor *f){
    for (int i = 0; i < 150; i++)
        free(f[i].especie);
    free(f);
}

int main(int argc, char *argv[]){

    srand(time(NULL)); // semente aleatória 

    int gp = 0, repet = 0; 

    Flor *f = criaStruct();// cria vetor de struct que pega os dados do arquivo

    lerDados(f, argv[1]); // passa os dados do arquivo para a struct

    printf("Escreva o numero de grupos que deseja:\n");
    scanf("%d", &gp);
    
    Flor **grupos = criaGrupos(gp); // cria matriz de grupos, cada linha um grupo, cada coluna uma flor

    inicializar(f, grupos, gp); // inicializa o representante 

    printf("Escreva quantas vezes deseja que as etapas sejam feitas:\n");
    scanf("%d", &repet); 

    for(int i = 0; i < repet; i++){// roda o número de etapas
        alocarGP(grupos, f, gp); // aloca cada flor em seu grupo
        printf("---Atualizando representante---\n\n");
        atualizarR(grupos, gp);// atualiza representante
    }

    escreverResult(argv[2], f); // escreve no arquivo csv

    imprimirGP(gp, grupos); // imprime os grupos 

    liberarMat(grupos, gp);
    liberarVet(f);
}