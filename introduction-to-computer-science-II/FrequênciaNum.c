#include <stdio.h>
#include <stdlib.h>

int EntradaDeVetor(int arr[100]){// Funcão de entrada do vetor.
    int length = 0, c, bytesread;
    char string[100];

    fgets(string, sizeof(string), stdin); //Lê como se fosse uma string.
    
    char* input1 = string;
    
    while (sscanf(input1, "%d%n", &c, &bytesread) > 0) { // Laço os números para um veotr de inteiros.
        arr[length++] = c;
        input1 += bytesread;
    }
    return length;// Tamanho do vetor.
}

int EliminarRep(int arr[100], int freq[100], int aux[100], int auxfreq[100], int size){ // Função que elimina os inteiros repetidos para a impressão
    int j, i, n = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < n; j++ )
        {
            if(arr[i] == aux[j] )
                break;
        }
        if(j == n)
        {
            auxfreq[n] = freq[i];
            aux[n] = arr[i];
            n++;
        }
    }
    return n;
}

void FreqNum(int arr[100], int freq[100], int size){ //Calcula a frequência dos números
    for(int i = 0; i < size; i++){
        freq[i] = 0;
        for(int j = 0; j < size; j++){
            if(arr[i]==arr[j]){
                freq[i]++;
            }
        }
    }
}

void ImprimirSeq(int arr[100], int freq[100], int size){ //Função de impressão
    int aux[size+1], auxfreq[size+1], n;
    
    n = EliminarRep(arr, freq, aux, auxfreq, size);

    for(int i = 0; i < n; i++){
        printf("%d (%d)\n", aux[i], auxfreq[i]);
    }
}

int main(void) {
	int size, arr[100], freq[100];

    size = EntradaDeVetor(arr);

    FreqNum(arr, freq, size);
    ImprimirSeq(arr, freq, size);

    return 0;
}