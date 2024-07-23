#include <stdio.h>
#include <string.h>

int count(char string[25]){
	int tam = strlen(string), total = 0;

    for (int i = 0; i < tam; i++){
		char letra = string[i];
 		if (letra != 0){
			total = total + 1;			
			string[i] = 0;				
			for (int j = i+1; j < tam; j++){
				if (string[j] == letra)
					string[j] = 0;		
			}	
		}
	}
	return total;
}

int main(void){
    char string[25];
    
    scanf("%s", string);

    printf("%d\n", count(string));
    return 0;
}