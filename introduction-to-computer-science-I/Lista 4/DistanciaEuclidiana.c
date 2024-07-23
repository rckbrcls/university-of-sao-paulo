#include<stdio.h>
#include<math.h>

int main(void){
    float vet1[3], vet2[3], distanciaEuclidiana = 0, final = 0;  

    for(int i = 0; i < 3; i++){
        scanf("%f", &vet1[i]);
    }
    for(int i = 0; i < 3; i++){
        scanf("%f", &vet2[i]);
    }
    for(int i = 0; i < 3; i++){
        distanciaEuclidiana += (pow(vet1[i] - vet2[i], 2));
        final = sqrt(distanciaEuclidiana);
    }
    
    printf("%f\n", final);

    return 0;
}