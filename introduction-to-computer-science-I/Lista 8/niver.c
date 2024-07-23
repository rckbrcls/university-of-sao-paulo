#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct aniversariante
typedef struct aniver{
    char nome[50];
    int dia;
    int mes;
    int ano;
}Niver;
// abrir arquivo para leitura
FILE *abrirLeitura(char *arqname){
    FILE *arq = fopen(arqname, "rb");

    if(arq == NULL){
        printf("ERRO!\n");
        exit(1);
    }

    return arq;
}
// abrir arquivo para escrita
FILE *abrirEscrita(char *arqname){
    FILE *arq = fopen(arqname, "wb");

    if(arq == NULL){
        printf("ERRO!\n");
        exit(1);
    }

    return arq;
}
// fazer cadastro dos aniversariantes
void cadastrar(int num, char *arqname){
    Niver *p = calloc(num, sizeof(Niver)); // calloca um vetor de struct
    FILE *bin = abrirEscrita(arqname); // abre pra escrita

    for(int i = 0; i < num; i++){
        printf("Aniversariante %d:\n", i+1);
        printf("Nome: ");
        scanf("%s", p[i].nome);
        getchar();
        
        printf("Dia: ");
        scanf("%d", &p[i].dia);
        
        printf("Mes: ");
        scanf("%d", &p[i].mes);
        
        printf("Ano: ");
        scanf("%d", &p[i].ano);
        printf("\n");
        
    }

    fwrite(p, sizeof(Niver), num, bin); // escreve vetor

    //fecha e libera
    fclose(bin);
    free(p);
}
// buscar mês
void buscar(int mes, int num, char *arqname){
    FILE *bin = abrirLeitura(arqname); // abre para leitura
    Niver p; // struct auxiliar
    int achou = 0; // se achou algum aniversariante

    while(fread(&p, sizeof(Niver), 1, bin) != 0){ //pega struct por struct
        if(mes == p.mes){ // se acha alguma com mês procurado
            printf("%s faz aniversario no mes %d!!!\n", p.nome, p.mes);
            achou = 1; // true
        }
    }

    if (!achou)
		printf("Nao achou nenhum aniversariante no mes: %d\n", mes);

    fclose(bin);
}
// remover do arquivo
void remover(char *arqname, char *busca, int num){
    FILE *bin = abrirLeitura(arqname); // abrir o original para leitura
	FILE *binTemp = abrirEscrita("tmp.bin"); // auxiliar para escrita
	Niver p;
	int achou = 0;

    while(fread(&p, sizeof(Niver), 1, bin) != 0) { 
        if (strcmp (busca, p.nome) == 0){ // se achou, não escreve sua struct no arquivo auxiliar
            printf("Removeu o aniversariante: %s\n", busca);
            achou = 1;
        }else
            fwrite(&p, sizeof(Niver), 1, binTemp); // escreve struct por struct 
    }

	if (!achou)
		printf("Nao achou o aniversariante: %s\n", busca);
	
    // fecha
	fclose(bin);
	fclose(binTemp);

	remove(arqname);// apaga o original
	rename("tmp.bin", arqname); // renomeia o auxiliar com o nome do original
}

void exportar(char *arqname, int num){
    FILE *arq = abrirEscrita("niver.csv"); // abrir para escrever
    FILE *bin = abrirLeitura(arqname); // abrir para leitura
    Niver p;

    fprintf(arq, "%s", "Nome;Dia;Mes;Ano\n"); // cabeçalho das colunas

    while(fread(&p, sizeof(Niver), 1, bin) != 0)
        fprintf(arq, "%s;%d;%d;%d\n", p.nome, p.dia, p.mes, p.ano); // passa os dados para o arquivo

    // fecha o arquivo
    fclose(arq); 
    fclose(bin);
    
}

int main(void){
    
    int num = 0, mes = 0;
    char *remov = malloc(sizeof(char)*50);

    printf("\nEscreva quantos aniversariantes deseja incluir:\n");
    scanf("%d", &num);

    printf("----CADASTRO----\n\n");
    cadastrar(num, "binario.bin");

    printf("----BUSCA----\n\n");
    printf("-1 = parar busca:\n\n");
    
    while (mes != -1){
        printf("Mes escolhido: ");
        scanf("%d", &mes);
        printf("\n");
        if(mes != -1)
            buscar(mes, num, "binario.bin");
        printf("\n");
    }

    printf("----REMOÇÃO----\n\n");
    printf("-1 = parar remoçao:\n\n");

    do{
        printf("Nome a ser removido: ");
        scanf("%s", remov);
        getchar();
        printf("\n");

        if(strcmp(remov, "-1") != 0)
            remover("binario.bin", remov, num);
        
        printf("\n");
    }while (strcmp(remov, "-1") != 0);
    
    printf("----EXPORTAR----\n\n");
    exportar("binario.bin", num);

    free(remov);

    return 0;
}