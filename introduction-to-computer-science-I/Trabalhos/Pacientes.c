// Erick Barcelos - NUSP: 11345562
#include <stdio.h>
#include <math.h>
#define TRUE 1

int main (void){
    int indicadores = 0, pacientes = 11;
    /*Vetor que vai armazenar as distâncias euclidianas em 
      relação as posições das linhas da matriz*/
    float distanciaEuclidiana[10]; 
    
    printf("Entre com o número de exames e sintomas\n");
    scanf("%d", &indicadores); // Indicador de número de exames e sintomas
    
    //Verifica se entrou com um indicador errado
    while(indicadores < 3 || indicadores > 7){
        printf("Entre com um número valido\n");
        scanf("%d", &indicadores);
    }
    
    //Declara matriz com base no número de pacientes e indicador
    float matriz[pacientes][indicadores];
    
    //For's para entrar o histórico dos pacientes
    printf("Entre com o histórico de sintomas e exames dos pacientes\n");
    for(int i = 0; i < pacientes-1; i++){
        printf("Paciente %d\n", i+1);
        for(int j = 0; j < indicadores; j++){
            if(j==indicadores-1){ // Se chegou na posição do sintoma
                scanf("%f", &matriz[i][j]); // Escreve o sintoma
                while (TRUE){
                    if(matriz[i][j] == 1 || matriz[i][j] == -1){ // Se ele for valido, sai do while
                        break;
                    }else{ // Se não, escreve até entrar com o número valido
                        printf("Escreva um número valido\n");
                        scanf("%f", &matriz[i][j]);
                    }
                }
            }else{ // Se não for a posição do sintoma
                scanf("%f", &matriz[i][j]);
            }
        }
    }
    //Entrar com o novo paciente, que fica na última linha
    printf("Entre com o novo paciente\n");
    for(int i = 0; i < indicadores-1; i++){
        scanf("%f", &matriz[pacientes-1][i]);//Última linha, e escreve somente os exames (até penúltima coluna)
    }
    
    printf("Fazendo a distância euclidiana para saber seu sintoma...\n");
    int menor = 0; // Índice de onde tem a menor distância nas linhas da matriz

    //Calcula cada distância
    for(int i = 0; i < pacientes-1; i++){
        for(int j = 0; j < indicadores-1; j++){
            distanciaEuclidiana[i] += sqrt(pow(matriz[pacientes-1][j] - matriz[i][j], 2)); // Distância da i linha
        }
        if(distanciaEuclidiana[i]<distanciaEuclidiana[menor]){ //Se a posição i for menor, atribui para a variável "menor"
            menor = i;
        }      
    }

    matriz[pacientes-1][indicadores-1] = matriz[menor][indicadores-1]; // Atribibui o sintoma da menor linha para o novo paciente

    //Imprime todos os pacientes
    printf("Todos os pacientes\n");
    for(int i = 0; i < pacientes; i++){
        printf("Paciente %d - ", i+1);
        for(int j = 0; j < indicadores; j++){
            printf("%.1f ", matriz[i][j]);
        }      
        printf("\n");
    }

    return 0;// Finalizado
}